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
  
  // arm.setGoalPositionTolerance(0.1);	

  // print current pose
  geometry_msgs::PoseStamped current_pose = arm.getCurrentPose();
  cout << current_pose << endl;

  // goal pose
  geometry_msgs::PoseStamped goal_pose;
  goal_pose.header.frame_id = "base_link";
  goal_pose.pose.position.x = -0.06; 
  goal_pose.pose.position.y = 0.30;
  goal_pose.pose.position.z = -0.375;
  goal_pose.pose.orientation.x = 0.275455;
  goal_pose.pose.orientation.y = -0.933449;
  goal_pose.pose.orientation.z = -0.142808;
  goal_pose.pose.orientation.w = 0.180007; // use quanternion

  // move to goal pose
  ROS_INFO("Moving to goal pose");
  arm.setPoseTarget(goal_pose);
  arm.setGoalTolerance(0.01);
  if ( !arm.move() ){
    ROS_WARN("Coudl not move to goal pose");
    return 1;
  }
  
  ros::shutdown();
  return 0;
}
