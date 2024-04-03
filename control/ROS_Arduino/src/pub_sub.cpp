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
    // servo_init();
    pca_init();
    BNO_init();

    nh.subscribe(command);
    nh.advertise(feedback);

    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    nh.spinOnce();
    delay(10);
}

// void servo_init() {
//     for (int i = 0; i < NUMBER_OF_SERVOS; i++) {
//         servo_array[i].attach(servo_pins[i]);
//     }
// }

void pca_init() {
    pca.begin();
    pca.setPWMFreq(PWM_FREQ);
}

void BNO_init() {
    while (!Serial)
        delay(10);  // Wait for serial port to open

    if (!bno.begin()) {
        // Serial.print("No BNO055 detected");
        // while (1);
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


/*
    Converts the angle received from the controller into an impulse sent to the servo.
    angle is in degrees (deg).
*/
uint16_t deg2imp(bool isShoulder, float angle) {
    if (isShoulder)
        imp = (uint16_t)(angle * (MAX_IMPULSE - MIN_IMPULSE) / (MAX_ANGLE_S - MIN_ANGLE) + MIN_IMPULSE);
    else
        imp =(uint16_t)(angle * (MAX_IMPULSE - MIN_IMPULSE) / (MAX_ANGLE_FT - MIN_ANGLE) + MIN_IMPULSE);
    return constrain(imp, MIN_IMPULSE, MAX_IMPULSE);
}

