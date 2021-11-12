//=================================================================================================
// Name: motor.hpp
// Description:
//
// Author: Nico van Ommen
// Date: 02-11-2021
//=================================================================================================
#ifndef MOTOR
#define MOTOR


#define LEFT 1
#define RIGHT 2
#define STEPPER_STEPS 4096


bool up_flag = false;
bool down_flag = false;


/**
 * @brief Functie voor het defineren van de pinnen voor de 
 *        stepper motor
 * 
 * @param int motor_pin_1
 * @param int motor_pin_2
 * @param int motor_pin_3
 * @param int motor_pin_4
 **/
void define_pins_for_stepper_motor(int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4)
{
    pinMode(motor_pin_1, OUTPUT);
    pinMode(motor_pin_2, OUTPUT);
    pinMode(motor_pin_3, OUTPUT);
    pinMode(motor_pin_4, OUTPUT);
}


/**
 * @brief Functie voor het zetten van de up/down flag
 * 
 */
void check_up_down(int value)
{
    switch (value)
    {
        // Omhoog
        case 1:
            up_flag = true;
            down_flag = false;
        break;
        // Omlaag
        case 2:
            up_flag = false;
            down_flag = true;
        break;
    }
}


/**
 * @brief Functie voor het laten draaien van de motor
 * 
 */
void drive(int direction, int turns, int stepper_pin_1, int stepper_pin_2, int stepper_pin_3, int stepper_pin_4) 
{
    int i, steps = 0;

    switch (direction)
    {
        // Stepper motor de linkerkant op laten draaien
        case LEFT:
            for (i = 0; i < STEPPER_STEPS * turns; i++) {
                delay(5);
                
                switch (steps)
                {
                    case 0:
                        digitalWrite(stepper_pin_1, HIGH);
                        digitalWrite(stepper_pin_2, LOW);
                        digitalWrite(stepper_pin_3, LOW);
                        digitalWrite(stepper_pin_4, LOW);
                    break;
                    case 1:
                        digitalWrite(stepper_pin_1, HIGH);
                        digitalWrite(stepper_pin_2, HIGH);
                        digitalWrite(stepper_pin_3, LOW);
                        digitalWrite(stepper_pin_4, LOW);
                    break;
                    case 2:
                        digitalWrite(stepper_pin_1, LOW);
                        digitalWrite(stepper_pin_2, HIGH);
                        digitalWrite(stepper_pin_3, LOW);
                        digitalWrite(stepper_pin_4, LOW);
                    break;
                    case 3:
                        digitalWrite(stepper_pin_1, LOW);
                        digitalWrite(stepper_pin_2, HIGH);
                        digitalWrite(stepper_pin_3, HIGH);
                        digitalWrite(stepper_pin_4, LOW);
                    break;
                    case 4:
                        digitalWrite(stepper_pin_1, LOW);
                        digitalWrite(stepper_pin_2, LOW);
                        digitalWrite(stepper_pin_3, HIGH);
                        digitalWrite(stepper_pin_4, LOW);
                    break;
                    case 5:
                        digitalWrite(stepper_pin_1, LOW);
                        digitalWrite(stepper_pin_2, LOW);
                        digitalWrite(stepper_pin_3, HIGH);
                        digitalWrite(stepper_pin_4, HIGH);
                    break;
                    case 6:
                        digitalWrite(stepper_pin_1, LOW);
                        digitalWrite(stepper_pin_2, LOW);
                        digitalWrite(stepper_pin_3, LOW);
                        digitalWrite(stepper_pin_4, HIGH);
                    break;
                    case 7:
                        digitalWrite(stepper_pin_1, HIGH);
                        digitalWrite(stepper_pin_2, LOW);
                        digitalWrite(stepper_pin_3, LOW);
                        digitalWrite(stepper_pin_4, HIGH);
                    break;

                    if (steps > 7) {
                        steps = 0;
                    }
                }
            }
        break;
        // Stepper motor de rechterkant op laten draaien
        case RIGHT:
            for (i = STEPPER_STEPS; i > 0; i--) {

            }
        break;
    }
}


/**
 * @brief Functie voor het starten van de motor
 * 
 */
void start()
{

}


/**
 * @brief Functie voor het stoppen van de motor
 * 
 */
void stop()
{

}
#endif