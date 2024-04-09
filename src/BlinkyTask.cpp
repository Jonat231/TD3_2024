#include "BlinkyTask.h"
#include <Arduino.h>
#include "TimerClass.h"
namespace Blinky
{
    int     _st = 0 ;

    uint8_t _pin ; // arduino tiene los pines como enteros de 8 bits

    Timer   _tim;

    uint32_t _period;

    void init( uint32_t pin , uint32_t period);
    {
        pinMode( pin , OUTPUT);
        _st = 1;
        _pin = pin;
        _period = period;
    }
    void task()
    {
        if ( st == 0 )
        return;
        // con estas instrucciones resumo todo el codigo de if
        if ( _st == 1 )
        {
            digitalWrite(_pin , !digitalRead(_pin))
            _tim.reset();
            _st ++;
            return;
        }
        if( _st == 2 )
        {
            if( _tim.elapsed() < _period )
                return;
            _st=1;
            return;
        }
        /*
        if( _st == 1 )
        {
            pinMode(_pin , HIGH );//enciende el led
            _tim.reset();// resetea el timer
            _st = 2;

            return;// para que no se ejecuten las demas tareas
        }
        if( _st == 2 )
        {
           if (_tim.elapsed() < 500 ) //pregunto si ya pasaron 500ms que es el valor del periodo por ej
            return;
            _st = 3;
            return;
        }
        if( st == 3 )
        {
            digitalWrite(_pin , LOW); // apago el led
            _tim.reset();
            _st = 4;
            return;
        }
           if( st == 3 )
        {
          if(_tim.elapsed() < 500 )
            return;
           
            _st = 1;
            return; 

        }*/

    }
}//namepace blinky
