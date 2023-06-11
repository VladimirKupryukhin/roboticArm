#pragma ONCE
#include "pico/stdlib.h"

class StepperMotor {

private:
    enum Direction{
        CLOCKWISE = true,
        COUNTER_CLOCKWISE = false
    };

    int gpioPin1 = -1;
    int gpioPin2 = -1;
    int gpioPin3 = -1;
    int gpioPin4 = -1;

    int currentStep = 0;
    double currentAngle = 0;

    int MILLISECOND_DELAY_BETWEEN_SIGNALS = 3;

    // //true = clockwise, false = counterclockwise
    // void rotateOneStep(StepperMotor::Direction direction);

public:
    StepperMotor(int pin1, int pin2, int pin3, int pin4);
    //~StepperMotor();

    //Moves the motor to the specified angle relative to its zero
    bool rotateToAngle(double angle);

    //Moves the motor the specified angle. If the end point is outside of the motor's range, return false
    bool rotateAngle(double angle);

    //true = clockwise, false = counterclockwise
    void rotateOneStep(StepperMotor::Direction direction);

    


};