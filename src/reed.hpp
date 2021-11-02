//=================================================================================================
// Name: reed.hpp
// Description: 
//
// Author: Nico van Ommen
// Date: 29-10-2021
//=================================================================================================
#ifndef REED_SENSOR
#define REED_SENSOR




/**
 * Functie voor het defineren van de pinnen
 **/
void define_pins_for_reed(int reed_pin)
{
    pinMode(reed_pin, INPUT_PULLUP);
}


/**
 * Functie voor het uitlezen van de  sensor
 **/
int read_reed_sensor(int reed_pin)
{
    int value = digitalRead(reed_pin);

    if (value == HIGH) {
        arrived = true;
    }
}


#endif