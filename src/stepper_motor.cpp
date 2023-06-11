#include "stepper_motor.hpp"

StepperMotor::StepperMotor(int pin1, int pin2, int pin3, int pin4): 
    gpioPin1(pin1), gpioPin2(pin2), gpioPin3(pin3), gpioPin4(pin4){}


bool StepperMotor::rotateToAngle(double angle){


    return true;
}

bool StepperMotor::rotateAngle(double angle){


    return true;
}


void StepperMotor::rotateOneStep(StepperMotor::Direction direction){

}