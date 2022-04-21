#include "auton.h"
#include <iostream>

void skills(){
  clawLiftBackL.open();
  clawLiftBackR.close();
  clawLiftFrontL.open();
  clawLiftFrontR.close();
  clawFront.close();
  clawBack.close();
  wait(250,msec);
  while(!blueDist.isObjectDetected() || blueDist.objectDistance(distanceUnits::cm) > 4){
    leftDrive.spin(fwd, 15, pct);
    rightDrive.spin(fwd, 15, pct);
  }
  stopDrive(coast);
  clawFront.open();
  wait(250,msec);
  clawLiftFrontL.close();
  clawLiftFrontR.open();
  while(inert.rotation() <= 83){
    leftDrive.spin(reverse, 7, pct);
    rightDrive.spin(reverse, 20, pct);
    if(inert.rotation() > 25)intakeF.spin(fwd,100, pct);
  }
  stopDrive(hold);
  intakeF.spin(fwd,100, pct);
  backwardPID(2300, 150, 50, 3.4);
  turnRight(112);
  backwardPID(1030, 200, 50, 3);
  turnLeft(0, 250);
  while(!orangeDist.isObjectDetected() || orangeDist.objectDistance(distanceUnits::cm) > 3){
    leftDrive.spin(reverse, 10, pct);
    rightDrive.spin(reverse, 10, pct);
  }
  stopDrive(coast);
  clawBack.open();
  wait(250, msec);
  clawLiftBackL.close();
  clawLiftBackR.open();
  forwardPID(300, 200);
  turnLeft(-90, 150);
  clawLiftFrontL.open();
  clawLiftFrontR.close();
  clawFront.close();
  backwardPID(230, 200);
  turnRight(-1, 150);
  intakeF.stop();
  intakeB.spin(fwd,100, pct);
  forwardPID(3000, 120, 50, 3.8);
  turnLeft(-115, 250);
  while(!blueDist.isObjectDetected() || blueDist.objectDistance(distanceUnits::cm) > 4){
    leftDrive.spin(fwd, 25, pct);
    rightDrive.spin(fwd, 25, pct);
  }
  stopDrive(coast);
  clawFront.open();
  wait(250, msec);
  clawLiftFrontL.close();
  clawLiftFrontR.open();

  backwardPID(800);
  turnRight(-90);
  backwardPID(2900);
  turnLeft(-180);
  leftDrive.spin(reverse, 25, pct);
  rightDrive.spin(reverse, 25, pct);
  wait(2, sec);
  stopDrive(coast);
  forwardPID(450, 200);


  // turnRight(90);
  // forwardPID(3800);

  // forwardPID(3800, 400, 50, 3.4);
  // clawFront.close();
  // turnLeft(-90, 340);
  // forwardPID(150);
  // clawFront.open();
  // wait(0.25, sec);
  // clawLiftFrontL.open();
  // clawLiftFrontR.close();
  // turnRight(-80);
  // backwardPID(150);
  // turnLeft(-90);
  // //2700
  // backwardPID(3000);
  // turnLeft(-270);

  // //turnLeft(-180, 340);
  // //backwardPID(450);
  // clawBack.open();
  // wait(0.25, sec);
  // clawLiftBackL.open();
  // clawLiftBackR.open();
  

}