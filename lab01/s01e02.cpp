#include <math.h>
#include <stdio.h>

#include "tpl_os.h"
#include "Arduino.h"

// int main(void) {
//     StartOS(OSDEFAULTAPPMODE);
//     return 0;
// }
void setup()
{
	// initialize digital pin 13 as an output.
	pinMode(13, OUTPUT);
}
DeclareAlarm(a500msec);
DeclareAlarm(a750msec);
TASK(TaskA) {
    static unsigned int counterA = 0;
    digitalWrite(13, HIGH);
	counterA += 500;
    TerminateTask();
}
TASK(TaskB) {
    static unsigned int counterB = 1500;
    digitalWrite(13, LOW);
	counterB +=750;
    TerminateTask();
}
TASK(stop) {
    CancelAlarm(a500msec);
    CancelAlarm(a750msec);
    digitalWrite(13, LOW);
    ShutdownOS(E_OK);
    TerminateTask();
}