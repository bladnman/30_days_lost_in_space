
#include <Arduino.h>
#include <Keypad.h>

#include "blink.h"

// const byte ROWS = 4;  //four rows
// const byte COLS = 3;  //three columns
// char keys[ROWS][COLS] = {
//     {'1', '2', '3'},
//     {'4', '5', '6'},
//     {'7', '8', '9'},
//     {'*', '0', '#'}};
// byte rowPins[ROWS] = {5, 4, 3, 2};  //connect to the row pinouts of the keypad
// byte colPins[COLS] = {8, 7, 6};     //connect to the column pinouts of the keypad

const byte ROWS = 4;  //four rows
const byte COLS = 1;  //three columns
char keys[ROWS][COLS] = {
    {1},
    {2},
    {3},
    {4}};
byte rowPins[ROWS] = {6, 7, 8, 9};  //connect to the row pinouts of the keypad
byte colPins[COLS] = {5};           //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
#define BUZZER_PIN 10

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
    Serial.begin(9600);
}
void loop() {
    digitalWrite(LED10, digitalRead(SWITCH1) == ON);
    digitalWrite(LED11, digitalRead(SWITCH2) == ON);
    digitalWrite(LED12, digitalRead(SWITCH3) == ON);
    char key = keypad.getKey();

    if (key) {
        Serial.println(key);
        tone(BUZZER_PIN, 100 * key, 200);
    }
}
