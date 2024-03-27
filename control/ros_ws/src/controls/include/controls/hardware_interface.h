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
#include <string.h>
#include <controls/Servo_cmd.h>
#include <controls/BNO.h>
#include <math.h>
#include <trajectory_msgs/JointTrajectory.h>


#define Nb_Of_Joints 12

class Bear : public hardware_interface::RobotHW 
{
    public:
        Bear(ros::NodeHandle& nh);
        ~Bear();
        void init();
        void update(const ros::TimerEvent& e);
        //void read(const std_msgs::Float64MultiArray& Arduino_joint_position_subsriber);
        void read(const std_msgs::Int8MultiArray& Arduino_joint_position_subsriber);
        void IMU_callback(const controls::BNO& BNO_callback);
        void fetchFeedback(const std_msgs::Float64MultiArray& feedback_message);
        void write( trajectory_msgs::JointTrajectory );
        void Selector(const std_msgs::Bool& controller_selector);
        void GUI_ID(const std_msgs::Int8& GUI_id);
        void GUI_CMD(const std_msgs::Float32& GUI_cmd);

        
    protected:

        hardware_interface::JointStateInterface joint_state_interface_;
        hardware_interface::PositionJointInterface position_joint_interface_;
        
        joint_limits_interface::JointLimits limits[Nb_Of_Joints];
        //joint_limits_interface::PositionJointSaturationInterface positionJointSaturationInterface;
        
        joint_limits_interface::JointLimits jlimits[Nb_Of_Joints];

        hardware_interface::JointStateHandle jsHandle[Nb_Of_Joints];
        hardware_interface::JointHandle jpHandle[Nb_Of_Joints];

        double pos[Nb_Of_Joints];
        double vel[Nb_Of_Joints];
        double eff[Nb_Of_Joints];
        double cmd[Nb_Of_Joints];
        double joint_position_command_;
        
        ros::Subscriber champ_cmd;
        ros::Subscriber GUI_cmd;
        ros::Subscriber GUI_id;
        ros::Subscriber controller_selector;
        ros::Subscriber BNO_callback;

        ros::Subscriber Arduino_joint_position_subsriber;
        ros::Publisher commandPublisher;
        ros::Publisher IMU_feedback_publisher;
        //std_msgs::Float32MultiArray messageCommand;
        controls::Servo_cmd messageCommand;
        sensor_msgs::Imu IMU_data;

        ros::NodeHandle nh_;
        ros::Timer my_control_loop_;
        ros::Duration elapsed_time_;
        double loop_hz_;
        boost::shared_ptr<controller_manager::ControllerManager> controller_manager_;
};