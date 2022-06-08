#include "pch.h"
#include "Vehicle.h"

int Vehicle::num_of_vehicles = 0;
void Vehicle::setmonthofcare(int month)
{
	this->care_month = month;
}

void Vehicle::setisrent(int status)
{
	if (status == 0)
	{
		this->is_rent = false;
	}
	else
	{
		this->is_rent = true;
	}
}

int Vehicle::getmonthofcare()
{
	return this->care_month;
}

int Vehicle::getid()
{
	return this->id;
}

bool Vehicle::getisrent()
{
	return this->is_rent;
}

void Vehicle::set_comapny_name(CString companyname)
{
	this->company_name = companyname;
}
