#include <avr/io.h>          // this contains all the IO port definitions
#include <compat/ina90.h>    // among other things, contains _NOP()

void wait_some_time()
{
// Use this to store the counter at SRAM. This will be slower.
//volatile unsigned short int t = 0;

// Use this to store the counter inside registers.
register unsigned short int t = 0;

while(++t) _NOP();
}

int main()
{
  //  int i;

DDRC  = 0x07;  // PC0..PC2 as output, PC3 as input (I hope)
PORTC = 0x00;  // all PORTC output pins Off

while(1)
{
  //  i=ADC3;
PORTC = 0x01;
wait_some_time();
PORTC = 0x02;
wait_some_time();
PORTC = 0x03;
wait_some_time();
PORTC = 0x04;
wait_some_time();
PORTC = 0x05;
wait_some_time();
PORTC = 0x06;
wait_some_time();
//PORTC = i;
wait_some_time();
}
return 0;
}
