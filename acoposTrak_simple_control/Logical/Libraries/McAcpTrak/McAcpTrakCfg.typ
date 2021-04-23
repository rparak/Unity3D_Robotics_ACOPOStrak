TYPE
	McAFCCplgObjType : STRUCT (*Coupling object*)
		Name : STRING[250]; (*Name of the coupling object*)
		ShuttleCount : UINT; (*Maximum number of simultaneously coupled shuttles*)
		CamAutomatReference : McCfgReferenceType; (*Name of the axis feature reference*)
		CamListReference : McCfgReferenceType; (*Name of the cam list reference*)
	END_STRUCT;
	McCfgAsmFeatCplgType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_ASM_FEAT_CPLG*)
		CouplingObject : McCfgUnboundedArrayType; (*Coupling object*)
	END_STRUCT;
	McAFSSDShOnSecOrientEnum :
		( (*Orientation of the shuttle*)
		mcAFSSDSOSO_POS := 0, (*Positive - Same orientation as sector*)
		mcAFSSDSOSO_NEG := 1 (*Negative - Opposite orientation to the sector*)
		);
	McAFSSDShOnSecDefEnum :
		( (*Definition selector setting*)
		mcAFSSDSOSD_SNG_SH := 0, (*Single shuttle - Definition of shuttles separately*)
		mcAFSSDSOSD_SET_OF_SH := 1 (*Set of shuttles - Definition of the whole shuttle set*)
		);
	McAFSSDShOnSecDefSngShType : STRUCT (*Type mcAFSSDSOSD_SNG_SH settings*)
		Position : McCfgUnboundedArrayType; (*Position on the sector [Measurement units]*)
	END_STRUCT;
	McAFSSDShOnSecDefSetOfShType : STRUCT (*Type mcAFSSDSOSD_SET_OF_SH settings*)
		StartPosition : LREAL; (*Position of the first shuttle on the sector [Measurement units]*)
		NumberOfShuttles : USINT; (*Number of shuttles on the sector [Measurement units]*)
		DistanceBetweenShuttles : LREAL; (*Distance between consecutive shuttles [Measurement units]*)
	END_STRUCT;
	McAFSSDShOnSecDefType : STRUCT (*Type of shuttle definition*)
		Type : McAFSSDShOnSecDefEnum; (*Definition selector setting*)
		SingleShuttle : McAFSSDShOnSecDefSngShType; (*Type mcAFSSDSOSD_SNG_SH settings*)
		SetOfShuttles : McAFSSDShOnSecDefSetOfShType; (*Type mcAFSSDSOSD_SET_OF_SH settings*)
	END_STRUCT;
	McAFSSDShOnSecType : STRUCT (*Shuttle to be initialized*)
		SectorReference : McCfgReferenceType; (*Name of the referenced sector component*)
		Orientation : McAFSSDShOnSecOrientEnum; (*Orientation of the shuttle*)
		Definition : McAFSSDShOnSecDefType; (*Type of shuttle definition*)
	END_STRUCT;
	McCfgAsmFeatSimShDefType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_ASM_FEAT_SIM_SH_DEF*)
		ShuttleOnSector : McCfgUnboundedArrayType; (*Shuttle to be initialized*)
	END_STRUCT;
	McAFSTShTrcCfgSecRstEnum :
		( (*Sector restricted*)
		mcAFSTSTCSR_ON := 0, (*On - Sector restricted on*)
		mcAFSTSTCSR_OFF := 1 (*Off - Sector restricted off*)
		);
	McAFSTShTrcCfgType : STRUCT (*Shuttle trace configuration*)
		ShuttleCount : UINT; (*Maximum number of simultaneously traced shuttles*)
		SectorReference : McCfgReferenceType; (*Name of the sector reference*)
		SectorRestricted : McAFSTShTrcCfgSecRstEnum; (*Sector restricted*)
	END_STRUCT;
	McCfgAsmFeatShTraceType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_ASM_FEAT_SH_TRACE*)
		ShuttleTraceConfiguration : McAFSTShTrcCfgType; (*Shuttle trace configuration*)
	END_STRUCT;
	McAFSAAPrioOrientEnum :
		( (*Orientation of the shuttle*)
		mcAFSAAPO_KEEP_SEG_ORIENT := 0, (*Keep segment orientation - Keep currently assigned orientation*)
		mcAFSAAPO_POS := 1, (*Positive - Same orientation as sector*)
		mcAFSAAPO_NEG := 2 (*Negative - Opposite orientation to the sector*)
		);
	McAFSAAPrioType : STRUCT (*Sector priority definition for the shuttle auto attachment*)
		SectorReference : McCfgReferenceType; (*Name of the referenced sector component*)
		Orientation : McAFSAAPrioOrientEnum; (*Orientation of the shuttle*)
	END_STRUCT;
	McCfgAsmFeatShAutAttType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_ASM_FEAT_SH_AUT_ATT*)
		Priority : McCfgUnboundedArrayType; (*Sector priority definition for the shuttle auto attachment*)
	END_STRUCT;
	McAFLLScpEnum :
		( (*Scope selector setting*)
		mcAFLLS_ALL_SH := 0, (*All shuttles - Applies to all shuttles, not changeable*)
		mcAFLLS_SNG_SH := 1 (*Single shuttles - Applies only to shuttles which are defined*)
		);
	McAFLLScpSngShType : STRUCT (*Type mcAFLLS_SNG_SH settings*)
		LocalLimitName : STRING[250]; (*Local limit name to use for MC_BR_ShLocalLimitCmd_AcpTrak*)
	END_STRUCT;
	McAFLLScpType : STRUCT (*Defines for which shuttles the local limit applies*)
		Type : McAFLLScpEnum; (*Scope selector setting*)
		SingleShuttles : McAFLLScpSngShType; (*Type mcAFLLS_SNG_SH settings*)
	END_STRUCT;
	McAFLLLocEnum :
		( (*Location selector setting*)
		mcAFLLL_SEC := 0, (*Sector - Location defined by a sector*)
		mcAFLLL_CRV_AREA := 1, (*Curved area - Local limit in all curved areas*)
		mcAFLLL_DUALTRK_AREA := 2 (*Dual-track area - Local limit in all dual-track areas*)
		);
	McAFLLLocSecType : STRUCT (*Type mcAFLLL_SEC settings*)
		SectorReference : McCfgReferenceType; (*Name of the referenced sector component*)
	END_STRUCT;
	McAFLLLocCrvAreaType : STRUCT (*Type mcAFLLL_CRV_AREA settings*)
		CurvatureThreshold : REAL; (*Curvature from which the local limit is valid. Value given in the reciprocal of the radius of curvature. [1/m]*)
	END_STRUCT;
	McAFLLLocType : STRUCT (*Defines the location of the local limit*)
		Type : McAFLLLocEnum; (*Location selector setting*)
		Sector : McAFLLLocSecType; (*Type mcAFLLL_SEC settings*)
		CurvedArea : McAFLLLocCrvAreaType; (*Type mcAFLLL_CRV_AREA settings*)
	END_STRUCT;
	McAFLLMotLimVelEnum :
		( (*Velocity selector setting*)
		mcAFLLMLV_NOT_USE := 0, (*Not used - Velocity limit not used*)
		mcAFLLMLV_BASIC := 1, (*Basic -*)
		mcAFLLMLV_ADV := 2 (*Advanced -*)
		);
	McAFLLMotLimVelBasicType : STRUCT (*Type mcAFLLMLV_BASIC settings*)
		Velocity : REAL; (*Velocity limit in any movement direction [Measurement units/s]*)
	END_STRUCT;
	McAFLLMotLimVelType : STRUCT (*Limit the velocity*)
		Type : McAFLLMotLimVelEnum; (*Velocity selector setting*)
		Basic : McAFLLMotLimVelBasicType; (*Type mcAFLLMLV_BASIC settings*)
	END_STRUCT;
	McAFLLMotLimAccEnum :
		( (*Acceleration selector setting*)
		mcAFLLMLA_NOT_USE := 0, (*Not used - Acceleration limit not used*)
		mcAFLLMLA_BASIC := 1, (*Basic -*)
		mcAFLLMLA_ADV := 2 (*Advanced -*)
		);
	McAFLLMotLimAccBasicType : STRUCT (*Type mcAFLLMLA_BASIC settings*)
		Acceleration : REAL; (*Acceleration limit in any movement direction [Measurement units/s²]*)
	END_STRUCT;
	McAFLLMotLimAccType : STRUCT (*Limit the acceleration*)
		Type : McAFLLMotLimAccEnum; (*Acceleration selector setting*)
		Basic : McAFLLMotLimAccBasicType; (*Type mcAFLLMLA_BASIC settings*)
	END_STRUCT;
	McAFLLMotLimType : STRUCT (*Limits which are effective*)
		Velocity : McAFLLMotLimVelType; (*Limit the velocity*)
		Acceleration : McAFLLMotLimAccType; (*Limit the acceleration*)
	END_STRUCT;
	McAFLLType : STRUCT (*Local limit definition*)
		Scope : McAFLLScpType; (*Defines for which shuttles the local limit applies*)
		Location : McAFLLLocType; (*Defines the location of the local limit*)
		MotionLimits : McAFLLMotLimType; (*Limits which are effective*)
	END_STRUCT;
	McCfgAsmFeatLocLimType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_ASM_FEAT_LOC_LIM*)
		LocalLimit : McCfgUnboundedArrayType; (*Local limit definition*)
	END_STRUCT;
	McSCSegPosRelToEnum :
		( (*Absolute position from which the position is counted*)
		mcSCSPRT_ST_OF_SEG := 0, (*Start of segment - Positive from start of segment*)
		mcSCSPRT_END_OF_SEG := 1 (*End of segment - Negative from end of segment*)
		);
	McSCSegType : STRUCT (*Begin of the sector*)
		SegmentReference : STRING[250]; (*Name of the referenced segment component*)
		Position : LREAL; (*Position on the segment [Measurement units]*)
		PositionRelativeTo : McSCSegPosRelToEnum; (*Absolute position from which the position is counted*)
	END_STRUCT;
	McSCIntmSegType : STRUCT (*Segments between the start and the end segment*)
		SegmentReference : McCfgUnboundedArrayType; (*Name of the referenced segment component*)
	END_STRUCT;
	McCfgSecCompType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_SEC_COMP*)
		StartSegment : McSCSegType; (*Begin of the sector*)
		IntermediateSegments : McSCIntmSegType; (*Segments between the start and the end segment*)
		EndSegment : McSCSegType; (*End of the sector*)
	END_STRUCT;
	McSSStPosRelToEnum :
		( (*Absolute position from which the position is counted*)
		mcSSSPRT_ST_OF_SEC := 0, (*Start of sector - Tail of the sector*)
		mcSSSPRT_END_OF_SEC := 1 (*End of sector - Head of the sector*)
		);
	McSSStType : STRUCT (*Begin of the sector*)
		Position : LREAL; (*Position on the sector [Measurement units]*)
		PositionRelativeTo : McSSStPosRelToEnum; (*Absolute position from which the position is counted*)
	END_STRUCT;
	McSSDirEnum :
		( (*Direction of the sub sector*)
		mcSSD_POS := 0, (*Positive - Same direction as sector*)
		mcSSD_NEG := 1 (*Negative - Opposite direction of sector*)
		);
	McCfgSecSubType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_SEC_SUB*)
		SectorReference : McCfgReferenceType; (*Name of the referenced sector component*)
		Start : McSSStType; (*Begin of the sector*)
		Length : LREAL; (*Length of the sub sector [Measurement units]*)
		Direction : McSSDirEnum; (*Direction of the sub sector*)
	END_STRUCT;
END_TYPE