#include <avr/io.h>
#define F_CPU 120000
#include <util/delay.h>



int main (void)
{
  DDRB  = 0x1F;  //set PB.0-4 as output pins
  TCCR0B=0x02;   //Set Prescaler to 8


while (1) {

  if(TCNT0==0)
    {
      PORTB^=0x1F;  //Toggle all outputs
    }


}

}
