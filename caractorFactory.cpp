#include "caractorFactory.h"
//#include <stdexcept>


const CharactorData CharactorFactory::playerData[] = {
    {0,"勇者",Player,100,20,20},
    {1,"戦士",Player,80,25,25},
    {2,"忍者",Player,50,50,10},
};

const CharactorData CharactorFactory::enemyData[] = {
    {0,"スライム",Enemy,20,20,5},
    {1,"ゴブリン",Enemy,40,25,10},

};



const int CharactorFactory::playerTableSize = sizeof(playerData) / sizeof(CharactorData);
const int CharactorFactory::enemyTableSize = sizeof(enemyData) / sizeof(CharactorData);

PoolHandle<Charactor> CharactorFactory::PlayerCreate(const int& ID, ObjectPool<Charactor>& pool)
{
    for (int i = 0; i <= playerTableSize; i++)
    {
        if (playerData[i].ID == ID)
        {
            auto obj = pool.Acquire();
            obj->Set(playerData[i]);

            return obj;

        }
    }
}

//  生成メソッド
PoolHandle<Charactor> CharactorFactory::EnemyCreate
(const int& ID, ObjectPool<Charactor>& pool)
{
    // TODO: return ステートメントをここに挿入します
    for (int i = 0; i <= playerTableSize; i++) 
    {
        if (enemyData[i].ID == ID) 
        {

            auto obj = pool.Acquire();
            obj->Set(enemyData[i]);

            return obj;   

        }
    }

 //   std::runtime_error("生成失敗");

}
