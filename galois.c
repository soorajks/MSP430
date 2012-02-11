#include<msp430.h>
#include<stdint.h>
void delay(void);
main()
{
unsigned lfsr=0xace1;
P1DIR=0x41;
do
{
unsigned lsb= lfsr & 1;
lfsr>>=1;
if(lsb==1)
{
lfsr ^= 0xace1;
P1OUT=lfsr;
delay();
}
}while(lfsr!=0xace1);
}
void delay()
{
int i;
for(i=0;i<20000;i++);
}
