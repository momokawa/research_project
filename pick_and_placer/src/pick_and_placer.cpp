#include <ros/ros.h>
#include <moveit/move_group_interface/move_group_interface.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "pick_and_placer");
  ros::NodeHandle nh;

  // for moveit's async calc
  ros::AsyncSpinner spinner(2); // use 2 threads
  spinner.start();

  moveit::planning_interface::MoveGroupInterface arm("arm"); // set moveGroupInterface as arm ( this comes from moveit_setup_assistant)
  arm.setPoseReferenceFrame("base_link");
	

  // start pose
  geometry_msgs::PoseStamped start_pose;
  start_pose.header.frame_id = "base_link";
  start_pose.pose.position.x = -0.425; 
  start_pose.pose.position.y = 0.1;
  start_pose.pose.position.z = -0.5;
  start_pose.pose.orientation.x = 0.0;
  start_pose.pose.orientation.y = 0.707106;
  start_pose.pose.orientation.z = 0.0;
  start_pose.pose.orientation.w = 0.707106; // use quanternion

  // goal pose
  geometry_msgs::PoseStamped goal_pose;
  goal_pose.header.frame_id = "base_link";
  goal_pose.pose.position.x = -0.06; 
  goal_pose.pose.position.y = 0.30;
  goal_pose.pose.position.z = -0.375;
  goal_pose.pose.orientation.x = 0.0;
  goal_pose.pose.orientation.y = 0.707106;
  goal_pose.pose.orientation.z = 0.0;
  goal_pose.pose.orientation.w = 0.707106; // use quanternion

  ROS_INFO("Moving to prepose pose");
	arm.setPoseTarget(start_pose); // move to prepare
  if ( !arm.move() ) {
  	ROS_WARN("Could not move to prepare pose");
  	return 1;	
	}
  
  // move to goal pose
  ROS_INFO("Moving to goal pose");
  arm.setPoseTarget(goal_pose);
  if ( !arm.move() ){
    ROS_WARN("Coudl not move to goal pose");
    return 1;
  }
  
  ros::shutdown();
  return 0;
}
