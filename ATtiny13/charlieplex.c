#include <avr/io.h>
#include <avr/interrupt.h>


void Note(int, int);
void Rest(int);

void CharliePlex(int);

int ChSel;
int Value_PWM;

int main (void)
{
  int i,j;

  //DDRB  = 0x08;  //set PB.3 as output pin
  DDRB = 0x07; //set PB.0-PB.2 as output
  //TCCR0A= 0x02;  //Set Timer mode to CTC
  TCCR0A= 0x00;
  TCCR0B= 0x01;  //Set Prescaler to 8
  TIMSK0= 0x06;  //Allow COMPA, OVF interrupts

  OCR0A=155;
  Value_PWM=0;
  ChSel=0;

  //  sei(); //Globally Enable Interrupts

while (1) {
  //Here we´ll select the pwm value..
  for(i=0;i<60000;i=i+1);
  CharliePlex(1);
  for(i=0;i<60000;i=i+1);
  CharliePlex(2);

  //  Value_PWM=Value_PWM+1;
  //if(Value_PWM>290)Value_PWM=0;

  //OCR0A=Value_PWM;

 }

}



ISR(TIM0_COMPA_vect)
{
  //PORTB=0x00;
  CharliePlex(1);
}

ISR(TIM0_OVF_vect)
{
  //PORTB=0x08;
  CharliePlex(2);
  //Value_PWM=Value_PWM+1;
  //if(Value_PWM>255)Value_PWM=0;
  //OCR0A=Value_PWM;
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
      PORTB^=0x08;
    }

}

void Rest(int Duration)
{
  int i;
  OCR0A=100;
  for(i=0;i<Duration;i=i+1)while(TCNT0!=0);
}


void CharliePlex(int Sel)
{
  if(Sel==0)
    {
      DDRB=0x07;
      PORTB=0x00;
    }
  if(Sel==1)
    {
      DDRB=0x03;
      PORTB=0x01;
    }
  if(Sel==2)
    {
      DDRB=0x05;
      PORTB=0x01;
    }
  if(Sel==3)
    {
      DDRB=0x03;
      PORTB=0x02;
    }
  if(Sel==4)
    {
      DDRB=0x06;
      PORTB=0x02;
    }
  if(Sel==5)
    {
      DDRB=0x06;
      PORTB=0x04;
    }
  if(Sel==6)
    {
      DDRB=0x05;
      PORTB=0x04;
    }
}
