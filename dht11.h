#ifndef __DHT11_H
#define __DHT11_H

#define DHT11_pin P16

void DHT11_init();
unsigned char get_byte();
unsigned char get_data();
#endif