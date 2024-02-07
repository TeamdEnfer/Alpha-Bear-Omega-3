Etapes pour starter ROS sur le Pi, ainsi que la communication Rosserial

1: SSH sur le pi
2: roscore &
3: rosrun rosserial_python serial_node.py /dev/ttyACM0 & 

Nom du topic: /servo
    Format du message: rostopic pub /servo  std_msgs/UInt16 "data: 0"
    ou data: est un angle donner a un servo lier a la pin D13

Nom du node: /serial_node
