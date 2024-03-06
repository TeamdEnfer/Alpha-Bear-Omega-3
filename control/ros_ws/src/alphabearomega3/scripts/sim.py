import rospy
import os
from controller import Robot
import math
from trajectory_msgs.msg import JointTrajectory
from sensor_msgs.msg import JointState
from threading import Lock
mutex=Lock()

       
def twistCallback(BiData):    
        with mutex:
            adjust=[1,1/0.7542,0.5555]
            for i in range(len(BiData.points[0].positions)):
                #print(round(BiData.data[motor_IDs[i]]/360*(2*math.pi),4))
                
                Motor_List[motor_IDs[i]].setPosition(BiData.points[0].positions[motor_IDs[i]]*adjust[i%3]+((i%3==2)*(BiData.points[0].positions[motor_IDs[i-1]])))
                Motor_List[motor_IDs[i]].setVelocity(10)
                #print()
            feedback_msg.position=get_feedback()
            feedback_msg.header.stamp=rospy.Time.now()
            #feedback_msg.secs=now.secs
            #feedback_msg.nsecs=now.nsecs
            pup.publish(feedback_msg)
            
        
def enable_feedback():
    for i in range(len(Position_List)):
        Position_List[i].enable(10)
     
def get_feedback():

    data=[0]*12
    for i in range(len(Position_List)):
        data[i]=Position_List[motor_IDs[i]].getValue()
    return data
        
    


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



FR_femur_feedback = robot.getDevice('FR_femur_feedback')
FL_femur_feedback = robot.getDevice('FL_femur_feedback')
RR_femur_feedback = robot.getDevice('RR_femur_feedback')
RL_femur_feedback = robot.getDevice('RL_femur_feedback')
FR_tibia_feedback= robot.getDevice('FR_tibia_feedback')
FL_tibia_feedback= robot.getDevice('FL_tibia_feedback')
RR_tibia_feedback= robot.getDevice('RR_tibia_feedback')
RL_tibia_feedback= robot.getDevice('RL_tibia_feedback')
FR_shoulder_feedback = robot.getDevice('FR_shoulder_feedback')
FL_shoulder_feedback = robot.getDevice('FL_shoulder_feedback')
RR_shoulder_feedback = robot.getDevice('RR_shoulder_feedback')
RL_shoulder_feedback = robot.getDevice('RL_shoulder_feedback')

Position_name_list=['FL_shoulder_servo','FL_femur_servo','FL_tibia_servo','FR_shoulder_servo','FR_femur_servo','FR_tibia_servo','RL_shoulder_servo','RL_femur_servo','RL_tibia_servo','RR_shoulder_servo','RR_femur_servo','RR_tibia_servo']

Motor_List=[FL_shoulder_motor,FL_femur_motor,FL_tibia_motor,FR_shoulder_motor,FR_femur_motor,FR_tibia_motor,RL_shoulder_motor,RL_femur_motor,RL_tibia_motor,RR_shoulder_motor,RR_femur_motor,RR_tibia_motor]
Position_List=[FL_shoulder_feedback,FL_femur_feedback,FL_tibia_feedback,FR_shoulder_feedback,FR_femur_feedback,FR_tibia_feedback,RL_shoulder_feedback,RL_femur_feedback,RL_tibia_feedback,RR_shoulder_feedback,RR_femur_feedback,RR_tibia_feedback]
motor_IDs=[]



for i,motor in enumerate(Motor_List):
    motor.setPosition(float('inf'))
    motor.setVelocity(0)
    motor_IDs.append(i)

enable_feedback()


pup= rospy.Publisher('/joint_states',JointState,queue_size=10)

rospy.init_node('sim', anonymous=True)
sub= rospy.Subscriber('/joint_group_position_controller/command',JointTrajectory,twistCallback)

feedback_msg= JointState()
feedback_msg.position=[0]*12
feedback_msg.name=Position_name_list

        

while robot.step(timeStep) != -1 and not rospy.is_shutdown():
    with mutex:
        
        pass