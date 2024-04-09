#include "td3_timer.h"
#include <arduino.h>

static uint32_t tstart; // es una variable global que solo se va a ver aca

void timerReset()
{
    tstart = (uint32_t)(~millis()) + (uint32_t)1;

}

uint32_t timerElapsed()
{

    return tstart + (uint32_t)(millis());

}