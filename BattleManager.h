#pragma once
#include "charactor.h"

#include "pool.h"
#include "singleton.h"

#include "input.h"
#include <cctype>

enum ActionSide {
	PLAYER,
	ENEMY,
};


class BattleManager:public Singleton<BattleManager>
{
	friend class Singleton<BattleManager>;

	ActionSide actionSide = PLAYER;

	Input input;

	int actIndex = 0;
	int targetIndex = 0;

	//	プール作成
	ObjectPool<Charactor> charaPool{ 10 };

	//	キャラクター
	std::vector<PoolHandle<Charactor>> player;
	std::vector<PoolHandle<Charactor>> enemy;


	void CreatePlayer();
	void CreateEnemy(int id);

	void selectTarget();
	void Attack();

	void dispStatus();

public:
	void Run();


};