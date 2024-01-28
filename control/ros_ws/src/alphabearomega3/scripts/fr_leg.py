import rospy
import os
from controller import Robot
import math
from geometry_msgs.msg import Twist


       
def twistCallback(twistData):
    femur_motor.setPosition(twistData.linear.x)
    femur_motor.setVelocity(twistData.angular.x)
    tibia_motor.setPosition(twistData.linear.y)
    tibia_motor.setVelocity(twistData.angular.y)
    
    

robot= Robot()
timeStep = int(robot.getBasicTimeStep())
femur_motor = robot.getDevice('FR_femur_servo')
tibia_motor= robot.getDevice('FR_tibia_servo')

femur_motor.setPosition(float('inf'))
femur_motor.setVelocity(0)
tibia_motor.setPosition(float('inf'))
tibia_motor.setVelocity(0)

rospy.init_node('fr_leg', anonymous=True)
pub= rospy.Subscriber('fr_leg_pose',Twist,twistCallback)

        

while robot.step(timeStep) != -1:
    pass
    

    
	



        





