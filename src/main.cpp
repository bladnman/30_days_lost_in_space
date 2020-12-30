
#include <Arduino.h>

#include "blink.h"

#define ONBOARDLED 13
#define LED 12

void setup() {
    pinMode(ONBOARDLED, OUTPUT);
    pinMode(LED, OUTPUT);
}
void loop() {
    blink(ONBOARDLED, 500);
    blink(LED, 500);
}
