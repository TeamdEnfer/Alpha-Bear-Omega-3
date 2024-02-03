import rospy
import os
import math
from sensor_msgs.msg import JointState

def simKineTest():
    rospy.init_node('sim_leg_kine',anonymous=True)
    pub= rospy.Publisher('leg_poses',JointState,queue_size=10)
    rate1=rospy.Rate(0.5)
    cmd_msg=JointState(position=[0]*8,velocity=[0]*8)
   

    
    while not rospy.is_shutdown():
        
        for i in range(0,len(cmd_msg.position)):
            cmd_msg.position[i]=math.radians(90*(i%2)+(-45*((i+1)%2)))
            cmd_msg.velocity[i]=10
            
        pub.publish(cmd_msg)
        rate1.sleep()

        for i in range(0,len(cmd_msg.position)):
            cmd_msg.position[i]=0
            cmd_msg.velocity[i]=50

        pub.publish(cmd_msg)
        rate1.sleep()
        

if __name__ == '__main__':
 
    try:
        simKineTest()
    except rospy.ROSInterruptException:
        pass