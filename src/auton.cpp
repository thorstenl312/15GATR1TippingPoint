#include "auton.h"
#include  "spline.h"
#include "functions.h"
#include <iostream>

void matchAuto(){
  Brain.resetTimer();
  rotate.resetPosition();
  forwardPIDFAST(900, 600, 30);
  //flip.open();
  driveIntoWall(350, 60);
  flip.close();
  forwardPID(100);
  clampB.rotateFor(-450, deg, 100, percent, false);
  turnLeft(-80);
  backwardPID(120, 250);
  clampB.spin(fwd, 90, pct);
  wait(800,msec);
  clampB.stop(hold);
  intake.spin(fwd, 70, pct);
  wait(3000,msec);
  intake.stop(coast);
  forwardPID(300, 250, 50);
  while(inert.angle() < -3){
    leftDrive.spin(fwd, 40, pct);
    rightDrive.spin(fwd, 10, pct);
  }
  stopDrive(brake);
  clampF.rotateFor(-450, deg, 100, percent, false);
  //forwardPID(300, 200);
  /*
  armB.rotateFor(-500, deg, 30, percent, true);
  stopDrive(hold);
  armB.stop(hold);
  turnRight(80);
  while(fabs(leftDrive.velocity(pct)) > 5 && fabs(rightDrive.velocity(pct)) > 5);
  clampF.rotateFor(-450, deg, 100, percent, false);
  forwardPID(1500, 200, 50, 2, 150);
  turnRight(85, 250);
  forwardPID(1400, 200, 50, 2, 150);
  clampF.spin(fwd, 70, pct);
  wait(700,msec);
  clampF.stop(hold);
  intake.spin(fwd, 80, pct);
  wait(2000, msec);
  backwardPID(600);
  armBP.open();
  armB.stop(coast);*/
  /*arm.setBrake(hold);
  stage1.setBrake(hold);
  stage2.setBrake(hold);
  arm.spin(reverse, 15, percent);
  forwardPIDFAST(930, 600);
  wait(100,msec);
  arm.spin(reverse, 100, percent);
  //wait(50,msec);
  //arm.stop(hold);
  driveIntoWall(400, 100);
  arm.spin(forward, 100, pct);
  forwardPID(70);
  turnLeft(-88);
  arm.stop(hold);
  ring.close();
  backwardPID(200);
  clamp.spin(fwd,100,pct);
  wait(500,msec);
  leftDrive.spin(fwd, 100, pct);
  rightDrive.spin(fwd, 100, pct);
  clamp.stop(hold);
  arm.spin(reverse, 10, pct);
  wait(350, msec);
  arm.stop(hold);
  stopDrive(coast);
  stage1.spin(reverse, 25, pct);
  stage2.spin(fwd, 10, pct);
  wait(500,msec);
  stage2.stop(hold);
  stage1.stop(hold);
  ring.open();
  clamp.rotateFor(-80, deg, 100, percent, true);
  leftDrive.spin(reverse, 15, pct);
  rightDrive.spin(reverse, 15, pct);
  arm.spin(reverse, 30, pct);
  wait(200,msec);
  arm.stop(hold);
  clamp.rotateFor(60, deg, 100, percent, true);
  wait(250,msec);
  stopDrive(coast);
  arm.stop(hold);
  stage1.rotateFor(800, deg, 45, percent, true);
  wait(150,msec);
  stage2.rotateFor(190, deg, 45, percent, true);
  wait(150,msec);
  stage1.rotateFor(-150, deg, 45, percent, true);
  wait(500, msec);
  ring.close();
  wait(1500,msec);
  ring.open();
  stage1.rotateFor(150, deg, 45, percent, true);
  stage2.rotateFor(-230, deg, 45, percent, true);
  stage1.rotateFor(-800, deg, 45, percent, true);
  stage1.stop(coast);
  stage2.stop(coast);
  clamp.spin(reverse, 50, pct);
  wait(300,msec);
  clamp.stop(coast);
  turnLeft(-170);*/
}
 
void testSkills(){

}