#include <controls/hardware_interface.h>

#define PI 3.141592653
#define RAD2DEG 180/PI
#define DEG2RAD PI/180

bool ctrl_selector = false;
int leg_id = 0;         // [0, 11]; see 'config.h' for map
float leg_cmd = 0.0;    // cmd received from Arduino (deg)


Bear::Bear(ros::NodeHandle& nh) : nh_(nh) {



// Declare all JointHandles, JointInterfaces and JointLimitInterfaces of the robot.
    init();
    
// Create the controller manager
    controller_manager_.reset(new controller_manager::ControllerManager(this, nh_));
    
//Set the frequency of the control loop.
    loop_hz_= 100;
    // Sets the loop's period (ms)
    ros::Duration update_freq = ros::Duration(1.0/loop_hz_);
    
//Run the control loop
    my_control_loop_ = nh_.createTimer(update_freq, &Bear::update, this);

// Initializes publishers that communicate servo commands
// (FR) On publish les commande qui vont au servos
    commandPublisher = nh_.advertise<controls::Servo_cmd>("Command", 12);
    IMU_feedback_publisher = nh_.advertise<sensor_msgs::Imu>("imu/data" , 12);

// Subscribes to ArduiNode
// (FR) On subscribe au ArduiNode
    Pot_callback = nh_.subscribe("pot_feedback_topic" , 12 , &Bear::Angles_callback , this);
    BNO_callback = nh_.subscribe("Feedback" , 12 , &Bear::IMU_callback, this);

// Subscribes to CHAMP controller
// (FR) on subscribe au controller champ
    champ_cmd = nh_.subscribe("/joint_group_position_controller/command" , 10 , &Bear::write , this);

// Subscribes to GUI topics for manual control of the legs
// (FR) on subscribe au topics du GUI pour pouvoir controller manuellement, et changer de controlleur
    GUI_cmd = nh_.subscribe("/servo_cmd_topic" , 12 , &Bear::GUI_CMD , this);
    GUI_id = nh_.subscribe("/servo_id_topic" , 12 , &Bear::GUI_ID , this);
    controller_selector = nh_.subscribe("/control_switch_flag" , 1 , &Bear::Selector , this);
}


// Class destructor
Bear::~Bear() {
}


// Class instance initialization method
void Bear::init() {
        
// TODO: clean up commented codes
    //IMU_data.linear_acceleration.x = 0;
    //IMU_data.linear_acceleration.y = 0;
    //IMU_data.linear_acceleration.z = 0;

    // HWI for front left leg
    // (FR) HWI pour la jambe avant gauche
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

    // HWI for front right leg
    // (FR) HWI pour la jambe avant droite
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

    // HWI for rear left leg
    // (FR) HWI pour la jambe arriere gauche
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

    // HWI for rear right leg
    // (FR) HWI pour la jambe arriere droite
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
    // registerInterface(&positionJointSaturationInterface);    // 2024-04-03: Is this still usefull?

    //ros::Subscriber sub = nh_.subscribe("Feedback", 10 ,&Bear::fetchFeedback, this);// <std_msgs::Float64MultiArray> // 2024-04-03: Is this still usefull?
}



// This is the control loop
void Bear::update(const ros::TimerEvent& e) {
    elapsed_time_ = ros::Duration(e.current_real - e.last_real);
    //read();
    controller_manager_->update(ros::Time::now(), elapsed_time_);
    //write(elapsed_time_);
}

// Controller selector update method
void Bear::Selector(const std_msgs::Bool& controller_selector) {
    ctrl_selector = controller_selector.data;
}

// Servo ID update method (incorrectly named 'leg_id')
void Bear::GUI_ID(const std_msgs::Int8& GUI_id) {
    leg_id = GUI_id.data;
}

// Update servo cmd received from GUI
void Bear::GUI_CMD(const std_msgs::Float32& GUI_cmd) {
    leg_cmd = GUI_cmd.data;
}

//void Bear::read(const std_msgs::Float64MultiArray& Arduino_joint_position_topic){ // 2024-04-03: Is this still usefull?

// Read cmd msgs from Arduino
void Bear::Angles_callback(const controls::Servo_cmd Pot_callback) {
    for (int i = 0; i < Nb_Of_Joints; i++) {
        pos[i] = Pot_callback.data[i] * DEG2RAD;
    }
}

// BNO data update method (incorrectly called IMU_callback)
void Bear::IMU_callback(const controls::BNO& BNO_callback) {
    // Linear acceleration
    IMU_data.linear_acceleration.x = BNO_callback.data[0];
    IMU_data.linear_acceleration.y = BNO_callback.data[1];
    IMU_data.linear_acceleration.z = BNO_callback.data[2];

    // Body orientation data (quaternions)
    IMU_data.orientation.x = BNO_callback.data[3]*DEG2RAD;
    IMU_data.orientation.y = BNO_callback.data[4]*DEG2RAD;
    IMU_data.orientation.z = BNO_callback.data[5]*DEG2RAD;
    IMU_data.orientation.w = BNO_callback.data[6]*DEG2RAD;

    for(int i = 0 ; i < 9 ; i++) {  // 8 potentiometers are used, so hard-coded 9
        IMU_data.linear_acceleration_covariance[i] = 0;
        IMU_data.orientation_covariance[i] = 0;
    }

    // Linear velocity
    IMU_data.angular_velocity_covariance[0] = -1;

    // Publish data to CHAMP controller
    IMU_feedback_publisher.publish(IMU_data);
}

// 2024-04-03: is still useful?
void Bear::fetchFeedback(const std_msgs::Float64MultiArray& feedback_message)
{
    //On s'attend a recevoir des lectures de IMU de la part du arduino via rosserial
    //On prend les lecture et on les met dans le JointStateHandle (jsHandle[i]) du joint approrier.

    
    for(int i = 0 ; i < Nb_Of_Joints ; i++)
    {
        pos[i] = feedback_message.data[i];
    }
}

// Send cmds to servos received from controller
void Bear::write(trajectory_msgs::JointTrajectory champ_cmd) {

    // 2024-04-03: is this still useful?
    //On prend les messages de commande du controller, et on les mets dans un float64multiplearray, puis on les publish
	float ratio_pulleys_tibia=20.0f/36.0f;
    float OFFSET_03 = 2*PI/4;
    float OFFSET_69 = -2*PI/4;

    // Sending cmds with CHAMP controller
    if(ctrl_selector == false) {    // Could be changed to '!ctrl_selector'

/* Servo structure:
    1) Block = leg: [front left, front right, rear left, rear right]
    2) In the same block:
        i) Shoulder
        ii) Femur
        iii) Tibia
*/
        // N.B. This section is FULL of magic numbers; ask TX for more info.
        messageCommand.data[0]=(abs((-champ_cmd.points[0].positions[0]+OFFSET_03)*RAD2DEG));
        messageCommand.data[1]=(0.3408*pow(champ_cmd.points[0].positions[1],2)-0.6434*(champ_cmd.points[0].positions[1])+0.0095)*RAD2DEG;
        messageCommand.data[2]=abs((champ_cmd.points[0].positions[2]-champ_cmd.points[0].positions[1]*ratio_pulleys_tibia+champ_cmd.points[0].positions[1]-1.658063)/ratio_pulleys_tibia)*RAD2DEG;

        messageCommand.data[3]=(abs((-champ_cmd.points[0].positions[3]+OFFSET_03)*RAD2DEG));
        messageCommand.data[4]=(-0.3593*pow(champ_cmd.points[0].positions[4],2)+0.6064*champ_cmd.points[0].positions[4]+2.375)*RAD2DEG;  
        messageCommand.data[5]=((champ_cmd.points[0].positions[5])-champ_cmd.points[0].positions[4]*ratio_pulleys_tibia+champ_cmd.points[0].positions[4])/ratio_pulleys_tibia*RAD2DEG;

        messageCommand.data[6]=(abs((champ_cmd.points[0].positions[6]+OFFSET_69)*RAD2DEG));
        messageCommand.data[7]=(0.3408*pow(champ_cmd.points[0].positions[7],2)-0.6434*(champ_cmd.points[0].positions[7])+0.0095)*RAD2DEG;
        messageCommand.data[8]=abs((champ_cmd.points[0].positions[8]-champ_cmd.points[0].positions[7]*ratio_pulleys_tibia+champ_cmd.points[0].positions[7]-1.658063)/ratio_pulleys_tibia)*RAD2DEG;

        messageCommand.data[9]=(abs((champ_cmd.points[0].positions[9]+OFFSET_69)*RAD2DEG));
        messageCommand.data[10]=(-0.3593*pow(champ_cmd.points[0].positions[10],2)+0.6064*champ_cmd.points[0].positions[10]+2.375)*RAD2DEG;  
        messageCommand.data[11]=((champ_cmd.points[0].positions[11])-champ_cmd.points[0].positions[10]*ratio_pulleys_tibia+champ_cmd.points[0].positions[10])/ratio_pulleys_tibia*RAD2DEG;
    }

    // Sending cmds with manual controller
    else if (ctrl_selector == true) {   // Unnecessary (should be replaced with else)
        messageCommand.data[leg_id] = leg_cmd;
    }

    commandPublisher.publish(messageCommand);
}


int main(int argc, char** argv) {

    // Initialize the HWI node
    ros::init(argc, argv, "Bear_hardware_interface_node");
    ros::NodeHandle nh;
    
    // Separate Sinner thread for the Non Real-Time callbacks, such as service callbacks to load controllers
    ros::MultiThreadedSpinner spinner(2); 
    
    // Instanciate the robot's HWI and spin the thread 
    Bear Bear(nh);
    spinner.spin();
    
    return 0;
}
