//Frisbot code with music
//Uses Counter0 as the metronome, Counter1 as the voice.
//Counter0 also directs time between Frisbot motor commands
#include <avr/io.h>
#include <avr/interrupt.h>


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


#define FRIS_STOP 0x00
#define FRIS_RIGHT 0x05
#define FRIS_LEFT 0x12
#define FRIS_FORWARD 0x11
#define FRIS_BACK 0x06



void Note(int, int);
//void Rest(int);

void WaitT0 (int);

int main()
{


  TCCR0 = 0x02;//0x04; //Set Timer0 prescaler

  TCCR1A = 0x00; //No bits relevant here
  TCCR1B = 0x09; //Reset on CTC match, prescaler = 1 (I think)

  TIMSK=0x10; //Allow CTCA events
  
  DDRD  = 0xFF;  // PD0..PD7 as output
  PORTD = 0x00;  // all PORTD output pins Off

  DDRB  = 0x01; //PB0 as output
  PORTB = 0x00; //Start as zero

sei();

while(1)
{

  PORTD = FRIS_FORWARD;
  Note(100,N_C0);
  Note(200,N_B1);
  WaitT0(3500);

  PORTD = FRIS_LEFT;
  Note(200,N_G0);
  Note(200,N_F0);
  WaitT0(1500);

  PORTD = FRIS_FORWARD;
  Note(100,N_C0);
  Note(200,N_B1);
  WaitT0(6000);

  PORTD = FRIS_RIGHT;
  Note(200,N_F0);
  Note(200,N_G0);
  WaitT0(1500);


  PORTD = FRIS_BACK;
  Note(100,N_A0);
  Note(100,N_B0);
  Note(100,N_A0);
  Note(100,N_B0);
  WaitT0(500);
}

return 0;
}





ISR(TIMER1_COMPA_vect)
{
    PORTB ^=0x01; //Toggle PB0
}

void Note(int NSec, int Period)
{
  OCR1A=Period;
  TCCR1B=0x09;
  WaitT0(NSec);
  TCCR1B=0x00;  
}


void WaitT0(int NSec)
{
  int i;
  for(i=0;i<NSec;i=i+1)
    {
      TCNT0=1;
      while(TCNT0);
    }
  return;
}
