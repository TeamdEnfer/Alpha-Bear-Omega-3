#include <controls/hardware_interface.h>

#define PI 3.141592653
#define RAD2DEG 180/PI
#define DEG2RAD PI/180

Bear::Bear(ros::NodeHandle& nh) : nh_(nh) {

 

// Declare all JointHandles, JointInterfaces and JointLimitInterfaces of the robot.
    init();
    
// Create the controller manager
    controller_manager_.reset(new controller_manager::ControllerManager(this, nh_));
    
//Set the frequency of the control loop.
    loop_hz_= 200;
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
        

    //HWI pour la jambe avant gauche
    jsHandle[0] = hardware_interface::JointStateHandle(("FL_shoulder_servo"), &pos[0], &vel[0], &eff[0]);
    joint_state_interface_.registerHandle(jsHandle[0]);

    jpHandle[0] = hardware_interface::JointHandle(joint_state_interface_.getHandle(("FL_shoulder_servo")), &cmd[0]);
    position_joint_interface_.registerHandle(jpHandle[0]);

    jsHandle[1] = hardware_interface::JointStateHandle(("FL_femur_servo"), &pos[1], &vel[1], &eff[1]);
    joint_state_interface_.registerHandle(jsHandle[1]);

    jpHandle[1] = hardware_interface::JointHandle(joint_state_interface_.getHandle(("FL_femur_servo")), &cmd[1]);
    position_joint_interface_.registerHandle(jpHandle[1]);

    jsHandle[2] = hardware_interface::JointStateHandle(("FL_tibia_servo"), &pos[2], &vel[2], &eff[2]);
    joint_state_interface_.registerHandle(jsHandle[2]);

    jpHandle[2] = hardware_interface::JointHandle(joint_state_interface_.getHandle(("FL_tibia_servo")), &cmd[2]);
    position_joint_interface_.registerHandle(jpHandle[2]);

    //HWI pour la jambe avant droite
    jsHandle[3] = hardware_interface::JointStateHandle(("FR_shoulder_servo"), &pos[3], &vel[3], &eff[3]);
    joint_state_interface_.registerHandle(jsHandle[3]);

    jpHandle[3] = hardware_interface::JointHandle(joint_state_interface_.getHandle(("FR_shoulder_servo")), &cmd[3]);
    position_joint_interface_.registerHandle(jpHandle[3]);

    jsHandle[4] = hardware_interface::JointStateHandle(("FR_femur_servo"), &pos[4], &vel[4], &eff[4]);
    joint_state_interface_.registerHandle(jsHandle[4]);

    jpHandle[4] = hardware_interface::JointHandle(joint_state_interface_.getHandle(("FR_femur_servo")), &cmd[4]);
    position_joint_interface_.registerHandle(jpHandle[4]);

    jsHandle[5] = hardware_interface::JointStateHandle(("FR_tibia_servo"), &pos[5], &vel[5], &eff[5]);
    joint_state_interface_.registerHandle(jsHandle[5]);

    jpHandle[5] = hardware_interface::JointHandle(joint_state_interface_.getHandle(("FR_tibia_servo")), &cmd[5]);
    position_joint_interface_.registerHandle(jpHandle[5]);

    //HWI pour la jambe arriere gauche
    jsHandle[6] = hardware_interface::JointStateHandle(("RL_shoulder_servo"), &pos[6], &vel[6], &eff[6]);
    joint_state_interface_.registerHandle(jsHandle[6]);

    jpHandle[6] = hardware_interface::JointHandle(joint_state_interface_.getHandle(("RL_shoulder_servo")), &cmd[6]);
    position_joint_interface_.registerHandle(jpHandle[6]);

    jsHandle[7] = hardware_interface::JointStateHandle(("RL_femur_servo"), &pos[7], &vel[7], &eff[7]);
    joint_state_interface_.registerHandle(jsHandle[7]);

    jpHandle[7] = hardware_interface::JointHandle(joint_state_interface_.getHandle(("RL_femur_servo")), &cmd[7]);
    position_joint_interface_.registerHandle(jpHandle[7]);

    jsHandle[8] = hardware_interface::JointStateHandle(("RL_tibia_servo"), &pos[8], &vel[8], &eff[8]);
    joint_state_interface_.registerHandle(jsHandle[8]);

    jpHandle[8] = hardware_interface::JointHandle(joint_state_interface_.getHandle(("RL_tibia_servo")), &cmd[8]);
    position_joint_interface_.registerHandle(jpHandle[8]);

    //HWI pour la jambe arriere droite
    jsHandle[9] = hardware_interface::JointStateHandle(("RR_shoulder_servo"), &pos[9], &vel[9], &eff[9]);
    joint_state_interface_.registerHandle(jsHandle[9]);

    jpHandle[9] = hardware_interface::JointHandle(joint_state_interface_.getHandle(("RR_shoulder_servo")), &cmd[9]);
    position_joint_interface_.registerHandle(jpHandle[9]);

    jsHandle[10] = hardware_interface::JointStateHandle(("RR_femur_servo"), &pos[10], &vel[10], &eff[10]);
    joint_state_interface_.registerHandle(jsHandle[10]);

    jpHandle[10] = hardware_interface::JointHandle(joint_state_interface_.getHandle(("RR_femur_servo")), &cmd[10]);
    position_joint_interface_.registerHandle(jpHandle[10]);

    jsHandle[11] = hardware_interface::JointStateHandle(("RR_tibia_servo"), &pos[11], &vel[11], &eff[11]);
    joint_state_interface_.registerHandle(jsHandle[11]);

    jpHandle[11] = hardware_interface::JointHandle(joint_state_interface_.getHandle(("RR_tibia_servo")), &cmd[11]);
    position_joint_interface_.registerHandle(jpHandle[11]);

// Register all joints interfaces    
    registerInterface(&joint_state_interface_);
    registerInterface(&position_joint_interface_);
    //registerInterface(&positionJointSaturationInterface);    

    ros::Subscriber sub = nh_.subscribe("Feedback", 10 ,&Bear::fetchFeedback, this);// <std_msgs::Float64MultiArray>
    ros::Subscriber Arduino_joint_position_subsriber = nh_.subscribe("feedback", <std_msgs::Float64MultiArray>, 12, &Bear::read, this);
}



//This is the control loop
void Bear::update(const ros::TimerEvent& e) {
    elapsed_time_ = ros::Duration(e.current_real - e.last_real);
    read();
    controller_manager_->update(ros::Time::now(), elapsed_time_);
    write(elapsed_time_);
}



void Bear::read(std_msgs::Float64MultiArray Arduino_joint_position_topic){
    // Lecture des messages de commandes du controleur

    for (int i = 0; i < Nb_Of_Joints; i++) {
        joint_position[i] = Arduino_joint_position_topic.data[i]*DEG2RAD;
    }

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

    //On prend les messages de commande du controller, et on les mets dans un float64multiplearray, puis on les publish

    messageCommand.data.clear();
    for(int i = 0 ; i < Nb_Of_Joints ; i++)
    {
        messageCommand.data.push_back(cmd[i]*RAD2DEG);
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