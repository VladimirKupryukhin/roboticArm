#include "stepper_motor.hpp"
#include "pico/stdlib.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

StepperMotor::StepperMotor(int pin1, int pin2, int pin3, int pin4): 
    gpioPin1(pin1), gpioPin2(pin2), gpioPin3(pin3), gpioPin4(pin4){
        gpio_init(gpioPin1);
        gpio_init(gpioPin2);
        gpio_init(gpioPin3);
        gpio_init(gpioPin4);

        gpio_set_dir(gpioPin1, GPIO_OUT);
        gpio_set_dir(gpioPin2, GPIO_OUT);
        gpio_set_dir(gpioPin3, GPIO_OUT);
        gpio_set_dir(gpioPin4, GPIO_OUT);

    }


bool StepperMotor::rotateToAngle(double angle){
    if (angle > (2 * 3.14)) {
        angle = angle - (2 * M_PI);
    }

    if (angle < 0) {
        angle = (2 * M_PI) - abs(angle);
    }

    double target = 0;

    if (angle < currentAngle) {
        target = (-1) * (currentAngle - angle);
    }
    else {
        target = angle;
    }

    rotateAngle(target);

    return true;
}

bool StepperMotor::rotateAngle(double angle){


    StepperMotor::Direction direction = StepperMotor::Direction::NOTHING;

    if (angle < 0){
        direction = StepperMotor::Direction::CLOCKWISE;
    }
    else {
        direction = StepperMotor::Direction::COUNTER_CLOCKWISE;
    }

    currentAngle += angle;

    if (currentAngle > (2 * 3.14)) {
        currentAngle = currentAngle - (2 * M_PI);
    }

    if (currentAngle < 0) {
        currentAngle = (2 * M_PI) - abs(currentAngle);
    }

    int stepNumber = abs(angle) / ANGLE_PER_STEP;

    for (int step = 0; step < stepNumber; step++) {
        StepperMotor::rotateOneStep(direction);
    }

    return true;
}


void StepperMotor::rotateOneStep(StepperMotor::Direction direction){
    int gpioPinArray[4] = {gpioPin1, gpioPin2, gpioPin3, gpioPin4};
    resetByteOut(direction);

    if (direction == StepperMotor::Direction::CLOCKWISE) {
        for (int pin = 0; pin < 4; pin++) {
            gpio_put(gpioPinArray[3 - pin], (byteOut & (0x01 << pin)) >> pin);
        }

        byteOut = byteOut << 1;// 0000 0001 -> 0000 0010 -> 0000 0100 -> 0000 1000
        lastDirectionMoved = StepperMotor::Direction::COUNTER_CLOCKWISE;

    }
    else if (direction == StepperMotor::Direction::COUNTER_CLOCKWISE){
        for (int pin = 0; pin < 4; pin++) {
            gpio_put(gpioPinArray[pin], (byteOut & (0x01 << pin)) >> pin);
        }

        byteOut = byteOut << 1;// 0000 0001 -> 0000 0010 -> 0000 0100 -> 0000 1000
        lastDirectionMoved = StepperMotor::Direction::CLOCKWISE;
    }

    currentStep = ++currentStep % STEPS_PER_REVOLUTION;
    // currentAngle = (currentAngle + ANGLE_PER_STEP);

    // if (currentAngle > 360.0) {
    //     currentAngle = 360 - currentAngle;
    // }

    sleep_ms(StepperMotor::MILLISECOND_DELAY_BETWEEN_SIGNALS);

}


void StepperMotor::resetByteOut(StepperMotor::Direction direction){
    if (currentStep % 4 == 0) {
        byteOut = 0x01;
    }
}
