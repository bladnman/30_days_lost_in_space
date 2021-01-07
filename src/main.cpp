#include <Arduino.h>

int onboardLED = 13;
int sensorPin = A0;
int sensorValue = 0;

int minLight = 0;
int maxLight = 700;
int maxDelayMs = 1000;

void setup() {
    Serial.begin(9600);
    pinMode(onboardLED, OUTPUT);
}
void loop() {
    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);

    float lightPerc = (float)(maxLight - sensorValue) / (float)(maxLight - minLight);
    float delayFloat = maxDelayMs * lightPerc;
    int delayMs = (int)delayFloat;

    digitalWrite(onboardLED, HIGH);
    delay(delayMs);
    digitalWrite(onboardLED, LOW);
    delay(delayMs);
    Serial.println(delayMs);
}
