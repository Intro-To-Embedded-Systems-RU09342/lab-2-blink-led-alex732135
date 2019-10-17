//FR6989
#include <msp430.h>
int main(void)
{
    int x = 0;
    int y = 0;

    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO

    P1DIR |= BIT0;
    P1OUT |= BIT0;

    P9DIR |= BIT7;
    P9OUT |= BIT7;

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1)
    {
        if(x%2==0)
        P1OUT ^= BIT0;                      // Toggle LED
        if(y%3==0)
        P9OUT ^= BIT7;

        __delay_cycles(100000);
        x++;
        y++;
    }
}
