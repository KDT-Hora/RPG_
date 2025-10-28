#include "charactor.h"
#include <iostream>


void Charactor::Set(const CharactorData& data)
{
	name = data.name;
	type = data.Type;
	status.MAXHP = data.HP;
	status.HP = data.HP;
	status.STR = data.STR;
	status.VIT = data.VIT;
}

int Charactor::GetAtk()
{
	return status.STR;
}

void Charactor::ChageHp(const int& arg)
{
	status.HP -= arg;

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
