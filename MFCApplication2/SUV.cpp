#include "pch.h"
#include "SUV.h"
IMPLEMENT_SERIAL(SUV, CObject, 1)
SUV::SUV(int fuel_amount, int care_month, int type_of_vehicle, int price, int speed, int capacity, CString name)
{
	this->type_of_vehicle = type_of_vehicle;
	this->care_month = care_month;
	this->Fuel_amount = this->sizeoftank = fuel_amount;
	this->num_of_vehicles++;
	this->id = this->num_of_vehicles;
	this->is_rent = false;
	this->price = price;
	this->max_speed = speed;
	this->max_capacity = capacity;
	this->company_name = name;
}

void SUV::set_price(int price)
{
	this->price = price;
}

void SUV::set_max_speed(int maxspeed)
{
	this->max_speed = maxspeed;
}

void SUV::set_max_people(int maxpeople)
{
	this->max_capacity = maxpeople;
}


void SUV::Serialize(CArchive& arr)

{
    {
        CObject::Serialize(arr);
        if (arr.IsStoring())
        {
            arr << id << care_month << is_rent << num_of_vehicles << Fuel_amount << sizeoftank << max_speed << max_capacity << price<<type_of_vehicle<<company_name;

        }
        else 
        {
            arr >> id >> care_month >> is_rent >> num_of_vehicles >> Fuel_amount >> sizeoftank >> max_speed >> max_capacity >> price>>type_of_vehicle>>company_name;
        }
    }
}

int SUV::print(CListCtrl& vehicle_view, int nItem)
{
	
		char arr[1000];
		sprintf_s(arr, "%d", id);
		nItem = vehicle_view.InsertItem(0, (CString)arr);
		vehicle_view.SetItemText(nItem, 1, L"SUV");
		vehicle_view.SetItemText(nItem, 2, company_name);
		vehicle_view.SetItemText(nItem, 3, L"gas");
		sprintf_s(arr, "%d", Fuel_amount);
		vehicle_view.SetItemText(nItem, 4, (CString)arr);
		sprintf_s(arr, "%d", sizeoftank);
		vehicle_view.SetItemText(nItem, 5, (CString)arr);
		vehicle_view.SetItemText(nItem, 6, this->getisrent() ? L"yes" : L"no");
		sprintf_s(arr, "%d", price);
		vehicle_view.SetItemText(nItem, 7, (CString)arr);
		sprintf_s(arr, "%d", care_month);
		vehicle_view.SetItemText(nItem, 8, (CString)arr);
		sprintf_s(arr, "%d", max_speed);
		vehicle_view.SetItemText(nItem, 9, (CString)arr);
		sprintf_s(arr, "%d", max_capacity);
		vehicle_view.SetItemText(nItem, 10, (CString)arr);
		return nItem;
		


}
