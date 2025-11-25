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

//	戦闘操作クラス
class BattleController:public Singleton<BattleController>
{
	friend class Singleton<BattleController>;

	ActionSide actionSide = PLAYER;

	//	入力
	//	シングルトンにしてもいいけどその必要あんま感じないよね
	InputChecker input;

	//	行動キャラクターインデックス所持
	int actIndex = 0;
	//	攻撃対象インデックス所持
	int targetIndex = 0;

	//	行動キャラの参照
	PoolHandle<Charactor>* actChar;
	//	対象キャラの参照
	PoolHandle<Charactor>* targChar;
	//
	// いんでっくすでそれぞれでするのめんどくさいよね
	// これでポインタ持ってたらポインタ軽油でアクセスすればif文で分岐しなきゃいけないの減らせるよね
	//	

	//	プール作成
	//	いったん10で作成
	ObjectPool<Charactor> charaPool{ 10 };

	//　エネミー最大数
	const int ENEMY_MAX = 6;

	//	キャラクター
	std::vector<PoolHandle<Charactor>> players;		//	味方コレクション
	std::vector<PoolHandle<Charactor>> enemies;		//	敵側コレクション

	//	描画用処理をまとめたクラス
	View view;

	//　ゲームのループ判定 true:ループ false:終了
	bool gameLoop = true;

	//	コンストラクタ
	BattleController();

	//	キャラクター生成メソッド
	//	生成して配列に入れるまでを行う
	void CreatePlayer();
	void CreateEnemy(int id);

	//	対象選択
	void SelectTarget();
	//	攻撃
	int Attack();
	//	ダメージ反映処理
	//	反射と似た名前だから変更しようねー
	void ReflectDamage(int& damage);
	//	ステータスの表示
	void DispStatus();
	//	死亡ログ
	void Deadlog();
	//	削除
	void Destroy();
	//　ターン管理
	void Turn();
	//　ゲーム終了処理
	bool GameEnd();

public:

	void Run();

};