#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

motor FrontR = motor(PORT13, ratio6_1, true); 
motor MiddleR = motor(PORT11, ratio6_1, false); 
motor BMiddleR = motor(PORT14, ratio6_1, true); 
motor BackR = motor(PORT12, ratio6_1, true); 
motor FrontL = motor(PORT18, ratio6_1, false); 
motor BMiddleL = motor(PORT16, ratio6_1, false);
motor MiddleL = motor(PORT17, ratio6_1, true);
motor BackL = motor(PORT19, ratio6_1, false); 
motor intakeF = motor(PORT20, ratio18_1, true);
motor intakeB = motor(PORT15, ratio18_1, true);
motor flip = motor(PORT10, ratio18_1, true);
pneumatics clawFront = pneumatics(Brain.ThreeWirePort.B);
pneumatics clawBack = pneumatics(Brain.ThreeWirePort.D);
pneumatics clawLiftFrontR = pneumatics(Brain.ThreeWirePort.C);
pneumatics clawLiftFrontL = pneumatics(Brain.ThreeWirePort.A);
pneumatics clawLiftBackL = pneumatics(Brain.ThreeWirePort.E);
pneumatics clawLiftBackR = pneumatics(Brain.ThreeWirePort.F);
motor_group leftDrive = motor_group(FrontL, MiddleL, BMiddleL,BackL);
motor_group rightDrive = motor_group(FrontR, MiddleR, BMiddleR, BackR);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
rotation rotate = rotation(PORT8, false);
inertial inert = inertial(PORT7);
distance orangeDist = distance(PORT2);
distance blueDist = distance(PORT9);

void vexcodeInit(void) {
  // Nothing to initialize
}