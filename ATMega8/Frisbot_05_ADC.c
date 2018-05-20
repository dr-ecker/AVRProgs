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



#define FRIS_STOP 0x00
#define FRIS_RIGHT 0x05
#define FRIS_LEFT 0x12
#define FRIS_FORWARD 0x11
#define FRIS_BACK 0x06

#define MUSIC_QUEUE_SIZE 16
#define MOVE_QUEUE_SIZE 16


//void Note(int, int);
//void Rest(int);

//void WaitT0 (int);

void doNotes(void);
void doMoves(void);

//Globals for doNotes()
int MusicPitchQueue[MUSIC_QUEUE_SIZE];
int MusicLengthQueue[MUSIC_QUEUE_SIZE];
int MusicDurationCounter=0;
int MusicQueueIndex=0;
int ScaleNumeric[28];




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

  DDRC = 0x00; //PC0 ALL INPUTS

  ADMUX=0x20; //Look at ADC0 port, LR shift enabled
  ADCSRA=0xE0; //Enable, free running, high prescaler.

  sei();


  ScaleNumeric[0]= N_C0;
  ScaleNumeric[1]= N_CS0;
  ScaleNumeric[2]= N_D0;
  ScaleNumeric[3]= N_DS0;
  ScaleNumeric[4]= N_E0;
  ScaleNumeric[5]= N_F0;
  ScaleNumeric[6]= N_FS0;
  ScaleNumeric[7]= N_G0;
  ScaleNumeric[8]= N_GS0;
  ScaleNumeric[9]= N_A0;
  ScaleNumeric[10]= N_AS0;
  ScaleNumeric[11]= N_B0;
  ScaleNumeric[12]= N_C1;
  ScaleNumeric[13]= N_CS1;
  ScaleNumeric[14]= N_D1;
  ScaleNumeric[15]= N_DS1;
  ScaleNumeric[16]= N_E1;
  ScaleNumeric[17]= N_F1;
  ScaleNumeric[18]= N_FS1;
  ScaleNumeric[19]= N_G1;
  ScaleNumeric[20]= N_GS1;
  ScaleNumeric[21]= N_A1;
  ScaleNumeric[22]= N_AS1;
  ScaleNumeric[23]= N_B1;
  ScaleNumeric[24]= N_C2;


  
  MusicPitchQueue[0]=N_D0;
  MusicLengthQueue[0]=100;
  /*  MusicPitchQueue[1]=N_DS0;
  MusicPitchQueue[2]=N_E0;
  MusicPitchQueue[3]=N_C1;
  MusicPitchQueue[4]=N_E0;
  MusicPitchQueue[5]=N_C1;
  MusicPitchQueue[6]=N_E0;
  MusicPitchQueue[7]=N_C1;
  MusicPitchQueue[8]=0;
  MusicPitchQueue[9]=N_C1;
  MusicPitchQueue[10]=0;
  MusicPitchQueue[11]=N_C1;
  MusicPitchQueue[12]=N_D1;
  MusicPitchQueue[13]=0;
  MusicPitchQueue[14]=0;
  MusicPitchQueue[15]=0;

  MusicLengthQueue[0]=500;
  MusicLengthQueue[1]=5;
  MusicLengthQueue[2]=5;
  MusicLengthQueue[3]=10;
  MusicLengthQueue[4]=5;
  MusicLengthQueue[5]=10;
  MusicLengthQueue[6]=5;
  MusicLengthQueue[7]=20;
  MusicLengthQueue[8]=50;
  MusicLengthQueue[9]=500;
  MusicLengthQueue[10]=50;
  MusicLengthQueue[11]=500;
  MusicLengthQueue[12]=500;
  MusicLengthQueue[13]=500;
  MusicLengthQueue[14]=500;
  MusicLengthQueue[15]=2000;
  */

  TCCR1B=0x09;

  while(1)
  {
    //doNotes();
    doMoves();

    if (ADCH>200){
      PORTD = FRIS_FORWARD;
    } else {
      PORTD = FRIS_BACK;
    }

    OCR1A=ScaleNumeric[(ADCH*24)/255];
    
    
    /*if(ADCH>254)
    {
      NotePitchQueue[14]=N_C0;
    }
    else
    {
      NotePitchQueue[14]=N_C1;
      }*/


    //Idle
    while(TCNT0);
  }
  //*/
  return;
}

void doNotes(void)
{
  MusicDurationCounter=MusicDurationCounter-1;
  if(MusicDurationCounter<1)
  {
    MusicQueueIndex=(MusicQueueIndex+1)%MUSIC_QUEUE_SIZE;
    if (MusicPitchQueue[MusicQueueIndex]==0)
      TCCR1B=0x00;
    else
    {
      OCR1A=MusicPitchQueue[MusicQueueIndex];
      TCCR1B=0x09;
    }
    MusicDurationCounter=MusicLengthQueue[MusicQueueIndex];
  }

}


//Do the moves
void doMoves(void)
{
}


ISR(TIMER1_COMPA_vect)
{
    PORTB ^=0x01; //Toggle PB0
}



//void Note(int NSec, int Period)/
//{
//  OCR1A=Period;
//  TCCR1B=0x09;
//  SetSecondTimer(NSec);
  //WaitT0(NSec);
  //TCCR1B=0x00;  
//}


/*void WaitT0(int NSec)
{
  int i;
  for(i=0;i<NSec;i=i+1)
    {
      TCNT0=1;
      while(TCNT0);
    }
  return;
  }*/
