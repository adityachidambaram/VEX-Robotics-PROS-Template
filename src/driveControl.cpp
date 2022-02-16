#include "main.h"

/***************************************************************************************
- POWER MULTIPLIER INCREASES SPEED OF THE DRIVE. MUILTIPLIER CAPS AT 1                 *
- RIGHT/LEFT MULTIPLIER ACCOUNTS FOR ONE SIDE BEING MORE POWERFUL                      *
- TUNE THE CONSTANTS AS NEEDED                                                         *
***************************************************************************************/

double powerMultiplier = 1;
double rightMultiplier = 1;
double leftMultiplier = 1;

//DRIVE
void setDrive(int left, int right) {
  backLeft = left;
  backRight = right;
  frontLeft = left;
  frontRight = right;
}

void setDriveMotors() {

  double power = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  double direction = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

  power *= powerMultiplier;

  int left = power + (direction * leftMultiplier);
  int right = power - (direction * rightMultiplier);

  if (abs(power) <= 20)
    setDrive(0, 0);
  if(abs(direction) <= 20)
    setDrive(0, 0);

  setDrive(left, right);
}


void moveLift() {
/***************************************************************************************
- CHANGE BUTTONS IF NEED                                                               *
- CHANGE CHANGE LIFT SPEED AS NEED                                                     *
***************************************************************************************/
  bool getLiftUp = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
  bool getLiftDown = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
  const int liftSpeed = 115;

  if(getLiftUp) {
    lift = liftSpeed;
  }
  else if(getLiftDown) {
    lift = -liftSpeed;
  }
  else {
    lift = 0;
  }
}

void moveClamp() {
/***************************************************************************************
- CHANGE BUTTONS IF NEED                                                               *
***************************************************************************************/
  bool open = controller.get_digital(pros::E_CONTROLLER_DIGITAL_A);
  bool close = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);

  if(open) {
    piston.set_value(false);
  }
  if(close) {
    piston.set_value(true);
  }
}
/***************************************************************************************
- ADD MORE METHODS BY COPING AND PASTING THE "moveLift()" METHOD                       *
- CHANGE THE BUTTONS, LOOK AT README FOR MORE INFORMATION                              *
***************************************************************************************/


void resetMotorEncoders() {
  backLeft.tare_position();
  backRight.tare_position();
  frontRight.tare_position();
  frontLeft.tare_position();
}

double getRightEncoder() {
  return (fabs(backRight.get_position()) + fabs(frontRight.get_position())) / 2;
}

double getLeftEncoder() {
  return (fabs(frontLeft.get_position()) + fabs(backLeft.get_position())) / 2;
}

double getAvgEncoder() {
  return (fabs(backRight.get_position()) + fabs(backLeft.get_position()) +
         fabs(frontRight.get_position()) + fabs(frontLeft.get_position())) / 4;
}


//TESTING
void test() {
  //USE IF NEEDED TO TEST SPECIFIC MOTORS
}
