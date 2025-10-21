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
	std::cout << name << "‚ÌUŒ‚" << std::endl;

	return status.STR;
}

void Charactor::ChageHp(const int& arg)
{
	status.HP -= arg;
	std::cout << name << "‚É" << arg << "‚Ìƒ_ƒ[ƒW" << std::endl;

	//	Ž€–S
	if (status.HP <= 0) {
		std::cout << name << "‚Í“|‚ê‚½" << std::endl;
		isLife = false;
	}

}
