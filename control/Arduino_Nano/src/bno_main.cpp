#include <Arduino.h>
#include "bno_config.h"

// ROS object declarations
ros::NodeHandle nh;
ros::Publisher bno_feedback_pub("Feedback", &bno_array);

// BNO variables
float ACCEL_VEL_TRANSITION = (float)(BNO055_SAMPLERATE_DELAY_MS) / 1000.0;
float ACCEL_POS_TRANSITION = 0.5 * ACCEL_VEL_TRANSITION * ACCEL_VEL_TRANSITION;
float accelX = 0, accelY = 0, accelZ = 0;
imu::Quaternion quat;   // Waiting on a refactor of 'imu' namespace to 'bno'
float quatX, quatY, quatZ, quatW;

void setup() {
  nh.initNode();
  Serial.begin(115200);
  bno_init();
  nh.advertise(bno_feedback_pub);
}

void loop() {
  nh.spinOnce();
  delay(10);
  bno_update();
  bno_feedback(bno_array);
  delay(10);
}

void bno_init() {
  while (!Serial)
    delay(10); // wait for serial port to open!

  if (!bno.begin())
  {
    // Serial.print("No BNO055 detected");
    // while (1);
  }

  bno.setExtCrystalUse(true);
}

void bno_update() {
  // BNO measurements loop
  sensors_event_t linearAccelData;
  imu::Quaternion quat = bno.getQuat();
  bno.getEvent(&linearAccelData, Adafruit_BNO055::VECTOR_LINEARACCEL);

  // BNO acceleration data
  accelX = linearAccelData.acceleration.x;
  accelY = -linearAccelData.acceleration.y;
  accelZ = -linearAccelData.acceleration.z;

  // BNO quaternion data
  quatX = quat.x();
  quatY = -quat.y();
  quatZ = -quat.z();
  quatW = quat.w();

  // BNO Calibration data
  uint8_t sys, gyro, accel, mag = 0;
  bno.getCalibration(&sys, &gyro, &accel, &mag);
}

void bno_feedback(controls::BNO &bno_feedback_array) {
    bno_feedback_array.data[0] = accelX;
    bno_feedback_array.data[1] = accelY;
    bno_feedback_array.data[2] = accelZ;
    bno_feedback_array.data[3] = quatX;
    bno_feedback_array.data[4] = quatY;
    bno_feedback_array.data[5] = quatZ;
    bno_feedback_array.data[6] = quatW;
    bno_feedback_pub.publish(&bno_feedback_array);
}