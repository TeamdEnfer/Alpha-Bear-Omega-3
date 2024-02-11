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

def trajectory_goal(TrajectoryAction , angles): #les angles sont en radians

    #On utilise des JointTrajectory points transformer les angles du topic en points de trajectoire
    points = JointTrajectoryPoint()
    points.positions = angles
    #On done un temps voulu pour l'execution
    points.time_from_start = rospy.Duration(1)

    #On creer un goal a suivre qui va dicter la commande
    goal = FollowJointTrajectoryGoal()
    #On assigne les joints aux points de la trajectoire
    goal.trajectory.joint_names = ['Femur_FR', 'Tibia_FR']
    #On met les points dans la trajectoire goal
    goal.trajectory.points.append(points)

    #Enfin, on envoie le goal via le action client
    TrajectoryAction.send_goal(goal)


if __name__ == '__main__':

    #initialise un node pour le trajectory interface 
    rospy.init_node('rospy_trajectory_control_node')

    #A la place de publish directement sur un topic, on utilise un action client pour envoyer des goals
    TrajectoryAction = actionlib.SimpleActionClient('Alpha_Bear/front_right_leg_controller/follow_joint_trajectory' , FollowJointTrajectoryAction)

    #Le action client doit attendre que le action server soit pret
    TrajectoryAction.wait_for_server()

    #On a pas encore de kinematics, alors on hardcode un trajectoire pour demontrer le fonctionement de la control loop
    while(True):
        trajectory_goal(TrajectoryAction , [0,0])
        time.sleep(3)
        trajectory_goal(TrajectoryAction, [1,1])
        time.sleep(3)