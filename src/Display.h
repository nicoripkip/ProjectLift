#ifndef SEGMENT_DISPLAY
#define SEGMENT_DISPLAY

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
 * Functie voor het updaten van de nummers naar het display
 **/
void shift_number_to_display(int clock_pin, int data_pin, int latch_pin, byte number)
{
    digitalWrite(latch_pin, LOW);
    shiftOut(data_pin, clock_pin, LSBFIRST, number);
    digitalWrite(latch_pin, HIGH);
}


#endif