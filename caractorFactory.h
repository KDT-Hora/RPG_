#pragma once

#include "charactorDate.h"
#include "charactor.h"
#include "pool.h"
#include <memory>

//	キャラクターのファクトリー
class CharactorFactory
{
	//	情報
	static const CharactorData data[];
	
public:

	static const int tableSize;

	//	生成処理
	//	プールからフリーのオブジェクトを中身を入れて渡す
	static PoolHandle<Charactor> Create(const int& ID, ObjectPool<Charactor>& pool);

};

