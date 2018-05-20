//A sequence of output functions
//really this is just a sparkly 
//light thingus.

#include <avr/io.h>
#define F_CPU 120000
#include <util/delay.h>



int main (void)
{
  int PWM_0;
  int PWM_1;
  int PWM_2;
  int PWM_3;
  int PWM_4;

  int i;
  
  //Register Init
  DDRB   = 0x1F;   //set PB.0-4 as output pins
  TCCR0B = 0x03;   //Set Prescaler to 64

  //Variable Init
  PWM_0=0;
  PWM_1=0;
  PWM_2=0;
  PWM_3=0;
  PWM_4=0;
  i=0;


while (1) {

  TCCR0B = 0x03; //prescaler = 64
for(i=0;i<10000;i=i+1){
  if(TCNT0<20)
    {
      PORTB=0x00;  //All output to 0
      PWM_0=PWM_0+1;
      PWM_1=PWM_1+2;
      PWM_2=PWM_2+3;
      PWM_3=PWM_3+4;
      PWM_4=PWM_4+5;
      
      if(PWM_0>250)PWM_0=30;
      if(PWM_1>250)PWM_1=30;
      if(PWM_2>250)PWM_2=30;
      if(PWM_3>250)PWM_3=30;
      if(PWM_4>250)PWM_4=30;

    }

  if(TCNT0>PWM_0)PORTB=PORTB|0x01; //set PB.0
  if(TCNT0>PWM_1)PORTB=PORTB|0x02; //set PB.1
  if(TCNT0>PWM_2)PORTB=PORTB|0x04; //set PB.2
  if(TCNT0>PWM_3)PORTB=PORTB|0x08; //set PB.3
  if(TCNT0>PWM_4)PORTB=PORTB|0x10; //set PB.4
 }

 PORTB=0x1F;
 TCCR0B=0x04;
 for(i=0;i<10000;i=i+1)
   {
     if(TCNT0==0)PORTB^=0x1F;
   }
 TCNT0=0;
 TCCR0B=0x05;
 while(TCNT0<0x20)PORTB=TCNT0;

}

}
