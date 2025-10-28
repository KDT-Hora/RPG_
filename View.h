#pragma once

#include "status.h"
#include <string>

//	Viewクラス
class View
{
public:

	//	攻撃対象選択の促し
	void MsgSelect();

	//	ステータスの表示
	void DispState(const std::string& name, const Status& sta);
	//	攻撃の表示
	void DispAttack(const std::string& name);
	//	被ダメージの表示
	void DispReceveDamage(const std::string& name,const int& value);
	//	死亡ログの表示
	void DispDeadLog(const std::string& name, const bool& isLife);

	//	勝利
	void DispLose();
	//	敗北
	void DispWin();
};

//
// 描画するのはこのクラス
//	画面に対して何かをだすのに使用する　
//