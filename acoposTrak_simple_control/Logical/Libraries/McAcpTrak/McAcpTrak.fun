FUNCTION LLMInit : UINT
	VAR_INPUT
		sysInitPhase : DINT;
	END_VAR
END_FUNCTION

FUNCTION_BLOCK MC_BR_AsmPowerOn_AcpTrak (*Switches on/off the controllers of the Assembly.*)
	VAR_INPUT
		Assembly : REFERENCE TO McAssemblyType; (*The assembly reference establishes the connection between the function block and the assembly.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		CommandAborted : BOOL; (*Command aborted by another command.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_AsmPowerOff_AcpTrak (*Switches on/off the controllers of the Assembly.*)
	VAR_INPUT
		Assembly : REFERENCE TO McAssemblyType; (*The assembly reference establishes the connection between the function block and the assembly.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK


FUNCTION_BLOCK MC_BR_AsmReadStatus_AcpTrak (*Provides the current status (see State diagram) of the assembly.*)
	VAR_INPUT
		Assembly : REFERENCE TO McAssemblyType; (*The assembly reference establishes the connection between the function block and the assembly.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*Function block's output values can be used*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
		AssemblyDisabled : BOOL; (*State of the assembly (see State diagram)*)
		AssemblyReady : BOOL; (*State of the assembly (see State diagram)*)
		AssemblyHoming : BOOL; (*State of the assembly (see State diagram)*)
		AssemblyStopping : BOOL; (*State of the assembly (see State diagram)*)
		AssemblyErrorStop : BOOL; (*State of the assembly (see State diagram)*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_AsmReset_AcpTrak (*Takes the assembly out of assembly ErrorStop and acknowledges all assembly errors.*)
	VAR_INPUT
		Assembly : REFERENCE TO McAssemblyType; (*The assembly reference establishes the connection between the function block and the assembly.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_AsmCommandError_AcpTrak (*A assembly error can be set with this function block*)
	VAR_INPUT
		Assembly : REFERENCE TO McAssemblyType; (*The assembly reference establishes the connection between the function block and the assembly.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Command : McErrorCmdEnum; (*Error command*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_AsmGetShuttle_AcpTrak (*Loop through a snapshot of shuttles on a assembly.*)
	VAR_INPUT
		Assembly : REFERENCE TO McAssemblyType; (*The assembly reference establishes the connection between the function block and the assembly.*)
		Enable : BOOL;  (* The FB is active as long as this input is set.*)
		Next : BOOL; (* Show data of next shuttle.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (* Function block's output values can be used.*)
		Busy : BOOL; (* Function block is active and must continue to be called.*)
		Error : BOOL; (* Execution error*)
		ErrorID : DINT; (* Error number*)
		TotalCount : UINT; (* Total amount of shuttles in the assembly.*)
		RemainingCount : UINT; (* Remaining shuttles to loop through.*)
		Axis : McAxisType;
		AdditionalInfo :  McAcpTrakAsmGetShAddInfoType; (*Additional information.*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_AsmDeleteShuttle_AcpTrak (*Delete a shuttle of the assembly.*)
	VAR_INPUT
		Assembly : REFERENCE TO McAssemblyType; (*The assembly reference establishes the connection between the function block and the assembly.*)
		Execute : BOOL;  (* Execution of the function block begins on a rising edge of this input.*)
		Command : McAcpTrakAsmDeleteShCmdEnum; (* Define if one specific shuttle or all shuttles are deleted *)
		Axis : REFERENCE TO McAxisType; (* Shuttle which should be deleted.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (* Function block is active and must continue to be called.*)
		Error : BOOL; (* Execution error*)
		ErrorID : DINT; (* Error number*)
		DeletedCount : UINT; (* Number of shuttles which were deleted *)
	END_VAR
	VAR
		Internal : McInternalTwoRefType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK  MC_BR_AsmReadInfo_AcpTrak (*Read information of the assembly.*)
	VAR_INPUT
		Assembly : REFERENCE TO McAssemblyType; (*The assembly reference establishes the connection between the function block and the assembly.*)
		Enable : BOOL;  (* The FB is active as long as this input is set.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*Function block's output values can be used*)
		Busy : BOOL; (* Function block is active and must continue to be called.*)
		Error : BOOL; (* Execution error*)
		ErrorID : DINT; (* Error number*)
		AssemblyInfo :  McAcpTrakAsmInfoType;  (* Information of the assembly*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK  MC_BR_AsmGetInfo_AcpTrak (*Get information of the assembly.*)
	VAR_INPUT
		Assembly : REFERENCE TO McAssemblyType; (*The assembly reference establishes the connection between the function block and the assembly.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (* Function block is active and must continue to be called.*)
		Error : BOOL; (* Execution error*)
		ErrorID : DINT; (* Error number*)
		AssemblyInfo : McAcpTrakAsmGetInfoType;  (*Information of the assembly*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK  MC_BR_AsmGetMinShDist_AcpTrak (*Output minimum possible distance between shuttles*)
	VAR_INPUT
		Assembly : REFERENCE TO McAssemblyType; (*The assembly reference establishes the connection between the function block and the assembly.*)
		Execute : BOOL;  (*Execution of the function block begins on a rising edge of this input.*)
		Mode :   McAcpTrakShRelativeAlignmentEnum; (*Calculation mode selector*)
		AdvancedParameters :  McAcpTrakAdvGetMinShDistParType; (*Advanced parameters for distance calculation*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Function block is finished*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*Error number*)
		Distance : McAcpTrakAsmGetMinShDistType; (*Calculated minimum distance between shuttles*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_BarrierCommand_AcpTrak (*Open or close a barrier*)
	VAR_INPUT
		ProcessPoint : REFERENCE TO McProcessPointType; (*The ProcessPoint reference establishes the connection between the function block and the trigger point.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Command : McAcpTrakBarrierCmdEnum; (*Command which should be executed*)
		AdvancedParameters : McAcpTrakAdvBarrierParType; (*Advanced parameters for a barrier*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_BarrierReadInfo_AcpTrak (*Get informations about the barrier*)
	VAR_INPUT
		ProcessPoint : REFERENCE TO McProcessPointType; (*The ProcessPoint reference establishes the connection between the function block and the trigger point.*)
		Enable : BOOL; (*The function block is active as long as this input is set*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*Function block's output values can be used*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
		BarrierInfo : McAcpTrakBarrierInfoType; (*Information of the barrier*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_TrgPointGetInfo_AcpTrak (*Get information about a shuttle passed the trigger*)
	VAR_INPUT
		ProcessPoint : REFERENCE TO McProcessPointType; (*The ProcessPoint reference establishes the connection between the function block and the trigger point.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
		TrgPointInfo : McAcpTrakTrgPointGetInfoType; (*Trigger point information*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_TrgPointEnable_AcpTrak (*Activate a trigger point*)
	VAR_INPUT
		ProcessPoint : REFERENCE TO McProcessPointType; (*The ProcessPoint reference establishes the connection between the function block and the trigger point.*)
		Enable : BOOL; (*The function block is active as long as this input is set*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*Function block's output values can be used*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
		EventCount : UINT; (*Reference to userdata.*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SecAddShuttle_AcpTrak (*Add a shuttle on a sector.*)
	VAR_INPUT
		Sector : REFERENCE TO McSectorType; (*The sector reference establishes the connection between the function block and the sector.*)
		Execute : BOOL;  (*FB is active as long as input is set.*)
		Position : LREAL; (*Shuttle position on the sector.*)
		AdvancedParameters : McAcpTrakAdvSecAddShParType; (* Advanced parameters for adding a shuttle.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
		Axis : McAxisType; (*Added shuttle*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK


FUNCTION_BLOCK MC_BR_SecGetShuttle_AcpTrak (*Loop through a snapshot of shuttles on a sector.*)
	VAR_INPUT
		Sector : REFERENCE TO McSectorType; (*The sector reference establishes the connection between the function block and the sector.*)
		Enable : BOOL;  (* The FB is active as long as this input is set.*)
		Next : BOOL; (* Show data of next shuttle.*)
		Mode : McAcpTrakSearchModeEnum; (* Direction for generating shuttle list.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (* Function block's output values can be used.*)
		Busy : BOOL; (* Function block is active and must continue to be called.*)
		Error : BOOL; (* Execution error*)
		ErrorID : DINT; (* Error number*)
		TotalCount : UINT; (* Total amount of shuttles on the sector.*)
		RemainingCount : UINT; (* Remaining shuttles to loop through.*)
		Axis : McAxisType; (* Shuttle*)
		AdditionalInfo : McAcpTrakSecGetShAddInfoType; (* Additional information about the shuttle. *)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK  MC_BR_SecGetInfo_AcpTrak (*Get information of the assembly.*)
	VAR_INPUT
		Sector : REFERENCE TO McSectorType; (*The sector reference establishes the connection between the function block and the sector.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (* Function block is active and must continue to be called.*)
		Error : BOOL; (* Execution error*)
		ErrorID : DINT; (* Error number*)
		SectorInfo :    McAcpTrakSecGetInfoType;  (*Information of the assembly*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SegPowerOn_AcpTrak (*Switches on the controllers of the segment.*)
	VAR_INPUT
		Segment : REFERENCE TO McSegmentType; (*The segment reference establishes the connection between the function block and the segment.*)
		Execute : BOOL; (*Turns drive power stages on*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Indicates whether the segment is on*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		CommandAborted : BOOL; (*Command aborted by another command.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SegPowerOff_AcpTrak (*Switches off the controllers of the segment.*)
	VAR_INPUT
		Segment : REFERENCE TO McSegmentType; (*The segment reference establishes the connection between the function block and the segment.*)
		Execute : BOOL; (*Turns drive power stages off*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Indicates whether the segment is on*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SegReset_AcpTrak (*Takes the segment out of LlmErrorStop and acknowledges all segment errors.*)
	VAR_INPUT
		Segment : REFERENCE TO McSegmentType; (*The segment reference establishes the connection between the function block and the segment.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SegProcessParID_AcpTrak (*Transfers a parameter list from or to the drive.*)
	VAR_INPUT
		Segment : REFERENCE TO McSegmentType; (*The segment reference establishes the connection between the function block and the segment.*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		DataAddress : UDINT; (*Data address of a structure array of type McAcpTrakSegProcessParIDType*)
		NumberOfParIDs : UDINT; (*Number of ParIDs which should be processed*)
		Mode : McAcpTrakSegProcessParIDModeEnum; (*Mode which defines if ParIDs should be written*)
		ChannelIndex : USINT; (*Channel index, gripper for which the ParIDs are transferred*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_RoutedMoveVel_AcpTrak (*drives shuttle with a maximum velocity to a defined position on a defined sector*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*the shuttle reference establishes the connection between the function block and the shuttle.*)
		Execute: BOOL; (*execution of this FB started on a rising edge of the input*)
		Sector : REFERENCE TO McSectorType; (*target sector where shuttle should reach position*)
		Position: LREAL; (*target position for continuous motion*)
		Velocity : REAL; (*maximum velocity after position reached*)
		RouteVelocity : REAL; (*maximum velocity before position reached*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Jerk : REAL; (*maximum jerk*)
		BufferMode : McBufferModeEnum; (*defines the chronological sequence of FB*)
		AdvancedParameters : McAcpTrakAdvRouteParType; (*structure for using additional functions*)
	END_VAR
	VAR_OUTPUT
		InVelocity : BOOL; (*shuttle is moving with demanded velocity*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Active : BOOL; (*FB has control over shuttle*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*Error number*)
		PositionReached : BOOL; (*Indicates that shuttle reached demanded position on sector*)
	END_VAR
	VAR
		Internal : McInternalTwoRefType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_RoutedMoveAbs_AcpTrak (*drives shuttle to a defined position on a defined sector*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*the shuttle reference establishes the connection between the function block and the shuttle.*)
		Execute: BOOL; (*execution of this FB started on a rising edge of the input*)
		Sector : REFERENCE TO McSectorType; (*target sector where shuttle should reach position*)
		Position: LREAL; (*target position for continuous motion*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Jerk : REAL; (*maximum jerk*)
		BufferMode : McBufferModeEnum; (*defines the chronological sequence of FB*)
		AdvancedParameters : McAcpTrakAdvRouteParType; (*structure for using additional functions*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Active : BOOL; (*FB has control over shuttle*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalTwoRefType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ElasticMoveAbs_AcpTrak (*commands a controlled motion to a specified absolute position.*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*sthe shuttle reference establishes the connection between the function block and the shuttle.*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		Position : LREAL; (*target position for the motion*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Jerk : REAL; (*maximum jerk*)
		BufferMode : McBufferModeEnum; (*defines the chronological sequence of FB*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. FB finished*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Active : BOOL; (*FB has control over the axis*)
		CommandAborted : BOOL; (*Command was aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ElasticMoveAdd_AcpTrak (*commands a motion of a specified relative distance*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*the shuttle reference establishes the connection between the function block and the shuttle.*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		Distance : LREAL; (*relative distance for the motion*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Jerk : REAL; (*maximum jerk*)
		BufferMode : McBufferModeEnum; (*defines the chronological sequence of FB*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. FB finished*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Active : BOOL; (*FB has control over the axis*)
		CommandAborted : BOOL; (*Command was aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ElasticMoveVel_AcpTrak (*commands a motion with specific velocity*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*the shuttle reference establishes the connection between the function block and the shuttle.*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Jerk : REAL; (*maximum jerk*)
		Direction : McDirectionEnum; (*movement direction*)
		BufferMode : McBufferModeEnum; (*defines the chronological sequence of FB*)
	END_VAR
	VAR_OUTPUT
		InVelocity : BOOL; (*Commanded velocity reached*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Active : BOOL; (*FB has control over the axis*)
		CommandAborted : BOOL; (*Command was aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SegReadStatus_AcpTrak (*Provides the current status (see State diagram) of the segment.*)
	VAR_INPUT
		Segment : REFERENCE TO McSegmentType; (*The segment reference establishes the connection between the function block and the segment.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*Function block's output values can be used*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
		SegmentDisabled : BOOL; (*State of the segment (see State diagram)*)
		SegmentReady : BOOL; (*State of the segment (see State diagram)*)
		SegmentStopping : BOOL; (*State of the segment (see State diagram)*)
		SegmentErrorStop : BOOL; (*State of the segment (see State diagram)*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SegReadInfo_AcpTrak (*Provides status information of the segment.*)
	VAR_INPUT
		Segment : REFERENCE TO McSegmentType; (*The segment reference establishes the connection between the function block and the segment.*)
		Enable : BOOL; (*The function block is active as long as this input is set.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*Function block's output values can be used*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*Execution error*)
		ErrorID : DINT; (*Error number*)
		SegmentInfo : McAcpTrakSegInfoType; (*Segment information*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ShReadInfo_AcpTrak (*reads shuttle information*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*the shuttle reference establishes the connection between the function block and the shuttle.*)
		Enable: BOOL; (*The function block is active as long as this input is set.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*function block's output values can be used*)
		Busy : BOOL; (*function block is active and must continue to be called.*)
		Error : BOOL; (*execution error*)
		ErrorID : DINT; (*error number*)
		ShuttleInfo : McAcpTrakShInfoType; (*information structure*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ShReadSegmentInfo_AcpTrak (*reads shuttle information*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*the shuttle reference establishes the connection between the function block and the shuttle.*)
		Enable: BOOL; (*The function block is active as long as this input is set.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*function block's output values can be used*)
		Busy : BOOL; (*function block is active and must continue to be called.*)
		Error : BOOL; (*execution error*)
		ErrorID : DINT; (*error number*)
		SegmentInfo :  McAcpTrakShSegmentInfoType; (*information structure*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ShReadFrame_AcpTrak (*reads shuttle frame*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*the shuttle reference establishes the connection between the function block and the shuttle.*)
		Enable: BOOL; (*The function block is active as long as this input is set.*)
		CoordSystem: UDINT; (*The frame refers to the coordinate system which is given at this input*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*function block's output values can be used*)
		Busy : BOOL; (*function block is active and must continue to be called.*)
		Error : BOOL; (*execution error*)
		ErrorID : DINT; (*error number*)
		Frame : McFrameType; (*shuttle frame*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ShCopyUserData_AcpTrak (*reads or writes the shuttle user data from or to pv*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*the shuttle reference establishes the connection between the function block and the shuttle.*)
		Execute: BOOL; (*execution of this FB started on a rising edge of the input*)
		DataAddress : UDINT; (* Reference to pv to read or write user data*)
		DataSize : UDINT; (* size of pv in byte*)
		Mode : McAcpTrakCopyUserDataModeEnum; (*Mode which defines if user data should be read or written*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. Function block is finished.*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*execution error*)
		ErrorID : DINT; (*error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ShSelCtrlParSet_AcpTrak (*INTERNAL TEST FUNCTION BLOCK FOR SWITCHING OF CONTROLLER PARAMETER SETS*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*the shuttle reference establishes the connection between the function block and the shuttle.*)
		Execute: BOOL; (*execution of this FB started on a rising edge of the input*)
		Mode :  McAcpTrakSelectShSideEnum; (* Command to select the side of the shuttle which will be affected*)
		ParameterSetIndex: USINT; (*Index of used shuttle parameter set. Value range 0 .. 7*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Function block is finished*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ShResize_AcpTrak (*Resizes/change shuttle depending parameter*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*The shuttle reference establishes the connection between the function block and the shuttle.*)
		Execute: BOOL; (*Execution of this FB started on a rising edge of the input*)
		Command :   McAcpTrakShResizeCmdEnum; (* Command to select which elements of the struct are applied*)
		ResizeParameter:  McAcpTrakShResizeParamType; (*Structure containing possible parameter*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Function block is finished*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ElasticMoveCycPos_AcpTrak (*commands the shuttle to follow a cyclically transferred position elastic*)
	VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Enable : BOOL; (*FB is active as long as input is set*)
        InterpolationMode : McIplModeEnum; (*interpolation mode of cyclic position on receiving drive*)
        AdvancedParameters : McAdvMoveCycParType; (*structure for using additional functions*)
		CyclicPosition : LREAL; (*cyclic position that is transferred to the axis*)
    END_VAR
    VAR_OUTPUT
        Valid : BOOL; (*initialization complete, position is beeing transferred cyclically*)
        Busy : BOOL; (*FB is active and needs to be called*)
        CommandAborted : BOOL; (*Command was aborted by another command*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
        InCyclicPosition : BOOL; (*shuttle reaches cyclic position*)
    END_VAR
    VAR
        Internal : McInternalType;(*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ShCouplingObjCmd_AcpTrak (*set a coupling object for a shuttle*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*the shuttle reference establishes the connection between the function block and the shuttle.*)
		Execute: BOOL; (*execution of this FB started on a rising edge of the input*)
		Command: McAcpTrakCouplingObjCmdEnum; (*command that should be executed*)
		CouplingObjectName: STRING[32]; (*Name of the used coupling object*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Function block is finished*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ShLocalLimitCmd_AcpTrak (*add/remove a shuttle to a local limit*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*the shuttle reference establishes the connection between the function block and the shuttle.*)
		Execute: BOOL; (*execution of this FB started on a rising edge of the input*)
		Command:  McAcpTrakShLocalLimitCmdEnum; (*command that should be executed*)
		LocalLimitName: STRING[32]; (*Name of the used local limit object*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Function block is finished*)
		Busy : BOOL; (*Function block is active and must continue to be called.*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK
