// s01e01.c
#include "tpl_os.h"
#include <stdio.h>

// Declare global counters for the tasks
int counter_a = 0;
int counter_b = 1500;

int main(void) {
    printf("--- Starting OS ---\n");
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

// Task A implementation
TASK(TaskA) {
    printf("Task A activates. Counter = %d\n", counter_a);
    counter_a += 500;
    TerminateTask();
}

// Task B implementation
TASK(TaskB) {
    printf("Task B activates. Counter = %d\n", counter_b);
    counter_b += 750;
    TerminateTask();
}

// StopTask implementation
TASK(StopTask) {
    printf("--- 6000ms elapsed. Shutting down. ---\n");
    ShutdownOS(E_OK);
    TerminateTask();
}