	#include<LPC21XX.H>
	void delay_sec (unsigned int n)
	{
	int a[]={15,60,30,15,15},PCLK;
	PCLK = a[VPBDIV]*1000000;
	T0PC = 0;
	T0PR = PCLK-1;
	T0TC = 0;
	T0TCR=1;
	while(T0TC<n);
 	T0TCR = 0;
	}
	
void delay_ms (unsigned int n)
	{
	int a[]={15,60,30,15,15},PCLK;
	PCLK = a[VPBDIV]*1000;
	T0PC = 0;
	T0PR = PCLK-1;
	T0TC = 0;
	T0TCR=1;
	while(T0TC<n);
 	T0TCR = 0;
	}
	
	void delay_us (unsigned int n)
	{
	int a[]={15,60,30,15,15},PCLK;
	PCLK = a[VPBDIV];
	T0PC = 0;
	T0PR = PCLK-1;
	T0TC = 0;
	T0TCR=1;
	while(T0TC<n);
 	T0TCR = 0;
	}

