#include <msp430.h>
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO

    P1DIR |= BIT0;
    P1OUT |= BIT0;

    while(1)
    {
        P1OUT ^= BIT0;                      // Toggle LED
        __delay_cycles(100000);
    }
}
