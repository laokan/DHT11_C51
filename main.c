#include "stc15f204ea.h"
#include "typedef.h"
#include "uart.h"
#include "delay.h"
#include "dht11.h"

extern unsigned char values[5];
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
				uartSendString("Tmp/ C: ");
				uartSendString("R.H/ %:");
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