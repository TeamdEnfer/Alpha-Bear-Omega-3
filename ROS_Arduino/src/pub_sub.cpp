#include "config.h"

ros::NodeHandle  nh;

MPU6050 mpu1(Wire);
MPU6050 mpu2(Wire);

void servo_cmd( const std_msgs::Float64MultiArray &cmd_msg){
    Femur.write(cmd_msg.data[0]*(180/PI));
    Tibia.write(cmd_msg.data[1]*(180/PI));
}

void TCA9548A(uint8_t bus){
  Wire.beginTransmission(0x70);  // TCA9548A address
  Wire.write(1 << bus);          // send byte to select bus
  Wire.endTransmission();
}

ros::Publisher feedback("feedback", &data_imu);
ros::Subscriber<std_msgs::Float64MultiArray> command("command", servo_cmd);

void setup(){ 
  //nh.getHardware()->setBaud(115200);
  nh.initNode();

  Serial.begin(115200);

  TCA9548A(0);  
  Wire.begin();
  mpu1.begin();

  TCA9548A(1);  
  Wire.begin();
  mpu2.begin();

  data_imu.data_length = DATA_IMU_LENGTH;
  data_imu.data = (float*)malloc(sizeof(float) * data_imu.data_length);
  
  data_multi_imu.data_length = DATA_MULTIPLE_IMU_LENGTH;
  data_multi_imu.data = (float*)malloc(sizeof(float) * data_multi_imu.data_length);

  nh.subscribe(command);
  nh.advertise(feedback);

  Femur.attach(2);
  Tibia.attach(3);

  //Serial.begin(115200);
}

void readXYangles(std_msgs::Float64MultiArray* data_imu){
    float Xdata;
    float Ydata;

    TCA9548A(0);
    mpu1.update();
    Xdata = mpu1.getAngleX();

    TCA9548A(1);
    mpu2.update();
    Ydata = mpu2.getAngleY();

    data_imu->data[0] = Xdata;
    data_imu->data[1] = Ydata;
}

void loop(){
  readXYangles(&data_imu);
  feedback.publish(&data_imu);
  free(data_imu.data);

  data_imu.data = (float*)malloc(sizeof(float) * data_imu.data_length);

  nh.spinOnce();
}