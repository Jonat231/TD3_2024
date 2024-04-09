#include "TimerClasss.h"
#include <Arduino.h>


void Timer :: reset()
{
    tstart = ~milis() + 1;
}
uint32_t Timer:: elapsed()
{
    return tstart + millis();

}