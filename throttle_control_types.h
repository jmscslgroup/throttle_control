//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: throttle_control_types.h
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
#ifndef RTW_HEADER_throttle_control_types_h_
#define RTW_HEADER_throttle_control_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_throttle_control_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_throttle_control_ros_time_Time_

// MsgType=ros_time/Time
struct SL_Bus_throttle_control_ros_time_Time
{
  real_T Sec;
  real_T Nsec;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_throttle_control_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_throttle_control_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_throttle_control_geometry_msgs_Vector3
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_throttle_control_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_throttle_control_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
struct SL_Bus_throttle_control_geometry_msgs_Twist
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_throttle_control_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_throttle_control_geometry_msgs_Vector3 Angular;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

struct SL_Bus_ROSVariableLengthArrayInfo
{
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_throttle_control_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_throttle_control_std_msgs_Header_

// MsgType=std_msgs/Header
struct SL_Bus_throttle_control_std_msgs_Header
{
  uint32_T Seq;

  // MsgType=ros_time/Time
  SL_Bus_throttle_control_ros_time_Time Stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_throttle_control_steer_avcontrol_
#define DEFINED_TYPEDEF_FOR_SL_Bus_throttle_control_steer_avcontrol_

// MsgType=steer/avcontrol
struct SL_Bus_throttle_control_steer_avcontrol
{
  // MsgType=std_msgs/Header
  SL_Bus_throttle_control_std_msgs_Header Header;
  real_T Throttle;
  real_T Brake;
  real_T Steer;
  uint8_T ShiftGears;
};

#endif

#ifndef struct_f_robotics_slcore_internal_bl_T
#define struct_f_robotics_slcore_internal_bl_T

struct f_robotics_slcore_internal_bl_T
{
  int32_T __dummy;
};

#endif                                // struct_f_robotics_slcore_internal_bl_T

#ifndef struct_ros_slros_internal_block_Curr_T
#define struct_ros_slros_internal_block_Curr_T

struct ros_slros_internal_block_Curr_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_robotics_slcore_internal_bl_T SampleTimeHandler;
};

#endif                                // struct_ros_slros_internal_block_Curr_T

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_S_T

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_P_T

// Parameters (default storage)
typedef struct P_throttle_control_T_ P_throttle_control_T;

// Forward declaration for rtModel
typedef struct tag_RTM_throttle_control_T RT_MODEL_throttle_control_T;

#endif                                 // RTW_HEADER_throttle_control_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
