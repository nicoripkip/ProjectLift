//=================================================================================================
// Name: queue.hpp
// Description:
//
// Author: Nico van Ommen
// Date: 02-11-2021
//=================================================================================================
#ifndef QUEUE
#define QUEUE

/**
 * @brief Structure voor een queue
 * 
 */
typedef struct LiftQueue
{
    int item;
    LiftQueue *next;
} LiftQueue;

#endif