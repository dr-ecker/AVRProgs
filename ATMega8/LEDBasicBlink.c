//LED Cube Code
//
//Port Setup:
//Port D: PCCC_CCCC
//Port B: CCXX_XXPP
//C, column; P, Plane; X, not connected 
#include <avr/io.h>          // this contains all the IO port definitions


void WaitT0 (int);

int main()
{

TCCR0 = 0x04;    //High prescaler (1028)
  
DDRD  = 0xFF;  // PD0..PD7 as output
PORTD = 0x00;  // all PORTD output pins Off

while(1)
{
  PORTD = 0x01;
  WaitT0(10);
  PORTD = 0x00;
  WaitT0(10);
}

return 0;
}



void WaitT0(int NSec)
{
  int i;
  for(i=0;i<NSec;i=i+1)
    {
      TCNT0=1;
      while(TCNT0);
    }
  return;
}
