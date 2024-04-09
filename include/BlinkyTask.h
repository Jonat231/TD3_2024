#pragma once
#include <stdint.h>

namespace Blinky
{
    void init( uint32_t pin , uint32_t period);
    void task(); 
}// namepace blinky
