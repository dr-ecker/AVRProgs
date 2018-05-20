//ADC_fade.c
//Demo of the ATTiny13 ADC in action--
//Measures pin 2´s voltage and sets an
//LED on pin 5 to a PWM signal so that
//the LED´s brightness reflects the voltage.

//Demonstrated concepts: a (very) cheap
//realtime scheduler, using this for PWM
//on multiple pins, and setup of the ADC
//in free-running mode.


#include <avr/io.h>
#define F_CPU 120000
#include <util/delay.h>



int main (void)
{
  int PWM_0;
  int PWM_1;

  
  //Register Init
  DDRB   = 0x17;   //set PB.0-4 as output pins (except 3)
  TCCR0B = 0x03;   //Set Prescaler of Counter0 to 8
  ADMUX |=0x23;    //Set analog mux to ADC3
  ADCSRA|=0xE0;    //Activate ADC, prescaler 2

  //Variable Init
  PWM_0=0;
  PWM_1=128;

  

while (1) {

  if(TCNT0<20)  //TCNT0 is the value of Counter0
    {
      PORTB=0x14;  //Set pins at the ¨start¨ point
      PWM_0=ADCH;  //ADCH is the top 8 bits of the 10-bit ADC
      if(PWM_0>250)PWM_0=250;
      if(PWM_0<30)PWM_0=30;
      if(PWM_1>250)PWM_1=250;
      
    }

  if(TCNT0>PWM_0)PORTB=PORTB|0x01; //set PB.0
  if(TCNT0>PWM_1)PORTB=PORTB|0x02; //set PB.1

}

}
