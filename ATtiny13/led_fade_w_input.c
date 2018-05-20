#include <avr/io.h>
#define F_CPU 120000
#include <util/delay.h>

int A;
int A_N;
int B;
int Speed;
int i;

int main (void)
{

  //Initialize
  A=0;
  A_N=0;
  B=0;
  i=0;
  Speed=20;

// set PB.0-3 as output pins, PB.4 as input

DDRB  = 0x0F;


 A=40;
while (1) {
  B=B+1;
  if(B==Speed)
    {
      B=0;
      A=A+1;
      if(A==50)A=2;
      A_N=50-A;
    }
   PORTB = 0x00;
   for(i=0;i<A;i=i+1)
     {}

   if(PINB & 0x10)Speed=50;
   else Speed=20;

   //   if(PINB==0x00)Speed=50;
   //if(PINB==0x02)Speed=20;

   PORTB = 0x1F;
   for(i=0;i<A_N;i=i+1)
     {}


}

}
