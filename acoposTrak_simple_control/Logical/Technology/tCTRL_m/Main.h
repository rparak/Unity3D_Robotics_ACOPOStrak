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
 * File Name: Main.h
 * Github   : https://github.com/rparak
 */

/** < Include B&R Automation libraries (declarations for B&R ANSI C extensions) */
#include <bur/plctypes.h>

/** < Include other libraries (mathematical functions, character string handling, etc.) */
#include <math.h>
#include <string.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

/**
 * Main state machine for control of a ACOPOStrak.
 */
typedef enum acoposT_ctrl_state_enum{
	ACPt_CTRL_POWER_OFF, /**< Turn off the axes and reset each of the parameters. */
	ACPt_CTRL_POWER_ON, /**< Turn on each of the axes. */
	ACPt_CTRL_ADD_SHUTTLE_1, /**< Adding Shuttle for simulation. */
	ACPt_CTRL_ADD_SHUTTLE_2, /**< When the shuttle is added correctly, increase the index by one. */
	ACPt_CTRL_GET_SHUTTLE_1, /**< Get all available assembly information. (Initialization State) */
	ACPt_CTRL_GET_SHUTTLE_2, /**< Get all available assembly information. (Get next shuttle information) */
	ACPt_CTRL_GET_SHUTTLE_3, /**< Get all available assembly information. (When the shuttle is exist, increase the index by one) */
	ACPt_CTRL_WAIT, /**< Wait for command from HMI visualization (user). */
	ACPt_CTRL_MOVE_VEL_1, /**< Velocity control of the axes. */
	ACPt_CTRL_MOVE_VEL_2, /**< Increase index by one (Velocity Control). */
	ACPt_CTRL_MOVE_POS_1, /**< Position control of the axes. */
	ACPt_CTRL_MOVE_POS_2, /**< Increase index by one (Position Control). */
	ACPt_CTRL_STOPPING, /**< Stop each of the axes. */
	ACPt_CTRL_RESET_ERR, /**< The state machine is in an error state, wait for the automatic reset. */
	ACPt_CTRL_DELETE /**< Deleting each of the axes (shuttles) from the environment and returning to the initialization state. */
}acoposT_ctrl_state_enum;

/**
 * Main state machine for animation mode control of a ACOPOStrak.
 */
typedef enum acoposT_animMode_state_enum{
	ACPt_ANIM_MODE_1, /**< Animation Mode 1 - Velocity control (around the specified sector). */
	ACPt_ANIM_MODE_2, /**< Animation Mode 2 - Position control (around the Sector A, stop under the machine vision camera). */
	ACPt_ANIM_MODE_3, /**< Animation Mode 3 - Position control (around the Sector B, stop under the machine vision camera). */
	ACPt_ANIM_MODE_4 /**< Animation Mode 4 - Velocity control (around both sectors). */
}acoposT_animMode_state_enum;

/**
 * Command execution structure for control of a machine ACOPOStrak.
 */
typedef struct TrakAsm_ctrl_command{
	BOOL power; /**< Power on. */
	BOOL reset_evn; /**< Reset environment. */
	BOOL shuttle_start; /**< Start movement. */
	BOOL shuttle_stop; /**< Stop movement. */
	BOOL default_shuttle_parameters; /**< Set default parameters. */
	acoposT_animMode_state_enum animation_mode; /**< Animation Mode - Enum. */
	acoposT_animMode_state_enum animation_mode_before; /**< Animation Mode - Enum. */
}TrakAsm_ctrl_command;

/**
 * Main state machine for animation mode control of a ACOPOStrak.
 */
typedef struct TrakAsm_parameter_shuttle{
	LREAL initial_position; /**< Initial Position of the shuttle. */
	USINT sector_number; /**< Sector Number: 0 - Sector A, 1 - Sector  */
	USINT direction; /**< Movement direction: 0 - Positive, 1 - Negative */
	LREAL position; /**< Target position. */
	REAL velocity; /**< Target velocity. */
	REAL accDec; /**< Target acceleration/deceleration -> same value. */
}TrakAsm_parameter_shuttle;

/**
 * Structure for shuttle parameters.
 */
typedef struct TrakAsm_shuttle{
	USINT num_of_shuttles; /**< Number of shuttles. */
	USINT num_of_shuttles_mv; /**< Number of shuttles (from mappview). */
	REAL shuttle_offset; /**< Initial shuttle offset. */
	LREAL sector_legth; /**< Sector length - in our experiment, both have the same value. */
	USINT move_type; /**< Move type: 0 - Move Velocity, 1 - Move Position */
	USINT initial_sector; /**< Initial sector of the start of the movement. */
	REAL shuttle_velocity; /**< Target velocity of the shuttle. */
	TrakAsm_parameter_shuttle parameter[6];
}TrakAsm_shuttle;

/**
 * Structure for ACOPOStrak status information.
 */
typedef struct TrakAsm_status_command{
	BOOL power_on; /**< The machine is power on. */
	BOOL active;  /**< The machine is active. */
	BOOL is_homed; /**< The shuttles of the machine are homed. */
	BOOL shuttles_exist; /**< There are one or more shuttles. */
	USINT shuttle_index; /**< Controlled shuttle index. */
}TrakAsm_status_command;

/**
 * Structure for shuttle data collection.
 */
typedef struct TrakAsm_data_collection{
	LREAL position; /**< Current position. */
	REAL velocity; /**< Current velocity. */
	USINT sector; /**< Current sector. */
	USINT number_of_rotates; /**< Number of rotates (around the sector). */
}TrakAsm_data_collection;

/**
 * Custom structure for digital-twin service (camera control, machine vision position, etc.)
 */
typedef struct DigitalTwin_service{
	BOOL camera[5]; /**< Camera control (index): 0 - right, 1 - left, 2 - up, 3 - machine vision (Sector A), 4 - machine vision (Sector B) */
	USINT index; /**< Index for Digital-Twin. */
	LREAL machine_vision_position[2]; /**< Initial position under the machine vision camera in the current sector: 0 - Sector A, 1 - Sector B */
}DigitalTwin_service;

/**
 * Custom structure for controlling some MappView functions.
 */
typedef struct mappView_service{
	BOOL enable_param; /**< Enable/disable of widgets. */
}mappView_service;


/**
 * Custom structure for ACOPOStrak control and data collection.
 */
typedef struct TrakAsm_ctrl_main{
	TrakAsm_ctrl_command control;
	TrakAsm_shuttle shuttle;
	TrakAsm_status_command status;
	TrakAsm_data_collection data_collection[6];
	McAxisType shuttle_axis[6];
	acoposT_ctrl_state_enum actual_state;
}TrakAsm_ctrl_main;


/**
* Function blocks for smooth control of the ACOPOStrak machine (for more information, see Help 'F1').
*/
_LOCAL struct MC_BR_AsmPowerOn_AcpTrak MC_BR_AsmPowerOn_AcpTrak_0;
_LOCAL struct MC_BR_AsmPowerOff_AcpTrak MC_BR_AsmPowerOff_AcpTrak_0;
_LOCAL struct MC_BR_SecAddShuttle_AcpTrak MC_BR_SecAddShuttle_AcpTrak_0;
_LOCAL struct MC_BR_AsmGetShuttle_AcpTrak MC_BR_AsmGetShuttle_AcpTrak_0;
_LOCAL struct MC_BR_RoutedMoveVel_AcpTrak MC_BR_RoutedMoveVel_AcpTrak_0;
_LOCAL struct MC_BR_RoutedMoveAbs_AcpTrak MC_BR_RoutedMoveAbs_AcpTrak_0;
_LOCAL struct MC_BR_AsmDeleteShuttle_AcpTrak MC_BR_AsmDeleteShuttle_AcpTrak_0;
_LOCAL struct MC_BR_AsmReadStatus_AcpTrak MC_BR_AsmReadStatus_AcpTrak_0;
_LOCAL struct MC_BR_AsmReset_AcpTrak MC_BR_AsmReset_AcpTrak_0;
_LOCAL struct MC_Stop MC_Stop_0;
_LOCAL struct MC_BR_ShReadInfo_AcpTrak MC_BR_ShReadInfo_AcpTrak_ID[6];
_LOCAL struct MC_BR_ShReadInfo_AcpTrak MC_BR_ShReadInfo_AcpTrak_NULL;

/// Custom structure for digital-twin service (camera control, machine vision position, etc.)
_LOCAL DigitalTwin_service dt_service;
/// Custom structure for ACOPOStrak control and data collection.
_LOCAL TrakAsm_ctrl_main gTrakAsm;
/// Custom structure for controlling some MappView functions (enable/disable of widgets, etc.)
_LOCAL mappView_service mv_service;

/// auxiliary counter (animation mode 2 - 3)
_LOCAL USINT animation_aux_counter;

/// Reset parameters, environment, etc.
void reset_shuttle_param(USINT num_of_shuttles, USINT initial_sector, REAL offset);
void reset_env();
/// Cyclic reading shuttle parameters (position, velocity, etc.)
void read_shuttle_param(USINT num_of_shuttles, REAL offset);
/// Axis motion control functions (parameters, mode, etc.)
void set_animation_mode();
void set_shuttle_move_param(USINT index, USINT sector, LREAL position, REAL velocity);
/// Auxiliary functions for calculating the maximum/minimum position index of the shuttle.
USINT min_number_index(USINT num_of_shuttles, LREAL machine_vision_position, USINT sector);
USINT max_number_index(USINT num_of_shuttles, LREAL machine_vision_position, USINT sector);

void reset_shuttle_param(USINT num_of_shuttles, USINT initial_sector, REAL offset){
	/**
	Description:
		Function to reset each of the parameters.
	
	Args:
		(1) num_of_shuttles [USINT]: Number of the shuttles.
		(2) initial_sector [USINT]: Initial sector of the start of the movement.
		(3) offset [REAL]: Initial shuttle offset. 
	*/
	
	int i;
	
	for(i = 0; i < (int)(sizeof(gTrakAsm.shuttle.parameter)/sizeof(gTrakAsm.shuttle.parameter[0])); i++){
		if(i < num_of_shuttles){
			gTrakAsm.shuttle.parameter[i].initial_position = (i + 1) * offset;
			gTrakAsm.shuttle.parameter[i].sector_number = initial_sector;
			
			if(initial_sector == 0){
				gTrakAsm.shuttle.parameter[i].direction     = 0;
			}else if(initial_sector == 1){
				gTrakAsm.shuttle.parameter[i].direction     = 1;
			}
			gTrakAsm.shuttle.parameter[i].position      = 1.0;
			gTrakAsm.shuttle.parameter[i].velocity      = gTrakAsm.shuttle.shuttle_velocity;
			gTrakAsm.shuttle.parameter[i].accDec  		= gTrakAsm.shuttle.shuttle_velocity*10;
		}else{
			gTrakAsm.shuttle.parameter[i].initial_position = 0.0;
			gTrakAsm.shuttle.parameter[i].sector_number = 0;
			gTrakAsm.shuttle.parameter[i].direction     = 0;
			gTrakAsm.shuttle.parameter[i].position      = 0.0;
			gTrakAsm.shuttle.parameter[i].velocity      = 0.0;
			gTrakAsm.shuttle.parameter[i].accDec  		= 0.0;
		}
	}
	
	gTrakAsm.control.animation_mode = ACPt_ANIM_MODE_1;
}

void reset_env(){
	/**
	Description:
		Function to reset environment (clear the shuttles from the Digital-Twin).
	*/
	
	int i;
	
	for(i = 0; i < (int)(sizeof(gTrakAsm.data_collection)/sizeof(gTrakAsm.data_collection[0])); i++){
		gTrakAsm.data_collection[i].position = 0.0;
		gTrakAsm.data_collection[i].velocity = 0.0;
		gTrakAsm.data_collection[i].number_of_rotates = 0;
		/// Global Variable Reset
		gShuttleMon.Shuttle[i].Position.X 	      = 0.0;
		gShuttleMon.Shuttle[i].Position.Y 		  = 0.0;
		gShuttleMon.Shuttle[i].Orientation.Angle1 = 0.0;
		/// Reset the data collection function block
		MC_BR_ShReadInfo_AcpTrak_ID[i] = MC_BR_ShReadInfo_AcpTrak_NULL;
	}
}

void read_shuttle_param(USINT num_of_shuttles, REAL offset){
	/**
	Description:
		Function for reading shuttle parameters (position, velocity, etc.) and calculating the absolute position, number of rotation, etc., of the current sector.
		
	Args:
		(1) num_of_shuttles [USINT]: Number of the shuttles.
		(2) offset [REAL]: Initial shuttle offset.
	*/
	
	int i;

	for(i = 0; i < (int)(sizeof(gTrakAsm.shuttle.parameter)/sizeof(gTrakAsm.shuttle.parameter[0])); i++){
		if(i < num_of_shuttles){
			MC_BR_ShReadInfo_AcpTrak_ID[i].Enable = 1;
			MC_BR_ShReadInfo_AcpTrak_ID[i].Axis   = &gTrakAsm.shuttle_axis[i];
			/// Call Function Block
			MC_BR_ShReadInfo_AcpTrak(&MC_BR_ShReadInfo_AcpTrak_ID[i]);
			
			if(fabs(MC_BR_ShReadInfo_AcpTrak_ID[i].ShuttleInfo.CurrentValues.Position) <= gTrakAsm.shuttle.sector_legth){
				gTrakAsm.data_collection[i].number_of_rotates = 0;
				gTrakAsm.data_collection[i].position          = fabs(MC_BR_ShReadInfo_AcpTrak_ID[i].ShuttleInfo.CurrentValues.Position);
			}else{
				gTrakAsm.data_collection[i].number_of_rotates = (USINT)floor(((MC_BR_ShReadInfo_AcpTrak_ID[i].ShuttleInfo.LifeCycleInfo.AbsoluteMovementDistance + ((i + 1) * offset)) / gTrakAsm.shuttle.sector_legth));
				gTrakAsm.data_collection[i].position 	      = ((MC_BR_ShReadInfo_AcpTrak_ID[i].ShuttleInfo.LifeCycleInfo.AbsoluteMovementDistance + ((i + 1) * offset)) - (gTrakAsm.shuttle.sector_legth * (gTrakAsm.data_collection[i].number_of_rotates)));
			}

			gTrakAsm.data_collection[i].velocity = MC_BR_ShReadInfo_AcpTrak_ID[i].ShuttleInfo.CurrentValues.Velocity;
				
			if(strcmp(MC_BR_ShReadInfo_AcpTrak_ID[i].ShuttleInfo.CurrentValues.SectorName, "SectorTrackA") == 0){
				gTrakAsm.data_collection[i].sector = 0;
			}else if(strcmp(MC_BR_ShReadInfo_AcpTrak_ID[i].ShuttleInfo.CurrentValues.SectorName, "SectorTrackB") == 0){
				gTrakAsm.data_collection[i].sector = 1;
			}else{
				gTrakAsm.data_collection[i].sector = 10;
			}
		}
	}
}


void set_shuttle_move_param(USINT index, USINT sector, LREAL position, REAL velocity){
	/**
	Description:
		Function for setting the parameters of the shuttle's movement.
		
	Args:
		(1) index [USINT]: Index of the current shuttle.
		(1) sector [USINT]: Movement in the sector (0 - Sector A, 1 - Sector B).
		(1) position [LREAL]: Target position of the shuttle.
		(1) velocity [REAL]: Target velocity of the shuttle.
	*/
	
	gTrakAsm.shuttle.parameter[index].sector_number = sector;
			
	if(sector == 0){
		gTrakAsm.shuttle.parameter[index].direction     = 0;
	}else if(sector == 1){
		gTrakAsm.shuttle.parameter[index].direction     = 1;
	}
	
	gTrakAsm.shuttle.parameter[index].position      = position;
	gTrakAsm.shuttle.parameter[index].velocity      = velocity;
	gTrakAsm.shuttle.parameter[index].accDec  		= velocity*10;
}

USINT min_number_index(USINT num_of_shuttles, LREAL machine_vision_position, USINT sector){
	/**
	Description:
		Auxiliary function for calculating the minimum position index of the shuttle.
		
	Args:
		(1) num_of_shuttles [USINT]: Number of the shuttles.
		(2) machine_vision_position [LREAL]: Position of the machine vision camer in the digital-twin.
		(3) sector [USINT]: Sector number for calculation (0 - Sector A, 1 - Sector B).
		
	Returns:
		(1) parameter{1} [USINT]: Resulting index (0 .. num_of_shuttles - 1, 100 -> error).
	*/
	
	LREAL min_num = 10.0;
	USINT index = 100;
	
	int i = 0;
	
	for(i = 0; i < (int)(sizeof(gTrakAsm.data_collection)/sizeof(gTrakAsm.data_collection[0])); i++){
		if(i < num_of_shuttles){
			if(gTrakAsm.data_collection[i].position <= min_num && gTrakAsm.data_collection[i].position != machine_vision_position && gTrakAsm.data_collection[i].sector == sector){
				min_num = gTrakAsm.data_collection[i].position;
				index   = i;
			}
		}
	}
	
	return index;
}

USINT max_number_index(USINT num_of_shuttles, LREAL machine_vision_position, USINT sector){
	/**
	Description:
		Auxiliary function for calculating the maximum position index of the shuttle.
		
	Args:
		(1) num_of_shuttles [USINT]: Number of the shuttles.
		(2) machine_vision_position [LREAL]: Position of the machine vision camer in the digital-twin.
		(3) sector [USINT]: Sector number for calculation (1 - Sector A, 2 - Sector B).
		
	Returns:
		(1) parameter{1} [USINT]: Resulting index (0 .. num_of_shuttles - 1, 100 -> error).
	*/
	
	LREAL max_num = -1.0;
	USINT index   = 100;
	
	int i = 0;
	
	for(i = 0; i < (int)(sizeof(gTrakAsm.data_collection)/sizeof(gTrakAsm.data_collection[0])); i++){
		if(i < num_of_shuttles){
			if(gTrakAsm.data_collection[i].position >= max_num && gTrakAsm.data_collection[i].position != machine_vision_position && gTrakAsm.data_collection[i].sector == sector){
				max_num = gTrakAsm.data_collection[i].position;
				index   = i;
			}
		}
	}
	
	return index;
}


void set_animation_mode(){
	
	/**
	 * Main state machine for animation mode control of a ACOPOStrak.
	 *
	 * Number of states: 4
	 * Structure: acoposT_animMode_state_enum
	 *
	 * Note:
	 * Sector B has the initial opposite direction as in sector A, so the first shuttle is the minimum index. 
	 * In sector A, this is the maximum index.
	 */
	
	switch(gTrakAsm.control.animation_mode){
		case ACPt_ANIM_MODE_1: /**< Animation Mode 1 - Velocity control (around the specified sector). */
			{
				gTrakAsm.control.animation_mode_before = ACPt_ANIM_MODE_1;
				/// Type (0) -> Move Velocity
				gTrakAsm.shuttle.move_type             = 0;
				
				if(gTrakAsm.control.shuttle_start == 1){
					reset_shuttle_param(gTrakAsm.shuttle.num_of_shuttles, gTrakAsm.shuttle.initial_sector, gTrakAsm.shuttle.shuttle_offset);
				}
			}
			break;
		
		case ACPt_ANIM_MODE_2: /**< Animation Mode 2 - Position control (around the Sector A, stop under the machine vision camera). */
			{
				if(gTrakAsm.control.animation_mode != gTrakAsm.control.animation_mode_before){
					animation_aux_counter = 0;
					gTrakAsm.control.animation_mode_before = ACPt_ANIM_MODE_2;
				}
				
				/// Type (1) -> Move Position
				gTrakAsm.shuttle.move_type = 1;
				
				if(gTrakAsm.control.shuttle_start == 1){
					/// find the first shuttle from the train (the first scan in sector A because the final position of the shuttles is in sector A)
					animation_aux_counter = max_number_index(gTrakAsm.shuttle.num_of_shuttles, dt_service.machine_vision_position[0], 0);
					
					if(animation_aux_counter == 100){
						/// the second scan is in sector B
						animation_aux_counter = min_number_index(gTrakAsm.shuttle.num_of_shuttles, dt_service.machine_vision_position[1], 1);
					}
					
					int i;
					
					for(i = 0; i < (int)(sizeof(gTrakAsm.shuttle.parameter)/sizeof(gTrakAsm.shuttle.parameter[0])); i++){
						if(i < gTrakAsm.shuttle.num_of_shuttles){
							if(i == animation_aux_counter){
								/// stop under the machine vision camera (the variable *.machine_vision_position[0] is initialized in 'Main.c')
								set_shuttle_move_param(i, 0, dt_service.machine_vision_position[0], gTrakAsm.shuttle.shuttle_velocity);
							}else{
								/// stop one meter in front of the machine vision camera (the last shuttle position is *.machine_vision_position[0] - 1, other positions are calculated automatically from FB without collision)
								set_shuttle_move_param(i, 0, dt_service.machine_vision_position[1] - 1.0, gTrakAsm.shuttle.shuttle_velocity);
							}
						}
					}
				}
			}
			break;
		
		case ACPt_ANIM_MODE_3: /**< Animation Mode 3 - Position control (around the Sector B, stop under the machine vision camera). */
			{
				if(gTrakAsm.control.animation_mode != gTrakAsm.control.animation_mode_before){
					animation_aux_counter = 0;
					gTrakAsm.control.animation_mode_before = ACPt_ANIM_MODE_3;
				}

				/// Type (1) -> Move Position
				gTrakAsm.shuttle.move_type = 1;
				
				if(gTrakAsm.control.shuttle_start == 1){
					/// find the first shuttle from the train (the first scan in sector B because the final position of the shuttles is in sector B)
					animation_aux_counter = min_number_index(gTrakAsm.shuttle.num_of_shuttles, dt_service.machine_vision_position[1], 1);
					
					if(animation_aux_counter == 100){
						/// the second scan is in sector A
						animation_aux_counter = max_number_index(gTrakAsm.shuttle.num_of_shuttles, dt_service.machine_vision_position[0], 0);
					}
					
					int i;
					
					for(i = 0; i < (int)(sizeof(gTrakAsm.shuttle.parameter)/sizeof(gTrakAsm.shuttle.parameter[0])); i++){
						if(i < gTrakAsm.shuttle.num_of_shuttles){
							if(i == animation_aux_counter){
								/// stop under the machine vision camera (the variable *.machine_vision_position[1] is initialized in 'Main.c')
								set_shuttle_move_param(i, 1, dt_service.machine_vision_position[1], gTrakAsm.shuttle.shuttle_velocity);
							}else{
								/// stop one meter in front of the machine vision camera (the last shuttle position is *.machine_vision_position[1] - 1, other positions are calculated automatically from FB without collision)
								set_shuttle_move_param(i, 1, dt_service.machine_vision_position[1] + 1.0, gTrakAsm.shuttle.shuttle_velocity);
							}
						}
					}
				}
			}
			break;
		
		case ACPt_ANIM_MODE_4: /**< Animation Mode 4 - Velocity control (around both sectors). */
			{
				gTrakAsm.control.animation_mode_before = ACPt_ANIM_MODE_4;
				/// Type (0) -> Move Velocity
				gTrakAsm.shuttle.move_type = 0;
				
				int i;
				
				if(gTrakAsm.control.shuttle_start == 1){
					for(i = 0; i < (int)(sizeof(gTrakAsm.shuttle.parameter)/sizeof(gTrakAsm.shuttle.parameter[0])); i++){
						/// division of shuttles between individual sectors
						if(i < gTrakAsm.shuttle.num_of_shuttles){
							if(i % 2 == 0){
								set_shuttle_move_param(i, 0, 1.0, gTrakAsm.shuttle.shuttle_velocity);
							}else{
								set_shuttle_move_param(i, 1, 1.0, gTrakAsm.shuttle.shuttle_velocity);
							}
						}
					}
				}
			}
			break;
		
	}
}
