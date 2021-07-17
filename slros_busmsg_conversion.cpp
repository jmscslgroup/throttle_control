#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_throttle_control_geometry_msgs_Twist and geometry_msgs::Twist

void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_throttle_control_geometry_msgs_Twist const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertFromBus(&msgPtr->angular, &busPtr->Angular);
  convertFromBus(&msgPtr->linear, &busPtr->Linear);
}

void convertToBus(SL_Bus_throttle_control_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertToBus(&busPtr->Angular, &msgPtr->angular);
  convertToBus(&busPtr->Linear, &msgPtr->linear);
}


// Conversions between SL_Bus_throttle_control_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_throttle_control_geometry_msgs_Vector3 const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_throttle_control_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_throttle_control_ros_time_Time and ros::Time

void convertFromBus(ros::Time* msgPtr, SL_Bus_throttle_control_ros_time_Time const* busPtr)
{
  const std::string rosMessageType("ros_time/Time");

  msgPtr->nsec =  busPtr->Nsec;
  msgPtr->sec =  busPtr->Sec;
}

void convertToBus(SL_Bus_throttle_control_ros_time_Time* busPtr, ros::Time const* msgPtr)
{
  const std::string rosMessageType("ros_time/Time");

  busPtr->Nsec =  msgPtr->nsec;
  busPtr->Sec =  msgPtr->sec;
}


// Conversions between SL_Bus_throttle_control_std_msgs_Header and std_msgs::Header

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_throttle_control_std_msgs_Header const* busPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromBusVariablePrimitiveArray(msgPtr->frame_id, busPtr->FrameId, busPtr->FrameId_SL_Info);
  msgPtr->seq =  busPtr->Seq;
  convertFromBus(&msgPtr->stamp, &busPtr->Stamp);
}

void convertToBus(SL_Bus_throttle_control_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToBusVariablePrimitiveArray(busPtr->FrameId, busPtr->FrameId_SL_Info, msgPtr->frame_id, slros::EnabledWarning(rosMessageType, "frame_id"));
  busPtr->Seq =  msgPtr->seq;
  convertToBus(&busPtr->Stamp, &msgPtr->stamp);
}


// Conversions between SL_Bus_throttle_control_steer_avcontrol and steer::avcontrol

void convertFromBus(steer::avcontrol* msgPtr, SL_Bus_throttle_control_steer_avcontrol const* busPtr)
{
  const std::string rosMessageType("steer/avcontrol");

  msgPtr->brake =  busPtr->Brake;
  convertFromBus(&msgPtr->header, &busPtr->Header);
  msgPtr->shift_gears =  busPtr->ShiftGears;
  msgPtr->steer =  busPtr->Steer;
  msgPtr->throttle =  busPtr->Throttle;
}

void convertToBus(SL_Bus_throttle_control_steer_avcontrol* busPtr, steer::avcontrol const* msgPtr)
{
  const std::string rosMessageType("steer/avcontrol");

  busPtr->Brake =  msgPtr->brake;
  convertToBus(&busPtr->Header, &msgPtr->header);
  busPtr->ShiftGears =  msgPtr->shift_gears;
  busPtr->Steer =  msgPtr->steer;
  busPtr->Throttle =  msgPtr->throttle;
}

