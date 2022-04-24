#include "auton.h"
#include <iostream>

void skills(){
  clawFront.close();
  clawBack.close();
  clawLiftBackL.open();
  clawLiftBackR.close();
  clawLiftFrontL.close();
  clawLiftFrontR.open();
  
  wait(1000,msec);
  while(!blueDist.isObjectDetected() || blueDist.objectDistance(distanceUnits::cm) > 3){
    leftDrive.spin(fwd, 15, pct);
    rightDrive.spin(fwd, 15, pct);
  }
  stopDrive(coast);
  clawFront.open();
  wait(250,msec);
  clawLiftFrontL.open();
  clawLiftFrontR.close();
  while(inert.rotation() <= 83){
    leftDrive.spin(reverse, 7, pct);
    rightDrive.spin(reverse, 20, pct);
    if(inert.rotation() > 25)intakeF.spin(fwd,100, pct);
  }
  stopDrive(hold);
  intakeF.spin(fwd,100, pct);
  backwardPID(2300, 200, 50, 4.3);
  turnRight(112, 200);
  backwardPID(930, 200, 50, 4);
  turnLeft(1, 200);
  while(!orangeDist.isObjectDetected() || orangeDist.objectDistance(distanceUnits::cm) > 3){
    leftDrive.spin(reverse, 10, pct);
    rightDrive.spin(reverse, 10, pct);
  }
  stopDrive(coast);
  clawBack.open();
  wait(0.15, sec);
  clawLiftBackL.close();
  clawLiftBackR.open();
  forwardPID(300, 200);
  turnLeft(-90, 150);
  clawLiftFrontL.open();
  clawLiftFrontR.open();
  wait(0.35, sec);
  clawFront.close();
  backwardPID(200, 150);
  clawLiftFrontL.open();
  clawLiftFrontR.close();
  turnRight(-1.5, 150);
  clawFront.open();
  intakeB.spin(fwd,100, pct);
  leftDrive.spin(reverse, 33, pct);
  rightDrive.spin(reverse, 33, pct);
  wait(2000,msec);
  leftDrive.spin(reverse, 10, pct);
  rightDrive.spin(reverse, 10, pct);
  while(fabs(leftDrive.velocity(pct)) > 5 && fabs(rightDrive.velocity(pct)) > 5);
  stopDrive(coast);
  clawFront.close();
  clawLiftFrontL.close();
  clawLiftFrontR.open();
  forwardPID(3720, 200, 50, 4.5);
  turnLeft(-119, 250);
  while(!blueDist.isObjectDetected() || blueDist.objectDistance(distanceUnits::cm) > 4){
    leftDrive.spin(fwd, 25, pct);
    rightDrive.spin(fwd, 25, pct);
  }
  stopDrive(coast);
  clawFront.open();
  wait(250, msec);
  clawLiftFrontL.open();
  clawLiftFrontR.close();
  backwardPID(1000);
  turnRight(-90);
  backwardPID(2700,400, 50, 4);
  intakeB.spin(fwd, 100, pct);
  leftDrive.spin(reverse, 10, pct);
  rightDrive.spin(reverse, 10, pct);
  wait(1000,msec);
  while(fabs(leftDrive.velocity(pct)) > 3 && fabs(rightDrive.velocity(pct)) > 3);
  stopDrive(coast);
  turnLeft(-200, 150);
  wait(250,msec);
  forwardPID(110, 120);
  wait(250,msec);
  turnRight(-183, 120);
  wait(250,msec);
  turnLeft(-183, 120);
  flip.spin(reverse, 50, pct);
  wait(300,msec);
  while(fabs(flip.velocity(pct)) > 5);
  flip.spin(reverse, 10, pct);
  leftDrive.rotateFor(2550, deg, 100, percent, false);
  rightDrive.rotateFor(2550, deg, 100, percent);
  wait(2000, msec);
  clawLiftBackL.open();
  clawLiftBackR.open();
  clawLiftFrontL.open();
  clawLiftFrontR.open();
  wait(0.5, sec);
  clawBack.close();
  clawFront.close();
  wait(0.35, sec);
  clawLiftBackL.close();
  clawLiftBackR.open();
  clawLiftFrontL.open();
  clawLiftFrontR.close();
  wait(0.35, msec);
  clawBack.open();
  clawFront.open();
}