#include <avr/io.h>

int main (void)
{
  int i;
  int PWM_0;
  int PWM_1;
  int PWM_2;
  
  //Register Init
  DDRB   = 0x07;   //set PB.0-4 as output pins
  TCCR0B = 0x03;   //Set Prescaler to 8

  //Variable Init
  PWM_0=0;
  PWM_1=0;
  PWM_2=0;

while (1) {

  if(TCNT0<20)
    {
      PORTB=0x00;  //All output to 0
      //PWM_0=PWM_0+1;
      //PWM_1=PWM_1-1;
      //PWM_2=PWM_2+2;
      i=i+1;
      if(i>30){
	i=0;
	PWM_0=PWM_0+2;
	PWM_1=PWM_1+1;
	PWM_2=PWM_2+3;
      }

      
      if(PWM_0>250)PWM_0=30;
      if(PWM_1>250)PWM_1=30;
      if(PWM_2>250)PWM_2=30;

    }

  if(TCNT0>PWM_0)PORTB=PORTB|0x01; //set PB.0
  if(TCNT0>PWM_1)PORTB=PORTB|0x02; //set PB.1
  if(TCNT0>PWM_2)PORTB=PORTB|0x04; //set PB.2



}

}
