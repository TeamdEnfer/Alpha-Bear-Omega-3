import rospy
import os
from geometry_msgs.msg import Twist



pub= rospy.Publisher('fr_leg_pose',Twist,queue_size=10)
rospy.init_node('leg_cinematic',anonymous=True)
rate1=rospy.Rate(1)
cmd_msg=Twist()

while True:
    cmd_msg.angular.x=10
    cmd_msg.angular.y=10
    cmd_msg.linear.x=1
    cmd_msg.linear.y=1
    pub.publish(cmd_msg)
    rate1.sleep()
    cmd_msg.linear.x=0
    cmd_msg.linear.y=0
    pub.publish()
    rate1.sleep()