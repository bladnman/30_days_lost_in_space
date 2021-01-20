#include <Arduino.h>
#include <Keypad.h>

int buzzer = 8;
int errorFreq = 600;
int redPin = 9;
int greenPin = 10;
int bluePin = 11;
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
byte colPins[COLS] = {6, 7, 12, 13};

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
void RGB_color(int red_value, int green_value, int blue_value) {
    analogWrite(redPin, red_value);
    analogWrite(greenPin, green_value);
    analogWrite(bluePin, blue_value);
}
void playInput() {
    tone(buzzer, 880, 50);
    RGB_color(125, 125, 125);
    delay(50);
    noTone(buzzer);
}
void playError() {
    RGB_color(0, 255, 255);

    tone(buzzer, errorFreq, 250);
    delay(250);
    noTone(buzzer);
}
void playSuccess() {
    RGB_color(255, 0, 255);

    tone(buzzer, 400, 100);
    delay(100);
    tone(buzzer, 600, 100);
    delay(100);
    tone(buzzer, 800, 100);
    delay(100);
    tone(buzzer, 1000, 100);
    delay(250);

    tone(buzzer, 600, 100);
    delay(100);
    tone(buzzer, 800, 500);
    delay(500);
    noTone(buzzer);
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
            playError();
            return -1;
        }
        Serial.print("*");
        playInput();
    }
    Serial.println("");
    Serial.println("Device Unlocked");
    playSuccess();
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
        playInput();
    }
    Serial.println("");
    playSuccess();
}
void loop() {
    char customKey = customKeypad.getKey();

    if (customKey) {  // if a button is pressed
        if (customKey == '*') {
            int access = unlockMode();

            // NO ACCESS
            if (access < 0) {
                Serial.println("Access DENIED. Cannot change password without your old password first.");
                playError();
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
            playError();

        } else {
            Serial.println("YOU ARE IN!");
        }
    }
}
