#pragma once
#include "Vehicle.h"
class Electric :
    public Vehicle
{

protected:
	int battery_level;
	int battery_quantity;
public:
	virtual void tofull() ;
	virtual int print(CListCtrl& vehicle_view, int nItem) = 0;
	virtual int get_quantity() { return battery_level; }
	virtual void set_quantity(int quantity) { this->battery_level = quantity; };
	virtual int get_tank() { return battery_quantity; };
	void setbatterylevel(int batterylvl);
	int getbatterylevel();
	int getbatteryquntity() { return battery_quantity; };
	virtual int getprice() = 0;
	void set_size_of_tank(int battery_quantity);
	virtual void set_price(int price) = 0;
	virtual void set_max_speed(int maxspeed) = 0;
	virtual void set_max_people(int maxpeople) = 0;
	virtual int get_max_people() = 0;
	virtual int get_max_speed() = 0;
};

