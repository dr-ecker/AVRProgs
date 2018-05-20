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
  int i;


TCCR0 = 0x04;    //High prescaler (1028)
  
DDRD  = 0xFF;  // PD0..PD7 as output
PORTD = 0x00;  // all PORTD output pins Off

DDRB  = 0xC3;  // PB0, 1, 6, 7 as output
 PORTB = 0x00;  //All PORTB output pins off


 PORTD = 0x7F;
 PORTB = 0xC0;
 WaitT0(2);

 PORTD = 0x00;
 PORTB = 0x00;
 WaitT0(2);

 PORTD = 0x7F;
 PORTB = 0xC0;
 WaitT0(2);

 PORTD = 0x00;
 PORTB = 0x00;
 WaitT0(2);

 PORTD = 0x7F;
 PORTB = 0xC0;
 WaitT0(2);


while(1)
{
  PORTD = 0x01;
  PORTB = 0x00;
  WaitT0(1);
  PORTD = 0x02;
  PORTB = 0x00;
  WaitT0(1);
  PORTD = 0x04;
  PORTB = 0x00;
  WaitT0(1);
  PORTD = 0x08;
  PORTB = 0x00;
  WaitT0(1);
  PORTD = 0x10;
  PORTB = 0x00;
  WaitT0(1);
  PORTD = 0x20;
  PORTB = 0x00;
  WaitT0(1);
  PORTD = 0x40;
  PORTB = 0x00;
  WaitT0(1);
  PORTD = 0x00;
  PORTB = 0x40;
  WaitT0(1);
  PORTD = 0x00;
  PORTB = 0x80;
  WaitT0(1);
 


  PORTD = 0x7F;
  PORTB = 0xC3;
  WaitT0(3);
  PORTD = 0xFF;
  PORTB = 0xC2;
  WaitT0(3);
  PORTD = 0xFF;
  PORTB = 0xC1;
  WaitT0(3);
  PORTD = 0x7F;
  PORTB = 0xC3;
  WaitT0(3);
  PORTD = 0xFF;
  PORTB = 0xC2;
  WaitT0(3);
  PORTD = 0xFF;
  PORTB = 0xC1;
  WaitT0(3);
  PORTD = 0x7F;
  PORTB = 0xC3;
  WaitT0(3);
  PORTD = 0xFF;
  PORTB = 0xC2;
  WaitT0(3);
  PORTD = 0xFF;
  PORTB = 0xC1;
  WaitT0(3);

  PORTD = 0x32;
  PORTB = 0x00;
  WaitT0(2);
  PORTD = 0x14;
  PORTB = 0x80;
  WaitT0(2);
  PORTD = 0x18;
  PORTB = 0x40;
  WaitT0(2);
  PORTD = 0x51;
  PORTB = 0x00;
  WaitT0(2);
  PORTD = 0x32;
  PORTB = 0x00;
  WaitT0(2);
  PORTD = 0x14;
  PORTB = 0x80;
  WaitT0(2);
  PORTD = 0x18;
  PORTB = 0x40;
  WaitT0(2);
  PORTD = 0x51;
  PORTB = 0x00;
  WaitT0(2);
  PORTD = 0x32;
  PORTB = 0x00;
  WaitT0(2);
  PORTD = 0x14;
  PORTB = 0x80;
  WaitT0(2);
  PORTD = 0x18;
  PORTB = 0x40;
  WaitT0(2);
  PORTD = 0x51;
  PORTB = 0x00;
  WaitT0(2);
  PORTD = 0x32;
  PORTB = 0x00;
  WaitT0(2);
  PORTD = 0x14;
  PORTB = 0x80;
  WaitT0(2);
  PORTD = 0x18;
  PORTB = 0x40;
  WaitT0(2);
  PORTD = 0x51;
  PORTB = 0x00;
  WaitT0(2);
  PORTD = 0x32;
  PORTB = 0x00;
  WaitT0(2);
  PORTD = 0x14;
  PORTB = 0x80;
  WaitT0(2);
  PORTD = 0x18;
  PORTB = 0x40;
  WaitT0(2);
  PORTD = 0x51;
  PORTB = 0x00;
  WaitT0(2);
  PORTD = 0x32;
  PORTB = 0x00;
  WaitT0(1);
  PORTD = 0x14;
  PORTB = 0x80;
  WaitT0(1);
  PORTD = 0x18;
  PORTB = 0x40;
  WaitT0(1);
  PORTD = 0x51;
  PORTB = 0x00;
  WaitT0(1);
  PORTD = 0x32;
  PORTB = 0x00;
  WaitT0(1);
  PORTD = 0x14;
  PORTB = 0x80;
  WaitT0(1);
  PORTD = 0x18;
  PORTB = 0x40;
  WaitT0(1);
  PORTD = 0x51;
  PORTB = 0x00;
  WaitT0(1);
  PORTD = 0x32;
  PORTB = 0x00;
  WaitT0(1);
  PORTD = 0x14;
  PORTB = 0x80;
  WaitT0(1);
  PORTD = 0x18;
  PORTB = 0x40;
  WaitT0(1);
  PORTD = 0x51;
  PORTB = 0x00;
  WaitT0(1);
  PORTD = 0x32;
  PORTB = 0x00;
  WaitT0(1);




  PORTD = 0x00;
  PORTB = 0x00;
  WaitT0(2);
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
