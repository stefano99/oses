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
    sleep(1000); // Sleep for 1 second
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

// TaskB prints after TaskA even if it has higher priority because TaskA is autostarted, 
// so its timer starts before TaskB is started (while other operations are run)
// so when it's time to run TaskB concurrently to TaskA, TaskA is already running, 
// but not for enough time to preempt it.