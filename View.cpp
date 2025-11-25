#include "View.h"
#include <iostream>
#include <iomanip>

//　ラインの描画
void View::DispLine()
{
	std::cout << "---------------------------------------" << std::endl;
}

// 番号の表示
void View::DispNum(int& Num)
{
	std::cout << Num << " : ";
}

//	攻撃対象選択の促し
void View::MsgSelect()
{
	std::cout << "数字で攻撃対象を選択" << std::endl;
}

//	ステータスの表示
void View::DispState(const std::string& name, const Status& sta)
{
	std::cout << std::setw(8) << name <<
		" | HP : "  << std::setw(3) << sta.HP <<
		"/"			<< std::setw(3) << sta.MAXHP <<
		" | ATK : " << std::setw(3) << sta.ATK <<
		std::endl;
}

//	攻撃の表示
void View::DispAttack(const std::string& name)
{
	std::cout << name << "の攻撃" << std::endl;
}

//	被ダメージの表示
void View::DispReceveDamage(const std::string& name, const int& value)
{
	std::cout << name << "に" << value << "のダメージ" << std::endl;
}

//	死亡ログの表示
void View::DispDeadLog(const std::string& name)
{
	std::cout << name << "は倒れた" << std::endl;
}

//	勝利
void View::DispWin()
{
	std::cout << "勝利" << std::endl;
}

//	敗北
void View::DispLose()
{
	std::cout << "敗北"<< std::endl;
}
