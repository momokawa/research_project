# repositoty for my research project

version: kinetic


## To launch demo,

> roslaunch my_robot_moveit_config all_in_one_moveit_gazebo.launch

## Everytime you update urdf model, you need to redo

> roslaunch moveit_setup_assistant setup_assistant.launch

do not include sample_robot_moveit_controller_manager.launch.xml when updating.

## Just to see the model in Rviz, run this

> roslaunch urdf_tutorial display.launch model:=sample.urdf

## To test pick_and_placer

> roslaunch my_robot_gazebo_simulation demo_gazebo.launch

> roslaunch my_robot_moveit_config move_group.launch 

> rosrun pick_and_placer pick_and_placer 
