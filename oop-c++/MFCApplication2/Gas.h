#pragma once
#include "Vehicle.h"
class Gas :
    public Vehicle
{
protected:
	int Fuel_amount;
	int sizeoftank;
public:
	virtual int print(CListCtrl& vehicle_view, int nItem) = 0;
	virtual int get_quantity() { return Fuel_amount; }
	virtual void set_quantity(int quantity) { this->Fuel_amount = quantity; };
	virtual int get_tank() { return sizeoftank; };
	virtual void tofull() ;
	int getfuelamount();
	void setfuelamount(int fuel_amount);
	int getsizeoftank() { return sizeoftank; };
	virtual int getprice() = 0;
	void set_size_of_tank(int size_of_tank);
	virtual void set_price(int price) = 0;
	virtual void set_max_speed(int maxspeed) = 0;
	virtual void set_max_people(int maxpeople) = 0;
	virtual int get_max_people() = 0;
	virtual int get_max_speed() = 0;
};

