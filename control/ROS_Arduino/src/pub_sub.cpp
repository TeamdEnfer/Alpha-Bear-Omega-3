#include "config.h"
#include <ros/time.h>
#include <string.h>

ros::NodeHandle  nh;
ros::Publisher feedback("Feedback", &test_array);
//ros::Publisher feedback("Feedback", &data_imu);
//ros::Publisher debugger("Debug", &msg);
bool LED_ON = false;
#define LED 22



//void servo_cmd( const std_msgs::Float32MultiArray &cmd_msg){
void servo_cmd(const controls::Servo_cmd &cmd_msg){

    ABD_AV_G.writeMicroseconds((int)(cmd_msg.data[0]*2000/270+500));
    FEM_AV_G.writeMicroseconds((int)(cmd_msg.data[1]*2000/270+500));
    TIB_AV_G.writeMicroseconds((int)(cmd_msg.data[2]*2000/270+500));

    ABD_AV_D.writeMicroseconds((int)(cmd_msg.data[3]*2000/270+500));
    FEM_AV_D.writeMicroseconds((int)(cmd_msg.data[4]*2000/270+500));
    TIB_AV_D.writeMicroseconds((int)(cmd_msg.data[5]*2000/270+500));

    ABD_AR_G.writeMicroseconds((int)(cmd_msg.data[6]*2000/270+500));
    FEM_AR_G.writeMicroseconds((int)(cmd_msg.data[7]*2000/270+500));
    TIB_AR_G.writeMicroseconds((int)(cmd_msg.data[8]*2000/270+500));

    ABD_AR_D.writeMicroseconds((int)(cmd_msg.data[9]*2000/270+500));
    FEM_AR_D.writeMicroseconds((int)(cmd_msg.data[10]*2000/270+500));
    TIB_AR_D.writeMicroseconds((int)(cmd_msg.data[11]*2000/270+500));

    //char message[100] = "in servo_cmd"; 
    //msg.data = message;
    //debugger.publish(&msg);
    
    //if(LED_ON == false)
    //{
    //  digitalWrite(LED , HIGH);
    //  delay(10);
    //  LED_ON = true;
    //}
//
    //else if (LED_ON == true)
    //{
    //  digitalWrite(LED , LOW);
    //  delay(10);
    //  LED_ON = false;
    //}
    
    delay(10);
    test_feedback(&test_array);
    free(test_array.data);
    test_array.data = (int8_t*)malloc(sizeof(int8_t) * test_array.data_length);


}

void TCA9548A(uint8_t bus){
  //Wire.beginTransmission(0x70);  // TCA9548A address
  //Wire.write(1 << bus);          // send byte to select bus
  //Wire.endTransmission();
}

//ros::Subscriber<std_msgs::Float32MultiArray> command("Command", servo_cmd);
ros::Subscriber<controls::Servo_cmd> command("Command", servo_cmd);

uint64_t current_time = 0;
int elapsed_time = 0;
uint64_t prev_time = 0;
uint64_t period_angle = 500;

void setup(){ 

  nh.initNode();

  Serial.begin(115200);

  //imu_init();
  servo_init();

  nh.subscribe(command);
  nh.advertise(feedback);
  //nh.advertise(debugger);

  pinMode(LED , OUTPUT);

  test_array.data_length = 12;
  test_array.data = (int8_t*)malloc(sizeof(int8_t) * test_array.data_length);

}

void readXYangles(std_msgs::Float64MultiArray* data_imu){

    //float data_FEM_AV_D;
    //float data_TIB_AV_D = 0;
    //float data_FEM_AV_G;
    //float data_TIB_AV_G;
    //float data_FEM_AR_D;
    //float data_TIB_AR_D;
    //float data_FEM_AR_G;
    //float data_TIB_AR_G;
//
    //data_FEM_AV_D = getXangles(IMU_FEM_AV_D, mpu_FEM_AV_D);
   //// data_TIB_AV_D = getXangles(IMU_TIB_AV_D, mpu_TIB_AV_D);  //IMU manquant
    //data_FEM_AV_G = getXangles(IMU_FEM_AV_G, mpu_FEM_AV_G);
    //data_TIB_AV_G = getXangles(IMU_TIB_AV_G, mpu_TIB_AV_G);
    //data_FEM_AR_D = getXangles(IMU_FEM_AR_D, mpu_FEM_AR_D);
    //data_TIB_AR_D = getXangles(IMU_TIB_AR_D, mpu_TIB_AR_D);
    //data_FEM_AR_G = getXangles(IMU_FEM_AR_G, mpu_FEM_AR_G);
    //data_TIB_AR_G = getXangles(IMU_TIB_AR_G, mpu_TIB_AR_G);
//
    //data_imu->data[0] = data_FEM_AV_D;
    //data_imu->data[1] = data_TIB_AV_D;
    //data_imu->data[2] = data_FEM_AV_G;
    //data_imu->data[3] = data_TIB_AV_G;
    //data_imu->data[4] = data_FEM_AR_D;
    //data_imu->data[5] = data_TIB_AR_D;
    //data_imu->data[6] = data_FEM_AR_G;
    //data_imu->data[7] = data_TIB_AR_G;
    //prev_time = millis();
    //char c[100];
    //char a[100] = "in read angle";
    //sprintf(c ,"%d" , prev_time);
    //strcat(a, c); 
  //
    //msg.data = a;
    //debugger.publish(&msg);
    


}

void loop(){

  //current_time = millis();
  

//if (current_time - prev_time >= period_angle)
//{
//  readXYangles(&data_imu);
//}
  //feedback.publish(&data_imu);

  
  //free(data_imu.data);
//
  //data_imu.data = (float*)malloc(sizeof(float) * data_imu.data_length);

  //elapsed_time = current_time - prev_time;
  nh.spinOnce();
  delay(10);
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

float getXangles(uint8_t imu_num, MPU6050 imu_type){
  double data;


  //TCA9548A(imu_num);
  //imu_type.update();
  //data = imu_type.getAngleX();


  return data;
}

float getYangles(uint8_t imu_num, MPU6050 imu_type){
  float data;
  TCA9548A(imu_num);
  imu_type.update();
  data = imu_type.getAngleY();
  return data;
}


void test_feedback(const std_msgs::Int8MultiArray *test_array)
{

  for(int i = 0 ; i < 12 ; i++)
  {
   test_array->data[i] = 69;
  }

  feedback.publish(test_array);

}