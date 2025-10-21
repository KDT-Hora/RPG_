#pragma once

#include <random>

class Random
{
	//	ランダム
	static std::random_device rd;

public:

	//	ランダムな値を取得
	static int GetRandom(int max)
	{
		//  ランダムの初期化
		std::mt19937 gen(rd());

		std::uniform_int_distribution<> dis(0, max);
		int value = dis(gen);
		return value;
	}
};