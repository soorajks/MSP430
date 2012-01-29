#include<msp430.h>
main()
{
P1DIR=0x41;
P1OUT=0x01;
TACTL=0x220;
while(1)
{
while(!(TACTL&1));
TACTL^=1;
P1OUT^=0x41;
TACTL=0x2e0;
while(!(TACTL&1));
TACTL^=1;
P1OUT^=0x41;
TACTL=0x220;
}

}

