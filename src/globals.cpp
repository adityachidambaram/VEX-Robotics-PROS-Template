#include "main.h"

// Motors
pros::Motor backRight(10, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor backLeft(20, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor frontRight(16, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES); // not wired
pros::Motor frontLeft(15, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor lift(17, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);
//pros::Motor clamp(1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

//pros::Motor backHook(1, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor backLift(9, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_ROTATIONS);

//Piston
#define DIGITAL_SENSOR_PORT 'A'
pros::ADIDigitalOut clampPiston('A');

// Sensors
pros::Imu inertial(8);

//auton switcher

//Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

int autonState = 0;
