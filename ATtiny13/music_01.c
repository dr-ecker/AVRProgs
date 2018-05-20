#include <avr/io.h>


int main (void)
{
  int i;

  DDRB  = 0x01;  //set PB.0 as output pin
  TCCR0A= 0x02;  //Set Timer mode to CTC
  TCCR0B= 0x02;  //Set Prescaler to 8


while (1) {

  if(TCNT0==0)
    {
      PORTB^=0x01;  //Toggle the speaker
    }
  OCR0A=250;
  for(i=0;i<100;i=i+1)
    {
      while(TCNT0!=0);
      PORTB^=0x01;
    }
  OCR0A=200;
  for(i=0;i<100;i=i+1)
    {
      while(TCNT0!=0);
      PORTB^=0x01;
    }
  OCR0A=150;
  for(i=0;i<100;i=i+1)
    {
      while(TCNT0!=0);
      PORTB^=0x01;
    }
  OCR0A=100;
  for(i=0;i<100;i=i+1)
    {
      while(TCNT0!=0);
      PORTB^=0x01;
    }


}

}
