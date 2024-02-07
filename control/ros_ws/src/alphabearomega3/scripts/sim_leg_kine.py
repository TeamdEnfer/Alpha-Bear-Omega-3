import rospy
import os
import math
from sensor_msgs.msg import JointState

def simKineTest():
    rospy.init_node('sim_leg_kine',anonymous=True)
    pub= rospy.Publisher('leg_poses',JointState,queue_size=10)
    rate1=rospy.Rate(10)
    cmd_msg=JointState(position=[0]*8,velocity=[0]*12)
   

    
    while not rospy.is_shutdown():
        
        for i in range(0,len(cmd_msg.position)):
            cmd_msg.position[i]=math.radians(90*(i%2)+(-45*((i+1)%2)))
            cmd_msg.velocity[i]=50
            
        pub.publish(cmd_msg)
        rate1.sleep()

        for i in range(0,len(cmd_msg.position)):
            cmd_msg.position[i]=0
            cmd_msg.velocity[i]=10

        pub.publish(cmd_msg)
        rate1.sleep()

def simKine():
    rospy.init_node('sim_leg_kine',anonymous=True)
    pub= rospy.Publisher('leg_poses',JointState,queue_size=10)
    rate1=rospy.Rate(10)


    while not rospy.is_shutdown():
        

        pub.publish(init_pose())
        rate1.sleep()
        pub.publish(zero_pose())
        rate1.sleep()


def init_pose():
    num_servo=12
    cmd_msg=JointState(position=[0]*num_servo,velocity=[0]*num_servo)
    for i in range(0,len(cmd_msg.position)):
                cmd_msg.position[i]=math.radians(90*(i%2)+(-45*((i+1)%2)))
                cmd_msg.velocity[i]=50
    return cmd_msg

def zero_pose():
    num_servo=12
    cmd_msg=JointState(position=[0]*num_servo,velocity=[0]*num_servo)
    for i in range(0,len(cmd_msg.position)):
        cmd_msg.position[i]=0
        cmd_msg.velocity[i]=50
    return cmd_msg
    

    


   

if __name__ == '__main__':
 
    try:
        simKine()
    except rospy.ROSInterruptException:
        pass