#include "auton.h"


void skills(){
  clawLiftFrontL.close();
  clawLiftFrontR.open();
  clawLiftBackL.close();
  clawLiftBackR.close();
  clawBack.close();

  forwardPID(3300);
  clawFront.close();
  turnLeft(-90, 340);
  forwardPID(150);
  clawFront.open();
  wait(0.25, sec);
  clawLiftFrontL.open();
  clawLiftFrontR.close();
  turnRight(-80);
  backwardPID(150);
  turnLeft(-90);
  //2700
  backwardPID(3000);
  turnLeft(-270);

  //turnLeft(-180, 340);
  //backwardPID(450);
  clawBack.open();
  wait(0.25, sec);
  clawLiftBackL.open();
  clawLiftBackR.open();
  

}