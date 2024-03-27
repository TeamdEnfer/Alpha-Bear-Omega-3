#include "config.h"
#include <ros/time.h>
#include <string.h>
#include <math.h>

bool LED_ON = false;
#define LED_PIN 22

// ROS objects declarations
ros::NodeHandle nh;
ros::Publisher feedback("Feedback", &bno_array);
ros::Publisher pot_feedback_pub("pot_feedback_topic", &pot_value_array);
ros::Subscriber<controls::Servo_cmd> command("Command", servo_cmd);

// TODO: ID and name this section
uint64_t current_time = 0;
int elapsed_time = 0;
uint64_t prev_time = 0;
uint64_t period_angle = 500;

// BNO variables
float ACCEL_VEL_TRANSITION = (float)(BNO055_SAMPLERATE_DELAY_MS) / 1000.0;
float ACCEL_POS_TRANSITION = 0.5 * ACCEL_VEL_TRANSITION * ACCEL_VEL_TRANSITION;
float xPos = 0, yPos = 0, heading_vel = 0, angleX = 0, angleY = 0, angleZ = 0;

void setup()
{
    nh.initNode();
    Serial.begin(115200);
    //servo_init();
    pot_init(pot_id_array);
    BNO_init();

    nh.subscribe(command);
    nh.advertise(feedback);

    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    nh.spinOnce();
    delay(250);
}

void servo_init(){
  ABD_AV_G.attach(MOT_ABD_AV_G);
  FEM_AV_G.attach(MOT_FEM_AV_G);
  TIB_AV_G.attach(MOT_TIB_AV_G);

  ABD_AV_D.attach(MOT_ABD_AV_D);
  FEM_AV_D.attach(MOT_FEM_AV_D);
  TIB_AV_D.attach(MOT_TIB_AV_D);

  ABD_AR_G.attach(MOT_ABD_AR_G);
  FEM_AR_G.attach(MOT_FEM_AR_G);
  TIB_AR_G.attach(MOT_TIB_AR_G);

  ABD_AR_D.attach(MOT_ABD_AR_D);
  FEM_AR_D.attach(MOT_FEM_AR_D);
  TIB_AR_D.attach(MOT_TIB_AR_D);
}

void pot_init(const int* pot_id_array) {
    for (uint8_t i = 0; i < NUMBER_OF_POTS; i++) {
        pinMode(pot_id_array[i], INPUT);
    }
}

void BNO_init() {
    while (!Serial)
        delay(10); // wait for serial port to open!

    if (!bno.begin()) {
        //Serial.print("No BNO055 detected");
        while (1);
    }
    
    bno.setExtCrystalUse(true);
}

void servo_cmd(const controls::Servo_cmd &cmd_msg){

    // ABD_AV_G.writeMicroseconds((int)(cmd_msg.data[0]*2000/270+500));
    // FEM_AV_G.writeMicroseconds((int)(cmd_msg.data[1]*2000/270+500));
    // TIB_AV_G.writeMicroseconds((int)(cmd_msg.data[2]*2000/270+500));

    // ABD_AV_D.writeMicroseconds((int)(cmd_msg.data[3]*2000/270+500));
    // FEM_AV_D.writeMicroseconds((int)(cmd_msg.data[4]*2000/270+500));
    // TIB_AV_D.writeMicroseconds((int)(cmd_msg.data[5]*2000/270+500));

    // ABD_AR_G.writeMicroseconds((int)(cmd_msg.data[6]*2000/270+500));
    // FEM_AR_G.writeMicroseconds((int)(cmd_msg.data[7]*2000/270+500));
    // TIB_AR_G.writeMicroseconds((int)(cmd_msg.data[8]*2000/270+500));

    // ABD_AR_D.writeMicroseconds((int)(cmd_msg.data[9]*2000/270+500));
    // FEM_AR_D.writeMicroseconds((int)(cmd_msg.data[10]*2000/270+500));
    // TIB_AR_D.writeMicroseconds((int)(cmd_msg.data[11]*2000/270+500));
    
    delay(10);
    bno_update();
    bno_feedback(bno_array);
    pot_feedback(pot_update(&pot_id_array));
}

void bno_update() {
    // BNO position loop
    sensors_event_t orientationData, linearAccelData;
    bno.getEvent(&orientationData, Adafruit_BNO055::VECTOR_EULER);
    bno.getEvent(&linearAccelData, Adafruit_BNO055::VECTOR_LINEARACCEL);

    xPos += ACCEL_POS_TRANSITION * linearAccelData.acceleration.x;
    yPos += ACCEL_POS_TRANSITION * linearAccelData.acceleration.y;

    // BNO velocity in the direction it's facing
    heading_vel = ACCEL_VEL_TRANSITION * linearAccelData.acceleration.x / cos(DEG_TO_RAD * orientationData.orientation.x);

    // BNO Tilt angles (deg)
    angleX = orientationData.orientation.x;
    angleY = orientationData.orientation.y;
    angleZ = orientationData.orientation.z;

    // BNO Calibration data
    uint8_t sys, gyro, accel, mag = 0;
    bno.getCalibration(&sys, &gyro, &accel, &mag);
}

void bno_feedback(controls::BNO &feedback_array) {
    feedback_array.data[0] = xPos;
    feedback_array.data[1] = yPos;
    feedback_array.data[2] = heading_vel;
    feedback_array.data[3] = angleX;
    feedback_array.data[4] = angleY;
    feedback_array.data[5] = angleZ;
    feedback.publish(&feedback_array);
}

controls::Servo_cmd pot_update(const int* pot_id_array) {
    for (uint8_t i = 0; i < NUMBER_OF_POTS; i++) {
        pot_value_array.data[i] = long2float_map(analogRead(pot_id_array[i]), POT_MIN_VALUE, POT_MAX_VALUE, POT_MIN_ANGLE, POT_MAX_ANGLE);
    }
    return pot_value_array;
}

void pot_feedback(controls::Servo_cmd pot_value_array) {
    pot_feedback_pub.publish(&pot_value_array);
}

float long2float_map(long x, long IN_min, long IN_max, long OUT_min, long OUT_max) {
    return ((float)x - (float)IN_min) * ((float)OUT_max - (float)OUT_min) / ((float)IN_max - (float)IN_min) + (float)OUT_min;
}

