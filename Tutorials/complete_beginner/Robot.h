#ifndef __ROBOT_H__
#define __ROBOT_H__

#include "NewPing.h"
#include <Servo.h>

struct Config {
	// The pin for the servo
	int servoPin = 9;

	// Servo settings
	int steps = 3;		// How many degrees the servo will rotate each step
	int servoPos = 0;	// The initial position of the servo

	// The pins for the ultrasonic sensor
	int triggerPin = 10;
	int echoPin = 11;

	// The pins for the DC Motors
	// Pins controlling the speed of the motor via PWM
	int enA = 5;
	int enB = 6;
	
	// Pins controlling the direction the motors are going
	// Left motor (speed controlled by enA)
	int motorPin1 = 7;
	int motorPin2 = 2;
	// Right motor (speed conotrlled by enB)
	int motorPin3 = 3;
	int motorPin4 = 4;

	// Ultrasonic sensor limits (cm)
	int maxDistance = 200;
	int minDistance = 2;
};


class Robot {
public:
	Robot();
	Robot(Config c);
	~Robot();

	int getDistance();

	void setServoPos(int pos);
	int getServoPos();

	void roboSetup();
	int doSweep();
	void drive(int leftSpeed, int rightSpeed);

	Config roboConfig;

private:
	void checkRange(int *val);
	void setMotorStates(int leftVal, int rightVal);

	// objects handling control over servos and our sensor.
	Servo servo;
	NewPing *sonar;
};

#endif //__ROBOT_H__
