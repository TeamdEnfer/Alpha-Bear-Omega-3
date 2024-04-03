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
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h> 
#include "Wire.h"


// Servos parameters
#define NUMBER_OF_SERVOS 12
// const int servo_pins[NUMBER_OF_SERVOS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

// Servo servo_array[NUMBER_OF_SERVOS] = {ABD_AV_G, FEM_AV_G, TIB_AV_G,
//                                         ABD_AV_D, FEM_AV_D, TIB_AV_D,
//                                         ABD_AR_G, FEM_AR_G, TIB_AR_G,
//                                         ABD_AR_D, FEM_AR_D, TIB_AR_D};

// PCA parameters
Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver(0x40);
const int MIN_IMPULSE = 500;
const int MAX_IMPULSE = 2500;
const int MIN_ANGLE = 0;        // Min angle of servos (deg)
const int MAX_ANGLE_S = 180;    // Max angle for shoulder servos (deg)
const int MAX_ANGLE_FT = 270;   // Max angle for femur and tibia servos (deg)
const int PWM_FREQ = 60;    // Frequency at which servos update (Hz)

// BNO parameters
uint16_t BNO055_SAMPLERATE_DELAY_MS = 100;
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

// ROS custom messages
std_msgs::String msg;
controls::BNO bno_array;

// === Functions prototypes ===

// Servo, PCA
void servo_init();
void pca_init();
void servo_cmd(const controls::Servo_cmd &cmd_msg);
uint16_t deg2imp(bool isShoulder, float angle);
// BNO
void BNO_init();
void bno_update();
void bno_feedback(controls::BNO &feedback_array);

#endif
