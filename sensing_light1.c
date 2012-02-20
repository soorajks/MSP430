#include<msp430.h>

void adc_init()
{
        ADC10CTL0 = ADC10ON | SREF_0 | ADC10SHT_2;
        ADC10CTL1 = INCH_0 | SHS_0 | ADC10SSEL_0 | ADC10DIV_0 | CONSEQ_0;
        ADC10CTL0 |= ENC;
        ADC10AE0 = BIT0;
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
        P1DIR=0x01;
        P1OUT=0x01;
        
        while(1)
        {
		adc_init();
                start_conversion();
                while(converting());
                if(ADC10MEM > 380)
                        P1OUT=0;
                else
                {
			ADC10AE0=0;
                        P1OUT=0x01;
                }
                delay();

        }
}
