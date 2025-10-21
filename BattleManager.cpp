#include "BattleManager.h"

#include "caractorFactory.h"

void BattleManager::CreateEnemy()
{
	//	ID‚ğ“ü‚ê‚ÄŒÄ‚Ño‚µ
	charas.push_back(CharactorFactory::Create(1, charaPool));
}

//	
void BattleManager::Run()
{
	this->CreateEnemy();

	for (int i = 0; i < charas.size();i++) {
		charas[i]->Atk();
	}
}
