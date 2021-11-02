//=================================================================================================
// Name: main.cpp
// Description:
//
// Author: Nico van Ommen
// Date: 01-10-2021
//=================================================================================================
#include <Wire.h>
#include <Arduino.h>
#include "verdieping.hpp"
#include "segment.hpp"
#include "reed.hpp"


#define LATCH_PIN 0x03
#define CLOCK_PIN 0x02
#define DATA_PIN 0x04

#define BUTTON_UP 0x06
#define BUTTON_DOWN 0x05
#define LED_UP 0x08
#define LED_DOWN 0x09

#define REED_PIN 0x0A

#define BAUD_RATE 115200


int pressed = 0;
int led_down = 0;


/**
 * Functie die alle belangrijke dingen opzet
 **/
void setup()
{
    define_pins_for_display(CLOCK_PIN, DATA_PIN, LATCH_PIN);
    define_pins_for_move_buttons(BUTTON_UP, BUTTON_DOWN, LED_UP, LED_DOWN, LED_ARRIVED, LED_AWAY);
    define_pins_for_reed(REED_PIN);

    Serial.begin(BAUD_RATE);
    Wire.begin(0x0002);
    Wire.onRequest(requestEvent);
}


/**
 * Functie die over en over loopt
 **/
void loop()
{
    shift_number_to_display(CLOCK_PIN, DATA_PIN, LATCH_PIN, counter[3]);

    int btn1 = digitalRead(BUTTON_UP);
    int btn2 = digitalRead(BUTTON_DOWN);

    if (btn1 == HIGH) {
        call_button(BUTTON_UP, LED_UP);
    } else if (btn2 == HIGH) {
        call_button(BUTTON_DOWN, LED_DOWN);
    } 
}


/**
 * Functie voor het zenden van de request
 **/
void requestEvent()
{
    int dataset[6] = {
        counter[0],
    };

    if (arrived == true) {
        //write_data(dataset);
    }
}