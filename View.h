#pragma once

#include "status.h"
#include <string>
#include "pool.h"
#include "charactor.h"

//	Viewクラス
class View
{
public:

	//　ラインの描画
	void DispLine();
	// 番号の表示
	void DispNum(int& Num);

	//	攻撃対象選択の促し
	void MsgSelect();

	//	ステータスの表示
	void DispState(const std::string& name, const Status& sta);
	//	攻撃の表示
	void DispAttack(const std::string& name);
	//	被ダメージの表示
	void DispReceveDamage(const std::string& name,const int& value);
	//	死亡ログの表示
	void DispDeadLog(const std::string& name);

	//	勝利
	void DispWin();
	//	敗北
	void DispLose();
};

//
// 描画するのはこのクラス
//	画面に対して何かをだすのに使用する　
//