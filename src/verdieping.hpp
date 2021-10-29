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
#include "segment.hpp"


#define LATCH_PIN 3
#define CLOCK_PIN 2
#define DATA_PIN 4


bool call = false;


/**
 * Functie voor het genereren van een slave id
 **/
int generate_slave_id(int ids[], int length)
{
    int id, i;

    for (i = 0; i < length; i++) {

    }

    id = i + 1;
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
 * Functie voor het schrijven van data van de slave naar de master
 **/
void write_data(int set[])
{
    int i;

    for (i = 0; i < (sizeof(set) / sizeof(set[0])); i++) {
        Wire.write(set[i]);
    }
}


/**
 * Functie voor het lezen van data van de master naar de slave
 **/
void read_data()
{
    while (Wire.available()) {
        char c = Wire.read();
    }
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
 * Functie voor het knipperen van het segment display 
 **/
void blinking_segment_display()
{
    int i;

    while (true) {
        if (i % 2 == 0) {
            shift_number_to_display(CLOCK_PIN, DATA_PIN, LATCH_PIN, counter[7]);
            delay(500);
            Serial.print("I = ");
            Serial.println(i);
        } else {
            shift_number_to_display(CLOCK_PIN, DATA_PIN, LATCH_PIN, B00000000);
            delay(500);
            Serial.print("I = ");
            Serial.println(i);
        }

        if (i >= 160) {
            call = false;
            break;
        }
        
        i++;
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
                call = true;
            break;
            // Instructies voor de down button
            case 7:
                ignite_button_light(led_pin, HIGH);
                call = true;
            break;
            // Error handling
            default:
    
            break;
        }
    }

    if (call == true) {
        blinking_segment_display();
    }
}


#endif 