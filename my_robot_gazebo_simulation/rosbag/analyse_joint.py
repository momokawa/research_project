import pandas as pd
import numpy as np

def torque_magnitude(joint_data):
    torque_x = (joint_data['field.wrench.torque.x']).values
    torque_y = (joint_data['field.wrench.torque.y']).values
    torque_z = (joint_data['field.wrench.torque.z']).values

    torque = np.sqrt(torque_x**2 + torque_y**2 + torque_z**2)
    return torque

ft_1_2_joint_data = pd.read_csv('ft_1_2_joint.csv')
ft_2_3_joint_data = pd.read_csv('ft_2_3_joint.csv')
ft_3_4_joint_data = pd.read_csv('ft_3_4_joint.csv')
ft_4_5_joint_data = pd.read_csv('ft_4_5_joint.csv')
ft_5_6_joint_data = pd.read_csv('ft_5_6_joint.csv')
ft_6_7_joint_data = pd.read_csv('ft_6_7_joint.csv')

torque_mag_1_2_joint = torque_magnitude(ft_1_2_joint_data)
torque_mag_2_3_joint = torque_magnitude(ft_2_3_joint_data)
torque_mag_3_4_joint = torque_magnitude(ft_3_4_joint_data)
torque_mag_4_5_joint = torque_magnitude(ft_4_5_joint_data)
torque_mag_5_6_joint = torque_magnitude(ft_5_6_joint_data)
torque_mag_6_6_joint = torque_magnitude(ft_6_7_joint_data)

print(torque_mag_1_2_joint)


