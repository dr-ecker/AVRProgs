#include <avr/io.h>
#define F_CPU 120000
#include <util/delay.h>
int main (void)
{

// set PB.0 as output pin

DDRB  = 0x01;

// set PB.0 to output high

PORTB = 0x01;

while (1) {

PORTB ^= 0x01;

_delay_loop_2(65535);

}

}
