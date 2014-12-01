
//----------------------------------------------------------------
//	© Thorlabs Limited.
//
//	FILE NAME       : APTAPI.h
//
//	AUTHOR          : Thorlabs Ltd, Ely, U.K.
//
//	CREATED         : 21-05-08
//
//	PLATFORM        : Win32
//
//	MODULE FUNCTION:-
//
//	Defines APT.DLL application programmers interface for accessing the APT system.
//	This interface can be included by C or C++ code.
//
//	RELATED DOCUMENTATION:-
//
//	NOTES:-
//
//----------------------------------------------------------------
//	MODIFICATION HISTORY:-
//
//	DATE			VERSION			AUTHOR
//
//	21-05-08		1.0.1			KAD
//
//	Initial implementation.
//
//	17-10-10		1.0.2			KAD
//
//	Brushless DC servo controller (BBD10X) support added.
//
//	22-04-12		1.0.3			KAD
//
//	L490MZ motorised labjack and LTS300/LTS150 long travel stage support added.
//
//	25-04-12		1.0.4			KAD
//
//	MOT_LLSetEncoderCount and MOT_LLGetEncoderCount exports added.
//
//----------------------------------------------------------------

//#include <Windows.h>	// This may need uncommenting in some environments.

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */


// >>>>>>>>>>>>>>>>> MACRO DEFINITIONS <<<<<<<<<<<<<<<<<<

// lHWType definitions - used with GetNumHWUnitsEx & GetHWSerialNumEx.
#define HWTYPE_BSC001		11	// 1 Ch benchtop stepper driver
#define HWTYPE_BSC101		12	// 1 Ch benchtop stepper driver
#define HWTYPE_BSC002		13	// 2 Ch benchtop stepper driver
#define HWTYPE_BDC101		14	// 1 Ch benchtop DC servo driver
#define HWTYPE_SCC001		21	// 1 Ch stepper driver card (used within BSC102,103 units)
#define HWTYPE_DCC001		22	// 1 Ch DC servo driver card (used within BDC102,103 units)
#define HWTYPE_ODC001		24	// 1 Ch DC servo driver cube
#define HWTYPE_OST001		25	// 1 Ch stepper driver cube
#define HWTYPE_MST601		26	// 2 Ch modular stepper driver module
#define HWTYPE_TST001		29	// 1 Ch Stepper driver T-Cube
#define HWTYPE_TDC001		31	// 1 Ch DC servo driver T-Cube
#define HWTYPE_LTSXXX		42	// LTS300/LTS150 Long Travel Integrated Driver/Stages
#define HWTYPE_L490MZ		43	// L490MZ Integrated Driver/Labjack
#define HWTYPE_BBD10X		44	// 1/2/3 Ch benchtop brushless DC servo driver

// Channel idents - used with MOT_SetChannel.
#define CHAN1_INDEX			0		// Channel 1.
#define CHAN2_INDEX			1		// Channel 2.

// Home direction (lDirection) - used with MOT_Set(Get)HomeParams.
#define HOME_FWD			1		// Home in the forward direction.
#define HOME_REV			2		// Home in the reverse direction.

// Home limit switch (lLimSwitch) - used with MOT_Set(Get)HomeParams.
#define HOMELIMSW_FWD		4		// Use forward limit switch for home datum.
#define HOMELIMSW_REV		1		// Use reverse limit switch for home datum.

// Stage units (lUnits) - used with MOT_Set(Get)StageAxisInfo.
#define STAGE_UNITS_MM		1		// Stage units are in mm.
#define STAGE_UNITS_DEG		2		// Stage units are in degrees.

// Hardware limit switch settings (lRevLimSwitch, lFwdLimSwitch) - used with MOT_Set(Get)HWLimSwitches
#define HWLIMSWITCH_IGNORE				1		// Ignore limit switch (e.g. for stages with only one or no limit switches).
#define HWLIMSWITCH_MAKES				2		// Limit switch is activated when electrical continuity is detected.
#define HWLIMSWITCH_BREAKS				3		// Limit switch is activated when electrical continuity is broken.
#define HWLIMSWITCH_MAKES_HOMEONLY		4		// As per HWLIMSWITCH_MAKES except switch is ignored other than when homing (e.g. to support rotation stages).
#define HWLIMSWITCH_BREAKS_HOMEONLY		5		// As per HWLIMSWITCH_BREAKS except switch is ignored other than when homing (e.g. to support rotation stages).

// Move direction (lDirection) - used with MOT_MoveVelocity.
#define MOVE_FWD			1		// Move forward.
#define MOVE_REV			2		// Move reverse.

// Profile mode settings - used with MOT_Set(Get)DCProfileModeParams.
#define DC_PROFILEMODE_TRAPEZOIDAL		0
#define DC_PROFILEMODE_SCURVE			2

// Joystick direction sense settings - used with MOT_Set(Get)DCJoystickParams.
#define DC_JS_DIRSENSE_POS			1
#define DC_JS_DIRSENSE_NEG			2

// >>>>>>>>>>>>>>>>> EXPORTED FUNCTIONS <<<<<<<<<<<<<<<<<<

// System Level Exports.
long WINAPI APTInit(void);
long WINAPI APTCleanUp(void);
long WINAPI GetNumHWUnitsEx(long lHWType, long *plNumUnits);
long WINAPI GetHWSerialNumEx(long lHWType, long lIndex, long *plSerialNum);
long WINAPI GetHWInfo(long lSerialNum, TCHAR *szModel, long lModelLen, TCHAR *szSWVer, long lSWVerLen, TCHAR *szHWNotes, long lHWNotesLen);
long WINAPI InitHWDevice(long lSerialNum);
long WINAPI EnableEventDlg(BOOL bEnable);

// Low Level Motor Specific Exports.
long WINAPI MOT_LLSetEncoderCount(long lSerialNum, long lEncCount);
long WINAPI MOT_LLGetEncoderCount(long lSerialNum, long *plEncCount);

// Motor Specific Exports.
long WINAPI MOT_SetChannel(long lSerialNum, long lChanID);
long WINAPI MOT_Identify(long lSerialNum);
long WINAPI MOT_EnableHWChannel(long lSerialNum);
long WINAPI MOT_DisableHWChannel(long lSerialNum);
long WINAPI MOT_SetVelParams(long lSerialNum, float fMinVel, float fAccn, float fMaxVel);
long WINAPI MOT_GetVelParams(long lSerialNum, float *pfMinVel, float *pfAccn, float *pfMaxVel);
long WINAPI MOT_GetVelParamLimits(long lSerialNum, float *pfMaxAccn, float *pfMaxVel);
long WINAPI MOT_SetHomeParams(long lSerialNum, long lDirection, long lLimSwitch, float fHomeVel, float fZeroOffset);
long WINAPI MOT_GetHomeParams(long lSerialNum, long *plDirection, long *plLimSwitch, float *pfHomeVel, float *pfZeroOffset);
long WINAPI MOT_GetStatusBits(long lSerialNum, long *plStatusBits);

long WINAPI MOT_SetBLashDist(long lSerialNum, float fBLashDist);
long WINAPI MOT_GetBLashDist(long lSerialNum, float *pfBLashDist);
long WINAPI MOT_SetMotorParams(long lSerialNum, long lStepsPerRev, long lGearBoxRatio);
long WINAPI MOT_GetMotorParams(long lSerialNum, long *plStepsPerRev, long *plGearBoxRatio);
long WINAPI MOT_SetStageAxisInfo(long lSerialNum, float fMinPos, float fMaxPos, long lUnits, float fPitch);
long WINAPI MOT_GetStageAxisInfo(long lSerialNum, float *pfMinPos, float *pfMaxPos, long *plUnits, float *pfPitch);
long WINAPI MOT_SetHWLimSwitches(long lSerialNum, long lRevLimSwitch, long lFwdLimSwitch);
long WINAPI MOT_GetHWLimSwitches(long lSerialNum, long *plRevLimSwitch, long *plFwdLimSwitch);
long WINAPI MOT_SetPIDParams(long lSerialNum, long lProp, long lInt, long lDeriv, long lIntLimit);
long WINAPI MOT_GetPIDParams(long lSerialNum, long *plProp, long *plInt, long *plDeriv, long *plIntLimit);

long WINAPI MOT_GetPosition(long lSerialNum, float *pfPosition);
long WINAPI MOT_MoveHome(long lSerialNum, BOOL bWait);
long WINAPI MOT_MoveRelativeEx(long lSerialNum, float fRelDist, BOOL bWait);
long WINAPI MOT_MoveAbsoluteEx(long lSerialNum, float fAbsPos, BOOL bWait);
long WINAPI MOT_MoveVelocity(long lSerialNum, long lDirection);
long WINAPI MOT_StopProfiled(long lSerialNum);

// Brushless DC Servo Specific Exports.
long WINAPI MOT_SetDCCurrentLoopParams(long lSerialNum, long lProp, long lInt, long lIntLim, long lIntDeadBand, long lFFwd);
long WINAPI MOT_GetDCCurrentLoopParams(long lSerialNum, long *plProp, long *plInt, long *plIntLim, long *plIntDeadBand, long *plFFwd);
long WINAPI MOT_SetDCPositionLoopParams(long lSerialNum, long lProp, long lInt, long lIntLim, long lDeriv, long lDerivTime, long lLoopGain, long lVelFFwd, long lAccFFwd, long lPosErrLim);
long WINAPI MOT_GetDCPositionLoopParams(long lSerialNum, long *plProp, long *plInt, long *plIntLim, long *plDeriv, long *plDerivTime, long *plLoopGain, long *plVelFFwd, long *plAccFFwd, long *plPosErrLim);
long WINAPI MOT_SetDCMotorOutputParams(long lSerialNum, float fContCurrLim, float fEnergyLim, float fMotorLim, float fMotorBias);
long WINAPI MOT_GetDCMotorOutputParams(long lSerialNum,  float *pfContCurrLim, float *pfEnergyLim, float *pfMotorLim, float *pfMotorBias);
long WINAPI MOT_SetDCTrackSettleParams(long lSerialNum, long lSettleTime, long lSettleWnd, long lTrackWnd);
long WINAPI MOT_GetDCTrackSettleParams(long lSerialNum, long *plSettleTime, long *plSettleWnd, long *plTrackWnd);
long WINAPI MOT_SetDCProfileModeParams(long lSerialNum, long lProfMode, float fJerk);
long WINAPI MOT_GetDCProfileModeParams(long lSerialNum, long *plProfMode,float *pfJerk);
long WINAPI MOT_SetDCJoystickParams(long lSerialNum, float fMaxVelLO, float fMaxVelHI, float fAccnLO, float fAccnHI, long lDirSense);
long WINAPI MOT_GetDCJoystickParams(long lSerialNum, float *pfMaxVelLO, float *pfMaxVelHI, float *pfAccnLO, float *pfAccnHI, long *plDirSense);
long WINAPI MOT_SetDCSettledCurrentLoopParams(long lSerialNum, long lSettledProp, long lSettledInt, long lSettledIntLim, long lSettledIntDeadBand, long lSettledFFwd);
long WINAPI MOT_GetDCSettledCurrentLoopParams(long lSerialNum, long *plSettledProp, long *plSettledInt, long *plSettledIntLim, long *plSettledIntDeadBand, long *plSettledFFwd);

#ifdef __cplusplus
}
#endif
