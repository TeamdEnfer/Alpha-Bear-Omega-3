import rospy
import os
from controller import Robot
import math
from sensor_msgs.msg import JointState



       
def twistCallback(BiData):
    for i in range(0,len(BiData.position)):
    
        Motor_List[i].setPosition(BiData.position[i])
        Motor_List[i].setVelocity(BiData.velocity[i])
        #print(oneBiData.x)
    
    

robot= Robot()
timeStep = int(robot.getBasicTimeStep())
FR_femur_motor = robot.getDevice('FR_femur_servo')
FL_femur_motor = robot.getDevice('FL_femur_servo')
RR_femur_motor = robot.getDevice('RR_femur_servo')
RL_femur_motor = robot.getDevice('RL_femur_servo')
FR_tibia_motor= robot.getDevice('FR_tibia_servo')
FL_tibia_motor= robot.getDevice('FL_tibia_servo')
RR_tibia_motor= robot.getDevice('RR_tibia_servo')
RL_tibia_motor= robot.getDevice('RL_tibia_servo')


Motor_List=[FR_femur_motor,FR_tibia_motor,FL_femur_motor,FL_tibia_motor,RR_femur_motor,RR_tibia_motor,RL_femur_motor,RL_tibia_motor]

for motor in Motor_List:
    motor.setPosition(float('inf'))
    motor.setVelocity(0)


rospy.init_node('sim', anonymous=True)
sub= rospy.Subscriber('leg_poses',JointState,twistCallback)

        

while robot.step(timeStep) != -1:
    pass
    

    
	



        





