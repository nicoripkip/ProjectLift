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