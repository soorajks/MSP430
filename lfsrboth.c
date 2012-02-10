#include<msp430.h>
#include<stdint.h>
void delay(void);
main()
{
unsigned lfsr=0xace1;
unsigned bit;
P1DIR=0x41;

do
{
bit = ((lfsr>>0)^(lfsr>>2)^(lfsr>>3)^(lfsr>>5))&1;
lfsr=(lfsr>>1)|(bit<<15);
P1OUT=lfsr;
delay();
}while(lfsr!=0xace1);
}
void delay()
{
unsigned int i;
for(i=0;i<20000;i++);
}
