#include "main.h"

void on_center_button() {
	/**
	 * A callback function for LLEMU's center button.
	 *
	 * When this callback is fired, it will toggle line 2 of the LCD text between
	 * "I was pressed!" and nothing.
	 */
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}


void initialize() {
	/**
	 * Runs initialization code. This occurs as soon as the program is started.
	 *
	 * All other competition modes are blocked by initialize; it is recommended
	 * to keep execution time for this mode under a few seconds.
	 */

	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hi monkey ");
	pros::lcd::register_btn1_cb(on_center_button);

	backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	backRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

	lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	backLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	clampPiston.set_value(false);

	inertial.reset();
}


void disabled() {
	/**
	 * Runs while the robot is in the disabled state of Field Management System or
	 * the VEX Competition Switch, following either autonomous or opcontrol. When
	 * the robot is enabled, this task will exit.
	 */
}


void competition_initialize() {
	/**
	 * Runs after initialize(), and before autonomous when connected to the Field
	 * Management System or the VEX Competition Switch. This is intended for
	 * competition-specific initialization routines, such as an autonomous selector
	 * on the LCD.
	 *
	 * This task will exit when the robot is enabled and autonomous or opcontrol
	 * starts.
	 */
	pros::lcd::initialize();
	pros::lcd::set_text(1, "750C :)");
	pros::lcd::register_btn1_cb(on_center_button);
	pros::lcd::clear_line(1);


	pros::lcd::set_text(1, "No auton currently selected.");
	clampPiston.set_value(false);


}


void autonomous() {
	forwardClamp();
	//forwardAWP();
}


void opcontrol() {
	/**
	 * Runs the operator control code. This function will be started in its own task
	 * with the default priority and stack size whenever the robot is enabled via
	 * the Field Management System or the VEX Competition Switch in the operator
	 * control mode.
	 *
	 * If no competition control is connected, this function will run immediately
	 * following initialize().
	 *
	 * If the robot is disabled or communications is lost, the
	 * operator control task will be stopped. Re-enabling the robot will restart the
	 * task, not resume it from where it left off.
	 */

	while(true) {
		setDriveMotors();
		moveLift();
		moveClamp();
		moveBackLift();
		pros::delay(10);
	}
}
