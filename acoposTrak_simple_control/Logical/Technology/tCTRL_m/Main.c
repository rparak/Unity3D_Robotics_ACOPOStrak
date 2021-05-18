/**
 * MIT License
 * Copyright(c) 2021 Roman Parak
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * Author   : Roman Parak
 * Email    : Roman.Parak@outlook.com
 * File Name: Main.c
 * Github   : https://github.com/rparak
 */

/** < Include B&R Automation libraries (declarations for B&R ANSI C extensions) */
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

/** < Include header file with specified structures / enums, etc. */
#include "Main.h"

/**
 * Program Intitialization
 */
void _INIT ProgramInit(void)
{
	/// Initialization of function block inputs
	MC_BR_AsmPowerOn_AcpTrak_0.Assembly       = &gAssembly_1;
	MC_BR_AsmGetShuttle_AcpTrak_0.Assembly    = &gAssembly_1;
	MC_BR_AsmPowerOff_AcpTrak_0.Assembly      = &gAssembly_1;
	MC_BR_AsmReadStatus_AcpTrak_0.Enable = 1;
	MC_BR_AsmReadStatus_AcpTrak_0.Assembly    = &gAssembly_1;
	MC_BR_AsmReset_AcpTrak_0.Assembly         = &gAssembly_1;
	MC_BR_AsmDeleteShuttle_AcpTrak_0.Assembly = &gAssembly_1;
	
	/// Set initialization parameters of the structure for custom structure (ACOPOStrak control and data collection).
	gTrakAsm.shuttle.num_of_shuttles  = 6;
	gTrakAsm.shuttle.shuttle_offset   = 0.2;
	gTrakAsm.shuttle.shuttle_velocity = 1.5;
	gTrakAsm.shuttle.sector_legth     = 5.885136451852274;
	gTrakAsm.actual_state             = ACPt_CTRL_POWER_OFF;
	
	/// Set machine vision camera (digital-twin) position (0 - Sector A, 1 - Sector B) 
	dt_service.machine_vision_position[0] = 4.45;
	dt_service.machine_vision_position[1] = 4.75;
}

/**
 * Program Cyclic 
 * 
 * Duration (Cycle Time): 2000 [µs] 
 * Tolerance            : 0    [µs]
 */
void _CYCLIC ProgramCyclic(void)
{
	/**
	 * Main state machine for control of a ACOPOStrak.
	 *
	 * Number of states: 15 (for more information -> 'Main.h')
	 * Structure: acoposT_ctrl_state_enum
	 */
	
	switch(gTrakAsm.actual_state){
		case ACPt_CTRL_POWER_OFF: ///< Turn off the axes and reset each of the parameters.
			{
				/// reset some status parameters
				gTrakAsm.status.power_on 	   = 0;
				gTrakAsm.status.is_homed       = 0;
				gTrakAsm.status.shuttles_exist = 0;
				/// enable the user to select initial parameters
				mv_service.enable_param 	   = 1;
				
				/// reset other parameters (for more information -> 'Main.h')
				reset_shuttle_param(gTrakAsm.shuttle.num_of_shuttles, gTrakAsm.shuttle.initial_sector, gTrakAsm.shuttle.shuttle_offset);
				reset_env();
				
				if(MC_BR_AsmPowerOff_AcpTrak_0.Done == 1){
					MC_BR_AsmPowerOff_AcpTrak_0.Execute = 0;
				}else if(gTrakAsm.control.power == 1){
					mv_service.enable_param = 0;
					gTrakAsm.actual_state = ACPt_CTRL_POWER_ON;
				}
			}
			break;
		
		case ACPt_CTRL_POWER_ON: ///< Turn on each of the axes.
			{
				MC_BR_AsmPowerOn_AcpTrak_0.Execute = 1;
				
				if(MC_BR_AsmPowerOn_AcpTrak_0.Done == 1){
					gTrakAsm.status.power_on      = 1;
					gTrakAsm.status.shuttle_index = 0;
					gTrakAsm.actual_state = ACPt_CTRL_ADD_SHUTTLE_1;
				}
			}
			break;
		
		case ACPt_CTRL_ADD_SHUTTLE_1: ///< Adding Shuttle for simulation.
			{
				if(gTrakAsm.status.shuttle_index < gTrakAsm.shuttle.num_of_shuttles){
					if(gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].sector_number == 0){
						MC_BR_SecAddShuttle_AcpTrak_0.Sector   = &SectorTrackA;
					}else if(gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].sector_number == 1){
						MC_BR_SecAddShuttle_AcpTrak_0.Sector   = &SectorTrackB;
					}
					
					MC_BR_SecAddShuttle_AcpTrak_0.Execute  					  = 1;
					MC_BR_SecAddShuttle_AcpTrak_0.Position 			          = gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].initial_position;
					MC_BR_SecAddShuttle_AcpTrak_0.AdvancedParameters.Velocity = 0.0;
					
					gTrakAsm.actual_state = ACPt_CTRL_ADD_SHUTTLE_2;
				}else{
					gTrakAsm.actual_state = ACPt_CTRL_GET_SHUTTLE_1;
				}
				
			}
			break;
		
		case ACPt_CTRL_ADD_SHUTTLE_2: ///< When the shuttle is added correctly, increase the index by one.
			{
				if(MC_BR_SecAddShuttle_AcpTrak_0.Done == 1){
					gTrakAsm.status.shuttle_index++;
					gTrakAsm.actual_state = ACPt_CTRL_ADD_SHUTTLE_1;
				}
			}
			break;
		
		case ACPt_CTRL_GET_SHUTTLE_1: ///< Get all available assembly information. (Initialization State)
			{
				MC_BR_AsmGetShuttle_AcpTrak_0.Enable = 1;
				MC_BR_AsmGetShuttle_AcpTrak_0.Next   = 0;
				gTrakAsm.status.shuttle_index = 0;
				gTrakAsm.actual_state 		  = ACPt_CTRL_GET_SHUTTLE_3;
				
			}
			break;
		
		case ACPt_CTRL_GET_SHUTTLE_2: ///< Get all available assembly information. (Get next shuttle information)
			{
				MC_BR_AsmGetShuttle_AcpTrak_0.Next = 1;
				gTrakAsm.actual_state = ACPt_CTRL_GET_SHUTTLE_3;
			}
			break;
		
		case ACPt_CTRL_GET_SHUTTLE_3: ///< Get all available assembly information. (When the shuttle is exist, increase the index by one)
			{
				if(MC_BR_AsmGetShuttle_AcpTrak_0.Valid == 1){
					gTrakAsm.shuttle_axis[gTrakAsm.status.shuttle_index] = MC_BR_AsmGetShuttle_AcpTrak_0.Axis;
					gTrakAsm.status.shuttle_index++;
					
					if(MC_BR_AsmGetShuttle_AcpTrak_0.RemainingCount == 0){
						MC_BR_AsmGetShuttle_AcpTrak_0.Enable = 0;
						gTrakAsm.status.shuttles_exist = 1;
						gTrakAsm.actual_state 		   = ACPt_CTRL_WAIT;
					}else{
						MC_BR_AsmGetShuttle_AcpTrak_0.Next = 0;
						gTrakAsm.actual_state = ACPt_CTRL_GET_SHUTTLE_2;
					}
				}
			}
			break;
		
		case ACPt_CTRL_WAIT: ///< Wait for command from HMI visualization (user).
			{
				gTrakAsm.status.shuttle_index = 0;
				gTrakAsm.status.is_homed      = 1;
				
				/// Main state machine for animation mode control of a ACOPOStrak. -> (for more information -> 'Main.h')
				set_animation_mode();
				/// Reading shuttle parameters (position, velocity, etc.) -> (for more information -> 'Main.h')
				read_shuttle_param(gTrakAsm.shuttle.num_of_shuttles, gTrakAsm.shuttle.shuttle_offset);
				
				/**
				* Read the user commands from the HMI and switch to the appropriate state.
				*
				* *.reset_evn: Delete each of the shuttles and return to the initial state (Power Off)
				* *.shuttle_start: Start moving from user-selected parameters.
				* *.shuttle_stop: Stop moving. The braking distance is initialized in the configuration file (Configuration File / mappMotion / ...)
				*/
				
				if(gTrakAsm.control.reset_evn == 1){
					gTrakAsm.control.power = 0;
					MC_BR_AsmPowerOff_AcpTrak_0.Execute = 1;
					gTrakAsm.actual_state = ACPt_CTRL_DELETE;
				}else if(gTrakAsm.control.shuttle_start == 1){
					gTrakAsm.control.shuttle_start = 0;
					if(gTrakAsm.shuttle.move_type == 0){
						gTrakAsm.actual_state = ACPt_CTRL_MOVE_VEL_1;
					}else if(gTrakAsm.shuttle.move_type == 1){
						gTrakAsm.actual_state = ACPt_CTRL_MOVE_POS_1;
					}
				}else if(gTrakAsm.control.shuttle_stop == 1){
					gTrakAsm.control.shuttle_stop = 0;
					gTrakAsm.actual_state = ACPt_CTRL_STOPPING;
				}
			}
			break;
		
		case ACPt_CTRL_MOVE_VEL_1: ///< Velocity control of the axes.
			{
				
				if(gTrakAsm.status.shuttle_index >= gTrakAsm.shuttle.num_of_shuttles){
					gTrakAsm.actual_state = ACPt_CTRL_WAIT;
				}else if(gTrakAsm.shuttle_axis[gTrakAsm.status.shuttle_index].controlif != 0){
					MC_BR_RoutedMoveVel_AcpTrak_0.Axis    = &gTrakAsm.shuttle_axis[gTrakAsm.status.shuttle_index];
					MC_BR_RoutedMoveVel_AcpTrak_0.Execute = 1;
					
					if(gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].sector_number == 0){
						MC_BR_RoutedMoveVel_AcpTrak_0.Sector = &SectorTrackA;
					}else if(gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].sector_number == 1){
						MC_BR_RoutedMoveVel_AcpTrak_0.Sector = &SectorTrackB;
					}
                     
					MC_BR_RoutedMoveVel_AcpTrak_0.Velocity      = gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].velocity;
					MC_BR_RoutedMoveVel_AcpTrak_0.RouteVelocity = gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].velocity;
					MC_BR_RoutedMoveVel_AcpTrak_0.Acceleration  = gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].accDec;
					MC_BR_RoutedMoveVel_AcpTrak_0.Deceleration  = gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].accDec;
					MC_BR_RoutedMoveVel_AcpTrak_0.Jerk          = 0.0;
					MC_BR_RoutedMoveVel_AcpTrak_0.BufferMode    = mcABORTING;
					MC_BR_RoutedMoveVel_AcpTrak_0.AdvancedParameters.StartDirection     = mcDIR_UNDEFINED;
					MC_BR_RoutedMoveVel_AcpTrak_0.AdvancedParameters.EndDirection       = gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].direction;
					MC_BR_RoutedMoveVel_AcpTrak_0.AdvancedParameters.ShuttleOrientation = mcDIR_UNDEFINED;

					gTrakAsm.actual_state = ACPt_CTRL_MOVE_VEL_2;
				}
				
				if(MC_BR_RoutedMoveVel_AcpTrak_0.Error == 1){
					MC_BR_AsmReset_AcpTrak_0.Execute = 1;
					gTrakAsm.actual_state = ACPt_CTRL_RESET_ERR;
				}
			}
			break;
		
		case ACPt_CTRL_MOVE_VEL_2: ///< Increase index by one (Velocity Control).
			{
				gTrakAsm.status.shuttle_index++;
				gTrakAsm.actual_state = ACPt_CTRL_MOVE_VEL_1;
			}
			break;
		
		case ACPt_CTRL_MOVE_POS_1: ///< Position control of the axes.
			{
				
				if(gTrakAsm.status.shuttle_index >= gTrakAsm.shuttle.num_of_shuttles){
					gTrakAsm.actual_state = ACPt_CTRL_WAIT;
				}else if(gTrakAsm.shuttle_axis[gTrakAsm.status.shuttle_index].controlif != 0){
					MC_BR_RoutedMoveAbs_AcpTrak_0.Axis          = &gTrakAsm.shuttle_axis[gTrakAsm.status.shuttle_index];
					MC_BR_RoutedMoveAbs_AcpTrak_0.Execute       = 1;
					
					if(gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].sector_number == 0){
						MC_BR_RoutedMoveAbs_AcpTrak_0.Sector = &SectorTrackA;
					}else if(gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].sector_number == 1){
						MC_BR_RoutedMoveAbs_AcpTrak_0.Sector = &SectorTrackB;
					}

					MC_BR_RoutedMoveAbs_AcpTrak_0.Position      = gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].position;
					MC_BR_RoutedMoveAbs_AcpTrak_0.Velocity      = gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].velocity;
					MC_BR_RoutedMoveAbs_AcpTrak_0.Acceleration  = gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].accDec;
					MC_BR_RoutedMoveAbs_AcpTrak_0.Deceleration  = gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].accDec;
					MC_BR_RoutedMoveAbs_AcpTrak_0.Jerk          = 0.0;
					MC_BR_RoutedMoveAbs_AcpTrak_0.BufferMode    = mcABORTING;
					MC_BR_RoutedMoveAbs_AcpTrak_0.AdvancedParameters.StartDirection     = mcDIR_UNDEFINED;
					MC_BR_RoutedMoveAbs_AcpTrak_0.AdvancedParameters.EndDirection       = gTrakAsm.shuttle.parameter[gTrakAsm.status.shuttle_index].direction;
					MC_BR_RoutedMoveAbs_AcpTrak_0.AdvancedParameters.ShuttleOrientation = mcDIR_UNDEFINED;

					gTrakAsm.actual_state = ACPt_CTRL_MOVE_POS_2;
				}
				
				if(MC_BR_RoutedMoveVel_AcpTrak_0.Error == 1){
					MC_BR_AsmReset_AcpTrak_0.Execute = 1;
					gTrakAsm.actual_state = ACPt_CTRL_RESET_ERR;
				}
			}
			break;
		
		case ACPt_CTRL_MOVE_POS_2: ///< Increase index by one (Position Control).
			{
				gTrakAsm.status.shuttle_index++;
				gTrakAsm.actual_state = ACPt_CTRL_MOVE_POS_1;
			}
			break;
		
		case ACPt_CTRL_STOPPING: ///< Stop each of the axes.
			{
				if(MC_Stop_0.Done == 1){
					gTrakAsm.status.shuttle_index++;
					MC_Stop_0.Execute = 0;
				}else if(gTrakAsm.shuttle_axis[gTrakAsm.status.shuttle_index].controlif != 0 && MC_Stop_0.Busy != 1){
					MC_Stop_0.Axis         = &gTrakAsm.shuttle_axis[gTrakAsm.status.shuttle_index];
					MC_Stop_0.Execute      = 1;
					MC_Stop_0.Deceleration = 20;
					MC_Stop_0.Jerk         = 0.0;
					MC_BR_RoutedMoveVel_AcpTrak_0.Execute = 0;		
				}
				
				if(MC_Stop_0.Done == 1 && gTrakAsm.status.shuttle_index > gTrakAsm.shuttle.num_of_shuttles - 1){
					gTrakAsm.control.shuttle_stop = 0;
					gTrakAsm.actual_state = ACPt_CTRL_WAIT;
				}
			}
			break;
		
		case ACPt_CTRL_RESET_ERR: ///< The state machine is in an error state, wait for the automatic reset.
			{
				if(MC_BR_AsmReset_AcpTrak_0.Done == 1){
					gTrakAsm.control.shuttle_start = 0;
					gTrakAsm.control.shuttle_stop  = 0;
					MC_BR_AsmReset_AcpTrak_0.Execute      = 0;
					MC_BR_RoutedMoveVel_AcpTrak_0.Execute = 0;
                
					gTrakAsm.actual_state = ACPt_CTRL_WAIT;	
				}
			}
			break;
		
		case ACPt_CTRL_DELETE: ///< Deleting each of the axes (shuttles) from the environment and returning to the initialization state.
			{
				MC_BR_AsmDeleteShuttle_AcpTrak_0.Command = mcACPTRAK_SH_DELETE_ALL;
				MC_BR_AsmDeleteShuttle_AcpTrak_0.Execute = 1;
				
				if(MC_BR_AsmDeleteShuttle_AcpTrak_0.Done == 1){
					gTrakAsm.actual_state = ACPt_CTRL_POWER_OFF;
				}
			}
			break;
		
	}
	
	/// set default parameters (change animation mode to default, null other parameters, etc.)
	if(gTrakAsm.control.default_shuttle_parameters == 1){
		gTrakAsm.control.animation_mode = ACPt_ANIM_MODE_1;
	}
	
	/// read output from the function block (the machine is active or not)
	gTrakAsm.status.active = MC_BR_AsmReadStatus_AcpTrak_0.AssemblyReady;
	
	/// read from mappview (HMI) -> set number of shuttles
	gTrakAsm.shuttle.num_of_shuttles = gTrakAsm.shuttle.num_of_shuttles_mv + 1;
	
	/**
	 * Digital-Twin camera control.
	 */
	
	if(dt_service.camera[0] == 1){
		/// Right Position
		dt_service.index = 0;
	}else if(dt_service.camera[1] == 1){
		/// Left Position
		dt_service.index = 1;
	}else if(dt_service.camera[2] == 1){
		/// Top Position
		dt_service.index = 2;
	}else if(dt_service.camera[3] == 1){
		/// Machine Vision 1 (Sector A)
		dt_service.index = 3;
	}else if(dt_service.camera[4] == 1){
		/// Machine Vision 2 (Sector B)
		dt_service.index = 4;
	}
	
	/**
	 * Call functions (FB) for control and data collection of each of the axes.
	 */
	
	/// This function block switches on the controllers for all segments of an assembly and identifies all shuttles.
	MC_BR_AsmPowerOn_AcpTrak(&MC_BR_AsmPowerOn_AcpTrak_0);
	MC_BR_AsmPowerOn_AcpTrak_0.Execute = 0;
	
	/// This function block switches off the controllers for all segments of an assembly.
	MC_BR_AsmPowerOff_AcpTrak(&MC_BR_AsmPowerOff_AcpTrak_0);
	
	/// This function block is used to create and add a shuttle to a defined position within a sector. 
	/// This function is used if identification is not possible.
	MC_BR_SecAddShuttle_AcpTrak(&MC_BR_SecAddShuttle_AcpTrak_0);
	MC_BR_SecAddShuttle_AcpTrak_0.Execute = 0;
	
	/// This function block provides the axis reference of all shuttles in the assembly.
	MC_BR_AsmGetShuttle_AcpTrak(&MC_BR_AsmGetShuttle_AcpTrak_0);
	
	/// This function block can be used to start an elastic movement in the direction of a specified absolute position on a defined sector. 
	/// This position is passed at the lower of the two velocity values at a maximum. The movement is performed continuously until the end of the target sector.
	MC_BR_RoutedMoveVel_AcpTrak(&MC_BR_RoutedMoveVel_AcpTrak_0);
	MC_BR_RoutedMoveVel_AcpTrak_0.Execute = 0;
	
	/// This function block can be used to start an elastic movement to a specified absolute position on a defined sector.
	MC_BR_RoutedMoveAbs_AcpTrak(&MC_BR_RoutedMoveAbs_AcpTrak_0);
	MC_BR_RoutedMoveAbs_AcpTrak_0.Execute = 0;
	
	/// This function block is used to determine the current state of the assembly.
	MC_BR_AsmReadStatus_AcpTrak(&MC_BR_AsmReadStatus_AcpTrak_0);
	MC_BR_AsmReset_AcpTrak(&MC_BR_AsmReset_AcpTrak_0);
	
	/// This function block deletes a shuttle and removes it from the assembly.
	MC_BR_AsmDeleteShuttle_AcpTrak(&MC_BR_AsmDeleteShuttle_AcpTrak_0);
	MC_BR_AsmDeleteShuttle_AcpTrak_0.Execute = 0;
	
	/// This function block performs a controlled movement stop and switches the axis to the Stopping state.
	MC_Stop(&MC_Stop_0);
}


