#ifndef CONFIG 
#define CONFIG 

#include <ros.h>
#include <controls/Servo_cmd.h>
#include <Servo.h> 




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



Servo FEM_AV_D;
Servo TIB_AV_D;
Servo ABD_AV_D;
Servo FEM_AV_G;
Servo TIB_AV_G;
Servo ABD_AV_G;
Servo FEM_AR_D;
Servo TIB_AR_D;
Servo ABD_AR_D;
Servo FEM_AR_G;
Servo TIB_AR_G;
Servo ABD_AR_G;






void servo_init();


#endif
