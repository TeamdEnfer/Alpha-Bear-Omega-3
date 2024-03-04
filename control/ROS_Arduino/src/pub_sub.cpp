#include "config.h"

ros::NodeHandle  nh;

void servo_cmd( const std_msgs::Float64MultiArray &cmd_msg){


    FEM_AV_G.writeMicroseconds(cmd_msg.data[1]*2000/270+500);
    TIB_AV_G.writeMicroseconds(cmd_msg.data[2]*2000/270+500);
    ABD_AV_D.writeMicroseconds(cmd_msg.data[3]*2000/270+500);
    FEM_AV_D.writeMicroseconds(cmd_msg.data[4]*2000/270+500);
    TIB_AV_D.writeMicroseconds(cmd_msg.data[5]*2000/270+500);
    ABD_AR_G.writeMicroseconds(cmd_msg.data[6]*2000/270+500);
    FEM_AR_G.writeMicroseconds(cmd_msg.data[7]*2000/270+500);
    TIB_AR_G.writeMicroseconds(cmd_msg.data[8]*2000/270+500);
    ABD_AR_D.writeMicroseconds(cmd_msg.data[9]*2000/270+500);
    FEM_AR_D.writeMicroseconds(cmd_msg.data[10]*2000/270+500);
    TIB_AR_D.writeMicroseconds(cmd_msg.data[11]*2000/270+500);
}

void TCA9548A(uint8_t bus){
  Wire.beginTransmission(0x70);  // TCA9548A address
  Wire.write(1 << bus);          // send byte to select bus
}

ros::Publisher feedback("Feedback", &data_imu);
ros::Subscriber<std_msgs::Float64MultiArray> command("Command", servo_cmd);

void setup(){ 

  nh.initNode();

  Serial.begin(115200);

  imu_init();
  servo_init();

  nh.subscribe(command);
  nh.advertise(feedback);

}

void readXangles(std_msgs::Float64MultiArray* data_imu){
    //double data_FEM_AV_D = 0;
    //double data_TIB_AV_D = 0;
    //double data_FEM_AV_G;
    //double data_TIB_AV_G;
    //double data_FEM_AR_D = 0;
    //double data_TIB_AR_D = 0;
    //double data_FEM_AR_G = 0;
    //double data_TIB_AR_G = 0;

    //data_FEM_AV_D = getXangle(IMU_FEM_AV_D, mpu_FEM_AV_D);
    //data_TIB_AV_D = getXangle(IMU_TIB_AV_D, mpu_TIB_AV_D);  //IMU manquant
    //data_FEM_AV_G = getXangle(IMU_FEM_AV_G, mpu_FEM_AV_G);
    //data_TIB_AV_G = getXangle(IMU_TIB_AV_G, mpu_TIB_AV_G);
    //data_TIB_AR_D = getXangle(IMU_TIB_AR_D, mpu_TIB_AR_D);
    //data_FEM_AR_G = getXangle(IMU_FEM_AR_G, mpu_FEM_AR_G);
    //data_TIB_AR_G = getXangle(IMU_TIB_AR_G, mpu_TIB_AR_G);
    //data_FEM_AR_D = getXangle(IMU_FEM_AR_D, mpu_FEM_AR_D);

    //data_imu->data[0] = data_FEM_AV_D;
    //data_imu->data[1] = data_TIB_AV_D;
    //data_imu->data[2] = data_FEM_AV_G;
    //data_imu->data[3] = data_TIB_AV_G;
    //data_imu->data[4] = data_FEM_AR_D;
    //data_imu->data[5] = data_TIB_AR_D;
    //data_imu->data[6] = data_FEM_AR_G;
    //data_imu->data[7] = data_TIB_AR_G;
}

void loop(){
  readXangles(&data_imu);

  feedback.publish(&data_imu);

  
  free(data_imu.data);

  data_imu.data = (float*)malloc(sizeof(float) * data_imu.data_length);
  

  nh.spinOnce();
  delay(250);
}

void imu_init(){

  TCA9548A(IMU_FEM_AV_D);  
  Wire.begin();
  mpu_FEM_AV_D.begin();
  mpu_FEM_AV_D.calcGyroOffsets();
  delay(100);

  TCA9548A(IMU_TIB_AV_D);  
  Wire.begin();
  //mpu_TIB_AV_D.begin();
  //mpu_TIB_AV_D.calcGyroOffsets();
  //delay(100);

  TCA9548A(IMU_FEM_AV_G);  
  Wire.begin();
  mpu_FEM_AV_G.begin();
  mpu_FEM_AV_G.calcGyroOffsets();
  delay(100);

  TCA9548A(IMU_TIB_AV_G);  
  Wire.begin();
  mpu_TIB_AV_G.begin();
  mpu_TIB_AV_G.calcGyroOffsets();
  delay(100);

  TCA9548A(IMU_FEM_AR_D);  
  Wire.begin();
  mpu_FEM_AR_D.begin();
  mpu_FEM_AR_D.calcGyroOffsets();
  delay(100);

  TCA9548A(IMU_TIB_AR_D);  
  Wire.begin();
  mpu_TIB_AR_D.begin();
  mpu_TIB_AR_D.calcGyroOffsets();
  delay(100);

  TCA9548A(IMU_FEM_AR_G);  
  Wire.begin();
  mpu_FEM_AR_G.begin();
  mpu_FEM_AR_G.calcGyroOffsets();
  delay(100);

  TCA9548A(IMU_TIB_AR_G);  
  Wire.begin();
  mpu_TIB_AR_G.begin();
  mpu_TIB_AR_G.calcGyroOffsets();
  delay(100);

  data_imu.data_length = DATA_IMU_LENGTH;
  data_imu.data = (float*)malloc(sizeof(float) * data_imu.data_length);
}

void servo_init(){
  FEM_AV_D.attach(MOT_FEM_AV_D);
  TIB_AV_D.attach(MOT_TIB_AV_D);
  ABD_AV_D.attach(MOT_ABD_AV_D);
  FEM_AV_G.attach(MOT_FEM_AV_G);
  TIB_AV_G.attach(MOT_TIB_AV_G);
  ABD_AV_G.attach(MOT_ABD_AV_G);
  FEM_AR_D.attach(MOT_FEM_AR_D);
  TIB_AR_D.attach(MOT_TIB_AR_D);
  ABD_AR_D.attach(MOT_ABD_AR_D);
  FEM_AR_G.attach(MOT_FEM_AR_G);
  TIB_AR_G.attach(MOT_TIB_AR_G);
  ABD_AR_G.attach(MOT_ABD_AR_G);
}

float getXangle(uint8_t imu_num, MPU6050 imu_type){
  TCA9548A(imu_num);
  imu_type.update();
  float data = imu_type.getAngleX();
  Wire.endTransmission();
  return data;
}