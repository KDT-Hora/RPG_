#pragma once

#include <iostream>
#include <conio.h>

//	入力クラス
class Input
{
public:
	//	文字を保持しておく変数
	char str;

	//	入力メソッド
	//	多分ほかにもっといい方法あるはず
	void input() {
		str = _getch();
		std::cout << str << std::endl;
	}

};