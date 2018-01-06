function generate_joint_mat_func(mat_filename, raw_num)
% this function generate mat_file of a joint with specific raw_num's data
% mat_filename: bracket_1_2_joint.mat
% raw_num: the num of raw where each joint array exists

data_input = readtable('data.txt', 'Delimiter', 'comma');
time_array = 0:0.01:0.01*1433; % 0.01sec interval array of time
joint_position_table = data_input(:, raw_num); % get the joint's position arra
joint_position_array = table2array(joint_position_table); % convert table to array

% create mat file with required structs
joint_position_trajectory.time = time_array';
joint_position_trajectory.signals.values = joint_position_array;
joint_position_trajectory.signals.dimensions = 1;
joint_position_trajectory.signals.label = 'joint_position';
save(mat_filename, 'joint_position_trajectory');

end