#include "View.h"
#include <iostream>
#include <iomanip>

void View::MsgSelect()
{
	std::cout << "”Žš‚ÅUŒ‚‘ÎÛ‚ð‘I‘ð" << std::endl;
}

void View::DispState(const std::string& name, const Status& sta)
{
	std::cout << std::setw(8) << name <<
		" | HP : "  << std::setw(3) << sta.HP <<
		"/"			<< std::setw(3) << sta.MAXHP <<
		" | STR : " << std::setw(3) << sta.STR <<
		//	" | VIT : " << status.VIT <<
		std::endl;

}

void View::DispAttack(const std::string& name)
{
	std::cout << name << "‚ÌUŒ‚" << std::endl;
}

void View::DispReceveDamage(const std::string& name, const int& value)
{
	std::cout << name << "‚É" << value << "‚Ìƒ_ƒ[ƒW" << std::endl;
}

void View::DispDeadLog(const std::string& name)
{
	std::cout << name << "‚Í“|‚ê‚½" << std::endl;
}

void View::DispLose()
{
	std::cout << "”s–k"<< std::endl;

}

void View::DispWin()
{
	std::cout << "Ÿ—˜" << std::endl;
}
