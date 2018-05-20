//Frisbot Code
//
//
//Motion Notes:
//0 = Stop
//1 = 
//2 =
//4 =
//5 = Spin Right
//6 = Forward
//8 = 
//9 = Back
//A = Spin Left

#include <avr/io.h>          // this contains all the IO port definitions


void WaitT0 (int);

int main()
{
  int i;


TCCR0 = 0x05;    //High prescaler (1028)
  
DDRD  = 0x17;  // PC0,PC1,PC2,PC4 as output
PORTD = 0x00;  // all PORTC output pins Off

//The Startup Spin Returns!!
 PORTD = 0x00;
 WaitT0(6);

 PORTD = 0x05;
 WaitT0(4);
 PORTD = 0x12;
 WaitT0(4);

 PORTD = 0x00;
 WaitT0(3);

while(1)
{
PORTD = 0x11;
 WaitT0(6);
PORTD = 0x05;
 WaitT0(2);
 PORTD = 0x11;
 WaitT0(4);
 PORTD = 0x12;
 WaitT0(3);
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
