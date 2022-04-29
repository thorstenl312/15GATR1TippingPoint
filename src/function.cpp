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
  leftDrive.spin(reverse, maxSpeed, rpm);
  rightDrive.spin(reverse, maxSpeed, rpm);
  wait(200,msec);
  speed = (fabs(leftDrive.velocity(rpm))+fabs(rightDrive.velocity(rpm))) / 2;
  while(fabs(pastPos - rotate.position(deg)) > 1 || fabs(startPos - rotate.position(deg)) < 300 ){
    leftDrive.spin(reverse, speed, rpm);
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

int gripperControl(){
  int frontPos = 1;
  int backPos = 1;
  while(true){
    if(Controller1.ButtonL1.pressing()){
      if(frontPos == 0){
        clawBack.open();
        wait(0.15, sec);
        clawLiftBackL.close();
        clawLiftBackR.open();
        frontPos = 1;

      }
      else if(orangeDist.isObjectDetected() && orangeDist.objectDistance(distanceUnits::cm) < 3 && frontPos == 1){
        clawLiftBackL.open();
        clawLiftBackR.open();
        wait(0.35, sec);
        clawBack.close();
        wait(0.5, sec);
        clawLiftBackL.open();
        clawLiftBackR.close();
        frontPos = 0;
      }
      else{
        clawBack.close();
        clawLiftBackL.open();
        clawLiftBackR.close();
        frontPos = 0;
      }
      while(Controller1.ButtonL1.pressing());
    }
    if(Controller1.ButtonR1.pressing()){
      if(backPos == 0){
        clawFront.open();
        wait(0.15, sec);
        clawLiftFrontL.open();
        clawLiftFrontR.close();
        backPos = 1;
      }
      else if(blueDist.isObjectDetected() && blueDist.objectDistance(distanceUnits::cm) < 3 && backPos == 1){
        clawLiftFrontL.open();
        clawLiftFrontR.open();
        wait(0.35, sec);
        clawFront.close();
        wait(0.5, sec);
        clawLiftFrontL.close();
        clawLiftFrontR.open();
        backPos = 0;
      }
      else{
        clawFront.close();
        clawLiftFrontL.close();
        clawLiftFrontR.open();
        backPos = 0;
      }
      while(Controller1.ButtonR1.pressing());
    }
    if(Controller2.ButtonA.pressing()){
      clawLiftFrontL.open();
      clawLiftFrontR.open();
      wait(0.5, sec);
      clawFront.close();
      wait(0.5, sec);
      clawLiftFrontL.open();
      clawLiftFrontR.close();
      wait(0.5, msec);
      clawFront.open();
      while(Controller2.ButtonA.pressing());
    }
    if(Controller2.ButtonY.pressing()){
      clawLiftBackL.open();
      clawLiftBackR.open();
      wait(0.5, sec);
      clawBack.close();
      wait(0.5, sec);
      clawLiftBackL.close();
      clawLiftBackR.open();
      wait(0.5, msec);
      clawBack.open();
      while(Controller2.ButtonY.pressing());
    }
    if(Controller2.ButtonX.pressing()){
      clawLiftFrontL.open();
      clawLiftFrontR.open();
      while(Controller2.ButtonX.pressing());
    }
    if(Controller2.ButtonB.pressing()){
      clawLiftBackL.open();
      clawLiftBackR.open();
      while(Controller2.ButtonB.pressing());
    }
  }
  return (0);
}