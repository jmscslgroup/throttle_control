#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "throttle_control";

// For Block throttle_control/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_throttle_control_geometry_msgs_Twist> Sub_throttle_control_38;

// For Block throttle_control/Subscribe1
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_throttle_control_geometry_msgs_Twist> Sub_throttle_control_45;

// For Block throttle_control/Subsystem/Publish
SimulinkPublisher<steer::avcontrol, SL_Bus_throttle_control_steer_avcontrol> Pub_throttle_control_37;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

