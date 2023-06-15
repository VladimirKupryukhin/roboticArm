/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "include/stepper_motor.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main() {

    stdio_init_all();

    for (int index = 0; index < 10; index++) {
        sleep_ms(1000);
        std::cout << index << std::endl;
    }


    StepperMotor stepperMotor(13,12,11,10);

    // stepperMotor.rotateAngle(360);
    // sleep_ms(1000);
    // stepperMotor.rotateAngle(-720);
    // sleep_ms(1000);
    // stepperMotor.rotateAngle(450);//90
    // sleep_ms(1000);


    // stepperMotor.rotateToAngle(90, StepperMotor::Direction::COUNTER_CLOCKWISE);
    // sleep_ms(1000);
    // stepperMotor.rotateToAngle(0, StepperMotor::Direction::CLOCKWISE);
    // sleep_ms(1000);
    // stepperMotor.rotateToAngle(180, StepperMotor::Direction::COUNTER_CLOCKWISE);
    // sleep_ms(1000);
    // stepperMotor.rotateToAngle(270, StepperMotor::Direction::COUNTER_CLOCKWISE);
    // sleep_ms(1000);
    // stepperMotor.rotateToAngle(0, StepperMotor::Direction::CLOCKWISE);

    sleep_ms(1000);
    stepperMotor.rotateAngle(-M_PI/2);//90
    // sleep_ms(1000);
    // stepperMotor.rotateAngle(-M_PI/2);//0
    // sleep_ms(1000);
    // stepperMotor.rotateAngle(M_PI);//180
    // sleep_ms(1000);
    // stepperMotor.rotateAngle(M_PI/2);//270
    // sleep_ms(1000);
    // stepperMotor.rotateAngle(-((3 * M_PI) / (2)));//0
    // sleep_ms(1000);
    // stepperMotor.rotateAngle(((3 * M_PI) / (2)) + (2 * M_PI));//270


    // stepperMotor.rotateAngle(-M_PI/2);
    // sleep_ms(1000);
    // stepperMotor.rotateAngle(-M_PI/2);
    // sleep_ms(1000);
    // stepperMotor.rotateAngle(-M_PI/2);
    // sleep_ms(1000);
    // stepperMotor.rotateAngle((3 * M_PI) / (2));
    // sleep_ms(1000);


    // stepperMotor.rotateAngle(90, StepperMotor::Direction::COUNTER_CLOCKWISE);

    // sleep_ms(500);

    // stepperMotor.rotateAngle(45, StepperMotor::Direction::CLOCKWISE);
    
    // sleep_ms(500);

    // stepperMotor.rotateToAngle(90, StepperMotor::Direction::COUNTER_CLOCKWISE);

}
