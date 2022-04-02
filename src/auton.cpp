#include "auton.h"
#include  "spline.h"
#include "functions.h"
#include <iostream>

void matchAuto(){
  Brain.resetTimer();
  flip.spin(reverse, 40, pct);
  //original 90 not 100

  clawLiftBackL.close();
  clawLiftBackR.close();
  clawBack.close();
  backwardPID(1600, 500, 50, 3);
  //leftDrive.spin(fwd, 90, pct);
  //rightDrive.spin(fwd, 90, pct);
  //without arm
  
  //100s
  clawBack.open();
  wait(0.15, sec);
  clawLiftBackL.open();
  clawLiftBackR.open();
  leftDrive.spin(forward, 60, pct);
  rightDrive.spin(forward, 100, pct);
  wait(1.25, sec);
  intakeB.spin(fwd, 100, pct);
  stopDrive(brake);
  leftDrive.spin(forward, 60, pct);
  wait(0.5, sec);
  backwardPID(700);
  wait(500,msec);
  forwardPID(600);
  wait(500,msec);
  backwardPID(600);
  wait(500,msec);
  forwardPID(600);
  wait(500,msec);
  backwardPID(600);
  wait(500,msec);
  forwardPID(600);
  wait(500,msec);
  backwardPID(600);
  wait(500,msec);
  forwardPID(600);
  wait(500,msec);
  /*
  

  flip.spin(fwd, 100, pct);
  wait(450,msec);
  stopDrive(coast);
  flip.stop(hold);



  wait(200,msec);
  leftDrive.spin(reverse, 30, pct);
  rightDrive.spin(reverse, 30, pct);
  wait(300,msec);
  leftDrive.spin(reverse, 40, pct);
  rightDrive.spin(reverse, 100, pct);
  wait(900,msec);
  leftDrive.spin(reverse, 100, pct);
  rightDrive.stop(hold);
  wait(350, msec);
  stopDrive(coast);
  flip.spin(reverse, 50, pct);
  forwardPID(80, 200);
  flip.stop(hold);
  turnLeft(-90, 220);
  clawLiftBackL.close();
  clawLiftBackR.close();
  clawBack.close();
  backwardPID(270, 100);
  clawBack.open();
  wait(150,msec);
  clawLiftBackL.open();
  clawLiftBackR.open();
  intakeB.spin(fwd, 100, pct);
  forwardPID(750, 300);
  backwardPID(500, 300);
  forwardPID(500, 300);
  backwardPID(500, 300);
  forwardPID(500, 300);
  backwardPID(500, 300);
  forwardPID(500, 300);
  while(Brain.timer(sec) < 20);
  while(inert.rotation() < 0){
    leftDrive.spin(fwd, 30, pct);
    rightDrive.stop(hold);
  }
  forwardPID(650);
  turnRight(88, 300);
  forwardPID(1000);
  */
}
 
void testSkills(){

}