#pragma once
#include <string>
#include "status.h"

struct CharactorData
{
	int ID;
	std::string name;
	CharacterType Type;
	int HP;
	int ATK;
	int DEF;
};