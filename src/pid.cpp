#include "pid.h"
#include <iostream>
void forwardPID(float pos, int maxPower, int tim, float decel, int lowSpeed, bool closeEarly, int closer) {
	float error, lasterror = pos, totalerror = 0, t = 0, speed = 0;
  rotate.resetPosition();
	while (t<tim) {
		error = (pos-rotate.position(deg)); //Distance Left = Total Distance - Current 
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 300 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kp, D = derivative * kd, I = totalerror * ki;
    speed=P+I+D;
    if((speed-fabs(FrontL.velocity(rpm)))>=pow(FrontL.velocity(rpm),1.2) && error>100) speed=30+fabs(pow(FrontL.velocity(rpm),1.2)); //Acceleration 
    if(speed>=maxPower)speed=maxPower;
    if(speed < 0 && (fabs(error-pos) < 30 || error < 30)) speed = 0;
    if(error < pos/decel && FrontL.velocity(rpm)>lowSpeed) speed=FrontL.velocity(rpm)-70;
    if(error < pos/decel && (fabs(FrontL.velocity(rpm)) < lowSpeed || speed < lowSpeed)) speed = lowSpeed;
		rightDrive.spin(forward, speed, rpm); //Give Power to Motors
    leftDrive.spin(forward, speed, rpm);
		lasterror = error;
    if(error>50) t = 0;
    t = t+15;
		wait(15, msec);

  }
	//Stops motor to ensure accuracy
  stopDrive(brake);
  while(fabs(leftDrive.velocity(pct)) > 5 || fabs(rightDrive.velocity(pct)) > 5);
  printf("rotater: %.2f\n", rotate.position(deg));

}
void forwardPIDFAST(float pos, int maxPower, int tim) {
	float error, lasterror = pos, totalerror = 0, t = 0, speed = 0;
  rotate.resetPosition();
  error = 500;
	while (error > 70) {
		error = (pos-rotate.position(deg)); //Distance Left = Total Distance - Current 
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 300 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kp*1.5, D = derivative * kd, I = totalerror * ki * 0;
    speed=P+I+D;
    if((speed-fabs(FrontL.velocity(rpm)))>=pow(FrontL.velocity(rpm),1.4) && error>100) speed=60+fabs(pow(FrontL.velocity(rpm),1.4)); //Acceleration
    if(speed>=maxPower)speed=maxPower;
    if(speed < 0 && (fabs(error-pos) < 100 || error < 30)) speed = 0;
    if(error < pos/2.4 && FrontL.velocity(rpm)>90) speed=FrontL.velocity(rpm)-60;
    if(error < pos/2.4 && (fabs(FrontL.velocity(rpm)) < 120 || speed < 120)) speed = 120;
		rightDrive.spin(forward, speed, rpm); //Give Power to Motors
    leftDrive.spin(forward, speed, rpm);
		lasterror = error;
    t = t+15;
		wait(15, msec);
  }
	//Stops motor to ensure accuracy
  stopDrive(brake);
  printf("rotater: %.2f\n", rotate.position(deg));

}
void forwardPID2(float pos, int maxPower, int tim) {
	float error, lasterror = pos, totalerror = 0, t = 0, speed = 0;
  rotate.resetPosition();
	while (t<tim) {
		error = (pos-rotate.position(deg)); //Distance Left = Total Distance - Current 
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 300 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kp*1.7, D = derivative * kd*1.9, I = totalerror * ki*0;
    speed=P+I+D;
    if((speed-fabs(FrontL.velocity(rpm)))>=70 && error>100) speed=fabs(FrontL.velocity(rpm))+70; //Acceleration 
    if(speed>=maxPower)speed=maxPower;
    if(speed < 0 && (fabs(error-pos) < 100)) speed = 0;
    if(error < pos/2.5 && FrontL.velocity(rpm)>50) speed=FrontL.velocity(rpm)-50;
    if(error < pos/2.5 && (fabs(FrontL.velocity(rpm)) < 60 || speed < 60)) speed = 60;
    //std::cout << "Speed: " << speed << std::endl;
		rightDrive.spin(forward, speed, rpm); //Give Power to Motors
    leftDrive.spin(forward, speed, rpm);
		lasterror = error;
    if(error>75) t = 0;
    t = t+15;
		wait(15, msec);
  }
	//Stops motor to ensure accuracy
  stopDrive(brake);
  while(fabs(leftDrive.velocity(pct)) > 5 || fabs(rightDrive.velocity(pct)) > 5);
  printf("rotater: %.2f\n", rotate.position(deg));

}
void backwardPID2(float pos, int maxPower, int tim) {
	float error, lasterror = pos, totalerror = 0, t = 0, speed = 0;
  rotate.setPosition(0, degrees);
	while (t<tim) {
		error = (pos+rotate.value()); //Distance Left = Total Distance - Current 
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 300 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kp * 0.2, D = derivative * kd*1, I = totalerror * ki * 0;
    speed=P+I+D;
    if(speed>=maxPower)speed=maxPower;
    if((speed-fabs(FrontL.velocity(rpm)))>=50 && error>500) speed=fabs(FrontL.velocity(rpm))+50; //Acceleration 
    if(error < pos/2 && fabs(FrontL.velocity(rpm)) > 40) speed=fabs(FrontL.velocity(rpm))-80;
    if(error < pos/2 && (fabs(FrontL.velocity(rpm)) < 30 || speed < 30)) speed = 30;
    if(speed < 0 && ((fabs(error-pos) < 100))) speed = 0;
		rightDrive.spin(reverse, speed, rpm); //Give Power to Motors
    leftDrive.spin(reverse, speed, rpm);
		lasterror = error;
    if(error>150) t = 0;
    t = t+15;
		wait(15, msec);
  }
	//Stops motor to ensure accuracy
  stopDrive(hold);
  while(fabs(leftDrive.velocity(pct)) > 5 || fabs(rightDrive.velocity(pct)) > 5);
  printf("rotater: %ld\n", rotate.value());

}
void backwardPID(float pos, int maxPower, int tim, float decel, int lowSpeed) {
	float error, lasterror = pos, totalerror = 0, t = 0, speed = 0;
  rotate.resetPosition();
	while (t<tim) {
		error = (pos+rotate.position(deg)); //Distance Left = Total Distance - Current 
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 250 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kp * 1.1, D = derivative * kd, I = totalerror * ki;
    speed=P+I+D;
    if((speed-fabs(FrontL.velocity(rpm)))>=pow(fabs(FrontL.velocity(rpm)),1.2) && error>100) speed=40+pow(fabs(FrontL.velocity(rpm)),1.2); //Acceleration 
    if(speed>=maxPower)speed=maxPower;
    if(speed < 0 && (fabs(error-pos) < 30 || error < 30)) speed = 0;
    if(error < pos/decel && fabs(FrontL.velocity(rpm))>lowSpeed) speed=fabs(FrontL.velocity(rpm))-60;
    if(error < pos/decel && (fabs(FrontL.velocity(rpm)) < lowSpeed || speed < lowSpeed)) speed = lowSpeed;
		rightDrive.spin(reverse, speed, rpm); //Give Power to Motors
    leftDrive.spin(reverse, speed, rpm);
		lasterror = error;
    if(error>30) t = 0;
    t = t+15;
		wait(15, msec);
  }
	//Stops motor to ensure accuracy
  stopDrive(brake);
  while(fabs(leftDrive.velocity(pct)) > 5 || fabs(rightDrive.velocity(pct)) > 5);
  printf("rotater: %.2f\n", rotate.position(deg));
}
void backwardPIDARC(float pos, int maxPower, int tim, float decel, int lowSpeed) {
	float error, lasterror = pos, totalerror = 0, t = 0, speed = 0;
  rotate.resetPosition();
	while (t<tim) {
		error = (pos+rotate.position(deg)); //Distance Left = Total Distance - Current 
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 250 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kp * 1.2, D = derivative * kd, I = totalerror * ki;
    speed=P+I+D;
    if((speed-fabs(FrontL.velocity(rpm)))>=pow(fabs(FrontL.velocity(rpm)),1.4) && error>100) speed=50+pow(fabs(FrontL.velocity(rpm)),1.4); //Acceleration 
    if(speed>=maxPower)speed=maxPower;
    if(speed < 0 && (fabs(error-pos) < 30 || error < 30)) speed = 0;
    if(error < pos/decel && fabs(FrontL.velocity(rpm))>lowSpeed) speed=fabs(FrontL.velocity(rpm))-60;
    if(error < pos/decel && (fabs(FrontL.velocity(rpm)) < lowSpeed || speed < lowSpeed)) speed = lowSpeed;
		rightDrive.spin(reverse, speed, rpm); //Give Power to Motors
    leftDrive.spin(reverse, speed*0.8, rpm);
		lasterror = error;
    if(error>30) t = 0;
    t = t+15;
		wait(15, msec);
  }
	//Stops motor to ensure accuracy
  stopDrive(brake);
  while(fabs(leftDrive.velocity(pct)) > 5 || fabs(rightDrive.velocity(pct)) > 5);
  printf("rotater: %.2f\n", rotate.position(deg));
}
void turnLeft(float pos, int maxPower, int tim) {
	float error = 300, lasterror = pos, totalerror = 0, t=0, Power= 10;
  //Clears the rotater
  float initialError = pos - inert.rotation();
	while (t<tim) {
		error = inert.rotation() - pos;//Q-pos;
		if (error < 0)totalerror = 0;
		if (fabs(error) < 25 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpT, D = derivative * kdT, I = totalerror * kiT;
    Power=P+I+D;
    if(maxPower < 20) maxPower = 20;
    if(Power<0 && (fabs(error-pos) < 5 || error < 1)) Power = 0;
    if((Power-fabs(FrontL.velocity(rpm))) >= 40 && error > initialError*0.6) Power=fabs(FrontL.velocity(rpm)) + 40; //Acceleration 
    if(Power>maxPower)Power=maxPower;
    rightDrive.spin(forward, Power, rpm); //Give Power to Motors
    leftDrive.spin(reverse, Power, rpm);
		lasterror = error;
    if(error>1) t = 0;
    t += 15;
		wait(15, msec);
	}
  stopDrive(hold);
  while(fabs(leftDrive.velocity(pct)) > 5 || fabs(rightDrive.velocity(pct)) > 5);
  printf("Angle: %.2f\n", inert.rotation());
}
void turnRight(float pos, int maxPower, int tim) {
	float error = 300, lasterror = pos, totalerror = 0, t=0, Power= 10;
  float initialError = pos - inert.rotation();
  //Clears the rotater
	while (t<tim) {
    error = pos - inert.rotation();
		if (fabs(error) < 25 && error != 0)totalerror += error;
		else totalerror = 0;
    if (error < 0)totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpT, D = derivative * kdT, I = totalerror * kiT;
    Power=P+I+D;
    if(maxPower < 20) maxPower = 20;
    if(Power<0 && (fabs(error-pos) < 5 || error < 1)) Power = 0;
    if((Power-fabs(FrontL.velocity(rpm))) >= 40 && error > initialError*0.6) Power=fabs(FrontL.velocity(rpm)) + 40; //Acceleration 
    if(Power>maxPower)Power=maxPower;
		rightDrive.spin(reverse, Power, rpm); //Give Power to Motors
    leftDrive.spin(forward, Power, rpm);
		lasterror = error;
    if(error>1) t = 0;
    t += 15;
		wait(15, msec);
	}
  stopDrive(hold);
  while(fabs(leftDrive.velocity(pct)) > 5 || fabs(rightDrive.velocity(pct)) > 5);
  printf("Angle: %.2f\n", inert.rotation());
}
void turnRight2(float pos, int maxPower, int tim) {
	float error = 300, lasterror = pos, totalerror = 0, t=0, Power= 10;
  float initialError = pos - inert.rotation();
  //Clears the rotater
	while (t<tim) {
    error = pos - inert.rotation();
		if (fabs(error) < 25 && error != 0)totalerror += error;
		else totalerror = 0;
    if (error < 0)totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpT, D = derivative * kdT, I = totalerror * kiT;
    Power=P+I+D;
    if(Power<0 && (fabs(error-pos) < 5 || error < 1)) Power = 0;
    if((Power-fabs(FrontL.velocity(rpm))) >= 40 && error > initialError*0.5) Power=fabs(FrontL.velocity(rpm)) + 40; //Acceleration 
    if(Power>maxPower)Power=maxPower;
    if(Power < 40) Power = 40;
		rightDrive.spin(reverse, Power, rpm); //Give Power to Motors
    leftDrive.spin(forward, Power, rpm);
		lasterror = error;
    if(error>1.5) t = 0;
    t += 15;
		wait(15, msec);
	}
  stopDrive(hold);
  while(fabs(leftDrive.velocity(pct)) > 5 || fabs(rightDrive.velocity(pct)) > 5);
  printf("Angle: %.2f\n", inert.rotation());
}