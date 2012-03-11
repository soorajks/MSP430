 org 0xf800
 start:
 	 mov.w #0x5a80, &0x0120
 	 mov.b #1, &0x22
 	 mov.b #0, &0x21
 L1:
	 xor.b #1, &0x21
	 mov.w #0xffff, R7
 L2:
	 sub.w #1, R7
	 jnz L2
	 jmp L1
 
 org 0xfffe
 dw start
