#include "BattleManager.h"

#include "caractorFactory.h"
#include "cstdlib"
#include "ctime"

BattleController::BattleController()
{
	//	プレイヤー生成
	this->CreatePlayer();
	//	敵生成
	this->CreateEnemy(0);
	this->CreateEnemy(0);
	this->CreateEnemy(0);
	this->CreateEnemy(1);
	this->CreateEnemy(1);
	this->CreateEnemy(1);
}

void BattleController::CreatePlayer()
{
	//	全キャラクター生成
	for (int i = 0; i < CharactorFactory::playerTableSize; i++) 
	{
		player.push_back(CharactorFactory::PlayerCreate(i, charaPool));
	}
}

void BattleController::CreateEnemy(int id)
{
	//	IDを入れて呼び出し
	enemy.push_back(CharactorFactory::EnemyCreate(id, charaPool));
}

//	攻撃対象選択
void BattleController::selectTarget()
{
	
	if (actionSide==ActionSide::PLAYER)
	{
		std::cout << "数字で攻撃対象を選択" << std::endl;
		input.input();

		if (std::isdigit(static_cast<unsigned char>(input.str)))
		{
			targetIndex = input.str - '0';
			if (enemy.size()-1 < targetIndex) {
				targetIndex = enemy.size()-1;
			}
		}
		else
		{
			targetIndex = 0;
		}
		 
	}
	else {

		std::srand(static_cast<unsigned int>(std::time(nullptr))); 
		int r = std::rand() % player.size();

		targetIndex = r;
	}

}

void BattleController::Attack()
{
	if (actionSide == ActionSide::PLAYER) 
	{
		//	攻撃
		int damage = player[actIndex]->GetAtk();
		view.DispAttack(player[actIndex]->GetName());
		//	ダメージ被弾
		enemy[targetIndex]->ChageHp(damage);
		view.DispReceveDamage(enemy[targetIndex]->GetName(),damage);

		view.DispDeadLog(enemy[targetIndex]->GetName(), enemy[targetIndex]->isLife);

		actIndex++;
		if (actIndex >= player.size()) {
			actIndex = 0;
			actionSide = ActionSide::ENEMY;
		}
	}
	else {
		int damage = enemy[actIndex]->GetAtk();
		view.DispAttack(enemy[actIndex]->GetName());

		player[targetIndex]->ChageHp(damage);
		view.DispReceveDamage(player[targetIndex]->GetName(), damage);

		view.DispDeadLog(player[targetIndex]->GetName(), player[targetIndex]->isLife);

		actIndex++;
		if (actIndex >= enemy.size()) {
			actIndex = 0;
			actionSide = ActionSide::PLAYER;
		}
	}

	


}

//	ステータス表示
void BattleController::dispStatus()
{
//	for (int i = 0; i < player.size(); i++)
//	{
//		player[i]->GetStatus();
//	}
	for (auto& a : player)
	{
		view.DispState( a->GetName(),a->GetStatus());
	}

//	for (int i = 0; i < enemy.size(); i++)
//	{
//		enemy[i]->GetStatus();
//	}
	for (auto& a : enemy)
	{
		view.DispState(a->GetName(), a->GetStatus());
	}

}

//	
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
		this->Attack();
		

		//	削除
		std::erase_if(enemy, [](PoolHandle<Charactor>& ch) {
			return ch->isLife == false;
			});
		std::erase_if(player, [](PoolHandle<Charactor>& ch) {
			return ch->isLife == false;
			});


		if (enemy.size() == 0) {
			view.DispWin();
			break;
		}
		if (player.size() == 0) {
			view.DispLose();
			break;
		}
		

	}//	while


}
