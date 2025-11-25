#pragma once

#include <iostream>
#include <conio.h>

//	入力クラス
class InputChecker
{
public:
	//	文字を保持しておく変数
	char str;

	//	入力メソッド
	void input() {
		std::cin >> str;
		//str = _getch();
		//std::cout << str << std::endl;
	}
};