#include<stdio.h>
#include"header.h"
#define THRE  ((U0LSR>>5)&1)
#define RDR  (U0LSR&1)
void uart0_init(u32 baud)
{
	int a[]={15,60,30,15,15},result;
	u32 pclk = a[VPBDIV]*1000000;
	result = pclk/(16*baud);
	PINSEL0 |= 0x5;
	U0LCR = 0x83;
	U0DLL = result&0xFF;
	U0DLM = (result>>8)&0xFF;
	U0LCR = 0x03;
}

void uart0_tx(u8 data)
{
	U0THR = data;
	while(THRE==0);
}

u8 uart0_rx(){
while(RDR==0);
	return U0RBR;
}

void uart0_rx_str(char *p,u8 len)
{
	int i;
for(i=0;i<len;i++)
	{
		while(RDR==0);
		p[i]=U0RBR;
		if(p[i]=='\n'||p[i]=='\r')
			break;
	}
	p[i] = '\0';


}

void uart0_tx_str(char *p)
{
	int i;
for(i=0;p[i];i++)
	{
		uart0_tx(p[i]);
	}
}

void uart0_tx_int(u32 data)
{
char a[10];
	sprintf(a,"%d",data);
uart0_tx_str(a);

}
