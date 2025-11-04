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
//	命名ほんとにこれでいい？？？
class BattleController:public Singleton<BattleController>
{
	friend class Singleton<BattleController>;

	ActionSide actionSide = PLAYER;

	//	入力
	//	シングルトンにしてもいいけどその必要あんま感じないよね
	Input input;

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

	//	キャラクター
	std::vector<PoolHandle<Charactor>> players;		//	味方コレクション
	std::vector<PoolHandle<Charactor>> enemies;		//	敵側コレクション

	//	描画用処理をまとめたクラス
	View view;

	//	コンストラクタ
	BattleController();

	//	キャラクター生成メソッド
	//	生成して配列に入れるまでを行う
	void createPlayer();
	void createEnemy(int id);

	//	対象選択
	void selectTarget();
	//	攻撃
	int attack();
	//	ダメージ反映処理
	//	反射と似た名前だから変更しようねー
	void reflectDamage(int& damage);
	//	ステータスの表示
	void dispStatus();
	//	死亡ログ
	void deadlog();
	//	削除
	void destroy();

public:

	void Run();


};