#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/robot_hw.h>
#include <joint_limits_interface/joint_limits.h>
#include <joint_limits_interface/joint_limits_interface.h>
#include <controller_manager/controller_manager.h>
#include <boost/scoped_ptr.hpp>
#include <ros/ros.h>
#include <ros/console.h>
#include <std_msgs/String.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Int8MultiArray.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Bool.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/JointState.h>
#include <string.h>
#include <controls/Servo_cmd.h>
#include <controls/BNO.h>
#include <math.h>
#include <trajectory_msgs/JointTrajectory.h>


#define NB_OF_JOINTS 12

class Bear : public hardware_interface::RobotHW {
    public:
        Bear(ros::NodeHandle& nh);
        ~Bear();
        void init();
        void update(const ros::TimerEvent& e);
        void Angles_callback(const controls::Servo_cmd Pot_data);
        void IMU_callback(const controls::BNO& BNO_callback);
        void fetchFeedback(const std_msgs::Float64MultiArray& feedback_message);
        void write( trajectory_msgs::JointTrajectory );
        void Selector(const std_msgs::Bool& controller_selector);
        void GUI_ID(const std_msgs::Int8& GUI_id);
        void GUI_CMD(const std_msgs::Float32& GUI_cmd);

        
    protected:
        hardware_interface::JointStateInterface joint_state_interface_;
        hardware_interface::PositionJointInterface position_joint_interface_;
        
        joint_limits_interface::JointLimits limits[NB_OF_JOINTS];        
        joint_limits_interface::JointLimits jlimits[NB_OF_JOINTS];

        hardware_interface::JointStateHandle jsHandle[NB_OF_JOINTS];
        hardware_interface::JointHandle jpHandle[NB_OF_JOINTS];

        double pos[NB_OF_JOINTS];
        double vel[NB_OF_JOINTS];
        double eff[NB_OF_JOINTS];
        double cmd[NB_OF_JOINTS];
        double joint_position_command_;
        
        ros::Subscriber champ_cmd;
        ros::Subscriber GUI_cmd;
        ros::Subscriber GUI_id;
        ros::Subscriber controller_selector;
        ros::Subscriber BNO_callback;
        ros::Subscriber Pot_callback;

        ros::Publisher commandPublisher;
        ros::Publisher IMU_feedback_publisher;
		ros::Publisher JointStatePublisher;
		
        controls::Servo_cmd messageCommand;
        controls::Servo_cmd Pot_data;
        sensor_msgs::Imu IMU_data;  // 2024-04-03: should be changed to BNO_data
        sensor_msgs::JointState JointState;

        ros::NodeHandle nh_;
        ros::Timer my_control_loop_;
        ros::Duration elapsed_time_;
        double loop_hz_;
        boost::shared_ptr<controller_manager::ControllerManager> controller_manager_;
};