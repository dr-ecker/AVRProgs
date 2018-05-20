#include <avr/io.h>

void Note(int, int);
void Rest(int);

int main (void)
{
  int i;
  
  int Val_A;
  int Val_B;


  DDRB  = 0x01;  //set PB.0 as output pin
  TCCR0A= 0x02;  //Set Timer mode to CTC
  TCCR0B= 0x02;  //Set Prescaler to 8
  ADMUX |=0x23;    //Set analog mux to ADC2
  ADCSRA|=0xE0;    //Activate ADC, prescaler 2

  
while (1) {
  if(i){
    ADMUX = 0x23;
    while(TCNT0!=0);
    //TCNT0=ADCH;
    i=0;
  }
  if(!i){
    ADMUX = 0x22;
    while(TCNT0!=0);
    //if(ADCH<100)TCNT0=0;
    i=1;
  }
  
  TCNT0=ADCH*3;
  //TCNT0=(Val_A+Val_B)/2;
  while(TCNT0!=0);
  PORTB^=0x01;
  //PORTB^=0x01;
}

}

