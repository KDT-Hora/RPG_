#pragma once
#include "status.h"
#include <string>
#include "charactorDate.h"

//	キャラクター型
class Charactor
{
	std::string name;
	Status  status;

public:

	int type = 0;
	bool isLife = true;

	//	ステータスセット
	void Set(CharactorData data);

	//	攻撃
	int Atk();

	//	HP変動
	void ChageHp(const int& arg);

	void DispStatus();

};