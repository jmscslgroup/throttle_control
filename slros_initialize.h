#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "slros_time.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block throttle_control/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_throttle_control_geometry_msgs_Twist> Sub_throttle_control_38;

// For Block throttle_control/Subscribe1
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_throttle_control_geometry_msgs_Twist> Sub_throttle_control_45;

// For Block throttle_control/Subsystem/Publish
extern SimulinkPublisher<steer::avcontrol, SL_Bus_throttle_control_steer_avcontrol> Pub_throttle_control_37;

void slros_node_init(int argc, char** argv);

#endif
