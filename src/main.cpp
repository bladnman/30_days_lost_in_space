
#include <Arduino.h>

#include "blink.h"
#define onboard 13

void setup() {
    pinMode(onboard, OUTPUT);
    Serial.begin(9600);
}
void loop() {
    blink(onboard, 100);
    blink(onboard, 100);
    blink(onboard, 50);
    blink(onboard, 50);
    blink(onboard, 50);
    blink(onboard, 50);
    blink(onboard, 50);
    blink(onboard, 50);
    blink(onboard, 100);
    blink(onboard, 500);
    Serial.println("Loop complete");
}
