import rospy
import os
from controller import Robot
import math
from trajectory_msgs.msg import JointTrajectory
from std_msgs.msg import Float64
from threading import Lock
mutex=Lock()

       
def twistCallback(BiData):    
        with mutex:
            Motor_List[4].setPosition(BiData.data)
            Motor_List[4].setVelocity(10)
            print(BiData.data)
        
        
        
        
    


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
FR_shoulder_motor = robot.getDevice('FR_shoulder_servo')
FL_shoulder_motor = robot.getDevice('FL_shoulder_servo')
RR_shoulder_motor = robot.getDevice('RR_shoulder_servo')
RL_shoulder_motor = robot.getDevice('RL_shoulder_servo')

Motor_List=[FL_shoulder_motor,FL_femur_motor,FL_tibia_motor,FR_shoulder_motor,FR_femur_motor,FR_tibia_motor,RL_shoulder_motor,RL_femur_motor,RL_tibia_motor,RR_shoulder_motor,RR_femur_motor,RR_tibia_motor]
motor_IDs=[]

for i,motor in enumerate(Motor_List):
    motor.setPosition(float('inf'))
    motor.setVelocity(0)
    motor_IDs.append(i)




rospy.init_node('sim', anonymous=True)
sub= rospy.Subscriber('/Bear/Femur_FR_PositionController/command',Float64,twistCallback)

        

while robot.step(timeStep) != -1:
    with mutex:
        pass
        
    

    
	



        





	



        





