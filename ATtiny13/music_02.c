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

  Note(10,1000);
  Rest(10);
  Note(12,900);
  Rest(10);
  Note(14,800);
  Rest(10);
  Note(16,700);
  Rest(10);
  Note(18,600);
  Rest(10);
  Note(20,500);
  Rest(10);
  Note(22,400);
  Rest(10);
  Note(24,300);
  Rest(10);
  Note(26,200);
  Rest(10);
  Note(28,100);

  Rest(10);
  Note(30,1000);
  Rest(10);
  Note(31,1000);
  Rest(10);
  Note(31,1000);
  Rest(10);
  Note(29,1000);
  Rest(400);
  


}

}


void Note(int Pitch, int Duration)
{
  int i;

  OCR0A=Pitch;
  for(i=0;i<Duration;i=i+1)
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
