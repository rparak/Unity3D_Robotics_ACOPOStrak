/* Automation Studio generated header file */
/* Do not edit ! */
/* McAcpTrak 5.12.2 */

#ifndef _MCACPTRAK_
#define _MCACPTRAK_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _McAcpTrak_VERSION
#define _McAcpTrak_VERSION 5.12.2
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif

#ifdef _SG4
#include <McBase.h> 
#include <McAxis.h>
#endif
 
#ifdef _SG3
#include <McBase.h> 
#include <McAxis.h>
#endif
 
#ifdef _SGC
#include <McBase.h> 
#include <McAxis.h>
#endif

/* Datatypes and datatypes of function blocks */
typedef enum McAcpTrakSegProcessParIDModeEnum
{	mcACPTRAK_SEG_PARID_GET = 0,
	mcACPTRAK_SEG_PARID_SET,
	mcACPTRAK_SEG_PARID_GET_NO_NCT
} McAcpTrakSegProcessParIDModeEnum;

typedef enum McAcpTrakSegDataTypeEnum
{	mcACPTRAK_SEG_PARTYPE_BOOL = 1,
	mcACPTRAK_SEG_PARTYPE_SINT,
	mcACPTRAK_SEG_PARTYPE_INT,
	mcACPTRAK_SEG_PARTYPE_DINT,
	mcACPTRAK_SEG_PARTYPE_USINT,
	mcACPTRAK_SEG_PARTYPE_UINT,
	mcACPTRAK_SEG_PARTYPE_UDINT,
	mcACPTRAK_SEG_PARTYPE_REAL,
	mcACPTRAK_SEG_PARTYPE_VOID = 65535
} McAcpTrakSegDataTypeEnum;

typedef enum McAcpTrakTrgPointEventEnum
{	mcACPTRAK_TP_PASSED_NEGATIVE,
	mcACPTRAK_TP_PASSED_POSITIVE
} McAcpTrakTrgPointEventEnum;

typedef enum McAcpTrakSearchModeEnum
{	mcACPTRAK_SEARCH_FORWARD,
	mcACPTRAK_SEARCH_BACKWARD
} McAcpTrakSearchModeEnum;

typedef enum McAcpTrakCopyUserDataModeEnum
{	mcACPTRAK_USERDATA_GET,
	mcACPTRAK_USERDATA_SET
} McAcpTrakCopyUserDataModeEnum;

typedef enum McAcpTrakShManeuverTypeEnum
{	mcACPTRAK_MANEUVER_NONE = 0,
	mcACPTRAK_MANEUVER_ADJUSTMENT = 1,
	mcACPTRAK_MANEUVER_STANDSTILL = 2,
	mcACPTRAK_MANEUVER_EMERGENCY = 3
} McAcpTrakShManeuverTypeEnum;

typedef enum McAcpTrakShManeuverReasonEnum
{	mcACPTRAK_REASON_UNSPECIFIED = 0,
	mcACPTRAK_REASON_SHUTTLE = 1,
	mcACPTRAK_REASON_LOCAL_VEL_LIMIT = 2,
	mcACPTRAK_REASON_BARRIER = 3,
	mcACPTRAK_REASON_SECTOREND = 4,
	mcACPTRAK_REASON_SECTORSWITCH = 5,
	mcACPTRAK_REASON_LOGISTICS = 6,
	mcACPTRAK_REASON_NONE = 7,
	mcACPTRAK_REASON_LOCAL_ACC_LIMIT = 8,
	mcACPTRAK_REASON_UNCONTROLLED = 9,
	mcACPTRAK_REASON_RECONTROLLED = 10
} McAcpTrakShManeuverReasonEnum;

typedef enum McAcpTrakSelectShSideEnum
{	mcACPTRAK_SIDE_BOTH = 0
} McAcpTrakSelectShSideEnum;

typedef enum McAcpTrakSecTypeEnum
{	mcACPTRAK_SEC_USER_DEFINED,
	mcACPTRAK_SEC_SEGMENT,
	mcACPTRAK_SEC_INTERNAL
} McAcpTrakSecTypeEnum;

typedef enum McAcpTrakRoutePosRelToEnum
{	mcACPTRAK_SEC_START,
	mcACPTRAK_SEC_END
} McAcpTrakRoutePosRelToEnum;

typedef enum McAcpTrakShMovementTypeEnum
{	mcACPTRAK_MOVEMENT_STANDSTILL,
	mcACPTRAK_MOVEMENT_ELASTIC,
	mcACPTRAK_MOVEMENT_RIGID
} McAcpTrakShMovementTypeEnum;

typedef enum McAcpTrakBarrierCmdEnum
{	mcACPTRAK_BARRIER_OPEN,
	mcACPTRAK_BARRIER_CLOSE,
	mcACPTRAK_BARRIER_ADD_TICKETS
} McAcpTrakBarrierCmdEnum;

typedef enum McAcpTrakBarrierStatusEnum
{	mcACPTRAK_BARRIER_OPENED,
	mcACPTRAK_BARRIER_CLOSED,
	mcACPTRAK_BARRIER_TICKETING
} McAcpTrakBarrierStatusEnum;

typedef enum McAcpTrakCouplingObjCmdEnum
{	mcACPTRAK_COUPLE_OBJ_SET,
	mcACPTRAK_COUPLE_OBJ_REMOVE
} McAcpTrakCouplingObjCmdEnum;

typedef enum McAcpTrakSimulationOnPlcEnum
{	mcACPTRAK_SIM_STATE_OFF,
	mcACPTRAK_SIM_STATE_ON
} McAcpTrakSimulationOnPlcEnum;

typedef enum McAcpTrakFieldModeEnum
{	mcACPTRAK_FIELD_NORMAL,
	mcACPTRAK_FIELD_WEAKENING,
	mcACPTRAK_FIELD_STRENGTHENING
} McAcpTrakFieldModeEnum;

typedef enum McAcpTrakShResizeCmdEnum
{	mcACPTRAK_RESIZE_DIMENSIONS
} McAcpTrakShResizeCmdEnum;

typedef enum McAcpTrakAsmDeleteShCmdEnum
{	mcACPTRAK_SH_DELETE_SPECIFIC,
	mcACPTRAK_SH_DELETE_ALL
} McAcpTrakAsmDeleteShCmdEnum;

typedef enum McAcpTrakPLCopenStateEnum
{	mcACPTRAK_DISABLED,
	mcACPTRAK_HOMING,
	mcACPTRAK_READY,
	mcACPTRAK_STOPPING,
	mcACPTRAK_ERRORSTOP,
	mcACPTRAK_STARTUP,
	mcACPTRAK_INVALID_CONFIGURATION
} McAcpTrakPLCopenStateEnum;

typedef enum McAcpTrakShRelativeAlignmentEnum
{	mcACPTRAK_ALIGNED_FRONT_TO_BACK,
	mcACPTRAK_ALIGNED_BACK_TO_FRONT,
	mcACPTRAK_ALIGNED_FRONT_TO_FRONT,
	mcACPTRAK_ALIGNED_BACK_TO_BACK
} McAcpTrakShRelativeAlignmentEnum;

typedef enum McAcpTrakShRelativeRefPointEnum
{	mcACPTRAK_DIST_CENTER_TO_CENTER,
	mcACPTRAK_DIST_CENTER_TO_EXTENT,
	mcACPTRAK_DIST_EXTENT_TO_CENTER,
	mcACPTRAK_DIST_EXTENT_TO_EXTENT
} McAcpTrakShRelativeRefPointEnum;

typedef enum McAcpTrakShLocalLimitCmdEnum
{	mcACPTRAK_LL_ADD_SHUTTLE,
	mcACPTRAK_LL_REMOVE_SHUTTLE
} McAcpTrakShLocalLimitCmdEnum;

typedef enum McAFSSDShOnSecOrientEnum
{	mcAFSSDSOSO_POS = 0,
	mcAFSSDSOSO_NEG = 1
} McAFSSDShOnSecOrientEnum;

typedef enum McAFSSDShOnSecDefEnum
{	mcAFSSDSOSD_SNG_SH = 0,
	mcAFSSDSOSD_SET_OF_SH = 1
} McAFSSDShOnSecDefEnum;

typedef enum McAFSTShTrcCfgSecRstEnum
{	mcAFSTSTCSR_ON = 0,
	mcAFSTSTCSR_OFF = 1
} McAFSTShTrcCfgSecRstEnum;

typedef enum McAFSAAPrioOrientEnum
{	mcAFSAAPO_KEEP_SEG_ORIENT = 0,
	mcAFSAAPO_POS = 1,
	mcAFSAAPO_NEG = 2
} McAFSAAPrioOrientEnum;

typedef enum McAFLLScpEnum
{	mcAFLLS_ALL_SH = 0,
	mcAFLLS_SNG_SH = 1
} McAFLLScpEnum;

typedef enum McAFLLLocEnum
{	mcAFLLL_SEC = 0,
	mcAFLLL_CRV_AREA = 1,
	mcAFLLL_DUALTRK_AREA = 2
} McAFLLLocEnum;

typedef enum McAFLLMotLimVelEnum
{	mcAFLLMLV_NOT_USE = 0,
	mcAFLLMLV_BASIC = 1,
	mcAFLLMLV_ADV = 2
} McAFLLMotLimVelEnum;

typedef enum McAFLLMotLimAccEnum
{	mcAFLLMLA_NOT_USE = 0,
	mcAFLLMLA_BASIC = 1,
	mcAFLLMLA_ADV = 2
} McAFLLMotLimAccEnum;

typedef enum McSCSegPosRelToEnum
{	mcSCSPRT_ST_OF_SEG = 0,
	mcSCSPRT_END_OF_SEG = 1
} McSCSegPosRelToEnum;

typedef enum McSSStPosRelToEnum
{	mcSSSPRT_ST_OF_SEC = 0,
	mcSSSPRT_END_OF_SEC = 1
} McSSStPosRelToEnum;

typedef enum McSSDirEnum
{	mcSSD_POS = 0,
	mcSSD_NEG = 1
} McSSDirEnum;

typedef struct McInternalAssemblyIfType
{	plcdword vtable;
} McInternalAssemblyIfType;

typedef struct McAssemblyType
{	struct McInternalAssemblyIfType* controlif;
} McAssemblyType;

typedef struct McInternalSegmentIfType
{	plcdword vtable;
} McInternalSegmentIfType;

typedef struct McSegmentType
{	struct McInternalSegmentIfType* controlif;
} McSegmentType;

typedef struct McInternalSectorIfType
{	plcdword vtable;
} McInternalSectorIfType;

typedef struct McSectorType
{	struct McInternalSectorIfType* controlif;
} McSectorType;

typedef struct McInternalProcessPointIfType
{	plcdword vtable;
} McInternalProcessPointIfType;

typedef struct McProcessPointType
{	struct McInternalProcessPointIfType* controlif;
} McProcessPointType;

typedef struct McAcpTrakSegProcessParIDType
{	unsigned short ParID;
	unsigned long VariableAddress;
	enum McAcpTrakSegDataTypeEnum DataType;
} McAcpTrakSegProcessParIDType;

typedef struct McAcpTrakRouteTransitPointsType
{	struct McSectorType* Sector;
	double Position;
	enum McDirectionEnum TransitDirection;
} McAcpTrakRouteTransitPointsType;

typedef struct McAcpTrakAdvRouteParType
{	enum McDirectionEnum StartDirection;
	enum McDirectionEnum EndDirection;
	enum McDirectionEnum ShuttleOrientation;
	struct McAcpTrakRouteTransitPointsType* TransitPoints;
	unsigned short NumberOfTransitPoints;
	enum McAcpTrakRoutePosRelToEnum PosRelativeTo;
} McAcpTrakAdvRouteParType;

typedef struct McAcpTrakShManeuverInfoType
{	enum McAcpTrakShManeuverTypeEnum Type;
	enum McAcpTrakShManeuverReasonEnum Reason;
} McAcpTrakShManeuverInfoType;

typedef struct McAcpTrakShCurrentValuesType
{	double Position;
	struct McSectorType Sector;
	plcstring SectorName[33];
	enum McAcpTrakSecTypeEnum SectorType;
	double SectorLength;
	enum McDirectionEnum Orientation;
	float Velocity;
	enum McAcpTrakShMovementTypeEnum MovementType;
	unsigned char CtrlParSetLeft;
	unsigned char CtrlParSetRight;
} McAcpTrakShCurrentValuesType;

typedef struct McAcpTrakShRouteDestInfoType
{	double Position;
	struct McSectorType Sector;
	plcstring SectorName[33];
	enum McAcpTrakSecTypeEnum SectorType;
	float VelocityAtDestination;
	double TotalDistance;
	double RemainingDistance;
} McAcpTrakShRouteDestInfoType;

typedef struct McAcpTrakShLifeCycleInfoType
{	double AbsoluteMovementDistance;
} McAcpTrakShLifeCycleInfoType;

typedef struct McAcpTrakShSegSetValuesType
{	plcbit Valid;
	plcstring SegmentName[33];
	double Position;
	unsigned char Channel;
	enum McAcpTrakFieldModeEnum FieldMode;
	unsigned short SegmentID;
} McAcpTrakShSegSetValuesType;

typedef struct McAcpTrakShSegCurrentValuesType
{	plcbit Valid;
	plcstring SegmentName[33];
	double Position;
} McAcpTrakShSegCurrentValuesType;

typedef struct McAcpTrakShInfoType
{	struct McAcpTrakShCurrentValuesType CurrentValues;
	struct McAcpTrakShRouteDestInfoType RouteDestinationInfo;
	struct McAcpTrakShManeuverInfoType ManeuverInfo;
	struct McAcpTrakShLifeCycleInfoType LifeCycleInfo;
} McAcpTrakShInfoType;

typedef struct McAcpTrakShSegmentInfoType
{	struct McAcpTrakShSegSetValuesType SegmentSetValues[4];
	struct McAcpTrakShSegCurrentValuesType SegmentCurrentValues[4];
} McAcpTrakShSegmentInfoType;

typedef struct McAcpTrakShResizeParamType
{	double ExtentToFront;
	double ExtentToBack;
	double Width;
} McAcpTrakShResizeParamType;

typedef struct McAcpTrakShuttleMonData
{	plcbit Available;
	struct McPosType Position;
	struct McOrientType Orientation;
	double ExtentToFront;
	double ExtentToBack;
	double Width;
	unsigned long UserData;
	unsigned short Index;
} McAcpTrakShuttleMonData;

typedef struct McAcpTrakAssemblyMonData
{	struct McAcpTrakShuttleMonData Shuttle[150];
} McAcpTrakAssemblyMonData;

typedef struct McAcpTrakShuttleVisData
{	plcbit Available;
	unsigned char Reserved[3];
	float PositionX;
	float PositionY;
	float RotationZ;
	plcstring Text[32];
	float ColorRed;
	float ColorGreen;
	float ColorBlue;
	float ExtentToFront;
	float ExtentToBack;
	float Width;
} McAcpTrakShuttleVisData;

typedef struct McAcpTrakAssemblyVisData
{	struct McAcpTrakShuttleVisData Shuttle[150];
} McAcpTrakAssemblyVisData;

typedef struct McAcpTrakSegInfoType
{	plcbit CommunicationReady;
	plcbit ReadyForPowerOn;
	plcbit PowerOn;
	unsigned long StartupCount;
	enum McCommunicationStateEnum CommunicationState;
} McAcpTrakSegInfoType;

typedef struct McAcpTrakTrgPointGetInfoType
{	struct McAxisType Axis;
	enum McAcpTrakTrgPointEventEnum Event;
	plcbit ShuttleControlled;
} McAcpTrakTrgPointGetInfoType;

typedef struct McAcpTrakBarrierInfoType
{	enum McAcpTrakBarrierStatusEnum Status;
	unsigned long RemainingTickets;
} McAcpTrakBarrierInfoType;

typedef struct McAcpTrakAdvBarrierParType
{	signed long TicketCount;
} McAcpTrakAdvBarrierParType;

typedef struct McAcpTrakSegmentPosition
{	signed short Index;
	double Position;
} McAcpTrakSegmentPosition;

typedef struct McAcpTrakShuttleEncoderPosition
{	plcbit Available;
	struct McAcpTrakSegmentPosition SegPos[4];
	double ActPosition;
	double DesPosition;
} McAcpTrakShuttleEncoderPosition;

typedef struct McAcpTrakShuttleEncoderMonitor
{	struct McAcpTrakShuttleEncoderPosition ShuttleEncPos[32];
} McAcpTrakShuttleEncoderMonitor;

typedef struct McAcpTrakAsmGetInfoType
{	enum McAcpTrakSimulationOnPlcEnum SimulationOnPlcMode;
} McAcpTrakAsmGetInfoType;

typedef struct McAcpTrakSecGetInfoType
{	double Length;
	plcbit SectorClosed;
	plcstring Name[33];
	enum McAcpTrakSecTypeEnum Type;
} McAcpTrakSecGetInfoType;

typedef struct McAcpTrakAdvSecAddShParType
{	float Velocity;
	enum McDirectionEnum Orientation;
} McAcpTrakAdvSecAddShParType;

typedef struct McAcpTrakAsmInfoType
{	plcbit CommunicationReady;
	plcbit ReadyForPowerOn;
	plcbit PowerOn;
	unsigned long StartupCount;
	unsigned short ShuttlesInErrorStopCount;
} McAcpTrakAsmInfoType;

typedef struct McAcpTrakAsmGetShAddInfoType
{	unsigned short ShuttleID;
} McAcpTrakAsmGetShAddInfoType;

typedef struct McAcpTrakSecGetShAddInfoType
{	unsigned short ShuttleID;
	double Position;
	enum McDirectionEnum Orientation;
} McAcpTrakSecGetShAddInfoType;

typedef struct McAcpTrakAdvGetMinShDistParType
{	enum McAcpTrakShRelativeRefPointEnum MeasurePointsMode;
	struct McAxisType* Shuttle1;
	struct McAxisType* Shuttle2;
} McAcpTrakAdvGetMinShDistParType;

typedef struct McAcpTrakAsmGetMinShDistType
{	double Curve;
	double Junction;
	double Straight;
} McAcpTrakAsmGetMinShDistType;

typedef struct McAcpTrakConvoyParType
{	double PositiveOffset;
	double NegativeOffset;
	plcbit MasterVelocityAdjustment;
	plcbit Separable;
} McAcpTrakConvoyParType;

typedef struct McAFCCplgObjType
{	plcstring Name[251];
	unsigned short ShuttleCount;
	struct McCfgReferenceType CamAutomatReference;
	struct McCfgReferenceType CamListReference;
} McAFCCplgObjType;

typedef struct McCfgAsmFeatCplgType
{	struct McCfgUnboundedArrayType CouplingObject;
} McCfgAsmFeatCplgType;

typedef struct McAFSSDShOnSecDefSngShType
{	struct McCfgUnboundedArrayType Position;
} McAFSSDShOnSecDefSngShType;

typedef struct McAFSSDShOnSecDefSetOfShType
{	double StartPosition;
	unsigned char NumberOfShuttles;
	double DistanceBetweenShuttles;
} McAFSSDShOnSecDefSetOfShType;

typedef struct McAFSSDShOnSecDefType
{	enum McAFSSDShOnSecDefEnum Type;
	struct McAFSSDShOnSecDefSngShType SingleShuttle;
	struct McAFSSDShOnSecDefSetOfShType SetOfShuttles;
} McAFSSDShOnSecDefType;

typedef struct McAFSSDShOnSecType
{	struct McCfgReferenceType SectorReference;
	enum McAFSSDShOnSecOrientEnum Orientation;
	struct McAFSSDShOnSecDefType Definition;
} McAFSSDShOnSecType;

typedef struct McCfgAsmFeatSimShDefType
{	struct McCfgUnboundedArrayType ShuttleOnSector;
} McCfgAsmFeatSimShDefType;

typedef struct McAFSTShTrcCfgType
{	unsigned short ShuttleCount;
	struct McCfgReferenceType SectorReference;
	enum McAFSTShTrcCfgSecRstEnum SectorRestricted;
} McAFSTShTrcCfgType;

typedef struct McCfgAsmFeatShTraceType
{	struct McAFSTShTrcCfgType ShuttleTraceConfiguration;
} McCfgAsmFeatShTraceType;

typedef struct McAFSAAPrioType
{	struct McCfgReferenceType SectorReference;
	enum McAFSAAPrioOrientEnum Orientation;
} McAFSAAPrioType;

typedef struct McCfgAsmFeatShAutAttType
{	struct McCfgUnboundedArrayType Priority;
} McCfgAsmFeatShAutAttType;

typedef struct McAFLLScpSngShType
{	plcstring LocalLimitName[251];
} McAFLLScpSngShType;

typedef struct McAFLLScpType
{	enum McAFLLScpEnum Type;
	struct McAFLLScpSngShType SingleShuttles;
} McAFLLScpType;

typedef struct McAFLLLocSecType
{	struct McCfgReferenceType SectorReference;
} McAFLLLocSecType;

typedef struct McAFLLLocCrvAreaType
{	float CurvatureThreshold;
} McAFLLLocCrvAreaType;

typedef struct McAFLLLocType
{	enum McAFLLLocEnum Type;
	struct McAFLLLocSecType Sector;
	struct McAFLLLocCrvAreaType CurvedArea;
} McAFLLLocType;

typedef struct McAFLLMotLimVelBasicType
{	float Velocity;
} McAFLLMotLimVelBasicType;

typedef struct McAFLLMotLimVelType
{	enum McAFLLMotLimVelEnum Type;
	struct McAFLLMotLimVelBasicType Basic;
} McAFLLMotLimVelType;

typedef struct McAFLLMotLimAccBasicType
{	float Acceleration;
} McAFLLMotLimAccBasicType;

typedef struct McAFLLMotLimAccType
{	enum McAFLLMotLimAccEnum Type;
	struct McAFLLMotLimAccBasicType Basic;
} McAFLLMotLimAccType;

typedef struct McAFLLMotLimType
{	struct McAFLLMotLimVelType Velocity;
	struct McAFLLMotLimAccType Acceleration;
} McAFLLMotLimType;

typedef struct McAFLLType
{	struct McAFLLScpType Scope;
	struct McAFLLLocType Location;
	struct McAFLLMotLimType MotionLimits;
} McAFLLType;

typedef struct McCfgAsmFeatLocLimType
{	struct McCfgUnboundedArrayType LocalLimit;
} McCfgAsmFeatLocLimType;

typedef struct McSCSegType
{	plcstring SegmentReference[251];
	double Position;
	enum McSCSegPosRelToEnum PositionRelativeTo;
} McSCSegType;

typedef struct McSCIntmSegType
{	struct McCfgUnboundedArrayType SegmentReference;
} McSCIntmSegType;

typedef struct McCfgSecCompType
{	struct McSCSegType StartSegment;
	struct McSCIntmSegType IntermediateSegments;
	struct McSCSegType EndSegment;
} McCfgSecCompType;

typedef struct McSSStType
{	double Position;
	enum McSSStPosRelToEnum PositionRelativeTo;
} McSSStType;

typedef struct McCfgSecSubType
{	struct McCfgReferenceType SectorReference;
	struct McSSStType Start;
	double Length;
	enum McSSDirEnum Direction;
} McCfgSecSubType;

typedef struct MC_BR_SegCycChanSetPos_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McSegmentType* Segment;
	unsigned char ChannelIndex;
	unsigned short CyclicControlBits;
	double CyclicSetPosition;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_BR_SegCycChanSetPos_AcpTrak_typ;

typedef struct MC_BR_ShCreateConvoy_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McAcpTrakConvoyParType Parameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	McConvoyType Convoy;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_ShCreateConvoy_AcpTrak_typ;

typedef struct MC_BR_AsmPowerOn_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAssemblyType* Assembly;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_AsmPowerOn_AcpTrak_typ;

typedef struct MC_BR_AsmPowerOff_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAssemblyType* Assembly;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_AsmPowerOff_AcpTrak_typ;

typedef struct MC_BR_AsmReadStatus_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAssemblyType* Assembly;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
	plcbit AssemblyDisabled;
	plcbit AssemblyReady;
	plcbit AssemblyHoming;
	plcbit AssemblyStopping;
	plcbit AssemblyErrorStop;
} MC_BR_AsmReadStatus_AcpTrak_typ;

typedef struct MC_BR_AsmReset_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAssemblyType* Assembly;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_AsmReset_AcpTrak_typ;

typedef struct MC_BR_AsmCommandError_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAssemblyType* Assembly;
	enum McErrorCmdEnum Command;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_AsmCommandError_AcpTrak_typ;

typedef struct MC_BR_AsmGetShuttle_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAssemblyType* Assembly;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	unsigned short TotalCount;
	unsigned short RemainingCount;
	struct McAxisType Axis;
	struct McAcpTrakAsmGetShAddInfoType AdditionalInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit Next;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_BR_AsmGetShuttle_AcpTrak_typ;

typedef struct MC_BR_AsmDeleteShuttle_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAssemblyType* Assembly;
	enum McAcpTrakAsmDeleteShCmdEnum Command;
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	unsigned short DeletedCount;
	/* VAR (analog) */
	struct McInternalTwoRefType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_AsmDeleteShuttle_AcpTrak_typ;

typedef struct MC_BR_AsmReadInfo_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAssemblyType* Assembly;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpTrakAsmInfoType AssemblyInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_BR_AsmReadInfo_AcpTrak_typ;

typedef struct MC_BR_AsmGetInfo_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAssemblyType* Assembly;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpTrakAsmGetInfoType AssemblyInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_AsmGetInfo_AcpTrak_typ;

typedef struct MC_BR_AsmGetMinShDist_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAssemblyType* Assembly;
	enum McAcpTrakShRelativeAlignmentEnum Mode;
	struct McAcpTrakAdvGetMinShDistParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpTrakAsmGetMinShDistType Distance;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_AsmGetMinShDist_AcpTrak_typ;

typedef struct MC_BR_BarrierCommand_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McProcessPointType* ProcessPoint;
	enum McAcpTrakBarrierCmdEnum Command;
	struct McAcpTrakAdvBarrierParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_BarrierCommand_AcpTrak_typ;

typedef struct MC_BR_BarrierReadInfo_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McProcessPointType* ProcessPoint;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpTrakBarrierInfoType BarrierInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_BR_BarrierReadInfo_AcpTrak_typ;

typedef struct MC_BR_TrgPointGetInfo_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McProcessPointType* ProcessPoint;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpTrakTrgPointGetInfoType TrgPointInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_TrgPointGetInfo_AcpTrak_typ;

typedef struct MC_BR_TrgPointEnable_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McProcessPointType* ProcessPoint;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	unsigned short EventCount;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_BR_TrgPointEnable_AcpTrak_typ;

typedef struct MC_BR_SecAddShuttle_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McSectorType* Sector;
	double Position;
	struct McAcpTrakAdvSecAddShParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAxisType Axis;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_SecAddShuttle_AcpTrak_typ;

typedef struct MC_BR_SecGetShuttle_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McSectorType* Sector;
	enum McAcpTrakSearchModeEnum Mode;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	unsigned short TotalCount;
	unsigned short RemainingCount;
	struct McAxisType Axis;
	struct McAcpTrakSecGetShAddInfoType AdditionalInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit Next;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_BR_SecGetShuttle_AcpTrak_typ;

typedef struct MC_BR_SecGetInfo_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McSectorType* Sector;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpTrakSecGetInfoType SectorInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_SecGetInfo_AcpTrak_typ;

typedef struct MC_BR_SegPowerOn_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McSegmentType* Segment;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_SegPowerOn_AcpTrak_typ;

typedef struct MC_BR_SegPowerOff_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McSegmentType* Segment;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_SegPowerOff_AcpTrak_typ;

typedef struct MC_BR_SegReset_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McSegmentType* Segment;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_SegReset_AcpTrak_typ;

typedef struct MC_BR_SegProcessParID_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McSegmentType* Segment;
	unsigned long DataAddress;
	unsigned long NumberOfParIDs;
	enum McAcpTrakSegProcessParIDModeEnum Mode;
	unsigned char ChannelIndex;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_SegProcessParID_AcpTrak_typ;

typedef struct MC_BR_RoutedMoveVel_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McSectorType* Sector;
	double Position;
	float Velocity;
	float RouteVelocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McBufferModeEnum BufferMode;
	struct McAcpTrakAdvRouteParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalTwoRefType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit InVelocity;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
	plcbit PositionReached;
} MC_BR_RoutedMoveVel_AcpTrak_typ;

typedef struct MC_BR_RoutedMoveAbs_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	struct McSectorType* Sector;
	double Position;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McBufferModeEnum BufferMode;
	struct McAcpTrakAdvRouteParType AdvancedParameters;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalTwoRefType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_RoutedMoveAbs_AcpTrak_typ;

typedef struct MC_BR_ElasticMoveAbs_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	double Position;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McBufferModeEnum BufferMode;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_ElasticMoveAbs_AcpTrak_typ;

typedef struct MC_BR_ElasticMoveAdd_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	double Distance;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McBufferModeEnum BufferMode;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_ElasticMoveAdd_AcpTrak_typ;

typedef struct MC_BR_ElasticMoveVel_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	float Velocity;
	float Acceleration;
	float Deceleration;
	float Jerk;
	enum McDirectionEnum Direction;
	enum McBufferModeEnum BufferMode;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit InVelocity;
	plcbit Busy;
	plcbit Active;
	plcbit CommandAborted;
	plcbit Error;
} MC_BR_ElasticMoveVel_AcpTrak_typ;

typedef struct MC_BR_SegReadStatus_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McSegmentType* Segment;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
	plcbit SegmentDisabled;
	plcbit SegmentReady;
	plcbit SegmentStopping;
	plcbit SegmentErrorStop;
} MC_BR_SegReadStatus_AcpTrak_typ;

typedef struct MC_BR_SegReadInfo_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McSegmentType* Segment;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpTrakSegInfoType SegmentInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_BR_SegReadInfo_AcpTrak_typ;

typedef struct MC_BR_ShReadInfo_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpTrakShInfoType ShuttleInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_BR_ShReadInfo_AcpTrak_typ;

typedef struct MC_BR_ShReadSegmentInfo_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McAcpTrakShSegmentInfoType SegmentInfo;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_BR_ShReadSegmentInfo_AcpTrak_typ;

typedef struct MC_BR_ShReadFrame_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	unsigned long CoordSystem;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	struct McFrameType Frame;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit Error;
} MC_BR_ShReadFrame_AcpTrak_typ;

typedef struct MC_BR_ShCopyUserData_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	unsigned long DataAddress;
	unsigned long DataSize;
	enum McAcpTrakCopyUserDataModeEnum Mode;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_ShCopyUserData_AcpTrak_typ;

typedef struct MC_BR_ShSelCtrlParSet_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McAcpTrakSelectShSideEnum Mode;
	unsigned char ParameterSetIndex;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_ShSelCtrlParSet_AcpTrak_typ;

typedef struct MC_BR_ShResize_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McAcpTrakShResizeCmdEnum Command;
	struct McAcpTrakShResizeParamType ResizeParameter;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_ShResize_AcpTrak_typ;

typedef struct MC_BR_ElasticMoveCycPos_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McIplModeEnum InterpolationMode;
	struct McAdvMoveCycParType AdvancedParameters;
	double CyclicPosition;
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit Valid;
	plcbit Busy;
	plcbit CommandAborted;
	plcbit Error;
	plcbit InCyclicPosition;
} MC_BR_ElasticMoveCycPos_AcpTrak_typ;

typedef struct MC_BR_ShCouplingObjCmd_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McAcpTrakCouplingObjCmdEnum Command;
	plcstring CouplingObjectName[33];
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_ShCouplingObjCmd_AcpTrak_typ;

typedef struct MC_BR_ShLocalLimitCmd_AcpTrak
{
	/* VAR_INPUT (analog) */
	struct McAxisType* Axis;
	enum McAcpTrakShLocalLimitCmdEnum Command;
	plcstring LocalLimitName[33];
	/* VAR_OUTPUT (analog) */
	signed long ErrorID;
	/* VAR (analog) */
	struct McInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} MC_BR_ShLocalLimitCmd_AcpTrak_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void MC_BR_SegCycChanSetPos_AcpTrak(struct MC_BR_SegCycChanSetPos_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_ShCreateConvoy_AcpTrak(struct MC_BR_ShCreateConvoy_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_AsmPowerOn_AcpTrak(struct MC_BR_AsmPowerOn_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_AsmPowerOff_AcpTrak(struct MC_BR_AsmPowerOff_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_AsmReadStatus_AcpTrak(struct MC_BR_AsmReadStatus_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_AsmReset_AcpTrak(struct MC_BR_AsmReset_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_AsmCommandError_AcpTrak(struct MC_BR_AsmCommandError_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_AsmGetShuttle_AcpTrak(struct MC_BR_AsmGetShuttle_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_AsmDeleteShuttle_AcpTrak(struct MC_BR_AsmDeleteShuttle_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_AsmReadInfo_AcpTrak(struct MC_BR_AsmReadInfo_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_AsmGetInfo_AcpTrak(struct MC_BR_AsmGetInfo_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_AsmGetMinShDist_AcpTrak(struct MC_BR_AsmGetMinShDist_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_BarrierCommand_AcpTrak(struct MC_BR_BarrierCommand_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_BarrierReadInfo_AcpTrak(struct MC_BR_BarrierReadInfo_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_TrgPointGetInfo_AcpTrak(struct MC_BR_TrgPointGetInfo_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_TrgPointEnable_AcpTrak(struct MC_BR_TrgPointEnable_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_SecAddShuttle_AcpTrak(struct MC_BR_SecAddShuttle_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_SecGetShuttle_AcpTrak(struct MC_BR_SecGetShuttle_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_SecGetInfo_AcpTrak(struct MC_BR_SecGetInfo_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_SegPowerOn_AcpTrak(struct MC_BR_SegPowerOn_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_SegPowerOff_AcpTrak(struct MC_BR_SegPowerOff_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_SegReset_AcpTrak(struct MC_BR_SegReset_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_SegProcessParID_AcpTrak(struct MC_BR_SegProcessParID_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_RoutedMoveVel_AcpTrak(struct MC_BR_RoutedMoveVel_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_RoutedMoveAbs_AcpTrak(struct MC_BR_RoutedMoveAbs_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_ElasticMoveAbs_AcpTrak(struct MC_BR_ElasticMoveAbs_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_ElasticMoveAdd_AcpTrak(struct MC_BR_ElasticMoveAdd_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_ElasticMoveVel_AcpTrak(struct MC_BR_ElasticMoveVel_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_SegReadStatus_AcpTrak(struct MC_BR_SegReadStatus_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_SegReadInfo_AcpTrak(struct MC_BR_SegReadInfo_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_ShReadInfo_AcpTrak(struct MC_BR_ShReadInfo_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_ShReadSegmentInfo_AcpTrak(struct MC_BR_ShReadSegmentInfo_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_ShReadFrame_AcpTrak(struct MC_BR_ShReadFrame_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_ShCopyUserData_AcpTrak(struct MC_BR_ShCopyUserData_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_ShSelCtrlParSet_AcpTrak(struct MC_BR_ShSelCtrlParSet_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_ShResize_AcpTrak(struct MC_BR_ShResize_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_ElasticMoveCycPos_AcpTrak(struct MC_BR_ElasticMoveCycPos_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_ShCouplingObjCmd_AcpTrak(struct MC_BR_ShCouplingObjCmd_AcpTrak* inst);
_BUR_PUBLIC void MC_BR_ShLocalLimitCmd_AcpTrak(struct MC_BR_ShLocalLimitCmd_AcpTrak* inst);
_BUR_PUBLIC unsigned short LLMInit(signed long sysInitPhase);


#ifdef __cplusplus
};
#endif
#endif /* _MCACPTRAK_ */

