/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "stepper_motor.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


void vBlinkTask(void* test) {

   for (;;) {

      gpio_put(PICO_DEFAULT_LED_PIN, 1);

      vTaskDelay(250);

      gpio_put(PICO_DEFAULT_LED_PIN, 0);

      vTaskDelay(250);

   }

}

void motor1(void* test) {
    StepperMotor motor(15,14,13,12);

    for (;;) {
        motor.rotateAngle(2 * M_PI);
    }
}

void motor2(void* test) {
    StepperMotor motor(16,17,18,19);

    for (;;) {
        motor.rotateAngle(2 * M_PI);
    }
}

int main() {

    stdio_init_all();

    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);

    for (int index = 0; index < 5; index++) {
        gpio_put(25,index % 2);
        sleep_ms(1000);
        std::cout << index << std::endl;
    }


    // gpio_init(PICO_DEFAULT_LED_PIN);

    // gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    // xTaskCreate(vBlinkTask, "Blink Task", 128, NULL, 1, NULL);

    xTaskCreate(motor1, "motor1",128,NULL,1,NULL);
    xTaskCreate(motor2, "motor2",128,NULL,1,NULL);

    vTaskStartScheduler();




    // StepperMotor motor(15,14,13,12);
    // motor.rotateAngle(-M_PI);


    // StepperMotor turntableMotor(15,14,13,12);
    // StepperMotor elbowMotor(16,17,18,19);
    // StepperMotor wristMotor(11,10,9,8);

    // elbowMotor.rotateAngle(M_PI/2);
    // wristMotor.rotateAngle(M_PI/2);


    // StepperMotor stepperMotor(13,12,11,10);

    // stepperMotor.rotateToAngle(M_PI/2);
    // sleep_ms(1000);
    // stepperMotor.rotateToAngle(0);
    // sleep_ms(1000);
    // stepperMotor.rotateToAngle(M_PI);
    // sleep_ms(1000);
    // stepperMotor.rotateToAngle(0);
    // sleep_ms(1000);
    // stepperMotor.rotateToAngle(((3 * M_PI) / (2)));
    // sleep_ms(1000);
    // stepperMotor.rotateToAngle(2 * M_PI);
    // sleep_ms(1000);

}

