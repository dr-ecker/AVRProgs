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

// set PB.0 as output pin

DDRB  = 0x07;

// set PB.0 to output high

PORTB = 0x01;

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
   PORTB = 0x01;
   for(i=0;i<A;i=i+1)
     {}


   if(PINB==0x00)Speed=50;
   if(PINB==0x02)Speed=20;

   PORTB = 0x04;
   for(i=0;i<A_N;i=i+1)
     {}


}

}
