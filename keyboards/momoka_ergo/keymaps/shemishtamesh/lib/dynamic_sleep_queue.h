// a queue implimentation for dynamic sleep in dynamic macros
// TODO: maybe figure out a convinient way to compile with a .c file and a .h file instead of just a .h

#include "../../../config.h"
#include "stdint.h"

typedef struct DynamicSleepQueue {
    uint16_t array[DYNAMIC_SLEEP_QUEUE_SIZE];
    int front;  // should be initialized with 0
    int end;  // should be initialized with 0
} DynamicSleepQueue;

int dynamic_sleep_enqueue(DynamicSleepQueue* queue, uint16_t item);
int dynamic_sleep_dequeue(DynamicSleepQueue* queue, uint16_t* output);
void dynamic_sleep_empty(DynamicSleepQueue* queue);
void dynamic_sleep_reset(DynamicSleepQueue* queue);


int dynamic_sleep_enqueue(DynamicSleepQueue* queue, uint16_t item) {
    // inserts an item to the end of the queue, returns 0 if successful, and 1 if overflows.
    if (queue->end >= DYNAMIC_SLEEP_QUEUE_SIZE - 1)
        return 1;

    queue->array[queue->end] = item;
    queue->end = queue->end + 1;
    return 0;
}

int dynamic_sleep_dequeue(DynamicSleepQueue* queue, uint16_t* output) {
    // removes an element from the queue, returns 0 if successful, and 1 if underflows (in this case output = 0).
    if (queue->front >= queue->end) {
        *output = 0;
        return 1;
    }

    *output = queue->array[queue->front];
    queue->front = queue->front + 1;
    return 0;
}

void dynamic_sleep_empty(DynamicSleepQueue* queue) {
    // removes all elements from the queue.
    queue->front = 0;
    queue->end = 0;
}

void dynamic_sleep_reset(DynamicSleepQueue* queue) {
    // resets the queue to be used again with the same values.
    queue->front = 0;
}

