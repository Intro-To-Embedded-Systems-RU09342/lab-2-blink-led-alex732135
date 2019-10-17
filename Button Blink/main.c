#include <msp430.h>
int buttonpress=1;
int y=0;
int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;                 // Stop watchdog timer

  // Configure GPIO
  P1DIR |= BIT0; //make P1.0 the output pin, automatically assigns P1.1, P1.2, etc as inputs
  P1REN |= BIT1; //internal resistor is enabled, P5.6 connects to either Vcc (3.3V) or ground
  P1OUT |= BIT1; //P1.1 is an input pin; this line defines internal resistor to connect to 3.3V
                      //the line above sets the pin as normally high (pull-up resistor)
  // Disable the GPIO power-on default high-impedance mode to activate
  // previously configured port settings
  PM5CTL0 &= ~LOCKLPM5;

  while (1)                                 // Test P1.4
  {
    if((P1IN & BIT1)!=BIT1 && buttonpress==1)
    {
      buttonpress=0;
      y++;
    }
    else if((P1IN & BIT1)==BIT1)
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

      // if P1.4 set, set P1.0                      // else reset
  }
}
