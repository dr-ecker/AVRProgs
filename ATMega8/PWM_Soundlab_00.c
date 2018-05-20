//Frisbot code with music
//Uses Counter0 as the metronome, Counter1 as the voice.
//Counter0 also directs time between Frisbot motor commands
#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>


char ADC_Sel=0;


int main()
{
  int SystemTime=0;

  TCCR0 = 0x02;//0x04; //Set Timer0 prescaler

  TCCR1A = 0x00; //No bits relevant here
  TCCR1B = 0x09; //Reset on CTC match, prescaler = 1 (I think)

  TIMSK=0x18; //Allow CTCA & CTCB events
  
  DDRB  = 0x03; //PB0,PB1 as output
  PORTB = 0x00; //Start as zero

  ADMUX=0x20; //Look at ADC0 port, LR shift enabled
  ADCSRA=0xE0; //Enable, free running, high prescaler.


  sei();



  TCCR1B=0x09;

  OCR1A=0x2400;
  OCR1B=0x80;
  while(1)
  {
    //SystemTime++;

    OCR1B=ADCH;


    //Idle
    //while(TCNT0);
  }
  //*/
  return;
}



ISR(TIMER1_COMPA_vect)
{
    PORTB=0x01; //PB0 ON
}

ISR(TIMER1_COMPB_vect)
{
  PORTB=0x00;   //PB0 OFF
}


ISR(ADC_vect)
{
  if(ADC_Sel)
    {
      ADC_Sel=0;
      ADMUX=0x20;
      OCR1A=ADCH*4;
    }
  else
    {
      ADC_Sel=1;
      ADMUX=0x21;
      OCR1B=ADCH;
    }

}
