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
  intakeB.stop(hold);
  Brain.resetTimer();
  clawFront.close();
  clawLiftFrontL.close();
  clawLiftFrontR.open();
  leftDrive.spin(fwd, 100, pct);
  rightDrive.spin(fwd, 100, pct);
  wait(900, msec);
  while(!blueDist.isObjectDetected() || !(blueDist.objectDistance(distanceUnits::cm) < 19)){
    wait(20,msec);
  }
  task p(pullIn);
  stopDrive(brake);
  wait(150,msec);
  backwardPID(1300, 600, 50, 3, 150);
  leftDrive.spin(reverse, 25, pct);
  rightDrive.spin(reverse, 25, pct);
  wait(1000,msec);
  while(fabs(leftDrive.velocity(pct)) > 2 && fabs(rightDrive.velocity(pct)) > 2);
  stopDrive(coast);
  clawBack.close();
  forwardPID(825, 300);
  clawLiftBackL.open();
  clawLiftBackR.close();
  turnLeft(-85, 110);
  while(!orangeDist.isObjectDetected() || orangeDist.objectDistance(distanceUnits::cm) > 3){
    leftDrive.spin(reverse, 20, pct);
    rightDrive.spin(reverse, 20, pct);
  }
  leftDrive.spin(reverse, 20, pct);
  rightDrive.spin(reverse, 20, pct);
  wait(500,msec);
  while(fabs(leftDrive.velocity(pct)) > 2 && fabs(rightDrive.velocity(pct)) > 5);
  stopDrive(coast);
  // leftDrive.spin(reverse, 5, pct);
  // rightDrive.spin(reverse, 5, pct);
  clawBack.open();
  wait(250,msec);
  stopDrive(coast);
  clawLiftBackL.close();
  clawLiftBackR.open();
  wait(0.5, sec);
  stopDrive(coast);
  intakeB.spin(fwd, 80, pct);
  forwardPID(175, 120);
  turnRight(0, 120);
  intakeB.spin(fwd, 100, pct);
  forwardPID(1400,120, 50, 1, 60);
  backwardPID(1350,200);
  //intakeB.stop(coast);
  turnLeft(-88, 120);
  forwardPID(800, 200);
  clawFront.close();
  clawLiftFrontL.close();
  clawLiftFrontR.open();
  wait(0.5, sec);
  backwardPID(400, 200);
  turnRight(-60, 150);
  forwardPID(670, 200);
  turnLeft(-83, 150);
  forwardPID(550, 150);

}
void middleAuto(){
  Brain.resetTimer();
  clawFront.close();
  clawLiftFrontL.close();
  clawLiftFrontR.open();
  leftDrive.spin(fwd, 100, pct);
  rightDrive.spin(fwd, 100, pct);
  wait(950, msec);
  /*while(!blueDist.isObjectDetected() || blueDist.objectDistance(distanceUnits::cm) > 13){
    std::cout << "DIST: " << blueDist.objectDistance(distanceUnits::cm) << std::endl;
    wait(10,msec);
  }*/
  task p(pullIn);
  stopDrive(brake);
  wait(250,msec);
  backwardPID(1800);
  turnRight(30);
  leftDrive.spin(reverse, 30, pct);
  rightDrive.spin(reverse, 30, pct);
  wait(370,msec);
  while(fabs(leftDrive.velocity(pct)) > 2 && fabs(rightDrive.velocity(pct)) > 2);
  stopDrive(coast);
  inert.resetHeading();
  inert.resetRotation();
  clawBack.close();
  forwardPID(850, 300);
  clawLiftBackL.open();
  clawLiftBackR.close();
  turnLeft(-85, 110);
  while(!orangeDist.isObjectDetected() || orangeDist.objectDistance(distanceUnits::cm) > 4){
    leftDrive.spin(reverse, 20, pct);
    rightDrive.spin(reverse, 20, pct);
  }
  leftDrive.spin(reverse, 20, pct);
  rightDrive.spin(reverse, 20, pct);
  wait(500,msec);
  while(fabs(leftDrive.velocity(pct)) > 5 && fabs(rightDrive.velocity(pct)) > 5);
  stopDrive(coast);
  // leftDrive.spin(reverse, 5, pct);
  // rightDrive.spin(reverse, 5, pct);
  clawBack.open();
  wait(250,msec);
  stopDrive(coast);
  clawLiftBackL.close();
  clawLiftBackR.open();
  wait(0.5, sec);
  stopDrive(coast);
  intakeB.spin(fwd, 80, pct);
  forwardPID(225, 120);
  turnRight(-1, 120);
  intakeB.spin(fwd, 100, pct);
  forwardPID(1400,120, 50, 1, 60);
  backwardPID(1350,200);
  //intakeB.stop(coast);
  turnLeft(-88, 120);
  forwardPID(800, 200);
  clawLiftFrontL.open();
  clawLiftFrontR.open();
  wait(0.5, sec);
  clawFront.close();
  wait(0.5, sec);
  backwardPID(400, 200);
  turnRight(-60, 150);
  forwardPID(660, 200);
  turnLeft(-85, 150);
  forwardPID(550, 200);
  
}
 
void testSkills(){

}