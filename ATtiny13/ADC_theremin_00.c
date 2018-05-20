#include <avr/io.h>

void Note(int, int);
void Rest(int);

int main (void)
{
  int i;
  

  DDRB  = 0x01;  //set PB.0 as output pin
  TCCR0A= 0x02;  //Set Timer mode to CTC
  TCCR0B= 0x02;  //Set Prescaler to 8
  ADMUX |=0x23;    //Set analog mux to ADC2
  ADCSRA|=0xE0;    //Activate ADC, prescaler 2

  
while (1) {

  TCNT0=ADCH;
  while(TCNT0!=0);
  PORTB^=0x01;
  
}

}

