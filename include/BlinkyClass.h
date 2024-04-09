#pragma once
#include <stdint.h>
#include "TimerClass.h"
// hago una clase para demostrar que es mas dificil trabajar con 
// clases que con multitask
// pero me sirve para crear varias instancias de tareas
// es decir que puedo trabajar con 3 o 4 leds al mismo tiempor
// esto es mejor que en multitask
class Blinky
{
    public:
    void init(uint8_t pin, uint32_t period);
    void task();
    private:
    
        enum State( shutdown , toggle , wait );
        
      Status   _st = shutdown ;

     uint8_t _pin ; // arduino tiene los pines como enteros de 8 bits

     Timer   _tim;

        int32_t _period;

};