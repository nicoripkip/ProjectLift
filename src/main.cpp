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


#define LATCH_PIN 3
#define CLOCK_PIN 2
#define DATA_PIN 4

#define BUTTON_UP 6
#define BUTTON_DOWN 7
#define LED_UP 8
#define LED_DOWN 9

#define BAUD_RATE 115200


int pressed = 0;
int led_down = 0;


/**
 * Functie die alle belangrijke dingen opzet
 **/
void setup()
{
    define_pins_for_display(CLOCK_PIN, DATA_PIN, LATCH_PIN);
    define_pins_for_move_buttons(BUTTON_UP, BUTTON_DOWN, LED_UP, LED_DOWN);

    Serial.begin(BAUD_RATE);
}


/**
 * Functie die over en over loopt
 **/
void loop()
{
    shift_number_to_display(CLOCK_PIN, DATA_PIN, LATCH_PIN, counter[7]);

    int btn1 = digitalRead(BUTTON_UP);
    int btn2 = digitalRead(BUTTON_DOWN);


    if (btn1 == HIGH && btn2 == LOW) {
        pressed = 1;

        Serial.print("De knop is: ");
        Serial.println(pressed);
        Serial.println("Klikkie");
    }

    if (btn2 == HIGH && btn1 == LOW) {
        pressed = 0;

        Serial.print("De knop is: ");
        Serial.println(pressed);

        digitalWrite(LED_DOWN, HIGH);

        if (led_down == 0) {
            led_down == 1;
        } 
    }

    Serial.print("De knop is: ");
    Serial.println(pressed);

    if (led_down == 1) {
        digitalWrite(LED_DOWN, HIGH);
    } else {
        digitalWrite(LED_DOWN, LOW);
    }
}