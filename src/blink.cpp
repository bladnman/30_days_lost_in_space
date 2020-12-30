#include <Arduino.h>


void blink(uint8_t pin, int ms) {
int dash = 400;
    digitalWrite(pin, HIGH);
    delay(ms);
    digitalWrite(pin, LOW);
    delay(dash);
}