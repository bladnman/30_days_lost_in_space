
#include <Arduino.h>

#include "blink.h"

#define ONBOARDLED 13
#define LED10 10
#define LED11 11
#define LED12 12
#define SWITCH1 2
#define SWITCH2 3
#define SWITCH3 4
#define ON 1
#define OFF 0
int outputs[] = {ONBOARDLED, LED10, LED11, LED12};
int inputs[] = {SWITCH1, SWITCH2, SWITCH3};
void setup() {
    for (int item : outputs) pinMode(item, OUTPUT);
    for (int item : inputs) pinMode(item, INPUT);
}
void loop() {
    digitalWrite(LED10, digitalRead(SWITCH1) == ON);
    digitalWrite(LED11, digitalRead(SWITCH2) == ON);
    digitalWrite(LED12, digitalRead(SWITCH3) == ON);
}
