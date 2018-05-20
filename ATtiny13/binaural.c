//binaural.c
//
//Lightweight (also, stupid) implementation of
//a binaural tone generator for ATTiny13 hardware.
//
//Throws out multiple timers in favor of a basic
//bit-bang implementation for both tones.
//
//(We can get away with this thanks to the % operator.)


#include <avr/io.h>

int main (void)
{
  volatile char i;
  volatile char j;
  volatile char LAud;
  volatile char RAud;
  volatile char PBOut;

  DDRB  = 0x03;  //set PB.0, PB.1 as output pin


  while (1) {
    LAud++;
    RAud++;
    for(i=0;i<20;i++);
    //LAud=LAud%1;
    //RAud=RAud%10;
    //PORTB^=(LAud==0)|((RAud==0)<<1);
    PORTB^=1;
  }
}
