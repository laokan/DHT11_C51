#include "stc15f204ea.h"
#include "delay.h"
#include "dht11.h"

unsigned char values[5];

void DHT11_init()
{
	delay_ms(1000);
}

unsigned char get_byte()
{
	unsigned char s = 0;
	unsigned char value = 0;

	for(s = 0; s < 8; s += 1)
	{
		value <<= 1;
		while(!DHT11_pin);
		Delay30us();

		if(DHT11_pin)
		{
			value |= 1; 
		} 
		while(DHT11_pin);
	} 
	return value; 
} 
unsigned char get_data()
{
	short chk = 0;
	unsigned char s = 0;
	unsigned char check_sum = 0;

	DHT11_pin = 1;
	DHT11_pin = 0;
	delay_ms(18);
	DHT11_pin = 1;
	Delay26us();

	chk = DHT11_pin;
	if(chk)
	{
		return 1;
	}

	Delay80us();

	chk = DHT11_pin;
	if(!chk)
	{
		return 2;
	}
	Delay80us();

	for(s = 0; s <= 4; s += 1)
	{
		values[s] = get_byte();
	}

	DHT11_pin=1;

	for(s = 0; s < 4; s += 1)
	{
		check_sum += values[s];
	}

	if(check_sum != values[4])
	{
		return 3;
	}else{
		return 0;
	}
}