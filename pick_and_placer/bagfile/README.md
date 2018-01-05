# how to ganerate csv of specific topic 
> rostopic echo -b 2017-12-30-23-56-29.bag -p /joint_states > data.csv

# extract bracket_2_3_joint in matlab 
> data = readtable('data.txt', 'Delimiter', 'comma');

> bracket_2_3_joint = data(:, 13); 
