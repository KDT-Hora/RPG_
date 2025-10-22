#include "charactor.h"
#include <iostream>


void Charactor::Set(CharactorData data)
{
	name = data.name;
	type = data.Type;
	status.MAXHP = data.HP;
	status.HP = data.HP;
	status.STR = data.STR;
	status.VIT = data.VIT;
}

int Charactor::Atk()
{
	std::cout << name << "の攻撃" << std::endl;

	return status.STR;
}

void Charactor::ChageHp(const int& arg)
{
	status.HP -= arg;
	std::cout << name << "に" << arg << "のダメージ" << std::endl;

	//	死亡
	if (status.HP <= 0) {
		std::cout << name << "は倒れた" << std::endl;
		isLife = false;
	}

}

//	ステータス表示
void Charactor::DispStatus()
{
	std::cout << name <<
		" | HP : " << status.HP << "/" << status.MAXHP <<
		" | STR : " << status.STR <<
		" | VIT : " << status.VIT <<
		std::endl;
}
