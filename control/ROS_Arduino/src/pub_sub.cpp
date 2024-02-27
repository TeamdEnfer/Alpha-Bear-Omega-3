#include "config.h"

ros::NodeHandle  nh;

void servo_cmd( const std_msgs::Float64MultiArray &cmd_msg){
    FEM_AV_D.write(cmd_msg.data[0]*(180/PI));
    TIB_AV_D.write(cmd_msg.data[1]*(180/PI));
    //ABD_AV_D.write(cmd_msg.data[2]*(180/PI));
    FEM_AV_G.write(cmd_msg.data[3]*(180/PI));
    TIB_AV_G.write(cmd_msg.data[4]*(180/PI));
    //ABD_AV_G.write(cmd_msg.data[5]*(180/PI));
    FEM_AR_D.write(cmd_msg.data[6]*(180/PI));
    TIB_AR_D.write(cmd_msg.data[7]*(180/PI));
    //ABD_AR_D.write(cmd_msg.data[8]*(180/PI));
    FEM_AR_G.write(cmd_msg.data[9]*(180/PI));
    TIB_AR_G.write(cmd_msg.data[10]*(180/PI));
    //ABD_AR_G.write(cmd_msg.data[11]*(180/PI));
}

void TCA9548A(uint8_t bus){
  Wire.beginTransmission(0x70);  // TCA9548A address
  Wire.write(1 << bus);          // send byte to select bus
  Wire.endTransmission();
}

ros::Publisher feedback("feedback", &data_imu);
ros::Subscriber<std_msgs::Float64MultiArray> command("command", servo_cmd);

void setup(){ 
  nh.initNode();

  Serial.begin(115200);

  imu_init();
  servo_init();

  nh.subscribe(command);
  nh.advertise(feedback);

}

void readXYangles(std_msgs::Float64MultiArray* data_imu){
    float data_FEM_AV_D;
    float data_TIB_AV_D;
    float data_FEM_AV_G;
    float data_TIB_AV_G;
    float data_FEM_AR_D;
    float data_TIB_AR_D;
    float data_FEM_AR_G;
    float data_TIB_AR_G;

    data_FEM_AV_D = getXangles(IMU_FEM_AV_D, mpu_FEM_AV_D);
    data_TIB_AV_D = getXangles(IMU_TIB_AV_D, mpu_TIB_AV_D);
    data_FEM_AV_G = getXangles(IMU_FEM_AV_G, mpu_FEM_AV_G);
    data_TIB_AV_G = getXangles(IMU_TIB_AV_G, mpu_TIB_AV_G);
    data_FEM_AR_D = getXangles(IMU_FEM_AR_D, mpu_FEM_AR_D);
    data_TIB_AR_D = getXangles(IMU_TIB_AR_D, mpu_TIB_AR_D);
    data_FEM_AR_G = getXangles(IMU_FEM_AR_G, mpu_FEM_AR_G);
    data_TIB_AR_G = getXangles(IMU_TIB_AR_G, mpu_TIB_AR_G);

    data_imu->data[0] = data_FEM_AV_D;
    data_imu->data[1] = data_TIB_AV_D;
    data_imu->data[2] = data_FEM_AV_G;
    data_imu->data[3] = data_TIB_AV_G;
    data_imu->data[4] = data_FEM_AR_D;
    data_imu->data[5] = data_TIB_AR_D;
    data_imu->data[6] = data_FEM_AR_G;
    data_imu->data[7] = data_TIB_AR_G;
}

void loop(){
  readXYangles(&data_imu);
  feedback.publish(&data_imu);
  free(data_imu.data);

  data_imu.data = (float*)malloc(sizeof(float) * data_imu.data_length);

  nh.spinOnce();
}

void imu_init(){

  TCA9548A(IMU_FEM_AV_D);  
  Wire.begin();
  mpu_FEM_AV_D.begin();

  TCA9548A(IMU_TIB_AV_D);  
  Wire.begin();
  mpu_TIB_AV_D.begin();

  TCA9548A(IMU_FEM_AV_G);  
  Wire.begin();
  mpu_FEM_AV_G.begin();

  TCA9548A(IMU_TIB_AV_G);  
  Wire.begin();
  mpu_TIB_AV_G.begin();

  TCA9548A(IMU_FEM_AR_D);  
  Wire.begin();
  mpu_FEM_AR_D.begin();

  TCA9548A(IMU_TIB_AR_D);  
  Wire.begin();
  mpu_TIB_AR_D.begin();

  TCA9548A(IMU_FEM_AR_G);  
  Wire.begin();
  mpu_FEM_AR_G.begin();

  TCA9548A(IMU_TIB_AR_G);  
  Wire.begin();
  mpu_TIB_AR_G.begin();

  data_imu.data_length = DATA_IMU_LENGTH;
  data_imu.data = (float*)malloc(sizeof(float) * data_imu.data_length);
}

void servo_init(){
  FEM_AV_D.attach(MOT_FEM_AV_D);
  TIB_AV_D.attach(MOT_TIB_AV_D);
  //ABD_AV_D.attach(MOT_ABD_AV_D);
  FEM_AV_G.attach(MOT_FEM_AV_G);
  TIB_AV_G.attach(MOT_TIB_AV_G);
  //ABD_AV_G.attach(MOT_ABD_AV_G);
  FEM_AR_D.attach(MOT_FEM_AR_D);
  TIB_AR_D.attach(MOT_TIB_AR_D);
  //ABD_AR_D.attach(MOT_ABD_AR_D);
  FEM_AR_G.attach(MOT_FEM_AR_G);
  TIB_AR_G.attach(MOT_TIB_AR_G);
  //ABD_AR_G.attach(MOT_ABD_AR_G);
}

float getXangles(uint8_t imu_num, MPU6050 imu_type){
  float data;
  TCA9548A(imu_num);
  data = imu_type.getAngleX();
  return data;
}

float getYangles(uint8_t imu_num, MPU6050 imu_type){
  float data;
  TCA9548A(imu_num);
  data = imu_type.getAngleY();
  return data;
}