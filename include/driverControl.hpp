#include "main.h"

//CONTROLLS

// helper method
void setDrive(int left, int right);

void resetMotorEncoders();
double getRightEncoder();
double getLeftEncoder();
double getAvgEncoder();

// motor method
void setDriveMotors();

// lift method
void moveLift();

// clamp method
void moveClamp();

// wing method
void moveHook();

void moveBackLift();

// test method
void test();
