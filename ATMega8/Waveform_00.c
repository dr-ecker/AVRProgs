//Basic Music System
//Uses Counter0 as the metronome, Counter1 as the voice.
#include <avr/io.h>
#include <avr/interrupt.h>



int Level,i;

int WAVE[32];

void WaitT0(int);


int main()
{
  int x;


  for(x=0;x!=16;x++)
    {
      WAVE[x]=x*10;
    }
  for(x=16;x!=32;x++)
    {
      WAVE[x]=(32-x)*10;
    }

    for(x=0;x!=16;x++)
  {
    WAVE[x]=0;
  }
  for(x=16;x!=32;x++)
  {
    WAVE[x]=160;
  }



  TCCR0 = 0x02;//0x04; //Set Timer0 prescaler

  TCCR1A = 0x00; //No bits relevant here
  TCCR1B = 0x09; //Reset on CTC match, prescaler = 1 (I think)

  TIMSK=0x18; //Allow CTCA, CTCB events
  
  DDRD  = 0xFF;  // PD0..PD7 as output
  PORTD = 0x00;  // all PORTD output pins Off
  OCR1A=180;
  OCR1B=2;
  i=1;  //Improper initialisation of i makes for FUNNY things happening...

sei();

while(1)
{
  for(x=0;x!=16;x++)
    {
      WAVE[x]=x*10;
    }
  for(x=16;x!=32;x++)
    {
      WAVE[x]=(32-x)*10;
    }

  WaitT0(1000);
  for(x=0;x!=16;x++)
    {
      WAVE[x]=0;
    }
  for(x=16;x!=32;x++)
    {
      WAVE[x]=160;
    }
  WaitT0(1000);
  WAVE[0]=80;
  WAVE[1]=100;
  WAVE[2]=115;
  WAVE[3]=120;
  WAVE[4]=140;
  WAVE[5]=150;
  WAVE[6]=155;
  WAVE[7]=160;
  WAVE[8]=155;
  WAVE[9]=150;
  WAVE[10]=140;
  WAVE[11]=120;
  WAVE[12]=115;
  WAVE[13]=100;
  WAVE[14]=80;
  for(x=15;x!=32;x++)
    {
      WAVE[x]=160-WAVE[(x-14)];
    }
  WaitT0(1000);
}

return 0;
}





ISR(TIMER1_COMPA_vect)
{
    PORTD = 0x03; //PortD On, two pins, one for pretty scope trace ;)
    if(i==30)
      {
	i=1;
      }
    else
      {
	i=i+1;
      }
    OCR1B=WAVE[i];

}

ISR(TIMER1_COMPB_vect)
{
  PORTD = 0x00;//PortD Off
}



void WaitT0(int NSec)
{
  int x;
  for(i=0;x<NSec;x=x+1)
    {
      TCNT0=1;
      while(TCNT0);
    }
  return;
}
