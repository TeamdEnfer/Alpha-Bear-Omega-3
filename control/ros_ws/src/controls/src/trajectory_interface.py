#! /usr/bin/env python3

import roslib
import rospy
import time
import random
import trajectory_msgs.msg
from trajectory_msgs.msg import JointTrajectory , JointTrajectoryPoint
import actionlib
import control_msgs.msg
from std_msgs.msg import Float64MultiArray
from control_msgs.msg import JointTrajectoryAction , JointTrajectoryGoal , FollowJointTrajectoryAction , FollowJointTrajectoryGoal

cmd_msg = Float64MultiArray(data=[0]*12)
pi = 3.141592
def JTM_to_F64(Data):

    cmd_msg.data = Data.points[0].positions
    trajectory_goal(TrajectoryAction , cmd_msg)


#def trajectory_goal(TrajectoryAction , angles = cmd_msg): #les angles sont en radians
def trajectory_goal(TrajectoryAction , angles): #Pour hard code un trajectoire de test

    #On utilise des JointTrajectory points transformer les angles du topic en points de trajectoire
    points = JointTrajectoryPoint()
    points.positions = angles.data
    #On done un temps voulu pour l'execution
    points.time_from_start = rospy.Duration(0.1)

    #On creer un goal a suivre qui va dicter la commande
    goal = FollowJointTrajectoryGoal()
    #On assigne les joints aux points de la trajectoire
    goal.trajectory.joint_names = ['FL_shoulder_servo','FL_femur_servo','FL_tibia_servo',
                                   'FR_shoulder_servo','FR_femur_servo','FR_tibia_servo',
                                   'RL_shoulder_servo','RL_femur_servo','RL_tibia_servo',
                                   'RR_shoulder_servo','RR_femur_servo','RR_tibia_servo']
    #On met les points dans la trajectoire goal
    goal.trajectory.points.append(points)

    #Enfin, on envoie le goal via le action client
    TrajectoryAction.send_goal(goal)

def trajectory_goal_hardcode(TrajectoryAction , angles): #les angles sont en radians

    #On utilise des JointTrajectory points transformer les angles du topic en points de trajectoire
    points = JointTrajectoryPoint()
    points.positions = angles
    #On done un temps voulu pour l'execution
    points.time_from_start = rospy.Duration(0.2)

    #On creer un goal a suivre qui va dicter la commande
    goal = FollowJointTrajectoryGoal()
    #On assigne les joints aux points de la trajectoire
    goal.trajectory.joint_names = ['FL_shoulder_servo','FL_femur_servo','FL_tibia_servo'
                                   ,'FR_shoulder_servo','FR_femur_servo','FR_tibia_servo',
                                   'RL_shoulder_servo','RL_femur_servo','RL_tibia_servo',
                                   'RR_shoulder_servo','RR_femur_servo','RR_tibia_servo']
    #On met les points dans la trajectoire goal
    goal.trajectory.points.append(points)

    #Enfin, on envoie le goal via le action client
    TrajectoryAction.send_goal(goal)

if __name__ == '__main__':

    #initialise un node pour le trajectory interface 
    rospy.init_node('rospy_trajectory_control_node')

    #A la place de publish directement sur un topic, on utilise un action client pour envoyer des goals
    TrajectoryAction = actionlib.SimpleActionClient('Alpha_Bear/leg_controller/follow_joint_trajectory' , FollowJointTrajectoryAction)

    #Le action client doit attendre que le action server soit pret
    TrajectoryAction.wait_for_server()

    #rospy.Subscriber('joint_group_position_controller/command' , JointTrajectory , JTM_to_F64 , TrajectoryAction , queue_size=10)
    rospy.Subscriber('joint_group_position_controller/command' , JointTrajectory , JTM_to_F64 , queue_size=10)

    rospy.spin()