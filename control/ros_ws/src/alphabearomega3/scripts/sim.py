import rospy
import os
from controller import Robot
import math
from trajectory_msgs.msg import JointTrajectory
from sensor_msgs.msg import JointState,Imu
from champ_msgs.msg import ContactsStamped
from threading import Lock
mutex=Lock()

       
def twistCallback(BiData):    
        with mutex:
            adjust=[1,1/0.7542,0.5555]
            for i in range(len(BiData.points[0].positions)):
                #print(round(BiData.data[motor_IDs[i]]/360*(2*math.pi),4))
                
                #Motor_List[motor_IDs[i]].setPosition((i%3==2 or i%3==0)*BiData.points[0].positions[motor_IDs[i]]*adjust[i%3]+(i%3==2)*(BiData.points[0].positions[motor_IDs[i-1]])+(i%3==1)*1.2823*math.exp(0.3865*BiData.points[0].positions[motor_IDs[i]]))
                Motor_List[motor_IDs[i]].setPosition(BiData.points[0].positions[motor_IDs[i]])
                Motor_List[motor_IDs[i]].setVelocity(10)
                #print()
            feedback_msg.position=get_feedback()
            feedback_msg.header.stamp=rospy.Time.now()
            foot_msg.contacts=get_contacts()
            foot_msg.header.stamp=rospy.Time.now()
            get_imu()
            
            #print(foot_msg)
            #feedback_msg.secs=now.secs
            #feedback_msg.nsecs=now.nsecs
            pup.publish(feedback_msg)
            pupTouch.publish(foot_msg)
            pupImu.publish(imu_msg)
            
        
def enable(thelist):
    for i in range(len(thelist)):
        thelist[i].enable(10)
     
def get_feedback():

    data=[0]*12
    for i in range(len(Position_List)):
        data[i]=Position_List[motor_IDs[i]].getValue()
    return data
        
def get_contacts():
    data=[0]*len(Touch_List)
    for i in range(len(Touch_List)):
        data[i]=Touch_List[i].getValue()==1.0
    
    return data

def get_imu():
    imu_msg.orientation_covariance=[0]*9
    imu_msg.orientation_covariance[0]=-1
    #print("quaternion ",alpha_imu.getQuaternion())
    imu_msg.orientation.x=alpha_imu.getQuaternion()[0]
    imu_msg.orientation.y=alpha_imu.getQuaternion()[1]
    imu_msg.orientation.z=alpha_imu.getQuaternion()[2]
    imu_msg.orientation.w=alpha_imu.getQuaternion()[3]
    imu_msg.angular_velocity_covariance=[0]*9
    imu_msg.angular_velocity_covariance[0]=-1
    #print("gyro ",alpha_gyro.getValues())
    imu_msg.angular_velocity.x=alpha_gyro.getValues()[0]
    imu_msg.angular_velocity.y=alpha_gyro.getValues()[1]
    imu_msg.angular_velocity.z=alpha_gyro.getValues()[2]
    imu_msg.linear_acceleration_covariance=[0]*9
    imu_msg.linear_acceleration_covariance[0]=-1
    #print("accel ",alpha_accel.getValues())
    imu_msg.linear_acceleration.x=alpha_accel.getValues()[0]
    imu_msg.linear_acceleration.y=alpha_accel.getValues()[1]
    imu_msg.linear_acceleration.z=alpha_accel.getValues()[2]
    
    
    

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

FR_touch_sensor = robot.getDevice('FR_touch_sensor')
FL_touch_sensor = robot.getDevice('FL_touch_sensor')
RR_touch_sensor = robot.getDevice('RR_touch_sensor')
RL_touch_sensor = robot.getDevice('RL_touch_sensor')

alpha_imu= robot.getDevice('alpha_imu')
alpha_accel=robot.getDevice('alpha_accel')

alpha_gyro=robot.getDevice('alpha_gyro')



Position_name_list=['FL_shoulder_servo','FL_femur_servo','FL_tibia_servo','FR_shoulder_servo','FR_femur_servo','FR_tibia_servo','RL_shoulder_servo','RL_femur_servo','RL_tibia_servo','RR_shoulder_servo','RR_femur_servo','RR_tibia_servo']

Motor_List=[FL_shoulder_motor,FL_femur_motor,FL_tibia_motor,FR_shoulder_motor,FR_femur_motor,FR_tibia_motor,RL_shoulder_motor,RL_femur_motor,RL_tibia_motor,RR_shoulder_motor,RR_femur_motor,RR_tibia_motor]
Position_List=[FL_shoulder_feedback,FL_femur_feedback,FL_tibia_feedback,FR_shoulder_feedback,FR_femur_feedback,FR_tibia_feedback,RL_shoulder_feedback,RL_femur_feedback,RL_tibia_feedback,RR_shoulder_feedback,RR_femur_feedback,RR_tibia_feedback]
Touch_List=[FL_touch_sensor,FR_touch_sensor,RL_touch_sensor,RR_touch_sensor]


motor_IDs=[]



for i,motor in enumerate(Motor_List):
    motor.setPosition(float('inf'))
    motor.setVelocity(0)
    motor_IDs.append(i)

enable(Position_List)
enable(Touch_List)
enable([alpha_imu])
enable([alpha_accel])
enable([alpha_gyro])

pup= rospy.Publisher('/joint_states',JointState,queue_size=10)
pupTouch= rospy.Publisher('/foot_contacts',ContactsStamped,queue_size=10)
pupImu= rospy.Publisher('/imu/data',Imu,queue_size=10)

rospy.init_node('sim', anonymous=True)
sub= rospy.Subscriber('/joint_group_position_controller/command',JointTrajectory,twistCallback)

feedback_msg= JointState()
feedback_msg.position=[0]*len(Position_List)
feedback_msg.name=Position_name_list
foot_msg=ContactsStamped()
foot_msg.contacts=[False]*len(Touch_List)
imu_msg=Imu()



        

while robot.step(timeStep) != -1 and not rospy.is_shutdown():
    with mutex:
        pass