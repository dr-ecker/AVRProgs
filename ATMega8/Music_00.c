//LED Cube Code
//
//Port Setup:
//Port D: PCCC_CCCC
//Port B: CCXX_XXPP
//C, column; P, Plane; X, not connected 
#include <avr/io.h>          // this contains all the IO port definitions
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





void WaitT0 (int);

int main()
{


 TCCR0 = 0x04;

 TCCR1A = 0x00; //No bits relevant here
 TCCR1B = 0x09; //Reset on CTC match, prescaler = 1 (I think)
 // TCCR1B = 0x06; //Reset on CTC match, Prescaler=8
 // OCR1A = N_C0; //Start at C0
 //OCR1AL = 0xF0;
 OCR1A=N_B0;
 TIMSK=0x10; //Allow CTCA events
  
DDRD  = 0xFF;  // PD0..PD7 as output
PORTD = 0x00;  // all PORTD output pins Off


sei();

while(1)
{
  WaitT0(10);
  OCR1A=N_C0;
  WaitT0(10);
  OCR1A=N_D0;
  WaitT0(10);
  OCR1A=N_E0;
  WaitT0(10);
  OCR1A=N_F0;
  WaitT0(10);
  OCR1A=N_G0;
  WaitT0(10);
  OCR1A=N_A0;
  WaitT0(10);
  OCR1A=N_B0;
  WaitT0(10);
  OCR1A=N_C1;
  WaitT0(10);
  OCR1A=N_D1;
  WaitT0(10);
  OCR1A=N_E1;
  WaitT0(10);
  OCR1A=N_F1;
  WaitT0(10);
  OCR1A=N_G1;
  WaitT0(10);
  OCR1A=N_A1;
  WaitT0(10);
  OCR1A=N_B1;
  WaitT0(10);

}

return 0;
}



ISR(TIMER1_COMPA_vect)
{
    PORTD ^=0x01; //Toggle PortD
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
