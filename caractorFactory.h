#pragma once

#include "charactorDate.h"
#include "charactor.h"
#include "pool.h"
#include <memory>

//	キャラクターのファクトリー
class CharactorFactory
{
	//	情報
	static const CharactorData playerData[];
	static const CharactorData enemyData[];

	
public:

	//	てーぶるサイズ
	static const int playerTableSize;
	static const int enemyTableSize;


	//	生成処理
	//	プールからフリーのオブジェクトを中身を入れて渡す
	static PoolHandle<Charactor> PlayerCreate(const int& ID, ObjectPool<Charactor>& pool);
	static PoolHandle<Charactor> EnemyCreate(const int& ID, ObjectPool<Charactor>& pool);
	

};

