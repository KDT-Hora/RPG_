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

	CharacterType type;
	bool isLife = true;

	//	ステータスセット
	void Set(const CharactorData& data);

	//	HP変動
	void Damage(const int& argDamage);
	//	名前取得
	const std::string  GetName();
	//	ステータス取得
	const Status GetStatus();

};