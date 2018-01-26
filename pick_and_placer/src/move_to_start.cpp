#include <ros/ros.h>
#include <moveit/move_group_interface/move_group_interface.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "move_to_start");
  ros::NodeHandle nh;

  ros::AsyncSpinner spinner(2); // use 2 threads
  spinner.start();

  moveit::planning_interface::MoveGroupInterface arm("arm"); // set moveGroupInterface as arm ( this comes from moveit_setup_assistant)
  arm.setPoseReferenceFrame("base_link");
  

// START POSE
  geometry_msgs::PoseStamped start_pose;
  start_pose.header.frame_id = "base_link";
  start_pose.pose.position.x = -0.300; 
  start_pose.pose.position.y = 0.10;
  start_pose.pose.position.z = -0.375;
  start_pose.pose.orientation.x = 0.275455;
  start_pose.pose.orientation.y = -0.933449;
  start_pose.pose.orientation.z = -0.142808;
  start_pose.pose.orientation.w = 0.180007; // use quanternion
	// notice: quantenion requires enough significant digit, so [0 1 0 0] cannot be used.

// MOVE TO START POSITION
  ROS_INFO("Moving to prepose pose");
  arm.setPoseTarget(start_pose); // move to prepare
  arm.setGoalTolerance(0.01);
  if ( !arm.move() ) {
  	ROS_WARN("Could not move to prepare pose");
  	return 1;	
	}

  ros::shutdown();
  return 0;
}

