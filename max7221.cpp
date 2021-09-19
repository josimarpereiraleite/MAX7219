/*
	@File 		nax7221.cpp
	@Author		JOSIMAR PEREIRA LEITE
	@country	Brazil
	@Date		07/06/2021
	

    Copyright (C) 2021  JOSIMAR PEREIRA LEITE

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/

#include "max7221.h"

#include <avr/io.h>

char digits[] =
{
	0x7e, // 0
	0x30, // 1
	0x6d, // 2
	0x79, // 3
	0x33, // 4
	0x5b, // 5
	0x5f, // 6
	0x70, // 7
	0x7f, // 8
	0x7b, // 9
};

char MAX7221::read()
{
	SPDR = 0xFF;
	while(!(SPSR & (1<<SPIF)));
	return(SPDR);
}

void MAX7221::write(char write_data)
{
	SPDR = write_data;
	while(!(SPSR & (1<<SPIF)));
}


void MAX7221::cmd(char cmd, char value)
{
	MAX7221_CS_LOW;
	
	write(cmd);
	write(value);
	
	MAX7221_CS_HIGH;
}

void MAX7221::display_number(char digit, int num)
{
	cmd(digit, digits[ num ]);
}

void MAX7221::init()
{
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<MAX7221_CS);
	
	MAX7221_CS_HIGH;
	
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	
	// 0x00	:	SHUTDOWN MODE
	// 0x01	:	NORMAL OPERATION
	MAX7221::cmd(MAX7221_SHUTDOWN, 0x01); 
	
	// From 0x00 to 0x0F
	MAX7221::cmd(MAX7221_INTENSITY, 0x07);
	
	// 0x01	:	DISPLAY TEST
	// 0x00	:	NORMAL OPERATION
	MAX7221::cmd(MAX7221_DISPLAYTEST, 0x01);
	
	// From 0x00 to 0x07
	MAX7221::cmd(MAX7221_SCANLIMIT, 0x07);
}
