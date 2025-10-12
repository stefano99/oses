#include <math.h>
#include <stdio.h>

#include "tpl_os.h"
int main(void) {
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}
DeclareAlarm(a500msec);
DeclareAlarm(a750msec);
TASK(TaskA) {
    static unsigned int counterA = 0;
    printf("CounterA=%u\r\n", counterA);
	counterA += 500;
    TerminateTask();
}
TASK(TaskB) {
    static unsigned int counterB = 1500;
    printf("CounterB=%u\r\n", counterB);
	counterB +=750;
    TerminateTask();
}
TASK(stop) {
    CancelAlarm(a500msec);
    CancelAlarm(a750msec);
    printf("Shutdown\r\n");
    ShutdownOS(E_OK);
    TerminateTask();
}