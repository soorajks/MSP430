#include<msp430.h>
void delay(void)
{
	int i;
	for(i=0;i<32000;i++);
}
main()
{
	P1DIR=0xff;
	while(1)
	{
		P1OUT=0x3f;
		delay();

		P1OUT=0x06;
		delay();

		P1OUT=0x5b;
		delay();

		P1OUT=0x4f;
		delay();

		P1OUT=0x64;
		delay();

		P1OUT=0x6d;
		delay();

		P1OUT=0x7d;
		delay();
		
		P1OUT=0x07;
		delay();

		P1OUT=0x7f;
		delay();

		P1OUT=0x6f;
		delay();
	}
}
