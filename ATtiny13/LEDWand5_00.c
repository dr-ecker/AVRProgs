#include <avr/io.h>



int main (void)
{
  int i,j;

  int A[30];

  //DDRB  = 0x08;  //set PB.3 as output pin
  DDRB = 0x1F; //set PB.0-PB.4 as output
  //TCCR0A= 0x02;  //Set Timer mode to CTC
  TCCR0A= 0x00;
  TCCR0B= 0x01;  //Set Prescaler to 8

  OCR0A=155;


  A[0]= 0x0E;
  A[1]= 0x11;
  A[2]= 0x11;
  A[3]= 0x11;
  A[4]= 0x0E;
  A[5]= 0x10;
  A[6]= 0x08;
  A[7]= 0x04;
  A[8]= 0x02;
  A[9]= 0x01;
  A[10]=0x02;
  A[11]=0x04;
  A[12]=0x08;
  A[13]=0x10;


while (1) {
  for(j=0;j<30;j=j+1)
    {
      for(i=0;i<100;i=i+1);
      PORTB = A[j];
    }
 }

}
