#include <controls/hardware_interface.h>



Bear::Bear(ros::NodeHandle& nh) : nh_(nh) {

 

// Declare all JointHandles, JointInterfaces and JointLimitInterfaces of the robot.
    init();
    
// Create the controller manager
    controller_manager_.reset(new controller_manager::ControllerManager(this, nh_));
    
//Set the frequency of the control loop.
    loop_hz_=100;
    ros::Duration update_freq = ros::Duration(1.0/loop_hz_);
    
//Run the control loop
    my_control_loop_ = nh_.createTimer(update_freq, &Bear::update, this);

//Inform master that the node will be publishing to topic /command with queue size 10
    commandPublisher = nh_.advertise<std_msgs::Float64MultiArray>("Command", 10);

    //ros::Subscriber<std_msgs::Float64MultiArray> sub("Feedback" , read);
}



Bear::~Bear() {
}



void Bear::init() {
        
// // Create joint_state_interface for JointA
//     hardware_interface::JointStateHandle jointStateHandleA("Femur_FR", &joint_position_[0]);
//     joint_state_interface_.registerHandle(jointStateHandleA);
// // Create effort joint interface as JointA accepts effort command.
//     hardware_interface::JointHandle jointPositionHandleA(jointStateHandleA, &joint_position_command_[0]);
//     position_joint_interface_.registerHandle(jointPositionHandleA); 
// // Create Joint Limit interface for JointA
//     joint_limits_interface::getJointLimits("Femur_FR", nh_, limits);
//     joint_limits_interface::PositionJointSaturationHandle jointLimitsHandleA(jointPositionHandleA, limits);
//     positionJointSaturationInterface.registerHandle(jointLimitsHandleA);    

    

// // Create joint_state_interface for JointC
//     hardware_interface::JointStateHandle jointStateHandleC("Tibia_FR", &joint_position_[2]);
//     joint_state_interface_.registerHandle(jointStateHandleC);

// // Create position joint interface as JointC accepts position command.
//     hardware_interface::JointHandle jointPositionHandleC(jointStateHandleC, &joint_position_command_);
//     position_joint_interface_.registerHandle(jointPositionHandleC);
// // Create Joint Limit interface for JointC
//     joint_limits_interface::getJointLimits("Tibia_FR", nh_, limits);
//     joint_limits_interface::PositionJointSaturationHandle jointLimitsHandleC(jointPositionHandleC, limits);
//     positionJointSaturationInterface.registerHandle(jointLimitsHandleC);    
    // for(int i = 0 ; i < Nb_Of_Joints ; i++)
    // {

    //     jsHandle[i] = hardware_interface::JointStateHandle(("J" + std::to_string(i+1)), &pos[i], &vel[i], &eff[i]);
    //     joint_state_interface_.registerHandle(jsHandle[i]);

    //     jpHandle[i] = hardware_interface::JointHandle(joint_state_interface_.getHandle(("J" + std::to_string(i+1))), &cmd[i]);
    //     position_joint_interface_.registerHandle(jpHandle[i]);

    // }
        jsHandle[0] = hardware_interface::JointStateHandle(("Femur_FR"), &pos[0], &vel[0], &eff[0]);
        joint_state_interface_.registerHandle(jsHandle[0]);

        jpHandle[0] = hardware_interface::JointHandle(joint_state_interface_.getHandle(("Femur_FR")), &cmd[0]);
        position_joint_interface_.registerHandle(jpHandle[0]);

        jsHandle[1] = hardware_interface::JointStateHandle(("Tibia_FR"), &pos[1], &vel[1], &eff[1]);
        joint_state_interface_.registerHandle(jsHandle[1]);

        jpHandle[1] = hardware_interface::JointHandle(joint_state_interface_.getHandle(("Tibia_FR")), &cmd[1]);
        position_joint_interface_.registerHandle(jpHandle[1]);



// Register all joints interfaces    
    registerInterface(&joint_state_interface_);
    registerInterface(&position_joint_interface_);
    //registerInterface(&positionJointSaturationInterface);    

    ros::Subscriber sub = nh_.subscribe("Feedback", 10 ,&Bear::fetchFeedback, this);// <std_msgs::Float64MultiArray>
    
}



//This is the control loop
void Bear::update(const ros::TimerEvent& e) {
    elapsed_time_ = ros::Duration(e.current_real - e.last_real);
    read();
    controller_manager_->update(ros::Time::now(), elapsed_time_);
    write(elapsed_time_);
}



void Bear::read(){



  //from robot.
  // and fill JointStateHandle variables joint_position_[i], joint_velocity_[i] and joint_effort_[i]

}

void Bear::fetchFeedback(const std_msgs::Float64MultiArray& feedback_message)
{
    //On s'attend a recevoir des lectures de IMU de la part du arduino via rosserial
    //On prend les lecture et on les met dans le JointStateHandle (jsHandle[i]) du joint approrier.

    
    for(int i = 0 ; i < Nb_Of_Joints ; i++)
    {
        pos[i] = feedback_message.data[i];
    }
}



void Bear::write(ros::Duration elapsed_time) {

    //On prend les messages d ecommande du controller, et on les mets dans un float64multiplearray, puis on les publish

    messageCommand.data.clear();
    for(int i = 0 ; i < Nb_Of_Joints ; i++)
    {
        messageCommand.data.push_back(cmd[i]);
    }

    commandPublisher.publish(messageCommand);

}



int main(int argc, char** argv)
{

    //Initialze the ROS node.
    ros::init(argc, argv, "Bear_hardware_interface_node");
    ros::NodeHandle nh;
    
    //Separate Sinner thread for the Non-Real time callbacks such as service callbacks to load controllers
    ros::MultiThreadedSpinner spinner(2); 
    
    
    // Create the object of the robot hardware_interface class and spin the thread. 
    Bear Bear(nh);
    spinner.spin();
    
    return 0;
}