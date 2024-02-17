#include "config.h"

ros::NodeHandle  nh;

MPU6050 mpu(Wire);

void servo_cmd( const std_msgs::Float64MultiArray &cmd_msg){
    Femur.write(cmd_msg.data[0]*(180/PI));
    Tibia.write(cmd_msg.data[1]*(180/PI));
}

ros::Publisher feedback("feedback", &data_imu);
ros::Subscriber<std_msgs::Float64MultiArray> command("command", servo_cmd);

void setup(){ 
  Serial.begin(57600);
  nh.initNode();
  mpu.begin();
  Wire.begin();

  data_imu.data_length = DATA_IMU_LENGTH;
  data_imu.data = (float*)malloc(sizeof(float) * data_imu.data_length);
  
  data_multi_imu.data_length = DATA_MULTIPLE_IMU_LENGTH;
  data_multi_imu.data = (float*)malloc(sizeof(float) * data_imu.data_length);

  nh.subscribe(command);
  nh.advertise(feedback);

  Femur.attach(2);
  Tibia.attach(3);
}

void readXYangles(std_msgs::Float64MultiArray* data_imu){
    float Xdata;
    float Ydata;

    mpu.update();
    Xdata = mpu.getAngleX();
    Ydata = mpu.getAngleY();

    data_imu->data[0] = Xdata;
    data_imu->data[1] = Ydata;

}

void loop(){
  readXYangles(&data_imu);
  feedback.publish(&data_imu);
  free(data_imu.data);
  nh.spinOnce();
}