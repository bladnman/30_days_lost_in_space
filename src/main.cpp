#include <Arduino.h>
#include <Keypad.h>

int buzzer = 10;

const byte ROWS = 4;
const byte COLS = 4;
const byte passLength = 4;
char password[passLength] = {'1', '2', '3', '4'};
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
    Serial.println("");
    Serial.println("Options:");
    Serial.println("---------------------");
    Serial.println("- [*] to set a new password");
    Serial.println("- [#] to access the system");
    Serial.println("---------------------");
}
int unlockMode() {
    char customKey = customKeypad.getKey();
    Serial.println("Unlock Mode...");
    delay(500);
    Serial.println("Type Password to continue");

    for (int i = 0; i < passLength; i++) {
        // waiting for input
        while (!(customKey = customKeypad.getKey())) {
            // wait for input -- noop
        }
        // incorrect key
        if (password[i] != customKey) {
            Serial.println("");
            Serial.println("WRONG KEY");
            return -1;
        }
        Serial.print("*");
    }
    Serial.println("");
    Serial.println("Device Unlocked");
    return 0;
}
void changePassword() {
    char customKey = customKeypad.getKey();

    Serial.println("Welcome sir. What would you like your new password to be?");
    delay(500);

    for (int i = 0; i < passLength; i++) {
        // waiting for input
        while (!(customKey = customKeypad.getKey())) {
            // wait for input -- noop
        }
        password[i] = customKey;

        Serial.print("*");
    }
    Serial.println("");
}
void loop() {
    char customKey = customKeypad.getKey();

    if (customKey) {  // if a button is pressed
        if (customKey == '*') {
            int access = unlockMode();

            // NO ACCESS
            if (access < 0) {
                Serial.println("Access DENIED. Cannot change password without your old password first.");
            }
            // GAINED ACCESS
            else {
                changePassword();
                Serial.println("Sweet dude! You have a new password now.");
            }
        }
    }

    if (customKey == '#') {
        int access = unlockMode();
        if (access < 0) {
            Serial.println("Access denied");

        } else {
            Serial.println("YOU ARE IN!");
        }
    }
}
