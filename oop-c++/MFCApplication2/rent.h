#pragma once

#include "Bicycle.h"
#include "Scooter.h"
#include "SUV.h"
#include "Private.h"
class rent:public CObject
{
	DECLARE_SERIAL(rent)
private:
	int Km_usage;
	int Battery_Gas_Usage;
	int rentID;
	int carID;
	int is_returned;
	static int num_of_rent;
	int pricetag_vehicle;
	int typeofvehicle;
public:
	rent() {};
	int gettypeofvehicle() { return this->typeofvehicle; }
	void Serialize(CArchive& arr);
	rent(int carIDtorent, int price_tag, int type_of_vehicle);
	void setkmused(int x) {this->Km_usage=x; }
	void setbatgasused(int x) { this->Battery_Gas_Usage=x; }
	int getrentid() { return this->rentID; }
	int getpricetag() { return this->pricetag_vehicle; }
	int getcarid() { return this->carID; }
	int getkmused() { return this->Km_usage; }
	int getbatgasused() { return this->Battery_Gas_Usage; }
	int getisreturned() { return this->is_returned; }
	void setisreturned(int x) { if (x == 1) {is_returned = 1; } }

};

