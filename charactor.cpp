#include "charactor.h"
#include <iostream>

void Charactor::Set(const CharactorData& data)
{
	name = data.name;
	type = data.Type;
	status.MAXHP = data.HP;
	status.HP = data.HP;
	status.ATK = data.ATK;
	status.DEF = data.DEF;
}

void Charactor::Damage(const int& argDamage)
{
	status.HP -= argDamage;

	//	死亡
	if (status.HP <= 0) {
		isLife = false;
	}

}

//	名前取得
const std::string Charactor::GetName()
{
	return name;
}

//	ステータス取得
const Status Charactor::GetStatus()
{
	return status;
}
