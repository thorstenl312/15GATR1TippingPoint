#include "spline.h"
#include "pid.h"
#include <iostream>
void splineLeft(float firstAngle, int speed, int speed2, float endingAngle){
  while(fabs(inert.rotation()-firstAngle)>2){
    rightDrive.spin(reverse,speed,rpm);
    leftDrive.spin(reverse,speed2,rpm);
  }
  stopDrive(brake);
  turnLeft(endingAngle);
  //leftDrive.stop(brake);
  //rightDrive.stop(coast);
  //turnRightO(0);
	//Stops motor to ensure accuracy
  stopDrive(hold);
  wait(100,msec);
  stopDrive(coast);
}
void swingLeft(float firstAngle, int speed){
  while(fabs(inert.rotation()-firstAngle)>2){
    rightDrive.spin(forward,speed,rpm);
    leftDrive.stop(coast);
  }
  std::cout << "Done turning" << std::endl;
  stopDrive(brake);
  //leftDrive.stop(brake);
  //rightDrive.stop(coast);
  //turnRightO(0);
	//Stops motor to ensure accuracy
}

void splineRight(float firstAngle, int speed, int speed2, float endingAngle){
  while(fabs(inert.rotation()-firstAngle)>2){
    rightDrive.spin(reverse,speed2,rpm);
    leftDrive.spin(reverse,speed,rpm);
  }
  stopDrive(brake);
  turnRight(endingAngle);
  //leftDrive.stop(brake);
  //rightDrive.stop(coast);
  //turnRightO(0);
	//Stops motor to ensure accuracy
  stopDrive(hold);
  wait(100,msec);
  stopDrive(coast);
}