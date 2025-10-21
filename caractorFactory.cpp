#include "caractorFactory.h"
//#include <stdexcept>


const CharactorData CharactorFactory::data[] = {
    {0,"勇者",Player,100,20,20},
    {1,"戦士",Player,80,25,25},
    {2,"忍者",Player,50,50,10},
    {3,"スライム",Enemy,20,20,5},
    

};

const int CharactorFactory::tableSize = sizeof(data) / sizeof(data);

//  生成メソッド
PoolHandle<Charactor> CharactorFactory::Create
(const int& ID, ObjectPool<Charactor>& pool)
{
    // TODO: return ステートメントをここに挿入します
    for (int i = 0; i <= tableSize; i++) {
        if (data[i].ID == ID) {

            auto obj = pool.Acquire();
            obj->Set(data[i]);

            return obj;   

        }
    }

 //   std::runtime_error("生成失敗");

}
