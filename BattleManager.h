#pragma once
#include "charactor.h"

#include "pool.h"
#include "singleton.h"

#include "input.h"
#include <cctype>
#include "View.h"

enum ActionSide {
	PLAYER,
	ENEMY,
};


class BattleController:public Singleton<BattleController>
{
	friend class Singleton<BattleController>;

	ActionSide actionSide = PLAYER;

	Input input;

	//	行動キャラクターインデックス所持
	int actIndex = 0;
	//	攻撃対象インデックス所持
	int targetIndex = 0;

	//	プール作成
	ObjectPool<Charactor> charaPool{ 10 };

	//	キャラクター
	std::vector<PoolHandle<Charactor>> player;
	std::vector<PoolHandle<Charactor>> enemy;

	//	描画用処理をまとめたクラス
	View view;

	//	コンストラクタ
	BattleController();

	//	キャラクター生成メソッド
	//	生成して配列に入れるまでを行う
	void CreatePlayer();
	void CreateEnemy(int id);

	//	対象選択
	void selectTarget();
	//	攻撃
	void Attack();
	//	ステータスの表示
	void dispStatus();
	//	削除
	void Delete();

public:

	void Run();


};