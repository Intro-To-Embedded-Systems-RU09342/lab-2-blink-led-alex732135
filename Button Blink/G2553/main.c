//G2553
#include <msp430.h>
int buttonpress=1;
int y=0;
int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;                 // Stop watchdog timer

  // Configure GPIO
  P1DIR |= BIT0; //make P1.0 the output pin
  P1REN |= BIT3; //internal resistor is enabled
  P1OUT |= BIT3; 

  while (1)                                 // Test P1.4
  {
    if((P1IN & BIT3)!=BIT3 && buttonpress==1) //if button is pressed then cycle through speeds
    {
      buttonpress=0;
      y++;
    }
    else if((P1IN & BIT3)==BIT3)
        buttonpress=1;

    if(y%4==0)
    {
        P1OUT ^= BIT0;
        _delay_cycles(25000);
    }
    if(y%4==1)
        {
            P1OUT ^= BIT0;
            _delay_cycles(50000);
        }
    if(y%4==2)
        {
            P1OUT ^= BIT0;
            _delay_cycles(75000);
        }
    if(y%4==3)
        {
            P1OUT &= ~BIT0;
        }
  }
}
