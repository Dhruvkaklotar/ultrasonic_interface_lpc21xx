#include"header.h"
#define TRIG (1<<2)
#define ECHO ((IOPIN0>>3)&1)

int main()
{
	int a[]={15,60,30,15,15},echoTime,distance;
	IODIR0 |= TRIG;
	IOCLR0 = TRIG;
	uart0_init(9600);
	uart0_tx_str("data");
	while(1)
	{
		IOSET0 = TRIG;
		delay_us(10);
		IOCLR0 = TRIG;
		while(!ECHO);
		T0TCR = 0x2;
		T0PR = a[VPBDIV]-1;
		T0TCR = 0x01;
		while(ECHO);
		T0TCR = 0x00;
		echoTime = T0TC;
		
		distance= (0.0343*echoTime)/2;
		uart0_tx_int(distance);
		uart0_tx_str("\n\r");
	
	}

}
