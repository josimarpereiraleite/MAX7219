/*
	@File 		max7221.h
	@Author		JOSIMAR PEREIRA LEITE
	@country	Brazil
	@Date		07/06/2021
	

    Copyright (C) 2021  JOSIMAR PEREIRA LEITE

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/


#ifndef MAX7221_H_
#define MAX7221_H_

#define MAX7221_CS				1
#define MOSI					3
#define SCK						5

#define MAX7221_CS_HIGH			PORTB |=(1<<MAX7221_CS)
#define MAX7221_CS_LOW			PORTB &=(unsigned char)~(1<<MAX7221_CS)

#define MAX7221_DECODEMODE		0x09
#define MAX7221_INTENSITY		0x0A
#define MAX7221_SCANLIMIT		0x0B
#define MAX7221_SHUTDOWN		0x0C
#define MAX7221_DISPLAYTEST		0x0F


class  MAX7221
{
	private:
		char read();
		void write(char write_data);
	
	public:
		void init();
		void display_number(char digit, int num);
		void cmd(char address, char digit);
		void shutdown(char BOOL);	
};

#endif /* MAX7221_H_ */
