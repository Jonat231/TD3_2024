#include "BlinkyClass.h"
#include <Arduino.h>

void Blinky:: init (uint8_t _pin , uint32_t period)
{
    pinMode( pin , OUTPUT);
        _st = toggle;
        _pin = pin;
        _period = period;
}
void Blinky :: task ()
{
     if ( _st == shutdown )
        return;
        // con estas instrucciones resumo todo el codigo de if
        if ( _st == toggle )
        {
            digitalWrite(_pin , !digitalRead(_pin))
            _tim.reset();
            _st = wait;
            return;
        }
        if( _st == wait )
        {
            if( _tim.elapsed() < _period )
                return;
            _st = toggle ;
            return;
        }

}