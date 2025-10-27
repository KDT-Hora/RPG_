#include "BattleManager.h"

#include "caractorFactory.h"
#include "cstdlib"
#include "ctime"

void BattleManager::CreatePlayer()
{
	//	全キャラクター生成
	for (int i = 0; i < CharactorFactory::playerTableSize; i++) 
	{
		player.push_back(CharactorFactory::PlayerCreate(i, charaPool));
	}
}

void BattleManager::CreateEnemy(int id)
{
	//	IDを入れて呼び出し
	enemy.push_back(CharactorFactory::EnemyCreate(id, charaPool));
}

//	攻撃対象選択
void BattleManager::selectTarget()
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

void BattleManager::Attack()
{
	if (actionSide == ActionSide::PLAYER) 
	{
		int damage = player[actIndex]->Atk();
		enemy[targetIndex]->ChageHp(damage);

		actIndex++;
		if (actIndex >= player.size()) {
			actIndex = 0;
			actionSide = ActionSide::ENEMY;
		}
	}
	else {
		int damage = enemy[actIndex]->Atk();
		player[targetIndex]->ChageHp(damage);

		actIndex++;
		if (actIndex >= enemy.size()) {
			actIndex = 0;
			actionSide = ActionSide::PLAYER;
		}
	}

}

//	ステータス表示
void BattleManager::dispStatus()
{
	for (int i = 0; i < player.size(); i++)
	{
		player[i]->DispStatus();
	}


	for (int i = 0; i < enemy.size(); i++)
	{
		enemy[i]->DispStatus();
	}

}

//	
void BattleManager::Run()
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




	while (!player.empty()) 
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
		for (int i = 0; i < enemy.size();)
		{
			if (enemy[i]->isLife) {
				i++;
			}
			else {
			enemy.erase(enemy.begin() + i);

			}
		}
		for (int i = 0; i < player.size();)
		{
			if (player[i]->isLife) {
				i++;
			}
			else
			{
		//	player.erase(player.begin() + i);

			}
		}

		if (enemy.size() == 0) {
			break;
		}
		

	}//	while

	std::cout << "勝利" << std::endl;

}
