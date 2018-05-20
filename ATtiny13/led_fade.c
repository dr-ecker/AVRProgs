#include <avr/io.h>
#define F_CPU 120000
#include <util/delay.h>

int A;
int A_N;
int B;
volatile int i;

int main (void)
{

  //Initialize
  A=0;
  A_N=0;
  B=0;
  i=0;

// set PB.0 as output pin

DDRB  = 0x01;

// set PB.0 to output high

PORTB = 0x01;

// for(i=0;i<10;i=i+1)
// {
//   PORTB = 1;
//   _delay_loop_2(i*15000);
//   PORTB = 0;
//   _delay_loop_2(10000);
// }

 A=40;
while (1) {
  B=B+1;
  if(B==50)
    {
      B=0;
      A=A+1;
      if(A==50)A=2;
      A_N=50-A;
    }
  //for(i=0;i<10;i=i+1)
  //{
   PORTB = 1;
   for(i=0;i<A;i=i+1)
     {}
   //   _delay_loop_2(A);
   PORTB = 0;
   for(i=0;i<A_N;i=i+1)
     {}

   //_delay_loop_2(101-A);   
   //}
// _delay_loop_2(10);
//_delay_loop_2(65535);

}

}
