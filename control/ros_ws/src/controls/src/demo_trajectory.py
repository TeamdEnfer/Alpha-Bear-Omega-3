#! /usr/bin/env python3

import rospy
import random
from trajectory_msgs.msg import JointTrajectory , JointTrajectoryPoint

def demo_publisher():
    
    rospy.init_node('rospy_conrtol_node')
    control_publisher = rospy.Publisher('/front_right_leg_controller/command', JointTrajectory , queue_size= 10)

    while not rospy.is_shutdown():

        msg = JointTrajectory()
        msg.header.stamp = rospy.Time.now()
        msg.header.frame_id = ''
        msg.joint_names = ['Femur_FR, Tibia_FR']

        point = JointTrajectoryPoint()

        femur = random.random()
        tibia = random.random()

        point.positions = [femur , tibia]
        point.velocities = []
        point.accelerations = []
        point.effort = []

        point.time_from_start = rospy.Duration(1)

        msg.points.append(point)

        control_publisher.publish(msg)

        rospy.loginfo(msg)


if __name__ == '__main__':

    demo_publisher()