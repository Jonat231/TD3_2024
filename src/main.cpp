#include <Arduino.h>
#include "td3_timer.h"
#include "TimerClass.h"
#include "BlinkyClass.h"
/*
    millis();// retorna un valor entero de 32 bits. OverFlow 49,7 dias
    micros();// cuenta la cantidad de microsegundo que pasan a partie de que inicia. retorna un entero. 
                si es de 32 bits. OverFlow 1,19 hs. no puedo medir deltas de tiempo mayor a una hora
  */
  /*Ejemplo para medir tiempo, calcular cuanto tiempo partpadea un led en arduino*/
 
void toggleLed()
{
      pinMode(LED_BUILTIN,OUTPUT);
  if ( digitalWrite(LED_BUILTIN,HIGH) == HIGH )
     digitalWrite(LED_BUILTIN,LOW);

  else
     digitalWrite(LED_BUILTIN,HIGH);

}
  uint32_t tstart;
/*
void setup() 
{
  pinMode( LED_BUILTIN, OUTPUT );
 // tstart = (uint32_t)( ~millis() ) + (uint32_t)1 ; // Estoy negando y sumando uno de 32bits 
 
  
  timerReset(); // reemplaza la linea anterior

}

void loop() 
{

 // uint32_t dt = tstart + uint32_t( millis() ); 
// hasta aca el delta deberia dar cero en la primer vuelta
// por lo rapido que ejecuta las instrucciones

  if ( timerElapsed() > 250 )
  {
     // tstart = (uint32_t)( ~millis() ) + (uint32_t)1 ;// esto es equivalente a un reset
      timerReset();
      toggleLed(); 
  }
}*/
/*
Timer timer;
Timer serialTim;
void setup() 
{ 
    serial.println();
    pinMode(LED_BUILTIN, OUTPUT);
    timer.reset();
    serialTim.reset();

}

void loop() 
{

  if ( timer.elapsed() > 250 )
  {
    timer.reset();
    toggleLed();
  }
    if ( serialTim.elapsed() > 1000 )
  {
    serialTim.reset();
    serial.println("1 second tick");
  }
}
*/
#include "BllinkyTask.h"

Blinky blinky1;
Blinky blinky2;
Blinky blinky3;


void setup() 
{ 

  Serial.begin(115200);
  Serial.println("Testing serial...");
  //  blinky:: init( 2 , 250 ); // enciendo el led del puerto 2 cada 20 ms
    blinky1.init(2,1000);
    blinky2.init(5,500);
    blinky3.init(10,250);

}

void loop() 
{
 
 //   blinky:: task();
  blinky1.task();
  blinky2.task();
  blinky3.task();
}





