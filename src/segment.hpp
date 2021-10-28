//=================================================================================================
// Name: SegmentDisplay.hpp
// Description: 
//
// Author: Nico van Ommen
// Date: 14-10-2021
//=================================================================================================
#ifndef SEGMENT_DISPLAY
#define SEGMENT_DISPLAY


#include <Wire.h>


/**
 * Default array met alle standaard nummbers
 **/
byte counter[10] = { 
    B01110111, // Representeerd getal: 0
    B00010010, // Representeerd getal: 1
    B01011101, // Representeerd getal: 2
    B01011011, // Representeerd getal: 3
    B00111010, // Representeerd getal: 4
    B01101011, // Representeerd getal: 5
    B01101111, // Representeerd getal: 6
    B01010010, // Representeerd getal: 7
    B01111111, // Representeerd getal: 8
    B01111011  // Representeerd getal: 9
};


/**
 * Functie voor het van te voren defineren van de pinnen
 **/
void define_pins_for_display(int clock_pin, int data_pin, int latch_pin)
{
    pinMode(clock_pin, OUTPUT); 
    pinMode(data_pin, OUTPUT);
    pinMode(latch_pin, OUTPUT);
}


/**
 * Functie voor het updaten van de nummers naar het display
 **/
void shift_number_to_display(int clock_pin, int data_pin, int latch_pin, byte number)
{
    digitalWrite(latch_pin, LOW);
    shiftOut(data_pin, clock_pin, LSBFIRST, number);
    digitalWrite(latch_pin, HIGH);
}





#endif