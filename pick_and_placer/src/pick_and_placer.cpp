#include <ros/ros.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  ros::init(argc, argv, "pick_and_placer");
  ros::NodeHandle nh;

  // for moveit's async calc
  ros::AsyncSpinner spinner(2); // use 2 threads
  spinner.start();

  moveit::planning_interface::MoveGroupInterface arm("arm"); // set moveGroupInterface as arm ( this comes from moveit_setup_assistant)
  arm.setPoseReferenceFrame("base_link");
  
  // print current pose
  ROS_INFO_STREAM("Current States" << arm.getCurrentPose() ); 
  // goal pose
  geometry_msgs::PoseStamped goal_pose;
  goal_pose.header.frame_id = "base_link";
  goal_pose.pose.position.x = 0.04; 
  goal_pose.pose.position.y = 0.30;
  goal_pose.pose.position.z = -0.375;
  goal_pose.pose.orientation.x = 0.275455;
  goal_pose.pose.orientation.y = -0.933449;
  goal_pose.pose.orientation.z = -0.142808;
  goal_pose.pose.orientation.w = 0.180007; // use quanternion

  // move to goal pose
  ROS_INFO("Moving to goal pose");
  arm.setPoseTarget(goal_pose);
  arm.setGoalPositionTolerance(0.015);
  arm.setGoalOrientationTolerance(0.06);
  if ( !arm.move() ){
    ROS_WARN("Coudn't not move to goal pose");
    return 1;
  }
  
  ROS_INFO_STREAM("Current States" << arm.getCurrentPose() ); 
  ros::shutdown();
  return 0;
}
