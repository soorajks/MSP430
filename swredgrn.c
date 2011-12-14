 #include<msp430.h>
  main()
  {
while(1)
{
P1DIR=0x41;
P1OUT=0x40;

while(P1IN>>3&1)
{
	P1OUT=0x01;
}


}
	
	
  }

