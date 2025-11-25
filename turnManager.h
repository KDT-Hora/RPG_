#pragma once
#include "charactor.h"
#include <vector>
#include "pool.h"

//	ƒ^[ƒ“ŠÇ—
class TurnManager
{
	int actSide = Player;
	
public:
	
	//
	void Trun(std::vector<PoolHandle<Charactor>>& players, std::vector<PoolHandle<Charactor>>& enemies);

	void PlayerTurn();
	void EnemyTurn();

};