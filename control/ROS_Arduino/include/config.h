#ifndef CONFIG 
#define CONFIG 

#include <ros.h>

#include <std_msgs/UInt16.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Int8MultiArray.h>
#include <std_msgs/String.h>
#include <controls/Servo_cmd.h>

#include <MPU6050_light.h>

#include <Servo.h> 
#include "Wire.h"

#define DATA_IMU_LENGTH 8

#define IMU_FEM_AV_D 0
#define IMU_TIB_AV_D 1
#define IMU_FEM_AV_G 2
#define IMU_TIB_AV_G 3
#define IMU_FEM_AR_D 4
#define IMU_TIB_AR_D 5
#define IMU_FEM_AR_G 6
#define IMU_TIB_AR_G 7

#define MOT_FEM_AV_D 2
#define MOT_TIB_AV_D 3
#define MOT_ABD_AV_D 4
#define MOT_FEM_AV_G 5
#define MOT_TIB_AV_G 6
#define MOT_ABD_AV_G 7
#define MOT_FEM_AR_D 8
#define MOT_TIB_AR_D 9
#define MOT_ABD_AR_D 10
#define MOT_FEM_AR_G 11
#define MOT_TIB_AR_G 12
#define MOT_ABD_AR_G 13

MPU6050 mpu_FEM_AV_D(Wire);
MPU6050 mpu_TIB_AV_D(Wire);
MPU6050 mpu_FEM_AV_G(Wire);
MPU6050 mpu_TIB_AV_G(Wire);
MPU6050 mpu_FEM_AR_D(Wire);
MPU6050 mpu_TIB_AR_D(Wire);
MPU6050 mpu_FEM_AR_G(Wire);
MPU6050 mpu_TIB_AR_G(Wire);

Servo FEM_AV_D;
Servo TIB_AV_D;
Servo ABD_AV_D;
Servo FEM_AV_G;
Servo TIB_AV_G;
Servo ABD_AV_G;
Servo FEM_AR_D;
Servo TIB_AR_D;
Servo ABD_AR_D;
Servo FEM_AR_G;
Servo TIB_AR_G;
Servo ABD_AR_G;

std_msgs::Float64MultiArray data_imu;
std_msgs::Int8MultiArray test_array;
std_msgs::String msg;

//void servo_cb(const std_msgs::UInt16 &cmd_msg);
void TCA9548A(uint8_t bus);
void readXangles(std_msgs::Float64MultiArray* data_imu);
float getXangle(uint8_t imu_num, MPU6050 imu_type);
void imu_init();
void servo_init();
void test_feedback(const std_msgs::Int8MultiArray *test_array);

#endif