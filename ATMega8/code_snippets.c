/**
* @var PWM_value
* Array containing current PWM outport values.
**/
int PWM_value[3];
void setPWM(char pwmc, int value);
int getPWM(int c);
void PWMinit(void);


/**
* @brief This function sets a PWM duty-cycle value.
* @param pwmc - specifies PWM channel (A, B, C)
* @param value - duty-cycle value (0..255)
* @note values higher than 255 will be set to 255!
**/
void setPWM(char pwmc, int value)
{
  int pwmdc;  //pwm duty-cyle value

  if (value > 255) value = 255;
  else if (value < 0) value = 0;
  
  pwmdc = 255 - value;   

  // set PWM
  if ((pwmc)=='A') {
   OCR1A = pwmdc;
   PWM_value[0]=value;
   }   
  else if ((pwmc)=='B') {
   OCR1B = pwmdc;
   PWM_value[1]=value;
   }
  else {
   pwmc ='C';
   OCR1C = pwmdc;
   PWM_value[2]=value;
   }
}

/**
* @brief Returns duty-cylce value for a PWM port.
* @param c - specifies PWM channel
* @return duty-cycle value for PWM channel
* @retval 0..255
* @see InterpreteCommand()
**/
int getPWM(int c)
{
 return PWM_value[c];
}


/**
* @brief Configurates the onboard PWM controller.
**/
void PWMinit(void)
{
   int i;
   
   i = 0x00FF;
   //set TimerCounter   
   TCNT1 = i;
   i = 253;
   //set compare output mode and waveform gen mode 
   TCCR1A = i; 
   i = 9;
   //set ClockSource and waveform generation mode
   TCCR1B = i; 
   //set PWM outputs
   for (i=0;i<3;i++) 
    {
     PWM_value[i] = 0; 
     setPWM((i+65), 0); 
    }
   i = 0x00FF; //set all duty-cycles to 0% 
   OCR1A = i;
   OCR1B = i;
   OCR1C = i;
   // activate PWM outports OC1A, OC1B and OC1C
   TCCR1C = (128+64+32);  
}


