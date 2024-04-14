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
//#include <controls/BNO.h>
//#include <Adafruit_Sensor.h>
//#include <Adafruit_BNO055.h>

#include <Servo.h> 
//#include "Wire.h"


// Potentiometers parameters
const long POT_MIN_VALUE = 0;
const long POT_MAX_VALUE = 1023;
const long POT_MIN_ANGLE = 0;
const long POT_MAX_ANGLE = 343;
const uint8_t NUMBER_OF_POTS = 12;

#define POT_PIN_ABD_AV_G A0
#define POT_PIN_FEM_AV_G A1
#define POT_PIN_TIB_AV_G A2
#define POT_PIN_ABD_AV_D A3
#define POT_PIN_FEM_AV_D A4
#define POT_PIN_TIB_AV_D A5
#define POT_PIN_ABD_AR_G A6
#define POT_PIN_FEM_AR_G A7
#define POT_PIN_TIB_AR_G A8
#define POT_PIN_ABD_AR_D A9
#define POT_PIN_FEM_AR_D A10
#define POT_PIN_TIB_AR_D A11
const int pot_id_array[NUMBER_OF_POTS] = {POT_PIN_ABD_AV_G, POT_PIN_FEM_AV_G, POT_PIN_TIB_AV_G,
                                          POT_PIN_ABD_AV_D, POT_PIN_FEM_AV_D, POT_PIN_TIB_AV_D,
                                          POT_PIN_ABD_AR_G, POT_PIN_FEM_AR_G, POT_PIN_TIB_AR_G,
                                          POT_PIN_ABD_AR_D, POT_PIN_FEM_AR_D, POT_PIN_TIB_AR_D};

// Servos parameters
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

Servo ABD_AV_G, FEM_AV_G, TIB_AV_G, ABD_AV_D, FEM_AV_D, TIB_AV_D;
Servo ABD_AR_G, FEM_AR_G, TIB_AR_G, ABD_AR_D, FEM_AR_D, TIB_AR_D;

// BNO parameters
//uint16_t BNO055_SAMPLERATE_DELAY_MS = 100;
//Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

// ROS custom messages
std_msgs::String msg;
//controls::BNO bno_array;
//controls::Servo_cmd pot_value_array;

// Functions prototypes

// Servo
void servo_init();
void servo_cmd(const controls::Servo_cmd &cmd_msg);
// Potentiometers
//void pot_init(const int* pot_id_array);
controls::Servo_cmd pot_update(const int pot_id_array[NUMBER_OF_POTS]);
//void pot_feedback(const int pot_id_array[NUMBER_OF_POTS]);
//float long2float_map(long x, long IN_min, long IN_max, long OUT_min, long OUT_max);
// BNO
//void BNO_init();
//void bno_update();
//void bno_feedback(controls::BNO &feedback_array);

#endif