#include "config.h"
#include <ros/time.h>
#include <string.h>

ros::NodeHandle  nh;





void servo_cmd(const controls::Servo_cmd &cmd_msg){

    ABD_AV_G.writeMicroseconds((int)(cmd_msg.data[0]*2000/180+500));
    FEM_AV_G.writeMicroseconds((int)(cmd_msg.data[1]*2000/270+500));
    TIB_AV_G.writeMicroseconds((int)(cmd_msg.data[2]*2000/270+500));

    ABD_AV_D.writeMicroseconds((int)(cmd_msg.data[3]*2000/180+500));
    FEM_AV_D.writeMicroseconds((int)(cmd_msg.data[4]*2000/270+500));
    TIB_AV_D.writeMicroseconds((int)(cmd_msg.data[5]*2000/270+500));

    ABD_AR_G.writeMicroseconds((int)(cmd_msg.data[6]*2000/180+500));
    FEM_AR_G.writeMicroseconds((int)(cmd_msg.data[7]*2000/270+500));
    TIB_AR_G.writeMicroseconds((int)(cmd_msg.data[8]*2000/270+500));

    ABD_AR_D.writeMicroseconds((int)(cmd_msg.data[9]*2000/180+500));
    FEM_AR_D.writeMicroseconds((int)(cmd_msg.data[10]*2000/270+500));
    TIB_AR_D.writeMicroseconds((int)(cmd_msg.data[11]*2000/270+500));

}


ros::Subscriber<controls::Servo_cmd> command("Command", servo_cmd);



void setup(){ 

  nh.initNode();

  Serial.begin(115200);

  servo_init();

  nh.subscribe(command);
}


void loop(){

  nh.spinOnce();
  delay(250);
}

void servo_init(){
  FEM_AV_D.attach(MOT_FEM_AV_D);
  TIB_AV_D.attach(MOT_TIB_AV_D);
  ABD_AV_D.attach(MOT_ABD_AV_D);

  FEM_AV_G.attach(MOT_FEM_AV_G);
  TIB_AV_G.attach(MOT_TIB_AV_G);
  ABD_AV_G.attach(MOT_ABD_AV_G);

  FEM_AR_D.attach(MOT_FEM_AR_D);
  TIB_AR_D.attach(MOT_TIB_AR_D);
  ABD_AR_D.attach(MOT_ABD_AR_D);

  FEM_AR_G.attach(MOT_FEM_AR_G);
  TIB_AR_G.attach(MOT_TIB_AR_G);
  ABD_AR_G.attach(MOT_ABD_AR_G);
}
