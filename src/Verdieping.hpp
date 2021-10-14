//=================================================================================================
// Name: Verdieping.hpp
// Description: 
//
// Author: Nico van Ommen
// Date: 01-10-2021
//=================================================================================================
#ifndef VERDIEPING
#define VERDIEPING


/**
 * Functie voor het genereren van een slave id
 **/
int generate_slave_id(int ids[])
{
    int id, i;

    

    return id;
}


void define_pins_for_move_buttons(int button_up, int button_down, int led_up, int led_down)
{
    pinMode(button_up, INPUT_PULLUP);
    pinMode(button_down, INPUT_PULLUP);

    pinMode(led_up, OUTPUT);
    pinMode(led_down, OUTPUT);
}


#endif 