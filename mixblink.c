#include<msp430.h>
 void delay()
 {
 int i;
 for(i=0;i<32000;i++)
	{
	}
 }
 main()
 {
	P1DIR=0101;
	P1OUT=0x40;
	 while(1)
 	{
		delay();
		P1OUT^=0101;
		delay();
		P1OUT^=0101;
 	}
 }
