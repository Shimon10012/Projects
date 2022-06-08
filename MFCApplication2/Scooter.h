#pragma once
#include "Electric.h"
class Scooter :
    public Electric
{
	DECLARE_SERIAL(Scooter)

	private:
		int max_speed;
		int max_capacity ;
		int price ;
	public:
		Scooter() {};
		void Serialize(CArchive& arr);
		virtual int print(CListCtrl& vehicle_view, int nItem);
		Scooter(int fuel_amount, int care_month, int type_of_vehicle, int price, int speed, int capacity,CString name);
	
		int getprice() {
			return this->price;
		}int getspeed() {
			return this->max_speed;
		}int getcapacity() {
			return this->max_capacity;
		}
		void set_price(int price);
		void set_max_speed(int maxspeed);
		void set_max_people(int maxpeople);
		int get_max_speed() { return this->max_speed; }
		int get_max_people() { return this->max_capacity; }
};

