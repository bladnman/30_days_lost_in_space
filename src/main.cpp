
#include <Arduino.h>
#include <Keypad.h>

#include "blink.h"

const byte ROWS = 4;
const byte COLS = 4;

char buttons[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

// byte rowPins[ROWS] = {9, 8, 7, 6};
// byte colPins[COLS] = {2, 3, 4, 5};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad customKeypad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

void setup() {
    Serial.begin(9600);
}
void loop() {
    char customKey = customKeypad.getKey();

    if (customKey) {  // if a button is pressed
        Serial.println(customKey);
    }
}
