#include "auton.h"


void skill(){
  Brain.resetTimer();
  clawLiftFrontL.close();
  clawLiftFrontR.open();
  clawLiftBackL.close();
  clawLiftBackR.close();
  clawBack.close();
  
  forwardPID(2000, 350, 50, 3.7);
  turnRight(15, 200);
  forwardPID(1350, 350, 50, 3.7);
  clawFront.close();
  turnLeft(-90, 250);
  forwardPID(290, 100);
  while(Brain.timer(sec) < 14); 
  clawFront.open();
  wait(0.25, sec);
  clawLiftFrontL.open();
  clawLiftFrontR.close();
  intakeF.spin(fwd, 80, pct);
  turnRight(-80);
  backwardPID(200);
  turnLeft(-90);
  //2700
  backwardPID(3050, 400, 50, 3.5);
  turnLeft(-215);

  //turnLeft(-180, 340);
  backwardPID(500);
  clawBack.open();
  wait(0.25, sec);
  clawLiftBackL.open();
  clawLiftBackR.open();
  intakeB.spin(fwd, 80, pct);
  forwardPID(400);
  turnRight(-180);
  forwardPID(3500, 400, 50, 3.5);
  backwardPID(500,200);
  wait(500,msec);
  forwardPID(500, 200);
  wait(500,msec);
  backwardPID(500,200);
  wait(500,msec);
  forwardPID(500, 200);
  wait(500,msec);
  backwardPID(500,200);
  wait(500,msec);
  forwardPID(500, 200);
}