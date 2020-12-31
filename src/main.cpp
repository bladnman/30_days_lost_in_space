
#include <Arduino.h>

#include "blink.h"

#define ONBOARDLED 13
#define LED 12
#define SWITCH1 2
#define ON 1
#define OFF 0

// changes
void setup() {
    pinMode(ONBOARDLED, OUTPUT);
    pinMode(LED, OUTPUT);
    pinMode(SWITCH1, INPUT);
    // Serial.begin(9600);
}
void loop() {
    // Serial.println(digitalRead(SWITCH1));
    if (digitalRead(SWITCH1) == ON) {
        digitalWrite(LED, ON);
    } else {
        digitalWrite(LED, OFF);
    }
}
