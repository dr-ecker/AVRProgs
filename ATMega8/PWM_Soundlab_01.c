//Frisbot code with music
//Uses Counter0 as the metronome, Counter1 as the voice.
//Counter0 also directs time between Frisbot motor commands
#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>


//Musical Notes (periods in us)
#define N_C0 7645
#define N_CS0 7216
#define N_D0 6811
#define N_DS0 6428
#define N_E0 6068
#define N_F0 5727
#define N_FS0 5405
#define N_G0 5102
#define N_GS0 4816
#define N_A0 4545
#define N_AS0 4290
#define N_B0 4050
#define N_C1 3822
#define N_CS1 3608
#define N_D1 3405
#define N_DS1 3214
#define N_E1 3034
#define N_F1 2863
#define N_FS1 2702
#define N_G1 2551
#define N_GS1 2408
#define N_A1 2272
#define N_AS1 2145
#define N_B1 2025
#define N_C2 1911





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
