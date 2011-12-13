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
        P1OUT=0x40;
        P1DIR=0x40;
        while(1)
        {
                delay();
               P1OUT^=0x40;
        }
}
