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
#include "pico/cyw43_arch.h"


void vBlinkTask(void* test) {

//    for (;;) {

//       gpio_put(PICO_DEFAULT_LED_PIN, 1);

//       vTaskDelay(250);

//       gpio_put(PICO_DEFAULT_LED_PIN, 0);

//       vTaskDelay(250);

//    }

}

void turntableMotorTest(void* param) {
    StepperMotor motor(19,18,17,16);

    int direction = 1;

    while (true) {
        motor.rotateAngle(M_PI / 2 * direction);

        if (direction == 1) {
            direction = -1;
        }
        else {
            direction = 1;
        }
    }
}

void s0MotorTest(void* param) {
    StepperMotor s0(26,22,21,20);
    
    int direction = 1;

    while (true) {
        s0.rotateAngle(M_PI * direction);

        if (direction == 1) {
            direction = -1;
        }
        else {
            direction = 1;
        }
    }
    
    
}

void s1MotorTest(void* param){
    StepperMotor s1(0,1,2,3);

    int direction = 1;

    while (true) {
        s1.rotateAngle(M_PI * direction);

        if (direction == 1) {
            direction = -1;
        }
        else {
            direction = 1;
        }
    }

}

void s2MotorTest(void* param){
    StepperMotor s2(4,5,6,7);

    int direction = 1;

    while (true) {
        s2.rotateAngle(M_PI * direction);

        if (direction == 1) {
            direction = -1;
        }
        else {
            direction = 1;
        }
    }

}   

void e0MotorTest(void* param){
    StepperMotor motor(8,11,10,9);

    int direction = 1;

    while (true) {
        motor.rotateAngle(M_PI / 2 * direction);

        if (direction == 1) {
            direction = -1;
        }
        else {
            direction = 1;
        }
    }
}



int main() {

    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
        return -1;
    }

    for (int index = 0; index < 6; index++) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN,index % 2);
        sleep_ms(1000);
        std::cout << index << std::endl;
    }

    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);


    xTaskCreate(turntableMotorTest, "turntableMotorTest", 128, NULL, 1, NULL);

    xTaskCreate(s0MotorTest, "s0",128,NULL, 2, NULL);
    xTaskCreate(s1MotorTest, "s1",128,NULL, 2, NULL);
    xTaskCreate(s2MotorTest, "s2",128,NULL, 2, NULL);

    xTaskCreate(e0MotorTest,"e0", 128, NULL, 3, NULL);




    vTaskStartScheduler();




}

