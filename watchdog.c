#include<msp430.h>
#define LED1 BIT0
__attribute__((interrupt(WDT_VECTOR)))
void isr()
{
P1OUT ^= LED1;
}

void watchdog_init()
{

WDTCTL = WDTPW | WDTTMSEL | WDTCNTCL;
IE1 = IE1 | WDTIE;
}
main()
{
P1DIR = LED1;

__enable_interrupt();

watchdog_init();
while(1);
}
