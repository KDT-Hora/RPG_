#include "BattleManager.h"

#include "caractorFactory.h"
#include "cstdlib"
#include "ctime"

BattleController::BattleController()
{
	//	プレイヤー生成
	this->createPlayer();
	//	敵生成
	this->createEnemy(0);
	this->createEnemy(0);
	this->createEnemy(0);
	this->createEnemy(1);
	this->createEnemy(1);
	this->createEnemy(1);
}

//	プレイヤーの生成
//	すべて一気に作る形
void BattleController::createPlayer()
{
	//	全キャラクター生成
	for (int i = 0; i < CharactorFactory::playerTableSize; i++) 
	{
		players.push_back(CharactorFactory::PlayerCreate(i, charaPool));
	}
}

//	敵の生成処理
void BattleController::createEnemy(int id)
{
	//	IDを入れて呼び出し
	enemies.push_back(CharactorFactory::EnemyCreate(id, charaPool));
}

//	攻撃対象選択
void BattleController::selectTarget()
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
			//	２桁とかでは使えない技だから今回限定だよねー
			//	こんなん何で使うんよ
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
		int r = std::rand() % players.size();

		targetIndex = r;
	}

}

//	攻撃処理
int BattleController::attack()
{
	int damage = 0;

	//	プレイヤー側行動時の動作
	if (actionSide == ActionSide::PLAYER) 
	{
		//	攻撃
		damage = players[actIndex]->GetAtk();
		view.DispAttack(players[actIndex]->GetName());
		//	ダメージ被弾
//		enemies[targetIndex]->ChageHp(damage);
//		view.DispReceveDamage(enemies[targetIndex]->GetName(),damage);
//
//
//		//	順番
//		actIndex++;
//		if (actIndex >= players.size()) {
//			actIndex = 0;
//			actionSide = ActionSide::ENEMY;
//		}
	}
	else {
		damage = enemies[actIndex]->GetAtk();
		view.DispAttack(enemies[actIndex]->GetName());

//		players[targetIndex]->ChageHp(damage);
//		view.DispReceveDamage(players[targetIndex]->GetName(), damage);
//
//		view.DispDeadLog(players[targetIndex]->GetName(), players[targetIndex]->isLife);
//
//		actIndex++;
//		if (actIndex >= enemies.size()) {
//			actIndex = 0;
//			actionSide = ActionSide::PLAYER;
//		}
	}

	return damage;
}

//	ダメージ処理
//	VITなどの計算は受けるときに入るものとして考える
void BattleController::reflectDamage(int& damage)
{
	//	ダメージを与える処理
	if (actionSide == ActionSide::PLAYER)
	{
		enemies[targetIndex]->ChageHp(damage);
	}
	else if (actionSide == ActionSide::ENEMY)
	{
		players[targetIndex]->ChageHp(damage);
	}

}

//	ステータス表示
void BattleController::dispStatus()
{
	for (auto& a : players)
	{
		view.DispState( a->GetName(),a->GetStatus());
	}

	for (auto& a : enemies)
	{
		view.DispState(a->GetName(), a->GetStatus());
	}

}

//	死亡ログ
void BattleController::deadlog()
{
	//	プレイヤー側
	for (auto& a : players)
	{
		if (!a->isLife) 
		{
			view.DispDeadLog(a->GetName());
		}
	}
	//	プレイヤー側
	for (auto& a : enemies)
	{
		if (!a->isLife)
		{
			view.DispDeadLog(a->GetName());
		}
	}
}

//	削除
void BattleController::destroy()
{	
	//	敵側削除
	std::erase_if(enemies, [](PoolHandle<Charactor>& ch) {
		return ch->isLife == false;
		});
	//	プレイヤー削除
	std::erase_if(players, [](PoolHandle<Charactor>& ch) {
		return ch->isLife == false;
		});
}

//	全体フロー
void BattleController::Run()
{

	while (true) 
	{
		//	表示クリア
//		system("cls");
	
		//	ステータス表示
		this->dispStatus();
		//	行動対象決定
		this->selectTarget();
		//	攻撃
		int damage = this->attack();
		//	ダメージを適応
		this->reflectDamage(damage);
		//	死亡ログ出力
		this->deadlog();

		//	削除
		this->destroy();

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


		//	ゲーム終了条件
		if (enemies.size() == 0) {
			view.DispWin();
			break;
		}
		if (players.size() == 0) {
			view.DispLose();
			break;
		}
		

	}//	while


}
//
// 
//