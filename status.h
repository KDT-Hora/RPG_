#pragma once

enum CharacterType{
	Player,
	Enemy,
};

//	ステータス
struct Status
{
	int MAXHP;
	int HP;
	int ATK;
	int DEF;
};