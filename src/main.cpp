#include <Arduino.h>

int onboardLED = 13;
int sensorPin = A0;
int sensorValue = 0;

unsigned int batteryCapacity = 50000;
unsigned int batteryLevel = 0;

void PrintBatteryPercentage() {
    Serial.print(((double)batteryLevel / (double)batteryCapacity) * 100);
    Serial.println("%");
}
void setup() {
    Serial.begin(9600);
    pinMode(onboardLED, OUTPUT);
}
void loop() {
    sensorValue = analogRead(sensorPin);  // read the value from the sensor:
    batteryLevel += sensorValue;

    if (batteryLevel >= batteryCapacity) {
        Serial.println("FULLY CHARGED");
        batteryLevel = batteryCapacity;  // to prevent integer overflow errors
    } else {
        PrintBatteryPercentage();
    }

    delay(50);
}
