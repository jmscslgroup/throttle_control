//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: throttle_control.cpp
//
// Code generated for Simulink model 'throttle_control'.
//
// Model version                  : 1.41
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Jul 19 23:03:07 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "throttle_control.h"
#include "throttle_control_private.h"

// Block signals (default storage)
B_throttle_control_T throttle_control_B;

// Continuous states
X_throttle_control_T throttle_control_X;

// Block states (default storage)
DW_throttle_control_T throttle_control_DW;

// Previous zero-crossings (trigger) states
PrevZCX_throttle_control_T throttle_control_PrevZCX;

// Real-time model
RT_MODEL_throttle_control_T throttle_control_M_ = RT_MODEL_throttle_control_T();
RT_MODEL_throttle_control_T *const throttle_control_M = &throttle_control_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  throttle_control_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  throttle_control_step();
  throttle_control_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  throttle_control_step();
  throttle_control_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void throttle_control_step(void)
{
  real_T Switch1;
  real_T rtb_Gain;
  real_T rtb_IntegralGain;
  real_T rtb_Saturation_i;
  real_T rtb_Sum;
  real_T rtb_Sum6;
  real_T temp;
  boolean_T b_varargout_1;
  ZCEventType zcEvent;
  if (rtmIsMajorTimeStep(throttle_control_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&throttle_control_M->solverInfo,
                          ((throttle_control_M->Timing.clockTick0+1)*
      throttle_control_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(throttle_control_M)) {
    throttle_control_M->Timing.t[0] = rtsiGetT(&throttle_control_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(throttle_control_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S4>/SourceBlock' incorporates:
    //   Inport: '<S107>/In1'

    b_varargout_1 = Sub_throttle_control_45.getLatestMessage
      (&throttle_control_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S107>/Enable'

    if (b_varargout_1) {
      throttle_control_B.In1 = throttle_control_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S4>/SourceBlock'
    // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S3>/SourceBlock' incorporates:
    //   Inport: '<S106>/In1'

    b_varargout_1 = Sub_throttle_control_38.getLatestMessage
      (&throttle_control_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S106>/Enable'

    if (b_varargout_1) {
      throttle_control_B.In1_c = throttle_control_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S3>/SourceBlock'
    // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // Sum: '<Root>/Sum6' incorporates:
    //   Math: '<Root>/Square'
    //   Math: '<Root>/Square1'
    //   Sqrt: '<Root>/Square Root'
    //   Sum: '<Root>/Add'

    rtb_Sum6 = throttle_control_B.In1.Linear.X - sqrt
      (throttle_control_B.In1_c.Linear.X * throttle_control_B.In1_c.Linear.X +
       throttle_control_B.In1_c.Linear.Y * throttle_control_B.In1_c.Linear.Y);

    // Gain: '<S36>/Integral Gain'
    rtb_IntegralGain = throttle_control_P.PIDController1_I * rtb_Sum6;

    // Switch: '<S30>/Switch' incorporates:
    //   Memory: '<S30>/Memory'

    if (throttle_control_DW.Memory_PreviousInput) {
      // Switch: '<S30>/Switch' incorporates:
      //   Constant: '<S30>/Constant1'

      throttle_control_B.Switch = throttle_control_P.Constant1_Value;
    } else {
      // Switch: '<S30>/Switch'
      throttle_control_B.Switch = rtb_IntegralGain;
    }

    // End of Switch: '<S30>/Switch'

    // Signum: '<S30>/SignPreIntegrator'
    if (rtb_IntegralGain < 0.0) {
      rtb_IntegralGain = -1.0;
    } else if (rtb_IntegralGain > 0.0) {
      rtb_IntegralGain = 1.0;
    } else if (rtb_IntegralGain == 0.0) {
      rtb_IntegralGain = 0.0;
    } else {
      rtb_IntegralGain = (rtNaN);
    }

    // End of Signum: '<S30>/SignPreIntegrator'

    // DataTypeConversion: '<S30>/DataTypeConv2'
    if (rtIsNaN(rtb_IntegralGain)) {
      Switch1 = 0.0;
    } else {
      Switch1 = fmod(rtb_IntegralGain, 256.0);
    }

    // DataTypeConversion: '<S30>/DataTypeConv2'
    throttle_control_B.DataTypeConv2 = static_cast<int8_T>(Switch1 < 0.0 ?
      static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
      (static_cast<uint8_T>(-Switch1)))) : static_cast<int32_T>
      (static_cast<int8_T>(static_cast<uint8_T>(Switch1))));

    // Gain: '<S44>/Proportional Gain'
    throttle_control_B.ProportionalGain = throttle_control_P.PIDController1_P *
      rtb_Sum6;

    // Gain: '<S33>/Derivative Gain'
    throttle_control_B.DerivativeGain = throttle_control_P.PIDController1_D *
      rtb_Sum6;
  }

  // Gain: '<S42>/Filter Coefficient' incorporates:
  //   Integrator: '<S34>/Filter'
  //   Sum: '<S34>/SumD'

  throttle_control_B.FilterCoefficient = (throttle_control_B.DerivativeGain -
    throttle_control_X.Filter_CSTATE) * throttle_control_P.PIDController1_N;

  // Sum: '<S48>/Sum' incorporates:
  //   Integrator: '<S39>/Integrator'

  rtb_Sum = (throttle_control_B.ProportionalGain +
             throttle_control_X.Integrator_CSTATE) +
    throttle_control_B.FilterCoefficient;

  // DeadZone: '<S32>/DeadZone'
  if (rtb_Sum > throttle_control_P.PIDController1_UpperSaturationL) {
    rtb_Gain = rtb_Sum - throttle_control_P.PIDController1_UpperSaturationL;
  } else if (rtb_Sum >= throttle_control_P.PIDController1_LowerSaturationL) {
    rtb_Gain = 0.0;
  } else {
    rtb_Gain = rtb_Sum - throttle_control_P.PIDController1_LowerSaturationL;
  }

  // End of DeadZone: '<S32>/DeadZone'

  // Signum: '<S30>/SignPreSat'
  if (rtb_Gain < 0.0) {
    // DataTypeConversion: '<S30>/DataTypeConv1'
    Switch1 = -1.0;
  } else if (rtb_Gain > 0.0) {
    // DataTypeConversion: '<S30>/DataTypeConv1'
    Switch1 = 1.0;
  } else if (rtb_Gain == 0.0) {
    // DataTypeConversion: '<S30>/DataTypeConv1'
    Switch1 = 0.0;
  } else {
    // DataTypeConversion: '<S30>/DataTypeConv1'
    Switch1 = (rtNaN);
  }

  // End of Signum: '<S30>/SignPreSat'

  // DataTypeConversion: '<S30>/DataTypeConv1'
  if (rtIsNaN(Switch1)) {
    Switch1 = 0.0;
  } else {
    Switch1 = fmod(Switch1, 256.0);
  }

  // Logic: '<S30>/AND3' incorporates:
  //   DataTypeConversion: '<S30>/DataTypeConv1'
  //   Gain: '<S30>/ZeroGain'
  //   RelationalOperator: '<S30>/Equal1'
  //   RelationalOperator: '<S30>/NotEqual'

  throttle_control_B.AND3 = ((throttle_control_P.ZeroGain_Gain * rtb_Sum !=
    rtb_Gain) && ((Switch1 < 0.0 ? static_cast<int32_T>(static_cast<int8_T>(-
    static_cast<int8_T>(static_cast<uint8_T>(-Switch1)))) : static_cast<int32_T>
                   (static_cast<int8_T>(static_cast<uint8_T>(Switch1)))) ==
                  throttle_control_B.DataTypeConv2));

  // Switch: '<Root>/Switch'
  if (throttle_control_B.In1.Linear.X > throttle_control_P.Switch_Threshold) {
    // Saturate: '<S46>/Saturation'
    if (rtb_Sum > throttle_control_P.PIDController1_UpperSaturationL) {
      rtb_Sum = throttle_control_P.PIDController1_UpperSaturationL;
    } else if (rtb_Sum < throttle_control_P.PIDController1_LowerSaturationL) {
      rtb_Sum = throttle_control_P.PIDController1_LowerSaturationL;
    }

    // End of Saturate: '<S46>/Saturation'

    // Saturate: '<Root>/Saturation1'
    if (rtb_Sum > throttle_control_P.Saturation1_UpperSat) {
      // Switch: '<Root>/Switch'
      rtb_Sum = throttle_control_P.Saturation1_UpperSat;
    } else if (rtb_Sum < throttle_control_P.Saturation1_LowerSat) {
      // Switch: '<Root>/Switch'
      rtb_Sum = throttle_control_P.Saturation1_LowerSat;
    }

    // End of Saturate: '<Root>/Saturation1'
  } else {
    // Switch: '<Root>/Switch' incorporates:
    //   Constant: '<Root>/Constant'

    rtb_Sum = throttle_control_P.Constant_Value_c;
  }

  // End of Switch: '<Root>/Switch'
  if (rtmIsMajorTimeStep(throttle_control_M)) {
    // Saturate: '<Root>/Saturation'
    if (throttle_control_B.In1.Angular.Z >
        throttle_control_P.Saturation_UpperSat) {
      rtb_Saturation_i = throttle_control_P.Saturation_UpperSat;
    } else if (throttle_control_B.In1.Angular.Z <
               throttle_control_P.Saturation_LowerSat) {
      rtb_Saturation_i = throttle_control_P.Saturation_LowerSat;
    } else {
      rtb_Saturation_i = throttle_control_B.In1.Angular.Z;
    }

    // End of Saturate: '<Root>/Saturation'

    // Gain: '<S94>/Proportional Gain'
    throttle_control_B.ProportionalGain_e =
      throttle_control_P.SlowdownController1_P * rtb_Sum6;

    // Gain: '<S83>/Derivative Gain'
    throttle_control_B.DerivativeGain_c =
      throttle_control_P.SlowdownController1_D * rtb_Sum6;
  }

  // Gain: '<S92>/Filter Coefficient' incorporates:
  //   Integrator: '<S84>/Filter'
  //   Sum: '<S84>/SumD'

  throttle_control_B.FilterCoefficient_k = (throttle_control_B.DerivativeGain_c
    - throttle_control_X.Filter_CSTATE_n) *
    throttle_control_P.SlowdownController1_N;

  // Sum: '<S98>/Sum' incorporates:
  //   Integrator: '<S89>/Integrator'

  rtb_Gain = (throttle_control_B.ProportionalGain_e +
              throttle_control_X.Integrator_CSTATE_m) +
    throttle_control_B.FilterCoefficient_k;

  // Switch: '<Root>/Switch1'
  if (throttle_control_B.In1.Linear.X > throttle_control_P.Switch1_Threshold) {
    // Saturate: '<S96>/Saturation'
    if (rtb_Gain > throttle_control_P.SlowdownController1_UpperSatura) {
      Switch1 = throttle_control_P.SlowdownController1_UpperSatura;
    } else if (rtb_Gain < throttle_control_P.SlowdownController1_LowerSatura) {
      Switch1 = throttle_control_P.SlowdownController1_LowerSatura;
    } else {
      Switch1 = rtb_Gain;
    }

    // End of Saturate: '<S96>/Saturation'

    // Saturate: '<Root>/Saturation2'
    if (Switch1 > throttle_control_P.Saturation2_UpperSat) {
      // Switch: '<Root>/Switch1'
      Switch1 = throttle_control_P.Saturation2_UpperSat;
    } else if (Switch1 < throttle_control_P.Saturation2_LowerSat) {
      // Switch: '<Root>/Switch1'
      Switch1 = throttle_control_P.Saturation2_LowerSat;
    }

    // End of Saturate: '<Root>/Saturation2'
  } else {
    // Switch: '<Root>/Switch1' incorporates:
    //   Constant: '<Root>/Constant1'

    Switch1 = throttle_control_P.Constant1_Value_h;
  }

  // End of Switch: '<Root>/Switch1'

  // MATLABSystem: '<Root>/Current Time'
  currentROSTimeBus(&throttle_control_B.r);

  // SignalGenerator: '<Root>/Square Wave Generator' incorporates:
  //   Gain: '<Root>/Gain'
  //   MATLABSystem: '<Root>/Current Time'
  //   Sum: '<Root>/Total Time'

  temp = (throttle_control_P.Gain_Gain * throttle_control_B.r.Nsec +
          throttle_control_B.r.Sec) *
    throttle_control_P.SquareWaveGenerator_Frequency;
  if (rtmIsMajorTimeStep(throttle_control_M)) {
    // Outputs for Triggered SubSystem: '<Root>/Subsystem' incorporates:
    //   TriggerPort: '<S5>/Trigger'

    if (rtmIsMajorTimeStep(throttle_control_M)) {
      // SignalGenerator: '<Root>/Square Wave Generator'
      if (temp - floor(temp) >= 0.5) {
        temp = throttle_control_P.SquareWaveGenerator_Amplitude;
      } else {
        temp = -throttle_control_P.SquareWaveGenerator_Amplitude;
      }

      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &throttle_control_PrevZCX.Subsystem_Trig_ZCE,
                         (temp));
      if (zcEvent != NO_ZCEVENT) {
        // MATLAB Function: '<S5>/MATLAB Function'
        if (rtb_Sum == Switch1) {
          if (rtb_Sum6 >= 0.0) {
            Switch1 = 0.0;
          } else if (rtb_Sum6 < 0.0) {
            rtb_Sum = 0.0;
          }
        }

        // End of MATLAB Function: '<S5>/MATLAB Function'

        // BusAssignment: '<S5>/Bus Assignment' incorporates:
        //   Constant: '<S108>/Constant'

        throttle_control_B.BusAssignment = throttle_control_P.Constant_Value;
        throttle_control_B.BusAssignment.Throttle = rtb_Sum;
        throttle_control_B.BusAssignment.Brake = Switch1;
        throttle_control_B.BusAssignment.Steer = rtb_Saturation_i;

        // Outputs for Atomic SubSystem: '<S5>/Publish'
        // MATLABSystem: '<S110>/SinkBlock'
        Pub_throttle_control_37.publish(&throttle_control_B.BusAssignment);

        // End of Outputs for SubSystem: '<S5>/Publish'
      }
    }

    // End of Outputs for SubSystem: '<Root>/Subsystem'
  }

  // Gain: '<S80>/ZeroGain'
  rtb_Sum = throttle_control_P.ZeroGain_Gain_p * rtb_Gain;

  // DeadZone: '<S82>/DeadZone'
  if (rtb_Gain > throttle_control_P.SlowdownController1_UpperSatura) {
    rtb_Gain -= throttle_control_P.SlowdownController1_UpperSatura;
  } else if (rtb_Gain >= throttle_control_P.SlowdownController1_LowerSatura) {
    rtb_Gain = 0.0;
  } else {
    rtb_Gain -= throttle_control_P.SlowdownController1_LowerSatura;
  }

  // End of DeadZone: '<S82>/DeadZone'
  if (rtmIsMajorTimeStep(throttle_control_M)) {
    // Gain: '<S86>/Integral Gain'
    rtb_IntegralGain = throttle_control_P.SlowdownController1_I * rtb_Sum6;

    // Signum: '<S80>/SignPreIntegrator'
    if (rtb_IntegralGain < 0.0) {
      // DataTypeConversion: '<S80>/DataTypeConv2'
      Switch1 = -1.0;
    } else if (rtb_IntegralGain > 0.0) {
      // DataTypeConversion: '<S80>/DataTypeConv2'
      Switch1 = 1.0;
    } else if (rtb_IntegralGain == 0.0) {
      // DataTypeConversion: '<S80>/DataTypeConv2'
      Switch1 = 0.0;
    } else {
      // DataTypeConversion: '<S80>/DataTypeConv2'
      Switch1 = (rtNaN);
    }

    // End of Signum: '<S80>/SignPreIntegrator'

    // DataTypeConversion: '<S80>/DataTypeConv2'
    if (rtIsNaN(Switch1)) {
      Switch1 = 0.0;
    } else {
      Switch1 = fmod(Switch1, 256.0);
    }

    // DataTypeConversion: '<S80>/DataTypeConv2'
    throttle_control_B.DataTypeConv2_h = static_cast<int8_T>(Switch1 < 0.0 ?
      static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>(static_cast<
      uint8_T>(-Switch1)))) : static_cast<int32_T>(static_cast<int8_T>(
      static_cast<uint8_T>(Switch1))));
  }

  // Signum: '<S80>/SignPreSat'
  if (rtb_Gain < 0.0) {
    // DataTypeConversion: '<S80>/DataTypeConv1'
    Switch1 = -1.0;
  } else if (rtb_Gain > 0.0) {
    // DataTypeConversion: '<S80>/DataTypeConv1'
    Switch1 = 1.0;
  } else if (rtb_Gain == 0.0) {
    // DataTypeConversion: '<S80>/DataTypeConv1'
    Switch1 = 0.0;
  } else {
    // DataTypeConversion: '<S80>/DataTypeConv1'
    Switch1 = (rtNaN);
  }

  // End of Signum: '<S80>/SignPreSat'

  // DataTypeConversion: '<S80>/DataTypeConv1'
  if (rtIsNaN(Switch1)) {
    Switch1 = 0.0;
  } else {
    Switch1 = fmod(Switch1, 256.0);
  }

  // Logic: '<S80>/AND3' incorporates:
  //   DataTypeConversion: '<S80>/DataTypeConv1'
  //   RelationalOperator: '<S80>/Equal1'
  //   RelationalOperator: '<S80>/NotEqual'

  throttle_control_B.AND3_g = ((rtb_Sum != rtb_Gain) && ((Switch1 < 0.0 ?
    static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-Switch1)))) : static_cast<int32_T>(static_cast<int8_T>
    (static_cast<uint8_T>(Switch1)))) == throttle_control_B.DataTypeConv2_h));
  if (rtmIsMajorTimeStep(throttle_control_M)) {
    // Switch: '<S80>/Switch' incorporates:
    //   Memory: '<S80>/Memory'

    if (throttle_control_DW.Memory_PreviousInput_a) {
      // Switch: '<S80>/Switch' incorporates:
      //   Constant: '<S80>/Constant1'

      throttle_control_B.Switch_m = throttle_control_P.Constant1_Value_n;
    } else {
      // Switch: '<S80>/Switch'
      throttle_control_B.Switch_m = rtb_IntegralGain;
    }

    // End of Switch: '<S80>/Switch'
  }

  if (rtmIsMajorTimeStep(throttle_control_M)) {
    if (rtmIsMajorTimeStep(throttle_control_M)) {
      // Update for Memory: '<S30>/Memory'
      throttle_control_DW.Memory_PreviousInput = throttle_control_B.AND3;

      // Update for Memory: '<S80>/Memory'
      throttle_control_DW.Memory_PreviousInput_a = throttle_control_B.AND3_g;
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(throttle_control_M)) {
    rt_ertODEUpdateContinuousStates(&throttle_control_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++throttle_control_M->Timing.clockTick0;
    throttle_control_M->Timing.t[0] = rtsiGetSolverStopTime
      (&throttle_control_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.0005s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.0005, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      throttle_control_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void throttle_control_derivatives(void)
{
  XDot_throttle_control_T *_rtXdot;
  _rtXdot = ((XDot_throttle_control_T *) throttle_control_M->derivs);

  // Derivatives for Integrator: '<S39>/Integrator'
  _rtXdot->Integrator_CSTATE = throttle_control_B.Switch;

  // Derivatives for Integrator: '<S34>/Filter'
  _rtXdot->Filter_CSTATE = throttle_control_B.FilterCoefficient;

  // Derivatives for Integrator: '<S89>/Integrator'
  _rtXdot->Integrator_CSTATE_m = throttle_control_B.Switch_m;

  // Derivatives for Integrator: '<S84>/Filter'
  _rtXdot->Filter_CSTATE_n = throttle_control_B.FilterCoefficient_k;
}

// Model initialize function
void throttle_control_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&throttle_control_M->solverInfo,
                          &throttle_control_M->Timing.simTimeStep);
    rtsiSetTPtr(&throttle_control_M->solverInfo, &rtmGetTPtr(throttle_control_M));
    rtsiSetStepSizePtr(&throttle_control_M->solverInfo,
                       &throttle_control_M->Timing.stepSize0);
    rtsiSetdXPtr(&throttle_control_M->solverInfo, &throttle_control_M->derivs);
    rtsiSetContStatesPtr(&throttle_control_M->solverInfo, (real_T **)
                         &throttle_control_M->contStates);
    rtsiSetNumContStatesPtr(&throttle_control_M->solverInfo,
      &throttle_control_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&throttle_control_M->solverInfo,
      &throttle_control_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&throttle_control_M->solverInfo,
      &throttle_control_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&throttle_control_M->solverInfo,
      &throttle_control_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&throttle_control_M->solverInfo, (&rtmGetErrorStatus
      (throttle_control_M)));
    rtsiSetRTModelPtr(&throttle_control_M->solverInfo, throttle_control_M);
  }

  rtsiSetSimTimeStep(&throttle_control_M->solverInfo, MAJOR_TIME_STEP);
  throttle_control_M->intgData.y = throttle_control_M->odeY;
  throttle_control_M->intgData.f[0] = throttle_control_M->odeF[0];
  throttle_control_M->intgData.f[1] = throttle_control_M->odeF[1];
  throttle_control_M->intgData.f[2] = throttle_control_M->odeF[2];
  throttle_control_M->contStates = ((X_throttle_control_T *) &throttle_control_X);
  rtsiSetSolverData(&throttle_control_M->solverInfo, static_cast<void *>
                    (&throttle_control_M->intgData));
  rtsiSetSolverName(&throttle_control_M->solverInfo,"ode3");
  rtmSetTPtr(throttle_control_M, &throttle_control_M->Timing.tArray[0]);
  throttle_control_M->Timing.stepSize0 = 0.0005;

  {
    int32_T i;
    char_T b_zeroDelimTopic[8];
    char_T b_zeroDelimTopic_0[4];
    static const char_T tmp[7] = { 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_0[7] = { 'c', 'o', 'n', 't', 'r', 'o', 'l' };

    throttle_control_PrevZCX.Subsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;

    // InitializeConditions for Memory: '<S30>/Memory'
    throttle_control_DW.Memory_PreviousInput =
      throttle_control_P.Memory_InitialCondition;

    // InitializeConditions for Integrator: '<S39>/Integrator'
    throttle_control_X.Integrator_CSTATE =
      throttle_control_P.PIDController1_InitialConditi_m;

    // InitializeConditions for Integrator: '<S34>/Filter'
    throttle_control_X.Filter_CSTATE =
      throttle_control_P.PIDController1_InitialCondition;

    // InitializeConditions for Integrator: '<S89>/Integrator'
    throttle_control_X.Integrator_CSTATE_m =
      throttle_control_P.SlowdownController1_InitialCo_m;

    // InitializeConditions for Integrator: '<S84>/Filter'
    throttle_control_X.Filter_CSTATE_n =
      throttle_control_P.SlowdownController1_InitialCond;

    // InitializeConditions for Memory: '<S80>/Memory'
    throttle_control_DW.Memory_PreviousInput_a =
      throttle_control_P.Memory_InitialCondition_d;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S107>/Out1' incorporates:
    //   Inport: '<S107>/In1'

    throttle_control_B.In1 = throttle_control_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    throttle_control_DW.obj_o.matlabCodegenIsDeleted = false;
    throttle_control_DW.obj_o.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[7] = '\x00';
    Sub_throttle_control_45.createSubscriber(&b_zeroDelimTopic[0], 1);
    throttle_control_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S106>/Out1' incorporates:
    //   Inport: '<S106>/In1'

    throttle_control_B.In1_c = throttle_control_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    throttle_control_DW.obj_h.matlabCodegenIsDeleted = false;
    throttle_control_DW.obj_h.isInitialized = 1;
    b_zeroDelimTopic_0[0] = 'v';
    b_zeroDelimTopic_0[1] = 'e';
    b_zeroDelimTopic_0[2] = 'l';
    b_zeroDelimTopic_0[3] = '\x00';
    Sub_throttle_control_38.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    throttle_control_DW.obj_h.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Triggered SubSystem: '<Root>/Subsystem'
    // SystemInitialize for Atomic SubSystem: '<S5>/Publish'
    // Start for MATLABSystem: '<S110>/SinkBlock'
    throttle_control_DW.obj_ox.matlabCodegenIsDeleted = false;
    throttle_control_DW.obj_ox.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic[i] = tmp_0[i];
    }

    b_zeroDelimTopic[7] = '\x00';
    Pub_throttle_control_37.createPublisher(&b_zeroDelimTopic[0], 1);
    throttle_control_DW.obj_ox.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S110>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S5>/Publish'
    // End of SystemInitialize for SubSystem: '<Root>/Subsystem'

    // Start for MATLABSystem: '<Root>/Current Time'
    throttle_control_DW.obj.matlabCodegenIsDeleted = false;
    throttle_control_DW.obj.isInitialized = 1;
    throttle_control_DW.obj.isSetupComplete = true;
  }
}

// Model terminate function
void throttle_control_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!throttle_control_DW.obj_o.matlabCodegenIsDeleted) {
    throttle_control_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!throttle_control_DW.obj_h.matlabCodegenIsDeleted) {
    throttle_control_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for MATLABSystem: '<Root>/Current Time'
  if (!throttle_control_DW.obj.matlabCodegenIsDeleted) {
    throttle_control_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Current Time'

  // Terminate for Triggered SubSystem: '<Root>/Subsystem'
  // Terminate for Atomic SubSystem: '<S5>/Publish'
  // Terminate for MATLABSystem: '<S110>/SinkBlock'
  if (!throttle_control_DW.obj_ox.matlabCodegenIsDeleted) {
    throttle_control_DW.obj_ox.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S110>/SinkBlock'
  // End of Terminate for SubSystem: '<S5>/Publish'
  // End of Terminate for SubSystem: '<Root>/Subsystem'
}

//
// File trailer for generated code.
//
// [EOF]
//
