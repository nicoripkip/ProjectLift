//=================================================================================================
// Name: Verdieping.hpp
// Description: 
//
// Author: Nico van Ommen
// Date: 01-10-2021
//=================================================================================================
#ifndef VERDIEPING
#define VERDIEPING


#include <Wire.h>


#define UP 
#define DOWN 


/**
 * Functie voor het genereren van een slave id
 **/
int generate_slave_id(int ids[])
{
    int id, i;

    

    return id;
}


/**
 * Functie voor het genereren voor 
 **/
void define_pins_for_move_buttons(int button_up, int button_down, int led_up, int led_down)
{
    pinMode(button_up, INPUT);
    pinMode(button_down, INPUT);

    pinMode(led_up, OUTPUT);
    pinMode(led_down, OUTPUT);
}


/**
 * 
 **/
void write_data()
{

}


/**
 * 
 **/
void read_data()
{

}


/**
 * 
 **/
void ignite_button_light(int led_pin, bool action)
{
    if (action == HIGH) {
        digitalWrite(led_pin, action);
    } else {
        digitalWrite(led_pin, action);
    }
}


/**
 * Functie voor het aansturen van de button
 **/
void call_button(int button_pin, int led_pin) {
    int button = digitalRead(button_pin);

    if (button == HIGH) {
        switch (button_pin)
        {
            // Instructies voor de up button
            case 6:
                ignite_button_light(led_pin, HIGH);
            break;
            // Instructies voor de down button
            case 7:
                ignite_button_light(led_pin, HIGH);
            break;
            // Error handling
            default:

            break;
        }
    }
}


#endif 