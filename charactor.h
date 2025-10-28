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
	void Set(const CharactorData& data);

	//	攻撃
	int GetAtk();
	//	HP変動
	void ChageHp(const int& arg);
	//	名前取得
	const std::string  GetName();
	//	ステータス取得
	const Status GetStatus();

};