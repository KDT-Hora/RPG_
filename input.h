#pragma once

#include <iostream>
#include <conio.h>

//	“ü—ÍƒNƒ‰ƒX
class Input
{
public:
	char str;
	void input() {
		str = _getch();
		std::cout << str << std::endl;
	}

};