#include "stc15f204ea.h"
#include "typedef.h"
#include "uart.h"
#include "delay.h"
#include "dht11.h"
#include <stdio.h>

extern unsigned char values[5];
char tmpstr[6];
void int2str(int i, int j, char *s);
void setup();

void main()
{
	unsigned char state = 0;
	setup();

	while(1){
		state = get_data();
		switch(state)
		{
			case 1:
			{
			}
			case 2:
			{
				uartSendString("No Sensor Found!\r\n");
				uartSendData(state);
				break;
			}
			case 3:
			{
				uartSendString("Checksum Error!\r\n");
				break;
			}
			default:
			{
				uartSendString("T:");
				int2str((int)values[2], (int)values[3], tmpstr);
				uartSendString(tmpstr);
				uartSendString("\r\n");
				
				uartSendString("R.H%:");
				int2str((int)values[0], (int)values[1], tmpstr);
				uartSendString(tmpstr);
				uartSendString("\r\n");
				//printf(lcd_putc, "%3u.%03u ", values[2], values[3]);
				//printf(lcd_putc, "%3u.%03u ", values[0], values[1]);
				break;
			}
		}
		delay_ms(1000);
	}
}
void setup()
{
	DHT11_init();
	uartInit();
}
void int2str(int i, int j, char *s)
{
	sprintf(s,"%3u.%03u",i,j);
}