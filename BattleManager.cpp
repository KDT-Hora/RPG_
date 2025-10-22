#include "BattleManager.h"

#include "caractorFactory.h"

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
	this->CreateEnemy(0);


	while (!player.empty()) 
	{
		//	表示クリア
		system("cls");
	
		//	ステータス表示
		this->dispStatus();

		//	行動

		


	}//	while


}
