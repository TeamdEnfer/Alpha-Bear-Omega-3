import rospy
import os
from geometry_msgs.msg import Twist
from std_msgs.msg import UInt16MultiArray


def angleTest():
    pub= rospy.Publisher('servo',UInt16,queue_size=10)
    rospy.init_node('leg_kine',anonymous=True)
    rate1=rospy.Rate(10)
    cmd_msg=UInt16MultiArray

    while not rospy.is_shutdown():
      
        cmd_msg.data[0]=1
        pub.publish(cmd_msg)
        rate1.sleep()

if __name__ == '__main__':
 
    try:
        angleTest()
    except rospy.ROSInterruptException:
        pass