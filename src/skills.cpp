#include "auton.h"

int rollFix(){
  intake.spin(fwd, 100, pct);
  wait(200,msec);
  while(true){
    if(fabs(intake.velocity(pct)) < 5){
      intake.spin(reverse, 100, pct);
      wait(200,msec);
      intake.spin(fwd, 100, pct);
      wait(00,msec);
    }
    else{
      intake.spin(fwd, 100, pct);
    }
  }
  return(0);
}
void skills(){
  Brain.resetTimer();
  clampF.rotateFor(-450, deg, 100, percent, false);
  turnRight(12);
  forwardPID(500);
  armFP.open();
  clampF.spin(fwd, 70, pct);
  wait(700,msec);
  clampF.stop(hold);
  armF.rotateFor(750, deg, 100, percent, true);
  backwardPID(200);
  turnRight(87, 200);
  while(Brain.timer(sec) < 15);
  leftDrive.spin(reverse, 30, pct);
  rightDrive.spin(reverse, 30, pct);
  wait(1000,msec);
  while(fabs(leftDrive.velocity(pct)) > 2 && fabs(rightDrive.velocity(pct)) > 2);
  stopDrive(coast);
  wait(250,msec);
  while(fabs(leftDrive.velocity(pct)) > 2 && fabs(rightDrive.velocity(pct)) > 2);
  /*backwardPID(1230, 300);
  turnRight(168, 200);
  armF.stop(coast);
  armFP.close();
  wait(500,msec);
  task r(rollFix);
  backwardPID(3400, 150, 50, 2, 150);
  while(Brain.timer(sec) < 40);
  forwardPID(900, 100, 50, 2, 100);
  turnRight(203, 250);
  clampB.rotateFor(-450, deg, 100, percent, false);
  backwardPID(650, 200);
  clampB.spin(fwd, 70, pct);
  wait(700,msec);
  clampB.stop(hold);
  armBP.close();
  armFP.open();
  while(inert.rotation() < 205){
    rightDrive.spin(reverse, 40, pct);
    leftDrive.spin(fwd, 40, pct);
  }
  stopDrive(hold);
  armF.rotateFor(650, deg, 100, percent, false);
  armB.rotateFor(-650, deg, 100, percent, true);
  forwardPID(5000, 300, 50, 1.9, 150);*/
  while(Brain.timer(sec) < 30);
  leftDrive.rotateFor(100, deg, 100, percent, false);
  rightDrive.rotateFor(100, deg, 100, percent, true);
  turnLeft(5);
  forwardPID(100);
  armFP.close();
  armF.stop(coast);
  armF.spin(reverse, 100, pct);
  wait(300,msec);
  armF.stop(coast);
  wait(1200,msec);
  leftDrive.rotateFor(2300, deg, 100, percent, false);
  rightDrive.rotateFor(2300, deg, 100, percent, true);
  stopDrive(hold);
}