#include<msp430.h>
void delay(void)
{
int i;
for(i=0;i<10000;i++);
}
main()
{
int i;
P1DIR=0x0f;
while(1)
{
P1OUT = BIT0;
delay();
P1OUT=BIT1;
delay();
P1OUT=BIT2;
delay();
P1OUT=BIT3;
delay();
}
}

