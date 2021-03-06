#include<msp430.h>
#define LED_ON (P1OUT = BIT0)
#define LED_OFF (P1OUT = 0)
#define MAX 1000
int on_time = 0;

void delay(int n)
{
	while(n--);
}

void one_cycle()
{
	LED_ON;
	delay(on_time);
	LED_OFF;
	delay(MAX-on_time);
}

main()
{
	int step = 20;
	int dir= +1;
	P1DIR = BIT0;
	on_time =0;
	while(1)
	{
		one_cycle();
		if(on_time == 1000)
			dir = -1;
		else if(on_time == 0)
			dir = +1;
		on_time += (dir*step);

	}
}

