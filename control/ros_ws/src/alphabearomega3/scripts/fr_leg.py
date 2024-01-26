#import rospy
import os
from controller import Robot




robot= Robot()
timeStep = int(robot.getBasicTimeStep())
femur_motor = robot.getDevice('FR_femur_servo')

femur_motor.setPosition(float('inf'))
femur_motor.setVelocity(50)
        
        
while robot.step(timeStep) != -1:
	pass
       




        





