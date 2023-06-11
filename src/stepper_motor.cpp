#include "stepper_motor.hpp"
#include "pico/stdlib.h"

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


    return true;
}

bool StepperMotor::rotateAngle(double angle){


    return true;
}


void StepperMotor::rotateOneStep(StepperMotor::Direction direction){
    gpio_put(gpioPin1, 1);
    gpio_put(gpioPin2, 0);
    gpio_put(gpioPin3, 0);
    gpio_put(gpioPin4, 0);
    sleep_ms(StepperMotor::MILLISECOND_DELAY_BETWEEN_SIGNALS);
    gpio_put(gpioPin1, 0);
    gpio_put(gpioPin2, 1);
    gpio_put(gpioPin3, 0);
    gpio_put(gpioPin4, 0);
    sleep_ms(StepperMotor::MILLISECOND_DELAY_BETWEEN_SIGNALS);
    gpio_put(gpioPin1, 0);
    gpio_put(gpioPin2, 0);
    gpio_put(gpioPin3, 1);
    gpio_put(gpioPin4, 0);
    sleep_ms(StepperMotor::MILLISECOND_DELAY_BETWEEN_SIGNALS);
    gpio_put(gpioPin1, 0);
    gpio_put(gpioPin2, 0);
    gpio_put(gpioPin3, 0);
    gpio_put(gpioPin4, 1);
    sleep_ms(StepperMotor::MILLISECOND_DELAY_BETWEEN_SIGNALS);

    gpio_put(gpioPin1, 0);
    gpio_put(gpioPin2, 0);
    gpio_put(gpioPin3, 0);
    gpio_put(gpioPin4, 0);
}