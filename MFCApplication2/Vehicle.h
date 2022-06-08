#pragma once
class Vehicle : public CObject
{
	friend class CMFCApplication2Dlg;
protected:
	CString company_name;
	int type_of_vehicle;
	int id;
	int care_month;
	bool is_rent;
	static int num_of_vehicles;
public:
	int get_type() { return this->type_of_vehicle; }
	virtual int print(CListCtrl& vehicle_view, int nItem)=0;
	virtual int get_quantity() = 0;
	virtual void set_quantity(int quantity) = 0;
	virtual void tofull() = 0;
	virtual int get_tank()=0;
	void setmonthofcare(int month);
	void setisrent(int status);
	int getmonthofcare();
	int getid();
	bool getisrent();
	virtual int getprice() = 0;
	
	void set_comapny_name(CString companyname);
	virtual void set_size_of_tank(int sizeoftank) = 0;
	virtual void set_price(int price) = 0;
	virtual void set_max_speed(int maxspeed) = 0;
	virtual void set_max_people(int maxpeople) = 0;
	virtual int get_max_people() = 0;
	virtual int get_max_speed() = 0;
};