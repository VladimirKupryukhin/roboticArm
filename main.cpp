/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "include/stepper_motor.hpp"

int main() {
    StepperMotor stepperMotor(13,12,11,10);

    for (int step = 0; step < 64; step++) {
        stepperMotor.rotateOneStep(StepperMotor::CLOCKWISE);
    }

    sleep_ms(1000);

    for (int step = 0; step < 64; step++) {
        stepperMotor.rotateOneStep(StepperMotor::COUNTER_CLOCKWISE);
    }

    



// #ifndef PICO_DEFAULT_LED_PIN
// #warning blink example requires a board with a regular LED
// #else
//     const uint LED_PIN = PICO_DEFAULT_LED_PIN;
//     gpio_init(LED_PIN);
//     gpio_set_dir(LED_PIN, GPIO_OUT);
//     while (true) {
//         gpio_put(LED_PIN, 1);
//         sleep_ms(250);
//         gpio_put(LED_PIN, 0);
//         sleep_ms(250);
//     }
// #endif
}
