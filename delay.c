#include	"delay.h"
#include	"intrins.h"

void Delay1ms()		//@22.1184MHz
{
	unsigned char i, j;

	i = 22;
	j = 128;
	do
	{
		while (--j);
	} while (--i);
}

void delay_ms(unsigned int k)
{
	unsigned int i;
	for(i=0;i<k;i++)
	{
		Delay1ms();
	}
}

void Delay80us()		//@22.1184MHz
{
	unsigned char i, j;

	_nop_();
	_nop_();
	_nop_();
	i = 2;
	j = 180;
	do
	{
		while (--j);
	} while (--i);
}

void Delay26us()		//@22.1184MHz
{
	unsigned char i, j;

	_nop_();
	i = 1;
	j = 139;
	do
	{
		while (--j);
	} while (--i);
}

void Delay30us()		//@22.1184MHz
{
	unsigned char i, j;

	_nop_();
	_nop_();
	i = 1;
	j = 161;
	do
	{
		while (--j);
	} while (--i);
}

