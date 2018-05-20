#include <avr/io.h>
#include <avr/interrupt.h>


void Note(int, int);
void Rest(int);

int main (void)
{
  int i,j;

  DDRB  = 0x08;  //set PB.3 as output pin
  //TCCR0A= 0x02;  //Set Timer mode to CTC
  TCCR0A= 0x00;
  TCCR0B= 0x02;  //Set Prescaler to 8
  TIMSK0= 0x06;  //Allow COMPA, OVF interrupts

  OCR0A=155;

  sei(); //Globally Enable Interrupts

while (1) {
  //Here we´ll select the pwm value..
    for(i=0;i<250;i=i+1)
   {
    for(j=0;j<100;j=j+1);
    OCR0A=i;
  }

 }

}

ISR(TIM0_COMPA_vect)
{
  PORTB=0x00;
}

ISR(TIM0_OVF_vect)
{
  PORTB=0x08;
}


void Note(int Pitch, int Duration)
{
  int i;
  int NCycles;

  NCycles=Duration/Pitch;
  NCycles=NCycles*100;

  OCR0A=Pitch;

  for(i=0;i<NCycles;i=i+1)
    {
      while(TCNT0!=0);
      PORTB^=0x08;
    }

}

void Rest(int Duration)
{
  int i;
  OCR0A=100;
  for(i=0;i<Duration;i=i+1)while(TCNT0!=0);
}
