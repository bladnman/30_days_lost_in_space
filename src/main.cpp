#include <Arduino.h>
#include <TM1637Display.h>

/**
 *      AAA
 *    F     B
 *    F     B
 *      GGG
 *    E     C
 *    E     C
 *      DDD
 * */

// Define the connections pins:
#define CLK 6
#define DIO 5
// Create display object of type TM1637Display:
TM1637Display display = TM1637Display(CLK, DIO);
// Create array that turns all segments on:
const uint8_t data[] = {0xff, 0xff, 0xff, 0xff};
// Create array that turns all segments off:
const uint8_t blank[] = {0x00, 0x00, 0x00, 0x00};
// You can set the individual segments per digit to spell words or create other symbols:
const uint8_t done[] = {
    SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,          // d
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
    SEG_C | SEG_E | SEG_G,                          // n
    SEG_A | SEG_D | SEG_E | SEG_F | SEG_G           // E
};
const uint8_t leet[] = {
    SEG_D | SEG_E | SEG_F,                  // L
    SEG_A | SEG_D | SEG_E | SEG_F | SEG_G,  // E
    SEG_A | SEG_D | SEG_E | SEG_F | SEG_G,  // E
    // SEG_A | SEG_B | SEG_C | SEG_D | SEG_G,  // 3
    // SEG_A | SEG_B | SEG_C | SEG_D | SEG_G,  // 3
    SEG_A | SEG_B | SEG_C,  // T
};
void setup() {
    // Clear the display:
    display.clear();
    delay(1000);
}
void loop() {
    // Set the brightness:
    display.setBrightness(4);
    // All segments on:
    display.setSegments(data);
    delay(500);
    display.clear();
    delay(500);
    // Show counter:
    int i;
    for (i = 0; i <= 100; i++) {
        display.showNumberDec(i);
        delay(10);
    }
    delay(500);
    display.clear();
    delay(500);
    // display.setSegments(done);
    display.setSegments(leet);
    while (1)
        ;
}
