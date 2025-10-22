#pragma once
#include "charactor.h"

#include "pool.h"
#include "singleton.h"

class BattleManager:public Singleton<BattleManager>
{
	friend class Singleton<BattleManager>;



	//	プール作成
	ObjectPool<Charactor> charaPool{ 10 };

	//	キャラクター
	std::vector<PoolHandle<Charactor>> player;
	std::vector<PoolHandle<Charactor>> enemy;


	void CreatePlayer();
	void CreateEnemy(int id);

	void selectTarget();

	void dispStatus();

public:
	void Run();


};