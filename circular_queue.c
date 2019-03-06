/*
 * queue.c
 * This file creates a circular queue buffer that automatically
 * add to and reads from a queue for datatype data_t
 *
 * for validation, see end of file and
 *  ~/repos/embedded_C/test $ gcc -o test_queue test_queue.c && ./test_queue
 *
 *  Created on: Mar 6, 2019
 *      Author: gunnar pope
 *
 */
#include <stdint.h>
#define QUEUE_LEN 5

typedef struct{
    uint8_t value;
    uint8_t isvalid;
}data_t;

typedef struct{
    data_t  buffer[QUEUE_LEN];
    uint8_t current;
    uint8_t samples;
    uint8_t overflow;
}queue_t;

static queue_t queue;

void queue_init(){
  queue.current = 0;
  queue.samples = 0;
  queue.overflow = 0;
}
data_t get_queue(){
    queue.samples--;
    return queue.buffer[ queue.current++ % QUEUE_LEN];
}

void add_queue( data_t *val){
    if(queue.samples == QUEUE_LEN)
        queue.overflow = 1;
    else
        queue.buffer[ (queue.current + queue.samples++) % QUEUE_LEN] = *val;
}

// VALIDATION
// ~/repos/embedded_C/test $ gcc -o test_queue test_queue.c && ./test_queue
// QUEUE_LEN IS:5
// Write 1, read 1
// 1
// write 2,3 -> read 2
// 2
// write 4,5,6 -> read all
// 3
// 4
// 5
// 6
// write 7,8,9,10,11,12,13-> test overflow
// QUEUE OVERFLOW!: 12
// QUEUE OVERFLOW!: 13
// Read all in buffer and test if data was overwritten
// (should be 7,8,9,10,11)
// 7
// 8
// 9
// 10
// 11
