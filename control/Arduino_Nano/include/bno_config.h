#ifndef BNO_CONFIG
#define BNO_CONFIG

#include <ros.h>
<<<<<<< HEAD
#include <controls/BNO.h>
// #include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

=======

#include <std_msgs/UInt16.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float32.h>
#include <std_msgs/String.h>
#include <controls/BNO.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

#include <Servo.h> 
#include "Wire.h"

>>>>>>> 6aab6f32f276a02b6d6a9fa069145de750414a31
// BNO parameters
uint16_t BNO055_SAMPLERATE_DELAY_MS = 100;
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

// ROS custom messages
<<<<<<< HEAD
=======
// std_msgs::String msg;
>>>>>>> 6aab6f32f276a02b6d6a9fa069145de750414a31
controls::BNO bno_array;

// Functions prototypes
void bno_init();
void bno_update();
void bno_feedback(controls::BNO &feedback_array);

#endif