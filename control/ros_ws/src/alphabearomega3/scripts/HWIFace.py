import rospy
import os
from trajectory_msgs.msg import JointTrajectory
from std_msgs.msg import Float64MultiArray

def JointmsgCallback(Data): 
    cmd_msg=Float64MultiArray(data=[0]*12)
    cmd_msg.data=Data.points[0].positions
    #print(cmd_msg)
    pub.publish(cmd_msg)
    
    

rospy.init_node('sigma_words')
sub= rospy.Subscriber('joint_group_position_controller/command',JointTrajectory,JointmsgCallback)
pub= rospy.Publisher('servo',Float64MultiArray,queue_size=10)
rate1=rospy.Rate(1)

while not rospy.is_shutdown():
    rate1.sleep()


