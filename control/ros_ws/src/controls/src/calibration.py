import rospy
from trajectory_msgs.msg import JointTrajectory,JointTrajectoryPoint

pub=rospy.Publisher('/joint_group_position_controller/command',JointTrajectory,queue_size=10)

rospy.init_node('calibration',anonymous=True)
rate1=rospy.Rate(10)



positions=[0,90,125]*4
cmd_msg=JointTrajectory(points=[JointTrajectoryPoint(positions=[0,-1.57,2.18]*4)])
print(cmd_msg)



while not rospy.is_shutdown():
    cmd_msg.header.stamp=rospy.Time.now()
    
    pub.publish(cmd_msg)
    rate1.sleep()
    
    