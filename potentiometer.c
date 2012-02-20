#include<msp430.h>

void adc_init()
{
        ADC10CTL0 = ADC10ON | SREF_0 | ADC10SHT_2;
        ADC10CTL1 = INCH_4 | SHS_0 | ADC10SSEL_0 | ADC10DIV_0 | CONSEQ_0;
        ADC10CTL0 |= ENC;
        ADC10AE0 = BIT4;
}

void start_conversion()
{
        ADC10CTL0 |= ADC10SC;
}

unsigned int converting()
{
        return ADC10CTL1&ADC10BUSY;
}

void delay(void)
{
        int i;
        for(i=0;i<1000;i++);
}

main()
{
        P1DIR = 0x41;
        adc_init();
        while(1)
        {
                start_conversion();
                while(converting());
                if(ADC10MEM > 0 && ADC10MEM < 240)
                        P1OUT = 0x0;
                else if(ADC10MEM > 240 && ADC10MEM < 490)
                        P1OUT = 0x01;
                else if(ADC10MEM > 490 && ADC10MEM < 750)
			P1OUT = 0x40;
		else if(ADC10MEM > 750)
			P1OUT = 0x41;
                delay();

        }
}

