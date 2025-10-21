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
	std::vector<PoolHandle<Charactor>> charas;


	
	void CreateEnemy();


public:
	void Run();


};