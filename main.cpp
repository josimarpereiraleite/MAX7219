/*
	@File 		main.cpp
	@Author		JOSIMAR PEREIRA LEITE
	@country	Brazil
	@Date		07/06/2021
	

    Copyright (C) 2021  JOSIMAR PEREIRA LEITE

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "max7221.h"

int main(void)
{
	_delay_ms(50);
	
	MAX7221 max7221;
	
	max7221.init();
	
	max7221.display_number(1, 2);
	
	max7221.display_number(6, 6);
	
    while(1)
    {

    }
}
