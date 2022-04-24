#pragma once
#include "functions.h"
#include "math.h"
#define kp 0.53
#define kd 0.27
#define ki 0.05
#define kpT 3.6
#define kdT 0.6
#define kiT 0.08

void forwardPIDFAST(float pos, int maxPower = 600, int tim = 50);
void forwardPID(float pos, int maxPower = 400, int tim = 50, float decel = 2.4, int lowSpeed = 40, bool closeEarly = false, int closer = 400);
void forwardPID2(float pos, int maxPower = 430, int tim = 50);
void backwardPID(float pos, int maxPower = 400, int tim = 50, float decel = 2, int lowSpeed = 40);
void backwardPIDARC(float pos, int maxPower = 470, int tim = 50, float decel = 2, int lowSpeed = 70);
void backwardPID2(float pos, int maxPower = 430, int tim = 50);
void turnLeft(float pos, int maxSpeed = 370, int tim = 50);
void turnRight(float pos, int maxSpeed = 370, int tim = 50);
void turnRight2(float pos, int maxSpeed = 350, int tim = 50);
void turnTo(float pos, int tim, int maxSpeed);