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
    int gpioPinArray[4] = {gpioPin1, gpioPin2, gpioPin3, gpioPin4};


    // if (direction == StepperMotor::Direction::CLOCKWISE) {
    //     if (lastDirectionMoved == StepperMotor::Direction::COUNTER_CLOCKWISE) {
    //         byteOut[0] = 0;
    //         byteOut[1] = 0;
    //         byteOut[2] = 0;
    //         byteOut[3] = 1;
    //     }

    //     for (int pin = 0; pin < 4; pin++) {
    //         gpio_put(gpioPinArray[pin], byteOut[3 - pin]);
    //     }



    //     lastDirectionMoved = StepperMotor::Direction::CLOCKWISE;

    // }
    // else if (direction == StepperMotor::Direction::COUNTER_CLOCKWISE){
    //     if (lastDirectionMoved == StepperMotor::Direction::CLOCKWISE) {
    //         byteOut[0] = 1;
    //         byteOut[1] = 0;
    //         byteOut[2] = 0;
    //         byteOut[3] = 0;
    //     }


    //     lastDirectionMoved = StepperMotor::Direction::COUNTER_CLOCKWISE;
    // }

    // currentStep = ++currentStep;




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

    currentStep = ++currentStep;


    // gpio_put(gpioPin1, 0);
    // gpio_put(gpioPin2, 0);
    // gpio_put(gpioPin3, 0);
    // gpio_put(gpioPin4, 0);

    //sleep_ms(500);
    sleep_ms(StepperMotor::MILLISECOND_DELAY_BETWEEN_SIGNALS);

}


void StepperMotor::resetByteOut(StepperMotor::Direction direction){
    if (currentStep % 4 == 0) {
        byteOut = 0x01;
    }
}
