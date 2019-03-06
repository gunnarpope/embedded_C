# embedded_C
A repo of useful scripts and tricks in C

author: Gunnar Pope

## A Circular Queue for RTOS
Ever had a problem of data overflow when incoming data speeds are faster than your processing speeds in a real time operating system (RTOS)?

Here is a solution: `circular_queue.c` is a simple, efficient program to queue up incoming data structures in a circular queue register (of fixed size) that can be read from and written to at any convenient time. The queue is blocking when full.


    ~/repos/embedded_C/test $ gcc -o test_queue test_queue.c && ./test_queue
