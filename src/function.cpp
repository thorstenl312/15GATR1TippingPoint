#include "vex.h"
int count = 0;
void stopDrive(brakeType b){
  leftDrive.stop(b);
  rightDrive.stop(b);
}


void driveIntoWall(int maxSpeed, int accel){
  int speed = (leftDrive.velocity(rpm)+rightDrive.velocity(rpm)) / 2;
  rotate.resetPosition();
  double startPos = rotate.position(deg);
  double pastPos = rotate.position(deg);
  leftDrive.spin(reverse, maxSpeed*0.5, rpm);
  rightDrive.spin(reverse, maxSpeed, rpm);
  wait(200,msec);
  speed = (fabs(leftDrive.velocity(rpm))+fabs(rightDrive.velocity(rpm))) / 2;
  while(fabs(pastPos - rotate.position(deg)) > 1 || fabs(startPos - rotate.position(deg)) < 300 ){
    leftDrive.spin(reverse, speed*0.55, rpm);
    rightDrive.spin(reverse, speed, rpm);
    speed += 80;
    if(speed > maxSpeed)
      speed = maxSpeed;

    pastPos = rotate.position(deg);
    wait(accel, msec);
    //if(startPos > -800) arm.spin(reverse, 30, pct);
  }
  stopDrive(coast);
}