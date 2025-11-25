#include "BattleManager.h"

#include "caractorFactory.h"
#include "cstdlib"
#include "ctime"

BattleController::BattleController()
{
	//	プレイヤー生成
	this->CreatePlayer();
	//	敵ランダム生成
	int enemySize = CharactorFactory::enemyTableSize;
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	for (int i = 0; i < ENEMY_MAX; i++) {
		//	ランダムで攻撃対象取得
		int randID = std::rand() % enemySize;
		this->CreateEnemy(randID);
	}
}

//	プレイヤーの生成
//	すべて一気に作る形
//	プレイヤーのキャラクターの種類増やせるように、IDで指定のやつを作る形に変更しようね
void BattleController::CreatePlayer()
{
	//	全キャラクター生成
	for (int i = 0; i < CharactorFactory::playerTableSize; i++) 
	{
		players.push_back(CharactorFactory::PlayerCreate(i, charaPool));
	}
}

//	敵の生成処理
void BattleController::CreateEnemy(int id)
{
	//	IDを入れて呼び出し
	enemies.push_back(CharactorFactory::EnemyCreate(id, charaPool));
}

//	攻撃対象選択
void BattleController::SelectTarget()
{
	//	プレイヤー側行動選択
	if (actionSide==ActionSide::PLAYER)
	{
		//	攻撃対象選択
		view.MsgSelect();
		//	入力
		input.input();

		//	入力されたものを数値として保持
		if (std::isdigit(static_cast<unsigned char>(input.str)))
		{
			//	文字コードで引き算をして整数に変換
			targetIndex = input.str - '0';
			if (enemies.size()-1 < targetIndex) {
				targetIndex = enemies.size()-1;
			}
		}
		else
		{
			targetIndex = 0;
		}
		 
	}
	//	敵側行動選択
	else 
	{
		//	ランダムで攻撃対象取得
		std::srand(static_cast<unsigned int>(std::time(nullptr))); 
		// どのプレイヤーを攻撃するか決める
		int randEnemyAttack = std::rand() % players.size();

		targetIndex = randEnemyAttack;
	}

}

//	攻撃処理
int BattleController::Attack()
{
	int damage = 0;

	//	プレイヤー側行動時の動作
	if (actionSide == ActionSide::PLAYER) 
	{
		//	攻撃
		damage = players[actIndex]->GetStatus().ATK;
		view.DispAttack(players[actIndex]->GetName());
	}
	else {
		damage = enemies[actIndex]->GetStatus().ATK;
		view.DispAttack(enemies[actIndex]->GetName());
	}

	return damage;
}

//	ダメージ処理
//	DEFなどの計算は受けるときに入るものとして考える
void BattleController::ReflectDamage(int& damage)
{
	//	ダメージを与える処理
	if (actionSide == ActionSide::PLAYER)
	{
		enemies[targetIndex]->Damage(damage);
	}
	else if (actionSide == ActionSide::ENEMY)
	{
		players[targetIndex]->Damage(damage);
	}

}

//	ステータス表示
void BattleController::DispStatus()
{
	// 攻撃対象を見やすくするための変数
	int count = 0;
	view.DispLine();
	for (auto& a : players)
	{
		view.DispState( a->GetName(),a->GetStatus());
	}
	view.DispLine();
	for (auto& a : enemies)
	{
		view.DispNum(count);
		view.DispState(a->GetName(), a->GetStatus());
		count++;
	}
	view.DispLine();

}

//	死亡ログ
void BattleController::Deadlog()
{
	//	プレイヤー側
	for (auto& a : players)
	{
		if (!a->isLife) 
		{
			view.DispDeadLog(a->GetName());
		}
	}
	//	エネミー側
	for (auto& a : enemies)
	{
		if (!a->isLife)
		{
			view.DispDeadLog(a->GetName());
		}
	}
}

//	削除
void BattleController::Destroy()
{		
	//	プレイヤー削除
	std::erase_if(players, [](PoolHandle<Charactor>& ch) {
		return ch->isLife == false;
		});
	//	敵側削除
	std::erase_if(enemies, [](PoolHandle<Charactor>& ch) {
		return ch->isLife == false;
		});
}

//　ターン管理
void BattleController::Turn()
{
	//	ターンの経過処理
	actIndex++;
	//	キャラクターのコレクションサイズ以上の番号になるとき切り替え
	//	今回はプレイヤーが全員行動して敵側に切り替わる仕組みのためこれで問題なし
	//	別の仕様にするときはこの仕様だと問題あるので流用は不可
	//	自傷などで、行動側のキャラクターが減ることがあるときは変更を加える必要あり
	if (actionSide == ActionSide::PLAYER) {
		if (actIndex >= players.size()) {
			actionSide = ActionSide::ENEMY;
			actIndex = 0;
		}
	}
	else {
		if (actIndex >= enemies.size()) {
			actionSide = ActionSide::PLAYER;
			actIndex = 0;
		}
	}
}

//　ゲーム終了処理
bool BattleController::GameEnd()
{
	//	ゲーム終了条件
	if (players.size() == 0) {
		view.DispLose();
		gameLoop = false;
	}
	if (enemies.size() == 0) {
		view.DispWin();
		gameLoop = false;
	}
	return gameLoop;
}

//	全体フロー
void BattleController::Run()
{
	while (gameLoop) {
		//	ステータス表示
		this->DispStatus();
		//	行動対象決定
		this->SelectTarget();
		//	攻撃
		int damage = this->Attack();
		//	ダメージを適応
		this->ReflectDamage(damage);
		//	死亡ログ出力
		this->Deadlog();
		//	削除
		this->Destroy();
		//　ターン管理
		this->Turn();
		//　ゲーム終了処理
		this->GameEnd();
	}//	while
}