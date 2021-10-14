//=================================================================================================
// Name: main.cpp
// Description: 
//
// Author: Nico van Ommen
// Date: 01-10-2021
//=================================================================================================
#include <Wire.h>
#include <Arduino.h>
#include "Verdieping.hpp"
#include "SegmentDisplay.hpp"


#define LATCH_PIN 3
#define CLOCK_PIN 2
#define DATA_PIN 4

#define BUTTON_UP 6
#define BUTTON_DOWN 7

#define BAUD_RATE 115200


/**
 * Functie die alle belangrijke dingen opzet
 **/
void setup()
{
    define_pins_for_display(CLOCK_PIN, DATA_PIN, LATCH_PIN);

    Serial.begin(BAUD_RATE);
}


/**
 * Functie die over en over loopt
 **/
void loop()
{
    // shift_number_to_display(CLOCK_PIN, DATA_PIN, LATCH_PIN, counter[4]);
}