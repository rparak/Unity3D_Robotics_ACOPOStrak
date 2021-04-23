TYPE
	McInternalAssemblyIfType : STRUCT (*Partial interface type (C only)*)
		vtable : DWORD;
	END_STRUCT;

	McAssemblyType : STRUCT
		controlif : REFERENCE TO McInternalAssemblyIfType;
	END_STRUCT;

	McInternalSegmentIfType : STRUCT (*Partial interface type (C only)*)
		vtable : DWORD;
	END_STRUCT;

	McSegmentType : STRUCT
		controlif : REFERENCE TO McInternalSegmentIfType;
	END_STRUCT;

	McInternalSectorIfType : STRUCT (*Partial interface type (C only)*)
		vtable : DWORD;
	END_STRUCT;

	McSectorType : STRUCT
		controlif : REFERENCE TO McInternalSectorIfType;
	END_STRUCT;

	McInternalProcessPointIfType : STRUCT (*Partial interface type (C only)*)
		vtable : DWORD;
	END_STRUCT;

	McProcessPointType : STRUCT
		controlif : REFERENCE TO McInternalProcessPointIfType;
	END_STRUCT;

	McAcpTrakSegProcessParIDModeEnum :
	(
		mcACPTRAK_SEG_PARID_GET := 0, (*read ParID once from the segment*)
		mcACPTRAK_SEG_PARID_SET,	(*write ParID once to the segment*)
		mcACPTRAK_SEG_PARID_GET_NO_NCT (*read ParID once from the segment without entry into NCT*)
	);

	McAcpTrakSegDataTypeEnum :
	(
		mcACPTRAK_SEG_PARTYPE_BOOL := 1, (*data type BOOL*)
		mcACPTRAK_SEG_PARTYPE_SINT, (*data type SINT*)
		mcACPTRAK_SEG_PARTYPE_INT, (*data type INT*)
		mcACPTRAK_SEG_PARTYPE_DINT, (*data type DINT*)
		mcACPTRAK_SEG_PARTYPE_USINT, (*data type USINT*)
		mcACPTRAK_SEG_PARTYPE_UINT, (*data type UINT*)
		mcACPTRAK_SEG_PARTYPE_UDINT, (*data type UDINT*)
		mcACPTRAK_SEG_PARTYPE_REAL, (*data type REAL*)
		mcACPTRAK_SEG_PARTYPE_VOID := 65535  (*data type unknown*)
	);

	McAcpTrakSegProcessParIDType : STRUCT
		ParID : UINT; (*ParID which is read/written*)
		VariableAddress : UDINT; (*address the value of the ParID is written to/read from*)
		DataType : McAcpTrakSegDataTypeEnum; (*data type of the ParID value*)
	END_STRUCT;

	McAcpTrakTrgPointEventEnum :
	(
		mcACPTRAK_TP_PASSED_NEGATIVE, 	(*passed in negative direction*)
		mcACPTRAK_TP_PASSED_POSITIVE 	(*passed in positive direction*)
	);

	McAcpTrakSearchModeEnum :
	(
		mcACPTRAK_SEARCH_FORWARD, (*search forward*)
		mcACPTRAK_SEARCH_BACKWARD (*search backward*)
	);

	McAcpTrakCopyUserDataModeEnum :
	(
		mcACPTRAK_USERDATA_GET, (*get user data*)
		mcACPTRAK_USERDATA_SET 	(*set user data*)
	);

	McAcpTrakShManeuverTypeEnum :
	(
		mcACPTRAK_MANEUVER_NONE := 0, 		(*normal behaviour*)
		mcACPTRAK_MANEUVER_ADJUSTMENT := 1,	(*adjustment maneuver*)
		mcACPTRAK_MANEUVER_STANDSTILL := 2,	(*standstill maneuver*)
		mcACPTRAK_MANEUVER_EMERGENCY := 3 	(*emergency stop maneuver*)
	);

	McAcpTrakShManeuverReasonEnum:
	(
		mcACPTRAK_REASON_UNSPECIFIED := 0,		(*unspecified reason*)
		mcACPTRAK_REASON_SHUTTLE := 1,			(*maneuver due to another shuttle*)
		mcACPTRAK_REASON_LOCAL_VEL_LIMIT := 2,	(*maneuver due to an active local velocity limit*)
		mcACPTRAK_REASON_BARRIER := 3,			(*maneuver due to a closed barrier*)
		mcACPTRAK_REASON_SECTOREND := 4,		(*maneuver due to a closed sector end*)
		mcACPTRAK_REASON_SECTORSWITCH := 5,		(*maneuver due to an invalid sector switch*)
		mcACPTRAK_REASON_LOGISTICS := 6,		(*maneuver due to motion parameters of logistics*)
		mcACPTRAK_REASON_NONE := 7,				(*normal behaviour*)
		mcACPTRAK_REASON_LOCAL_ACC_LIMIT := 8,	(*maneuver due to an acceleration limit*)
		mcACPTRAK_REASON_UNCONTROLLED := 9,		(*maneuver due to transition from controlled to uncontrolled*)
		mcACPTRAK_REASON_RECONTROLLED := 10		(*maneuver due to transition from uncontrolled to controlled*)
	);

	McAcpTrakSelectShSideEnum:
	(
		 mcACPTRAK_SIDE_BOTH := 0			(* Both sides of the shuttle are affected*)
	);

	McAcpTrakSecTypeEnum :
	(
		mcACPTRAK_SEC_USER_DEFINED,		(*user defined sector*)
		mcACPTRAK_SEC_SEGMENT,			(*segment sector*)
		mcACPTRAK_SEC_INTERNAL			(*route*)
	);

	 McAcpTrakRoutePosRelToEnum :
	(
		mcACPTRAK_SEC_START,				(*Target position is calculated in relation to the start of the sector*)
	 	mcACPTRAK_SEC_END					(*Target position is calculated in relation to the end of the sector*)
	);

	McAcpTrakShMovementTypeEnum :
	(
		mcACPTRAK_MOVEMENT_STANDSTILL,	(*no movement active*)
		mcACPTRAK_MOVEMENT_ELASTIC,		(*elastic movement*)
		mcACPTRAK_MOVEMENT_RIGID		(*rigid movement*)
	);

	McAcpTrakBarrierCmdEnum :
	(
		mcACPTRAK_BARRIER_OPEN,			(*open the barrier*)
		mcACPTRAK_BARRIER_CLOSE,		(*close the barrier*)
		mcACPTRAK_BARRIER_ADD_TICKETS	(*adds tickets to or subtracts tickets from the barrier*)
	);

	McAcpTrakBarrierStatusEnum :
	(
		mcACPTRAK_BARRIER_OPENED,		(*barrier is open*)
		mcACPTRAK_BARRIER_CLOSED,		(*barrier is closed*)
		mcACPTRAK_BARRIER_TICKETING		(*barrier assigns tickets to shuttles*)
	);

	McAcpTrakCouplingObjCmdEnum :
	(
		mcACPTRAK_COUPLE_OBJ_SET,		(*sets a coupling object for the shuttle*)
		mcACPTRAK_COUPLE_OBJ_REMOVE		(*removes a coupling object from the shuttle*)
	);

	 McAcpTrakSimulationOnPlcEnum :
	 (
	  	mcACPTRAK_SIM_STATE_OFF,		(*simulation disabled*)
	  	mcACPTRAK_SIM_STATE_ON			(*simulation enabled*)
	 );

	 McAcpTrakFieldModeEnum :
	 (
	 	mcACPTRAK_FIELD_NORMAL,			(*magnetic field behaving normally*)
	 	mcACPTRAK_FIELD_WEAKENING,		(*magnetic field weakening*)
	 	mcACPTRAK_FIELD_STRENGTHENING	(*magnetic field strengthening *)
	 );

	 McAcpTrakShResizeCmdEnum :
	 (
	 	mcACPTRAK_RESIZE_DIMENSIONS		(*change dimension parameters immediately*)
	 );

	 McAcpTrakAsmDeleteShCmdEnum :
	 (
	 	mcACPTRAK_SH_DELETE_SPECIFIC,	(* Delete only one specific shuttle which is given at the input "Shuttle" *)
	 	mcACPTRAK_SH_DELETE_ALL			(* Delete all shuttles of the given assembly *)
	 );

	McAcpTrakPLCopenStateEnum :
	(
		mcACPTRAK_DISABLED,
		mcACPTRAK_HOMING,
		mcACPTRAK_READY,
		mcACPTRAK_STOPPING,
		mcACPTRAK_ERRORSTOP,
		mcACPTRAK_STARTUP,
		mcACPTRAK_INVALID_CONFIGURATION
	);

	 McAcpTrakShRelativeAlignmentEnum :
	(
		mcACPTRAK_ALIGNED_FRONT_TO_BACK,
		mcACPTRAK_ALIGNED_BACK_TO_FRONT,
		mcACPTRAK_ALIGNED_FRONT_TO_FRONT,
		mcACPTRAK_ALIGNED_BACK_TO_BACK
	);

	 McAcpTrakShRelativeRefPointEnum :
	 (
	 	mcACPTRAK_DIST_CENTER_TO_CENTER,
		mcACPTRAK_DIST_CENTER_TO_EXTENT,
		mcACPTRAK_DIST_EXTENT_TO_CENTER,
		mcACPTRAK_DIST_EXTENT_TO_EXTENT
	 );

	 McAcpTrakShLocalLimitCmdEnum :
	(
		mcACPTRAK_LL_ADD_SHUTTLE,
		mcACPTRAK_LL_REMOVE_SHUTTLE
	);

	McAcpTrakRouteTransitPointsType : STRUCT
		Sector : REFERENCE TO McSectorType; (*midpoint sector reference*)
		Position : LREAL; (*midpoint position on the sector*)
		TransitDirection : McDirectionEnum; (*direction in which the shuttle passes the transit point*)
	END_STRUCT;

	McAcpTrakAdvRouteParType : STRUCT
		StartDirection : McDirectionEnum; (*defines in which direction the shuttle is starting*)
		EndDirection : McDirectionEnum; (*defines in which direction the shuttle is starting*)
		ShuttleOrientation : McDirectionEnum; (*defines the orientation of the shuttle on end position*)
		TransitPoints : REFERENCE TO McAcpTrakRouteTransitPointsType; (*defines the midpoints for the shuttle to go through before reaching the end point *)
		NumberOfTransitPoints : UINT; (*number of used transit points*)
		PosRelativeTo :  McAcpTrakRoutePosRelToEnum; (*End position calculated relative to begin or end of a sector*)
	END_STRUCT;

	McAcpTrakShManeuverInfoType : STRUCT
		Type : McAcpTrakShManeuverTypeEnum := mcACPTRAK_MANEUVER_NONE; (*maneuver type*)
		Reason : McAcpTrakShManeuverReasonEnum := mcACPTRAK_REASON_NONE; (*maneuver reason*)
	END_STRUCT;

	McAcpTrakShCurrentValuesType : STRUCT
		Position : LREAL; 						(*position on Sector*)
		Sector : McSectorType; 					(*sector reference*)
		SectorName : STRING[32]; 				(*name of the reference sector*)
		SectorType : McAcpTrakSecTypeEnum; 		(*kind of sector*)
		SectorLength : LREAL; 					(*length of the reference sector*)
		Orientation : McDirectionEnum; 			(*defines the orientation of the shuttle on reference sector*)
		Velocity : REAL; 						(*current velocity*)
		MovementType : McAcpTrakShMovementTypeEnum; (*type of movement*)
		CtrlParSetLeft : USINT;					(*active controller parameter set of the left side of the shuttle*)
		CtrlParSetRight : USINT;				(*active controller parameter set of the right side of the shuttle*)
	END_STRUCT;

	McAcpTrakShRouteDestInfoType	: STRUCT
		Position : LREAL;						(*position on Sector*)
		Sector : McSectorType; 					(*sector reference*)
		SectorName : STRING[32]; 				(*name of the reference sector*)
		SectorType : McAcpTrakSecTypeEnum; 		(*kind of sector*)
		VelocityAtDestination : REAL; 			(*velocity at destination*)
		TotalDistance : LREAL; 					(*total distance*)
		RemainingDistance : LREAL; 				(*remaining distance to target*)
	END_STRUCT;

	McAcpTrakShLifeCycleInfoType : STRUCT
		AbsoluteMovementDistance : LREAL; (*distance traveled since the last shuttle identification was performed [measurement units]*)
	END_STRUCT;

	McAcpTrakShSegSetValuesType : STRUCT
		Valid : BOOL; (*values of "SegmentName", "Position", "Channel", "FieldMode" and "SegmentID" are valid*)
		SegmentName : STRING[32]; (*name of the segment*)
		Position : LREAL; (*position of the shuttle on the segment*)
		Channel : USINT; (*channel used to transmit the data*)
		FieldMode : McAcpTrakFieldModeEnum; (*active field mode*)
		SegmentID : UINT; (*ID of the segment*)
	END_STRUCT;

	McAcpTrakShSegCurrentValuesType : STRUCT
		Valid : BOOL; (*values of "SegmentName" and "Position" are valid*)
		SegmentName : STRING[32]; (*name of the segment*)
		Position : LREAL; (*position of the shuttle on the segment*)
	END_STRUCT;

	McAcpTrakShInfoType	: STRUCT
		CurrentValues : McAcpTrakShCurrentValuesType; (*info about current values*)
		RouteDestinationInfo : McAcpTrakShRouteDestInfoType; (*info about destination values*)
		ManeuverInfo : McAcpTrakShManeuverInfoType; (*info about current maneuver*)
		LifeCycleInfo : McAcpTrakShLifeCycleInfoType; (*life cycle info*)
	END_STRUCT;

	 McAcpTrakShSegmentInfoType	: STRUCT
		SegmentSetValues : ARRAY[0..3] OF McAcpTrakShSegSetValuesType; (*setpoints that are transferred to the segments*)
		SegmentCurrentValues : ARRAY[0..3] OF McAcpTrakShSegCurrentValuesType; (*actual values that are read from the segments*)
	END_STRUCT;

	McAcpTrakShResizeParamType : STRUCT
		ExtentToFront : LREAL; (*extent from the center point of the magnet plate to the front of the shuttle*)
		ExtentToBack : LREAL; (*extent from the center point of the magnet plate to the back of the shuttle*)
		Width : LREAL; (*symmetric width relative to the shuttle center point*)
	END_STRUCT;

	McAcpTrakShuttleMonData : STRUCT (*Shuttles*)
		Available : BOOL;
		Position : McPosType;
		Orientation : McOrientType;
		ExtentToFront : LREAL;
		ExtentToBack : LREAL;
		Width : LREAL;
		UserData : UDINT;
		Index : UINT;
	END_STRUCT;

	McAcpTrakAssemblyMonData : STRUCT
		Shuttle : ARRAY[0..149] OF McAcpTrakShuttleMonData;
	END_STRUCT;

	McAcpTrakShuttleVisData : STRUCT
		Available : BOOL; (* the shuttle is displayed in the scene *)
		Reserved : ARRAY[0..2] OF USINT;
		PositionX : REAL; (* X position of the shuttle *)
		PositionY : REAL; (* Y position of the shuttle *)
		RotationZ : REAL; (* rotation of the shuttle around Z axis *)
		Text : STRING[31]; (* text to be displayed for the shuttle *)
		ColorRed : REAL; (* red component of the shuttle color *)
		ColorGreen : REAL; (* blue component of the shuttle color *)
		ColorBlue : REAL; (* green component of the shuttle color *)
		ExtentToFront : REAL; (* extent from shuttle center point to front *)
		ExtentToBack : REAL; (* extent from shuttle center point to back *)
		Width : REAL; (* symmetric width of the shuttle *)
	END_STRUCT;

	McAcpTrakAssemblyVisData  : STRUCT (* representation of visualization communication buffer *)
		Shuttle : ARRAY[0..149] OF McAcpTrakShuttleVisData; (* shuttles *)
	END_STRUCT;

	McAcpTrakSegInfoType : STRUCT
		CommunicationReady : BOOL; (*Segment has a network connection*)
		ReadyForPowerOn : BOOL; (*Controller can be switched on*)
		PowerOn : BOOL; (*Controller is switched on*)
		StartupCount : UDINT; (*Number of times the segment was started up since the last PLC start*)
		CommunicationState : McCommunicationStateEnum; (*State of network communication*)
	END_STRUCT;

	McAcpTrakTrgPointGetInfoType : STRUCT
		Axis : McAxisType; (*determined axis reference*)
		Event : McAcpTrakTrgPointEventEnum; (*direction the shuttle passed*)
		ShuttleControlled : BOOL; (*shuttle status when passing - controlled/uncontrolled*)
	END_STRUCT;

	McAcpTrakBarrierInfoType : STRUCT
		Status : McAcpTrakBarrierStatusEnum; (*barrier state*)
		RemainingTickets : UDINT; (*number of remaining tickets*)
	END_STRUCT;

	McAcpTrakAdvBarrierParType : STRUCT
		TicketCount : DINT; (*number of tickets to be added to or subtracted from the barrier*)
	END_STRUCT;

	McAcpTrakSegmentPosition : STRUCT
		Index : INT;
		Position : LREAL;
	END_STRUCT;

	 McAcpTrakShuttleEncoderPosition : STRUCT
		Available : BOOL;
		SegPos : ARRAY[0..3] OF  McAcpTrakSegmentPosition;
		ActPosition : LREAL;
		DesPosition : LREAL;
	END_STRUCT;

	 McAcpTrakShuttleEncoderMonitor : STRUCT
		ShuttleEncPos :  ARRAY[0..31] OF  McAcpTrakShuttleEncoderPosition;
	END_STRUCT;

	 McAcpTrakAsmGetInfoType : STRUCT
	 	SimulationOnPlcMode : McAcpTrakSimulationOnPlcEnum; (*information about whether simulation mode is used*)
	 END_STRUCT;

	 McAcpTrakSecGetInfoType : STRUCT
	 	Length : LREAL; (*length of the sector*)
	 	SectorClosed : BOOL; (*set to TRUE if the sector is closed*)
	 	Name : STRING[32]; (*name of the sector*)
	 	Type :  McAcpTrakSecTypeEnum; (*type of the sector*)
	 END_STRUCT;

	 McAcpTrakAdvSecAddShParType  : STRUCT
		Velocity : REAL; (*velocity of a moving shuttle*)
		Orientation : McDirectionEnum; (*orientation of the shuttle in the sector*)
	END_STRUCT;

	 McAcpTrakAsmInfoType : STRUCT
	 	CommunicationReady : BOOL; (*"Network" of all segments of the assembly is initialized and ready for communication*)
		ReadyForPowerOn : BOOL; (*the controllers of all segments of the assembly are ready to be switched on*)
		PowerOn : BOOL; (*the controllers of all segments of the assembly are switched on*)
		StartupCount : UDINT; (*number of completed switch-on operations of the assembly*)
	 	ShuttlesInErrorStopCount : UINT; (*number of shuttles in state ErrorStop*)
	 END_STRUCT;

	McAcpTrakAsmGetShAddInfoType : STRUCT
		ShuttleID : UINT; (* Unique shuttle index on the assembly.*)
	END_STRUCT;

	McAcpTrakSecGetShAddInfoType : STRUCT
		ShuttleID : UINT; (* Unique shuttle index on the assembly.*)
		Position : LREAL; (* Position on sector*)
		Orientation : McDirectionEnum; (* Orientation of the shuttle on the sector*)
	END_STRUCT;

	McAcpTrakAdvGetMinShDistParType : STRUCT
	 	MeasurePointsMode : McAcpTrakShRelativeRefPointEnum; (*Measurement points selector*)
		Shuttle1 : REFERENCE TO McAxisType; (*Reference of the first shuttle in the comparison(optional)*)
		Shuttle2 : REFERENCE TO McAxisType; (*Reference of the second shuttle in the comparison(optional)*)
	END_STRUCT;

	McAcpTrakAsmGetMinShDistType : STRUCT
		Curve : LREAL; (* Minimum distance on a curved segment*)
		Junction : LREAL; (* Minimum distance in a junction*)
		Straight : LREAL; (* Minimum distance on a straight*)
	END_STRUCT;

	McAcpTrakConvoyParType : STRUCT
		PositiveOffset : LREAL;
		NegativeOffset : LREAL;
		MasterVelocityAdjustment : BOOL; (*Allow master shuttle adjust velocity to slave convoy members*)
		Separable : BOOL; (*Allow shuttles outside of convoy to use the spaces between convoy members*)
	END_STRUCT;

END_TYPE

