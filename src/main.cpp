#include <Wire.h>
#include "Verdieping.hpp"
#include "Display.h"


#define LATCH_PIN 3
#define CLOCK_PIN 2
#define DATA_PIN 4
#define BAUD_RATE 115200


/**
 * Functie die alle belangrijke dingen opzet
 **/
void setup()
{
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);

    Serial.begin(BAUD_RATE);
}


/**
 * Functie die over en over loopt
 **/
void loop()
{
    
}