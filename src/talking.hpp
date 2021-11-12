//=================================================================================================
// Name: communication.hpp
// Description:
//
// Author: Nico van Ommen
// Date: 02-11-2021
//=================================================================================================
#ifndef COMMUNICATION
#define COMMUNICATION


#include <Wire.h>


/**
 * @brief Functie voor het opvragen van de slave data
 *
 * @param int (*array)[5]
 * @param int bit_rate 
 */
int request(int address, int bit_rate) 
{
    int i = 1;


    Wire.requestFrom(address, bit_rate);

    if (Wire.available()) {
        return Wire.read();
    } else {
        return 0;
    }
}


/**
 * @brief Functie voor het verzenden van data
 * 
 */
void send(int address, int bit_rate, int number)
{
    Wire.beginTransmission(address);
    Wire.write(number);
    Wire.endTransmission();

    Serial.println("Data verzonden!");
}


/**
 * @brief Functie die kijkt of de lift op de juiste verdieping is
 * 
 * @param address int 
 * @param stop_code int
 * @return bool
 */
bool check_if_arrived(int address, int destination_address, int stop_code)
{
    if (address == destination_address) {
        return true;
    }

    return false;
}


#endif 