#include <Arduino.h>

int lightSensor = A0;

int red = 11;
int green = 10;
int blue = 9;
int minVal(int v1, int v2) {
    if (v1 > v2) return v1;
    return v2;
}
double invertedPercForInts(int value, int max, int min) {
    double perc = (double)(max - value) / (double)(max - min);
    return perc;
}
double invertedPercLight(int value) {
    return invertedPercForInts(value, 300, 0);
}
double percLight(int value) {
    double lightMax = 300;
    return (double)value / lightMax;  // 0.33
}
void RGB_color(int red_value, int green_value, int blue_value) {
    analogWrite(red, red_value);
    analogWrite(green, green_value);
    analogWrite(blue, blue_value);
}
void setup() {
    Serial.begin(9600);
    pinMode(lightSensor, INPUT);
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
}
void loop() {
    double sensorValue = analogRead(lightSensor);
    double lightPerc = percLight(sensorValue);
    double invertedPerc = invertedPercLight(sensorValue);
    int redValue = 255 - (int)(255 * invertedPerc);
    int blueValue = 255 - (int)(255 * lightPerc);
    RGB_color(redValue, 255, 255 - (int)(255 * lightPerc));

    // Serial.println("-----");
    // Serial.println(sensorValue);
    // Serial.println(lightPerc);
    // Serial.println(invertedPerc);
    // Serial.println(redValue);
    // Serial.println(blueValue);

    delay(30);
}
