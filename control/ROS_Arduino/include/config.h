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
#include <controls/BNO.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

#include <Servo.h> 
#include "Wire.h"

#define NUMBER_OF_POTS 12

#define POT_MIN_ANGLE 0
#define POT_MAX_ANGLE 343

#define POT_ABD_AV_G 0
#define POT_FEM_AV_G 1
#define POT_TIB_AV_G 2
#define POT_ABD_AV_D 3
#define POT_FEM_AV_D 4
#define POT_TIB_AV_D 5
#define POT_ABD_AR_G 6
#define POT_FEM_AR_G 7
#define POT_TIB_AR_G 8
#define POT_ABD_AR_D 9
#define POT_FEM_AR_D 10
#define POT_TIB_AR_D 11

#define NUMBER_OF_SERVOS 12

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

Servo ABD_AV_G;
Servo FEM_AV_G;
Servo TIB_AV_G;
Servo ABD_AV_D;
Servo FEM_AV_D;
Servo TIB_AV_D;
Servo ABD_AR_G;
Servo FEM_AR_G;
Servo TIB_AR_G;
Servo ABD_AR_D;
Servo FEM_AR_D;
Servo TIB_AR_D;

uint16_t BNO055_SAMPLERATE_DELAY_MS = 100;
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

std_msgs::String msg;

void servo_init();
void BNO_init();
void servo_cmd(const controls::Servo_cmd &cmd_msg);
void bno_update();
float get_angle(uint8_t pot_id);
void test_feedback(controls::BNO &feedback_array);

#endif