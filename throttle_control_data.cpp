//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: throttle_control_data.cpp
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
#include "throttle_control.h"
#include "throttle_control_private.h"

// Block parameters (default storage)
P_throttle_control_T throttle_control_P = {
  // Mask Parameter: PIDController1_D
  //  Referenced by: '<S33>/Derivative Gain'

  0.656379900606905,

  // Mask Parameter: SlowdownController1_D
  //  Referenced by: '<S83>/Derivative Gain'

  -2.26736704240256,

  // Mask Parameter: PIDController1_I
  //  Referenced by: '<S36>/Integral Gain'

  6.07606353611095,

  // Mask Parameter: SlowdownController1_I
  //  Referenced by: '<S86>/Integral Gain'

  8.8451000083051,

  // Mask Parameter: PIDController1_InitialCondition
  //  Referenced by: '<S34>/Filter'

  0.0,

  // Mask Parameter: SlowdownController1_InitialCond
  //  Referenced by: '<S84>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialConditi_m
  //  Referenced by: '<S39>/Integrator'

  0.0,

  // Mask Parameter: SlowdownController1_InitialCo_m
  //  Referenced by: '<S89>/Integrator'

  0.0,

  // Mask Parameter: PIDController1_LowerSaturationL
  //  Referenced by:
  //    '<S46>/Saturation'
  //    '<S32>/DeadZone'

  0.0,

  // Mask Parameter: SlowdownController1_LowerSatura
  //  Referenced by:
  //    '<S96>/Saturation'
  //    '<S82>/DeadZone'

  0.0,

  // Mask Parameter: PIDController1_N
  //  Referenced by: '<S42>/Filter Coefficient'

  2.27284583867859,

  // Mask Parameter: SlowdownController1_N
  //  Referenced by: '<S92>/Filter Coefficient'

  4.84135397787565,

  // Mask Parameter: PIDController1_P
  //  Referenced by: '<S44>/Proportional Gain'

  17.003798133407962,

  // Mask Parameter: SlowdownController1_P
  //  Referenced by: '<S94>/Proportional Gain'

  11.5137498864335,

  // Mask Parameter: PIDController1_UpperSaturationL
  //  Referenced by:
  //    '<S46>/Saturation'
  //    '<S32>/DeadZone'

  1.0,

  // Mask Parameter: SlowdownController1_UpperSatura
  //  Referenced by:
  //    '<S96>/Saturation'
  //    '<S82>/DeadZone'

  1.0,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S108>/Constant'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header
    0.0,                               // Throttle
    0.0,                               // Brake
    0.0,                               // Steer
    0U                                 // ShiftGears
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S106>/Out1'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S3>/Constant'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S107>/Out1'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Computed Parameter: Constant_Value_hj
  //  Referenced by: '<S4>/Constant'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Expression: 1
  //  Referenced by: '<Root>/Saturation2'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Saturation2'

  0.0,

  // Expression: 1
  //  Referenced by: '<Root>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Saturation1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S30>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S80>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S30>/ZeroGain'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<Root>/Constant'

  0.0,

  // Expression: 0.05
  //  Referenced by: '<Root>/Switch'

  0.05,

  // Expression: 1
  //  Referenced by: '<Root>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<Root>/Saturation'

  -1.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant1'

  1.0,

  // Expression: 0.05
  //  Referenced by: '<Root>/Switch1'

  0.05,

  // Expression: 1e-9
  //  Referenced by: '<Root>/Gain'

  1.0E-9,

  // Expression: 1
  //  Referenced by: '<Root>/Square Wave Generator'

  1.0,

  // Expression: 100
  //  Referenced by: '<Root>/Square Wave Generator'

  100.0,

  // Expression: 0
  //  Referenced by: '<S80>/ZeroGain'

  0.0,

  // Computed Parameter: Memory_InitialCondition
  //  Referenced by: '<S30>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_d
  //  Referenced by: '<S80>/Memory'

  0
};

//
// File trailer for generated code.
//
// [EOF]
//
