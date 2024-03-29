import rospy
from trajectory_msgs.msg import JointTrajectory,JointTrajectoryPoint

pub=rospy.Publisher('/joint_group_position_controller/command',JointTrajectory,queue_size=10)

rospy.init_node('calibration',anonymous=True)
rate1=rospy.Rate(1)



positions=[0,90,125]*4
cmd_msg=JointTrajectory(points=[JointTrajectoryPoint(positions=[0,-1.57,3*3.1415/4]*4)])
print(cmd_msg)

i=0

while not rospy.is_shutdown():
    cmd_msg.header.stamp=rospy.Time.now()
    if i==10:
    	i=0
    pub.publish(cmd_msg)
    print(cmd_msg)
    #cmd_msg.points[0].positions[10]=-3.1415/2*(i%10)/10
    i=i+1
    
    rate1.sleep()
    
    
