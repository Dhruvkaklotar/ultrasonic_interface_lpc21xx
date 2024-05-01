#include<LPC21XX.H>
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;


extern void delay_Sec(unsigned int n);
extern void delay_ms(unsigned int n);
extern void delay_us(unsigned int n);
extern void uart0_tx(u8);
extern void uart0_init(u32);
extern void uart0_rx_str(char *,u8);

