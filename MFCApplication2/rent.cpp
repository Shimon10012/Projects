#include "pch.h"
#include "rent.h"
IMPLEMENT_SERIAL(rent, CObject, 1)


int rent::num_of_rent = 0;

rent::rent(int carIDtorent,int price_tag,int type_of_vehicle)
{
	num_of_rent++;
	this->rentID = num_of_rent;
	this->carID = carIDtorent;
	this->Battery_Gas_Usage = 0;
	this->Km_usage = 0;
	this->is_returned = 0;
	this->pricetag_vehicle = price_tag;
    this->typeofvehicle = type_of_vehicle;
}

void rent::Serialize(CArchive& arr)
{
    {
        CObject::Serialize(arr);
        if (arr.IsStoring())
        {
            arr << Km_usage << Battery_Gas_Usage << rentID << carID << is_returned << num_of_rent << pricetag_vehicle<<typeofvehicle;

        }
        else 
        {
            arr >> Km_usage >> Battery_Gas_Usage >> rentID >> carID >> is_returned >> num_of_rent >> pricetag_vehicle>>typeofvehicle;
        }
    }
}

