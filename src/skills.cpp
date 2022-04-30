#include "auton.h"
#include <iostream>


int fixIntake(){
  intakeB.spin(fwd, 90,pct);
  intakeF.spin(fwd, 90, pct);
  wait(500,msec);
  while(true){
    intakeB.spin(fwd, 90,pct);
    intakeF.spin(fwd, 90, pct);
    if(intakeB.velocity(pct) < 5){
      intakeB.spin(reverse,50,pct);
      wait(350,msec);
      intakeB.spin(fwd, 90, pct);
      wait(1000,msec);
    }
    if(intakeF.velocity(pct) < 5){
      intakeF.spin(reverse,50,pct);
      wait(350,msec);
      intakeF.spin(fwd, 90, pct);
      wait(1000,msec);
    }
  }
}
void skills(){
  Brain.resetTimer();
  clawFront.close();
  clawBack.close();
  clawLiftFrontL.close();
  clawLiftFrontR.open();
  wait(400,msec);
  while(!blueDist.isObjectDetected() || blueDist.objectDistance(distanceUnits::cm) > 4){
    leftDrive.spin(fwd, 10, pct);
    rightDrive.spin(fwd, 10, pct);
  }
  stopDrive(coast);
  clawFront.open();
  wait(250,msec);
  clawLiftFrontL.open();
  clawLiftFrontR.close();
  while(inert.rotation() <= 83){
    leftDrive.spin(reverse, 7, pct);
    rightDrive.spin(reverse, 22 , pct);
    if(inert.rotation() > 25)intakeF.spin(fwd,100, pct);
  }
  stopDrive(hold);
  task f(fixIntake);
  backwardPID(2350, 130, 50, 1.5);
  turnRight(112, 150);
  backwardPID(910, 200, 50, 4);
  clawLiftBackL.open();
  clawLiftBackR.close();
  turnLeft(0, 200,30);
  while(!orangeDist.isObjectDetected() || orangeDist.objectDistance(distanceUnits::cm) > 4){
    leftDrive.spin(reverse, 10, pct);
    rightDrive.spin(reverse, 10, pct);
  }
  stopDrive(coast);
  clawBack.open();
  wait(0.25, sec);
  clawLiftBackL.close();
  clawLiftBackR.open();
  turnLeft(-88, 150);
  clawLiftFrontL.open();
  clawLiftFrontR.open();
  wait(0.35, sec);
  clawFront.close();
  backwardPID(160, 150);
  intakeF.stop(hold);
  clawLiftFrontL.close();
  clawLiftFrontR.open();
  turnRight(0, 150);
  clawFront.open();
  leftDrive.spin(reverse, 10, pct);
  rightDrive.spin(reverse, 10, pct);
  wait(1000,msec);
  while(fabs(leftDrive.velocity(pct)) > 3 && fabs(rightDrive.velocity(pct)) > 3);
  stopDrive(coast);
  clawFront.close();
  forwardPID(3780, 130, 50, 1.4);
  turnLeft(-117.5, 120);
  while(!blueDist.isObjectDetected() || blueDist.objectDistance(distanceUnits::cm) > 4){
    leftDrive.spin(fwd, 25, pct);
    rightDrive.spin(fwd, 25, pct);
  }
  intakeB.stop(hold);
  stopDrive(coast);
  clawFront.open();
  wait(250, msec);
  clawLiftFrontL.open();
  clawLiftFrontR.close();
  backwardPID(920, 200);
  intakeF.spin(fwd, 100, pct);
  turnRight(-95, 100, 40);
  wait(150,msec);
  backwardPID(2500,130, 50, 2);
  leftDrive.spin(reverse, 15, pct);
  rightDrive.spin(reverse, 15, pct);
  wait(1000,msec);
  while(fabs(leftDrive.velocity(pct)) > 3 && fabs(rightDrive.velocity(pct)) > 3);
  stopDrive(coast);
  turnLeft(-195, 150);
  flip.spin(reverse, 100, pct);
  wait(150,msec);
  forwardPID(170, 120);
  wait(300,msec);
  while(fabs(flip.velocity(pct)) > 5);
  flip.spin(reverse, 10, pct);
  wait(150,msec);
  turnRight(-189, 120);
  leftDrive.rotateFor(2620, deg, 100, percent, false);
  rightDrive.rotateFor(2620, deg, 100, percent);
  wait(2000, msec);
  flip.stop(hold);
  clawLiftBackL.open();
  clawLiftBackR.open();
  clawLiftFrontL.open();
  clawLiftFrontR.open();
  wait(0.7, sec);
  clawBack.close();
  clawFront.close();
  wait(0.7, sec);
  clawLiftBackL.close();
  clawLiftBackR.open();
  clawLiftFrontL.open();
  clawLiftFrontR.close();
  wait(1.14, msec);
  clawBack.open();
  clawFront.open();
  std::cout << Brain.timer(seconds) << std::endl;
}