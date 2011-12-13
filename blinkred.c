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
	P1OUT=1;
	P1DIR=1;
	while(1)
	{
		delay();
		P1OUT^=1;
	}
 }
