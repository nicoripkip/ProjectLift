#include <Arduino.h>
#include <Wire.h>
#include "queue.hpp"
#include "talking.hpp"


#define BAUD_RATE 115200

#define SLAVE_1 0x01
#define SLAVE_2 0x02
#define SLAVE_3 0x03
#define SLAVE_4 0x04
#define SLAVE_5 0x05


int x;
int address_array[5] = { 
    SLAVE_1, 
    SLAVE_2,
    SLAVE_3,
    SLAVE_4,
    SLAVE_5
};


/**
 * @brief 
 * 
 */
void setup()
{
    Wire.begin();
    Serial.begin(BAUD_RATE);
}


/**
 * @brief 
 * 
 */
void loop()
{
    x = request(address_array[1], 1);
    if (x > 0) {
        Serial.print("Slave: ");
        Serial.println(x);
    }

    delay(500);
}
