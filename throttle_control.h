//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: throttle_control.h
//
// Code generated for Simulink model 'throttle_control'.
//
// Model version                  : 1.29
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Tue May 25 22:41:50 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_throttle_control_h_
#define RTW_HEADER_throttle_control_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "throttle_control_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block signals (default storage)
struct B_throttle_control_T {
  SL_Bus_throttle_control_steer_avcontrol BusAssignment;// '<S5>/Bus Assignment' 
  SL_Bus_throttle_control_geometry_msgs_Twist In1;// '<S107>/In1'
  SL_Bus_throttle_control_geometry_msgs_Twist In1_c;// '<S106>/In1'
  SL_Bus_throttle_control_geometry_msgs_Twist b_varargout_2;
  SL_Bus_throttle_control_ros_time_Time r;
  real_T Switch;                       // '<S30>/Switch'
  real_T ProportionalGain;             // '<S44>/Proportional Gain'
  real_T DerivativeGain;               // '<S33>/Derivative Gain'
  real_T FilterCoefficient;            // '<S42>/Filter Coefficient'
  real_T ProportionalGain_e;           // '<S94>/Proportional Gain'
  real_T DerivativeGain_c;             // '<S83>/Derivative Gain'
  real_T FilterCoefficient_k;          // '<S92>/Filter Coefficient'
  real_T Switch_m;                     // '<S80>/Switch'
  int8_T DataTypeConv2;                // '<S30>/DataTypeConv2'
  int8_T DataTypeConv2_h;              // '<S80>/DataTypeConv2'
  boolean_T AND3;                      // '<S30>/AND3'
  boolean_T AND3_g;                    // '<S80>/AND3'
};

// Block states (default storage) for system '<Root>'
struct DW_throttle_control_T {
  ros_slros_internal_block_Curr_T obj; // '<Root>/Current Time'
  ros_slroscpp_internal_block_S_T obj_o;// '<S4>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_h;// '<S3>/SourceBlock'
  ros_slroscpp_internal_block_P_T obj_ox;// '<S110>/SinkBlock'
  boolean_T Memory_PreviousInput;      // '<S30>/Memory'
  boolean_T Memory_PreviousInput_a;    // '<S80>/Memory'
};

// Continuous states (default storage)
struct X_throttle_control_T {
  real_T Integrator_CSTATE;            // '<S39>/Integrator'
  real_T Filter_CSTATE;                // '<S34>/Filter'
  real_T Integrator_CSTATE_m;          // '<S89>/Integrator'
  real_T Filter_CSTATE_n;              // '<S84>/Filter'
};

// State derivatives (default storage)
struct XDot_throttle_control_T {
  real_T Integrator_CSTATE;            // '<S39>/Integrator'
  real_T Filter_CSTATE;                // '<S34>/Filter'
  real_T Integrator_CSTATE_m;          // '<S89>/Integrator'
  real_T Filter_CSTATE_n;              // '<S84>/Filter'
};

// State disabled
struct XDis_throttle_control_T {
  boolean_T Integrator_CSTATE;         // '<S39>/Integrator'
  boolean_T Filter_CSTATE;             // '<S34>/Filter'
  boolean_T Integrator_CSTATE_m;       // '<S89>/Integrator'
  boolean_T Filter_CSTATE_n;           // '<S84>/Filter'
};

// Zero-crossing (trigger) state
struct PrevZCX_throttle_control_T {
  ZCSigState Subsystem_Trig_ZCE;       // '<Root>/Subsystem'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_throttle_control_T_ {
  real_T PIDController1_D;             // Mask Parameter: PIDController1_D
                                          //  Referenced by: '<S33>/Derivative Gain'

  real_T SlowdownController1_D;        // Mask Parameter: SlowdownController1_D
                                          //  Referenced by: '<S83>/Derivative Gain'

  real_T PIDController1_I;             // Mask Parameter: PIDController1_I
                                          //  Referenced by: '<S36>/Integral Gain'

  real_T SlowdownController1_I;        // Mask Parameter: SlowdownController1_I
                                          //  Referenced by: '<S86>/Integral Gain'

  real_T PIDController1_InitialCondition;
                              // Mask Parameter: PIDController1_InitialCondition
                                 //  Referenced by: '<S34>/Filter'

  real_T SlowdownController1_InitialCond;
                              // Mask Parameter: SlowdownController1_InitialCond
                                 //  Referenced by: '<S84>/Filter'

  real_T PIDController1_InitialConditi_m;
                              // Mask Parameter: PIDController1_InitialConditi_m
                                 //  Referenced by: '<S39>/Integrator'

  real_T SlowdownController1_InitialCo_m;
                              // Mask Parameter: SlowdownController1_InitialCo_m
                                 //  Referenced by: '<S89>/Integrator'

  real_T PIDController1_LowerSaturationL;
                              // Mask Parameter: PIDController1_LowerSaturationL
                                 //  Referenced by:
                                 //    '<S46>/Saturation'
                                 //    '<S32>/DeadZone'

  real_T SlowdownController1_LowerSatura;
                              // Mask Parameter: SlowdownController1_LowerSatura
                                 //  Referenced by:
                                 //    '<S96>/Saturation'
                                 //    '<S82>/DeadZone'

  real_T PIDController1_N;             // Mask Parameter: PIDController1_N
                                          //  Referenced by: '<S42>/Filter Coefficient'

  real_T SlowdownController1_N;        // Mask Parameter: SlowdownController1_N
                                          //  Referenced by: '<S92>/Filter Coefficient'

  real_T PIDController1_P;             // Mask Parameter: PIDController1_P
                                          //  Referenced by: '<S44>/Proportional Gain'

  real_T SlowdownController1_P;        // Mask Parameter: SlowdownController1_P
                                          //  Referenced by: '<S94>/Proportional Gain'

  real_T PIDController1_UpperSaturationL;
                              // Mask Parameter: PIDController1_UpperSaturationL
                                 //  Referenced by:
                                 //    '<S46>/Saturation'
                                 //    '<S32>/DeadZone'

  real_T SlowdownController1_UpperSatura;
                              // Mask Parameter: SlowdownController1_UpperSatura
                                 //  Referenced by:
                                 //    '<S96>/Saturation'
                                 //    '<S82>/DeadZone'

  SL_Bus_throttle_control_steer_avcontrol Constant_Value;// Computed Parameter: Constant_Value
                                                            //  Referenced by: '<S108>/Constant'

  SL_Bus_throttle_control_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                         //  Referenced by: '<S106>/Out1'

  SL_Bus_throttle_control_geometry_msgs_Twist Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                                  //  Referenced by: '<S3>/Constant'

  SL_Bus_throttle_control_geometry_msgs_Twist Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                                           //  Referenced by: '<S107>/Out1'

  SL_Bus_throttle_control_geometry_msgs_Twist Constant_Value_hj;// Computed Parameter: Constant_Value_hj
                                                                   //  Referenced by: '<S4>/Constant'

  real_T Saturation2_UpperSat;         // Expression: 1
                                          //  Referenced by: '<Root>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: 0
                                          //  Referenced by: '<Root>/Saturation2'

  real_T Saturation1_UpperSat;         // Expression: 1
                                          //  Referenced by: '<Root>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: 0
                                          //  Referenced by: '<Root>/Saturation1'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S30>/Constant1'

  real_T Constant1_Value_n;            // Expression: 0
                                          //  Referenced by: '<S80>/Constant1'

  real_T ZeroGain_Gain;                // Expression: 0
                                          //  Referenced by: '<S30>/ZeroGain'

  real_T Constant_Value_c;             // Expression: 0.0
                                          //  Referenced by: '<Root>/Constant'

  real_T Switch_Threshold;             // Expression: 0.05
                                          //  Referenced by: '<Root>/Switch'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -1
                                          //  Referenced by: '<Root>/Saturation'

  real_T Constant1_Value_h;            // Expression: 1
                                          //  Referenced by: '<Root>/Constant1'

  real_T Switch1_Threshold;            // Expression: 0.05
                                          //  Referenced by: '<Root>/Switch1'

  real_T Gain_Gain;                    // Expression: 1e-9
                                          //  Referenced by: '<Root>/Gain'

  real_T SquareWaveGenerator_Amplitude;// Expression: 1
                                          //  Referenced by: '<Root>/Square Wave Generator'

  real_T SquareWaveGenerator_Frequency;// Expression: 100
                                          //  Referenced by: '<Root>/Square Wave Generator'

  real_T ZeroGain_Gain_p;              // Expression: 0
                                          //  Referenced by: '<S80>/ZeroGain'

  boolean_T Memory_InitialCondition;
                                  // Computed Parameter: Memory_InitialCondition
                                     //  Referenced by: '<S30>/Memory'

  boolean_T Memory_InitialCondition_d;
                                // Computed Parameter: Memory_InitialCondition_d
                                   //  Referenced by: '<S80>/Memory'

};

// Real-time Model Data Structure
struct tag_RTM_throttle_control_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_throttle_control_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_throttle_control_T throttle_control_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_throttle_control_T throttle_control_B;

#ifdef __cplusplus

}
#endif

// Continuous states (default storage)
extern X_throttle_control_T throttle_control_X;

// Block states (default storage)
extern struct DW_throttle_control_T throttle_control_DW;

// Zero-crossing (trigger) state
extern PrevZCX_throttle_control_T throttle_control_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void throttle_control_initialize(void);
  extern void throttle_control_step(void);
  extern void throttle_control_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_throttle_control_T *const throttle_control_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'throttle_control'
//  '<S1>'   : 'throttle_control/PID Controller1'
//  '<S2>'   : 'throttle_control/Slowdown Controller1'
//  '<S3>'   : 'throttle_control/Subscribe'
//  '<S4>'   : 'throttle_control/Subscribe1'
//  '<S5>'   : 'throttle_control/Subsystem'
//  '<S6>'   : 'throttle_control/PID Controller1/Anti-windup'
//  '<S7>'   : 'throttle_control/PID Controller1/D Gain'
//  '<S8>'   : 'throttle_control/PID Controller1/Filter'
//  '<S9>'   : 'throttle_control/PID Controller1/Filter ICs'
//  '<S10>'  : 'throttle_control/PID Controller1/I Gain'
//  '<S11>'  : 'throttle_control/PID Controller1/Ideal P Gain'
//  '<S12>'  : 'throttle_control/PID Controller1/Ideal P Gain Fdbk'
//  '<S13>'  : 'throttle_control/PID Controller1/Integrator'
//  '<S14>'  : 'throttle_control/PID Controller1/Integrator ICs'
//  '<S15>'  : 'throttle_control/PID Controller1/N Copy'
//  '<S16>'  : 'throttle_control/PID Controller1/N Gain'
//  '<S17>'  : 'throttle_control/PID Controller1/P Copy'
//  '<S18>'  : 'throttle_control/PID Controller1/Parallel P Gain'
//  '<S19>'  : 'throttle_control/PID Controller1/Reset Signal'
//  '<S20>'  : 'throttle_control/PID Controller1/Saturation'
//  '<S21>'  : 'throttle_control/PID Controller1/Saturation Fdbk'
//  '<S22>'  : 'throttle_control/PID Controller1/Sum'
//  '<S23>'  : 'throttle_control/PID Controller1/Sum Fdbk'
//  '<S24>'  : 'throttle_control/PID Controller1/Tracking Mode'
//  '<S25>'  : 'throttle_control/PID Controller1/Tracking Mode Sum'
//  '<S26>'  : 'throttle_control/PID Controller1/Tsamp - Integral'
//  '<S27>'  : 'throttle_control/PID Controller1/Tsamp - Ngain'
//  '<S28>'  : 'throttle_control/PID Controller1/postSat Signal'
//  '<S29>'  : 'throttle_control/PID Controller1/preSat Signal'
//  '<S30>'  : 'throttle_control/PID Controller1/Anti-windup/Cont. Clamping Parallel'
//  '<S31>'  : 'throttle_control/PID Controller1/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S32>'  : 'throttle_control/PID Controller1/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S33>'  : 'throttle_control/PID Controller1/D Gain/Internal Parameters'
//  '<S34>'  : 'throttle_control/PID Controller1/Filter/Cont. Filter'
//  '<S35>'  : 'throttle_control/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S36>'  : 'throttle_control/PID Controller1/I Gain/Internal Parameters'
//  '<S37>'  : 'throttle_control/PID Controller1/Ideal P Gain/Passthrough'
//  '<S38>'  : 'throttle_control/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S39>'  : 'throttle_control/PID Controller1/Integrator/Continuous'
//  '<S40>'  : 'throttle_control/PID Controller1/Integrator ICs/Internal IC'
//  '<S41>'  : 'throttle_control/PID Controller1/N Copy/Disabled'
//  '<S42>'  : 'throttle_control/PID Controller1/N Gain/Internal Parameters'
//  '<S43>'  : 'throttle_control/PID Controller1/P Copy/Disabled'
//  '<S44>'  : 'throttle_control/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S45>'  : 'throttle_control/PID Controller1/Reset Signal/Disabled'
//  '<S46>'  : 'throttle_control/PID Controller1/Saturation/Enabled'
//  '<S47>'  : 'throttle_control/PID Controller1/Saturation Fdbk/Disabled'
//  '<S48>'  : 'throttle_control/PID Controller1/Sum/Sum_PID'
//  '<S49>'  : 'throttle_control/PID Controller1/Sum Fdbk/Disabled'
//  '<S50>'  : 'throttle_control/PID Controller1/Tracking Mode/Disabled'
//  '<S51>'  : 'throttle_control/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S52>'  : 'throttle_control/PID Controller1/Tsamp - Integral/Passthrough'
//  '<S53>'  : 'throttle_control/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S54>'  : 'throttle_control/PID Controller1/postSat Signal/Forward_Path'
//  '<S55>'  : 'throttle_control/PID Controller1/preSat Signal/Forward_Path'
//  '<S56>'  : 'throttle_control/Slowdown Controller1/Anti-windup'
//  '<S57>'  : 'throttle_control/Slowdown Controller1/D Gain'
//  '<S58>'  : 'throttle_control/Slowdown Controller1/Filter'
//  '<S59>'  : 'throttle_control/Slowdown Controller1/Filter ICs'
//  '<S60>'  : 'throttle_control/Slowdown Controller1/I Gain'
//  '<S61>'  : 'throttle_control/Slowdown Controller1/Ideal P Gain'
//  '<S62>'  : 'throttle_control/Slowdown Controller1/Ideal P Gain Fdbk'
//  '<S63>'  : 'throttle_control/Slowdown Controller1/Integrator'
//  '<S64>'  : 'throttle_control/Slowdown Controller1/Integrator ICs'
//  '<S65>'  : 'throttle_control/Slowdown Controller1/N Copy'
//  '<S66>'  : 'throttle_control/Slowdown Controller1/N Gain'
//  '<S67>'  : 'throttle_control/Slowdown Controller1/P Copy'
//  '<S68>'  : 'throttle_control/Slowdown Controller1/Parallel P Gain'
//  '<S69>'  : 'throttle_control/Slowdown Controller1/Reset Signal'
//  '<S70>'  : 'throttle_control/Slowdown Controller1/Saturation'
//  '<S71>'  : 'throttle_control/Slowdown Controller1/Saturation Fdbk'
//  '<S72>'  : 'throttle_control/Slowdown Controller1/Sum'
//  '<S73>'  : 'throttle_control/Slowdown Controller1/Sum Fdbk'
//  '<S74>'  : 'throttle_control/Slowdown Controller1/Tracking Mode'
//  '<S75>'  : 'throttle_control/Slowdown Controller1/Tracking Mode Sum'
//  '<S76>'  : 'throttle_control/Slowdown Controller1/Tsamp - Integral'
//  '<S77>'  : 'throttle_control/Slowdown Controller1/Tsamp - Ngain'
//  '<S78>'  : 'throttle_control/Slowdown Controller1/postSat Signal'
//  '<S79>'  : 'throttle_control/Slowdown Controller1/preSat Signal'
//  '<S80>'  : 'throttle_control/Slowdown Controller1/Anti-windup/Cont. Clamping Parallel'
//  '<S81>'  : 'throttle_control/Slowdown Controller1/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S82>'  : 'throttle_control/Slowdown Controller1/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S83>'  : 'throttle_control/Slowdown Controller1/D Gain/Internal Parameters'
//  '<S84>'  : 'throttle_control/Slowdown Controller1/Filter/Cont. Filter'
//  '<S85>'  : 'throttle_control/Slowdown Controller1/Filter ICs/Internal IC - Filter'
//  '<S86>'  : 'throttle_control/Slowdown Controller1/I Gain/Internal Parameters'
//  '<S87>'  : 'throttle_control/Slowdown Controller1/Ideal P Gain/Passthrough'
//  '<S88>'  : 'throttle_control/Slowdown Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S89>'  : 'throttle_control/Slowdown Controller1/Integrator/Continuous'
//  '<S90>'  : 'throttle_control/Slowdown Controller1/Integrator ICs/Internal IC'
//  '<S91>'  : 'throttle_control/Slowdown Controller1/N Copy/Disabled'
//  '<S92>'  : 'throttle_control/Slowdown Controller1/N Gain/Internal Parameters'
//  '<S93>'  : 'throttle_control/Slowdown Controller1/P Copy/Disabled'
//  '<S94>'  : 'throttle_control/Slowdown Controller1/Parallel P Gain/Internal Parameters'
//  '<S95>'  : 'throttle_control/Slowdown Controller1/Reset Signal/Disabled'
//  '<S96>'  : 'throttle_control/Slowdown Controller1/Saturation/Enabled'
//  '<S97>'  : 'throttle_control/Slowdown Controller1/Saturation Fdbk/Disabled'
//  '<S98>'  : 'throttle_control/Slowdown Controller1/Sum/Sum_PID'
//  '<S99>'  : 'throttle_control/Slowdown Controller1/Sum Fdbk/Disabled'
//  '<S100>' : 'throttle_control/Slowdown Controller1/Tracking Mode/Disabled'
//  '<S101>' : 'throttle_control/Slowdown Controller1/Tracking Mode Sum/Passthrough'
//  '<S102>' : 'throttle_control/Slowdown Controller1/Tsamp - Integral/Passthrough'
//  '<S103>' : 'throttle_control/Slowdown Controller1/Tsamp - Ngain/Passthrough'
//  '<S104>' : 'throttle_control/Slowdown Controller1/postSat Signal/Forward_Path'
//  '<S105>' : 'throttle_control/Slowdown Controller1/preSat Signal/Forward_Path'
//  '<S106>' : 'throttle_control/Subscribe/Enabled Subsystem'
//  '<S107>' : 'throttle_control/Subscribe1/Enabled Subsystem'
//  '<S108>' : 'throttle_control/Subsystem/Blank Message'
//  '<S109>' : 'throttle_control/Subsystem/MATLAB Function'
//  '<S110>' : 'throttle_control/Subsystem/Publish'

#endif                                 // RTW_HEADER_throttle_control_h_

//
// File trailer for generated code.
//
// [EOF]
//
