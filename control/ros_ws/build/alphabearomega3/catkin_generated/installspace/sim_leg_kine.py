import rospy
import os
from geometry_msgs.msg import Vector3


def simKineTest():
    rospy.init_node('sim_leg_kine',anonymous=True)
    pub= rospy.Publisher('leg_poses',[Vector3],queue_size=10)
    rate1=rospy.Rate(0.5)
    cmd_msg=[]
    for i in Range(0,6):
        cmd_msg.append(Vector3)
        cmd_msg[i].x=0
        cmd_msg[i].y=0

    while not rospy.is_shutdown():
        for i in Range(0,6):
            cmd_msg[i].x=i*i+1
            cmd_msg[i].y=i+1
            
        pub.publish(cmd_msg)
