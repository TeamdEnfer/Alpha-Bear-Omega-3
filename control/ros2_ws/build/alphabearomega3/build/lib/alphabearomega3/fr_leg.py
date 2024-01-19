import rclpy
#from rclpy.node import Node
#from geometry_msgs.msg import Twist

class FRleg:
    def init(self, webots_node, properties):
        #super().__init__('obstacle_avoider')
        #self.__publisher = self.create_publisher(Twist, 'cmd_vel', 1)
        self.__robot=webots_node.robot
        print("==============>",self.__robot)

        self.__femur_motor = self.__robot.getDevice('FR_femur_servo')

        self.__femur_motor.setPosition(float('inf'))
        #self.__setVelocity(3)
        

        
        self.__femur_motor.setVelocity(1)

        rclpy.init(args=None)
        self.__node= rclpy.create_node('fr_leg')
        








