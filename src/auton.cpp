#include "auton.h"
#include  "spline.h"
#include "functions.h"
#include <iostream>
int pullIn(){
  clawFront.open();
  wait(100,msec);
  clawLiftFrontL.open();
  clawLiftFrontR.close();
  return(0);
}
void sideAuto(){
  Brain.resetTimer();
  clawFront.close();
  clawLiftFrontL.close();
  clawLiftFrontR.open();
  leftDrive.spin(fwd, 100, pct);
  rightDrive.spin(fwd, 100, pct);
  wait(600, msec);
  while(!blueDist.isObjectDetected() || !(blueDist.objectDistance(distanceUnits::cm) < 19)){
    wait(20,msec);
  }
  task p(pullIn);
  stopDrive(brake);
  wait(150,msec);
  leftDrive.spin(reverse, 30, pct);
  rightDrive.spin(reverse, 30, pct);
  wait(270,msec);
  leftDrive.spin(reverse, 60, pct);
  rightDrive.spin(reverse, 60, pct);
  wait(270,msec);
  leftDrive.spin(reverse, 80, pct);
  rightDrive.spin(reverse, 80, pct);
  wait(270,msec);
  leftDrive.spin(reverse, 100, pct);
  rightDrive.spin(reverse, 100, pct);
  wait(220,msec);
  stopDrive(coast);
  while(leftDrive.velocity(pct) < -2 && rightDrive.velocity(pct) < -2);
  clawBack.set(!clawBack.value());
  forwardPID(800, 300);
  clawLiftBackL.open();
  clawLiftBackR.close();
  turnLeft(-88, 110);
  while(!orangeDist.isObjectDetected() || orangeDist.objectDistance(distanceUnits::cm) > 3.5){
    leftDrive.spin(reverse, 12, pct);
    rightDrive.spin(reverse, 12, pct);
  }
  stopDrive(coast);
  clawBack.open();
  wait(0.15,msec);
  clawLiftBackL.close();
  clawLiftBackR.open();
  stopDrive(coast);
  forwardPID(60, 120);
  turnRight(-1, 120);
  intakeB.spin(fwd, 100, pct);
  forwardPID(1400,120, 50, 1, 60);
  backwardPID(1350,200);
  intakeB.stop(coast);
  turnLeft(-90, 120);
  forwardPID(800, 200);
  clawFront.close();
  clawLiftFrontL.close();
  clawLiftFrontR.open();
  backwardPID(400, 200);
}
void middleAuto(){
  Brain.resetTimer();
  clawFront.close();
  clawLiftFrontL.close();
  clawLiftFrontR.open();
  leftDrive.spin(fwd, 100, pct);
  rightDrive.spin(fwd, 109, pct);
  wait(700, msec);
  while(!blueDist.isObjectDetected() || !(blueDist.objectDistance(distanceUnits::cm) < 19)){
    wait(20,msec);
  }
  task p(pullIn);
  stopDrive(brake);
  wait(150,msec);
  backwardPID(1500);
  leftDrive.spin(reverse, 30, pct);
  rightDrive.spin(reverse, 30, pct);
  wait(370,msec);
  while(leftDrive.velocity(pct) < -2 && rightDrive.velocity(pct) < -2);
  clawBack.set(!clawBack.value());
  forwardPID(800, 300);
  clawLiftBackL.open();
  clawLiftBackR.close();
  turnLeft(-88, 110);
  while(!orangeDist.isObjectDetected() || orangeDist.objectDistance(distanceUnits::cm) > 3.5){
    leftDrive.spin(reverse, 12, pct);
    rightDrive.spin(reverse, 12, pct);
  }
  stopDrive(coast);
  clawBack.open();
  wait(0.15,msec);
  clawLiftBackL.close();
  clawLiftBackR.open();
  stopDrive(coast);
  forwardPID(60, 120);
  turnRight(-1, 120);
  intakeB.spin(fwd, 100, pct);
  forwardPID(1400,120, 50, 1, 60);
  backwardPID(1350,200);
  intakeB.stop(coast);
  turnLeft(-90, 120);
  forwardPID(800, 200);
  clawFront.close();
  clawLiftFrontL.close();
  clawLiftFrontR.open();
  backwardPID(400, 200);
}
 
void testSkills(){

}