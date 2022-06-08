#include "pch.h"
#include "Electric.h"

void Electric::setbatterylevel(int batterylvl)
{
	this->battery_level = batterylvl;
}
int Electric::getbatterylevel()
{
	return this->battery_level;
}
void Electric::set_size_of_tank(int battery_quantity)
{
	this->battery_quantity = battery_quantity;
}
void Electric::tofull()
{
	this->battery_level = battery_quantity;
}