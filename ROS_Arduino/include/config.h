#ifndef CONFIG 
#define CONFIG 

#include <ros.h>

#include <std_msgs/UInt16.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float64MultiArray.h>

#include <MPU6050_light.h>

#include <Servo.h> 
#include "Wire.h"

#define DATA_IMU_LENGTH 2
#define DATA_MULTIPLE_IMU_LENGTH 8

void servo_cb(const std_msgs::UInt16 &cmd_msg);
void TCA9548A(uint8_t bus);
void readXYangles(std_msgs::Float64MultiArray* data_imu);

std_msgs::Float64MultiArray data_imu;
std_msgs::Float64MultiArray data_multi_imu;

Servo Femur;
Servo Tibia;

#endif