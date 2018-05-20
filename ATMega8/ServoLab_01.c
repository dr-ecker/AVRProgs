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

  int ServoA=1;
  int ServoB=1;
  int ServoStep=0;


  TCCR0 = 0x01;//0x04; //Set Timer0 prescaler

  TCCR1A = 0x00; //No bits relevant here
  TCCR1B = 0x09; //Reset on CTC match, prescaler = 1 (I think)

  TIMSK=0x18; //Allow CTCA & CTCB events
  
  DDRB  = 0x03; //PB0,PB1 as output
  PORTB = 0x00; //Start as zero

  ADMUX=0x20; //Look at ADC0 port, LR shift enabled
  ADCSRA=0xE0; //Enable, free running, high prescaler.


  sei();



  TCCR1B=0x09;

  OCR1A=0x2E00; //Unforgivably, this 20ms value was determined
                //Empirically with a scope.
  OCR1B=0x80;
  while(1)
  {
    //SystemTime++;
    ServoStep=0;

    ServoA=ADCH/8;
    ADMUX=0x21;
    while(TCNT0);
    ServoB=ADCH/8;
    ADMUX=0x20;
    while(ServoStep<30)
      {
	while(TCNT0);
	if(ServoStep==ServoA)PORTB=PORTB+0x01;
	if(ServoStep==ServoB)PORTB=PORTB+0x02;
	ServoStep++;
      }
    //    while(TCNT0);
    PORTB=0x00;
    //OCR1B=ADCH<<6;
    //    ADMUX=0x21;
    //while(TCNT0);
    //    PORTB^=0x02;
    //OCR1A=ADCH<<6;
    //    ADMUX=0x20;
    //while(TCNT0);

	   //    PORTB^=0x02;



    //Idle
    //while(TCNT0);
  }
  //*/
  return;
}



ISR(TIMER1_COMPA_vect)
{
  //    PORTB=0x01; //PB0 ON
}

ISR(TIMER1_COMPB_vect)
{
  //PORTB=0x00;   //PB0 OFF
}

/*
ISR(ADC_vect)
{
    if(ADC_Sel)
    {
      ADC_Sel=0;
      ADMUX=0x20;
      //OCR1A=ADCH*4;
    }
  else
    {
      ADC_Sel=1;
      ADMUX=0x21;
      //OCR1B=ADCH;
    }
  
    //OCR1B=ADCH;
}

*/
