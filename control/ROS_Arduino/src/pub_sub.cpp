#include "config.h"
#include <ros/time.h>
#include <string.h>
#include <math.h>

bool LED_ON = false;
#define LED_PIN 22

// ROS objects declarations
ros::NodeHandle nh;
ros::Publisher feedback("Feedback", &bno_array);
// ros::Publisher pot_feedback_pub("pot_feedback_topic", &pot_value_array);
ros::Subscriber<controls::Servo_cmd> command("Command", servo_cmd);

// TODO: ID and name this section
uint64_t current_time = 0;
int elapsed_time = 0;
uint64_t prev_time = 0;
uint64_t period_angle = 500;

// BNO variables
float ACCEL_VEL_TRANSITION = (float)(BNO055_SAMPLERATE_DELAY_MS) / 1000.0;
float ACCEL_POS_TRANSITION = 0.5 * ACCEL_VEL_TRANSITION * ACCEL_VEL_TRANSITION;
float accelX = 0, accelY = 0, accelZ = 0;
imu::Quaternion quat;
float quatX, quatY, quatZ, quatW;

void setup()
{
    nh.initNode();
    Serial.begin(115200);
    servo_init();
    pca_init();
    // pot_init(pot_id_array);
    BNO_init();

    nh.subscribe(command);
    nh.advertise(feedback);
    // nh.advertise(pot_feedback_pub);

    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    nh.spinOnce();
    delay(10);
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

void pca_init() {
    pca.begin();
    pca.setPWMFreq(PWM_FREQ);
}

// void pot_init(const int* pot_id_array) {
//     for (uint8_t i = 0; i < NUMBER_OF_POTS; i++) {
//         pinMode(pot_id_array[i], INPUT);
//     }
// }

void BNO_init() {
    while (!Serial)
        delay(10);  // Wait for serial port to open

    if (!bno.begin()) {
        Serial.print("No BNO055 detected");
        while (1);
    }
    
    bno.setExtCrystalUse(true);
}

void servo_cmd(const controls::Servo_cmd &cmd_msg) {
    for (int i = 0; i < NUMBER_OF_SERVOS; i++) {
        pca.writeMicroseconds(i, (deg2imp(true, cmd_msg.data[i])));
        pca.setPin(i,0,true);   // Deactivate pin i
    }

    delay(10);
    bno_update();
    bno_feedback(bno_array);
    //pot_feedback(pot_id_array);
}

void bno_update() {
    // BNO measurements loop
    sensors_event_t linearAccelData;
    imu::Quaternion quat = bno.getQuat();
    bno.getEvent(&linearAccelData, Adafruit_BNO055::VECTOR_LINEARACCEL);
    
    // BNO acceleration data
    accelX = linearAccelData.acceleration.x;
    accelY = linearAccelData.acceleration.y;
    accelZ = linearAccelData.acceleration.z;

    // BNO quaternion data
    quatX = quat.x();
    quatY = quat.y();
    quatZ = quat.z();
    quatW = quat.w();

    // BNO Calibration data
    uint8_t sys, gyro, accel, mag = 0;
    bno.getCalibration(&sys, &gyro, &accel, &mag);
}

void bno_feedback(controls::BNO &feedback_array) {
    feedback_array.data[0] = accelX;
    feedback_array.data[1] = accelY;
    feedback_array.data[2] = accelZ;
    feedback_array.data[3] = quatX;
    feedback_array.data[4] = quatY;
    feedback_array.data[5] = quatZ;
    feedback_array.data[6] = quatW;
    feedback.publish(&feedback_array);
}

// controls::Servo_cmd pot_update(const int pot_id_array[NUMBER_OF_POTS]) {
//     return pot_value_array;
// }

/*
    Converts the angle received from the controller into an impulse sent to the servo.
    angle is in degrees (deg).
*/
int deg2imp(bool isShoulder, float angle) {
    if (isShoulder)
        imp = (int)(angle * (MAX_IMPULSE - MIN_IMPULSE) / (MAX_ANGLE_S - MIN_ANGLE) + MIN_IMPULSE);
    else
        imp =(int)(angle * (MAX_IMPULSE - MIN_IMPULSE) / (MAX_ANGLE_FT - MIN_ANGLE) + MIN_IMPULSE);
    return constrain(imp, MIN_IMPULSE, MAX_IMPULSE);
}

// void pot_feedback(const int pot_id_array[NUMBER_OF_POTS]) {

//     for (int i = 0; i < NUMBER_OF_POTS; i++) {
//         pot_value_array.data[i] = long2float_map(analogRead(pot_id_array[i]), POT_MIN_VALUE, POT_MAX_VALUE, POT_MIN_ANGLE, POT_MAX_ANGLE);
//     }
//     pot_feedback_pub.publish(&pot_value_array);

// }

// float long2float_map(long x, long IN_min, long IN_max, long OUT_min, long OUT_max) {
//     return (float)(x - IN_min) * (float)(OUT_max - OUT_min) / (float)(IN_max - IN_min) + (float)OUT_min;
// }

