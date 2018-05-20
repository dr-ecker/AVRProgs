#include <avr/io.h>

void Note(int, int);
void Rest(int);

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

  Note(10,400);
  Rest(10);
  Note(15,400);
  Rest(10);
  Note(20,400);
  Rest(10);
  Note(25,400);
  Rest(10);
  Note(30,400);
  Rest(10);
  Note(35,400);
  Rest(10);
  Note(40,400);
  Rest(10);
  Note(45,400);
  Rest(10);
  Note(50,400);
  Rest(400);

  
}

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
      PORTB^=0x01;
    }

}

void Rest(int Duration)
{
  int i;
  OCR0A=100;
  for(i=0;i<Duration;i=i+1)while(TCNT0!=0);
}
