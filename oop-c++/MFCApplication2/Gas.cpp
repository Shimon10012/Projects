#include "pch.h"
#include "Gas.h"

int Gas::getfuelamount()
{
	return this->Fuel_amount;
}
void Gas::setfuelamount(int fuel_amount)
{
	this->Fuel_amount = fuel_amount;
}
void Gas::set_size_of_tank(int size_of_tank)
{
	this->sizeoftank = size_of_tank;
}
void Gas::tofull()
{
	this->Fuel_amount = sizeoftank;
}