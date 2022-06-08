
// MFCApplication2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <string>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};


CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}


void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication2Dlg dialog

CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
	, car_radio(-1)
	, sizeoftankmfc(0)
	, selected_id(0)
	, rent_id_return(0)
	, km_used_return(0)
	, batgas_used_return(0)
	, rent_id_view(0)
	, price_t(0)
	, m_speed(0)
	, m_people(0)
	, Speed_demand(0)
	, People_demand(0)
{
	view_combo_box=0;
	atribute_selection = 0;
	car_rent_radio = 0;
	last_vehicle_view = 0;
	this->month_added = 0;
	this->month_treatment = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, car_radio);
	DDX_Control(pDX, IDC_COMBO1, add_mont);
	DDX_Text(pDX, IDC_EDIT1, sizeoftankmfc);
	DDX_Control(pDX, IDC_LIST1, vehicle_view);
	DDX_Control(pDX, IDC_LIST2, rent_view);
	DDX_Text(pDX, IDC_EDIT2, selected_id);
	DDX_Control(pDX, IDC_COMBO2, treatment_month);
	DDX_Text(pDX, IDC_EDIT4, rent_id_return);
	DDX_Text(pDX, IDC_EDIT5, km_used_return);
	DDX_Text(pDX, IDC_EDIT6, batgas_used_return);
	DDX_Text(pDX, IDC_EDIT3, rent_id_view);

	DDX_Text(pDX, IDC_EDIT10, price_t);
	DDX_Text(pDX, IDC_EDIT8, m_speed);
	DDX_Text(pDX, IDC_EDIT9, m_people);

	DDX_Control(pDX, IDC_EDIT11, value_set);
	DDX_Control(pDX, IDC_COMBO3, atribute_sel);
	DDX_Control(pDX, IDC_COMBO4, view_combo);
	DDX_Text(pDX, IDC_EDIT13, Speed_demand);
	DDX_Text(pDX, IDC_EDIT14, People_demand);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO8, &CMFCApplication2Dlg::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_RADIO5, &CMFCApplication2Dlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCApplication2Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCApplication2Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCApplication2Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCApplication2Dlg::OnBnClickedRadio4)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication2Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication2Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication2Dlg::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication2Dlg::OnEnChangeEdit2)
ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCApplication2Dlg::OnCbnSelchangeCombo2)
ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2Dlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication2Dlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_RADIO6, &CMFCApplication2Dlg::OnBnClickedRadio6)
ON_BN_CLICKED(IDC_RADIO7, &CMFCApplication2Dlg::OnBnClickedRadio7)
ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication2Dlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication2Dlg::OnBnClickedButton11)
ON_EN_CHANGE(IDC_EDIT4, &CMFCApplication2Dlg::OnEnChangeEdit4)
ON_EN_CHANGE(IDC_EDIT5, &CMFCApplication2Dlg::OnEnChangeEdit5)
ON_EN_CHANGE(IDC_EDIT6, &CMFCApplication2Dlg::OnEnChangeEdit6)
ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication2Dlg::OnBnClickedButton8)
ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication2Dlg::OnEnChangeEdit3)
ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication2Dlg::OnBnClickedButton9)
ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication2Dlg::OnBnClickedButton10)
ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication2Dlg::OnBnClickedButton12)
ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication2Dlg::OnBnClickedButton13)
ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication2Dlg::OnBnClickedButton14)
ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication2Dlg::OnBnClickedButton15)
ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication2Dlg::OnBnClickedButton16)
//ON_NOTIFY(LVN_ENDLABELEDIT, IDC_LIST1, &CMFCApplication2Dlg::OnLvnEndlabeleditList1)
ON_EN_CHANGE(IDC_EDIT7, &CMFCApplication2Dlg::OnEnChangeEdit7)
ON_EN_CHANGE(IDC_EDIT10, &CMFCApplication2Dlg::OnEnChangeEdit10)
ON_EN_CHANGE(IDC_EDIT8, &CMFCApplication2Dlg::OnEnChangeEdit8)
ON_EN_CHANGE(IDC_EDIT9, &CMFCApplication2Dlg::OnEnChangeEdit9)
ON_BN_CLICKED(IDC_BUTTON17, &CMFCApplication2Dlg::OnBnClickedButton17)
ON_CBN_SELCHANGE(IDC_COMBO3, &CMFCApplication2Dlg::OnCbnSelchangeCombo3)
ON_EN_CHANGE(IDC_EDIT11, &CMFCApplication2Dlg::OnEnChangeEdit11)
ON_CBN_SELCHANGE(IDC_COMBO4, &CMFCApplication2Dlg::OnCbnSelchangeCombo4)
ON_BN_CLICKED(IDC_BUTTON18, &CMFCApplication2Dlg::OnBnClickedButton18)
ON_EN_CHANGE(IDC_EDIT13, &CMFCApplication2Dlg::OnEnChangeEdit13)
ON_EN_CHANGE(IDC_EDIT14, &CMFCApplication2Dlg::OnEnChangeEdit14)
END_MESSAGE_MAP()


// CMFCApplication2Dlg message handlers


int CMFCApplication2Dlg::get_rent_price(int id)
{
	int km, usedbatgas;
	POSITION pos, pos1;
	int x = is_rent_car_exist(id);
	for (pos = rent_lst.GetHeadPosition(); pos != NULL; rent_lst.GetNext(pos))
	{
		if (rent_lst.GetAt(pos)->getrentid() == id)
		{
			km = rent_lst.GetAt(pos)->getkmused();
			usedbatgas = rent_lst.GetAt(pos)->getbatgasused();
			return rent_lst.GetAt(pos)->getpricetag()*km+usedbatgas;
		}
	}
}


int CMFCApplication2Dlg::is_month_exist(int month)
{
	POSITION pos1;
	
	for (pos1 = vehicle_lst.GetHeadPosition(); pos1 != NULL;)
	{
		if (vehicle_lst.GetAt(pos1)->getmonthofcare() == month)
		{
			return 1;
		}
		vehicle_lst.GetNext(pos1);
	}
	return 0;
}


int CMFCApplication2Dlg::is_id_exist(int id)
{
		POSITION pos1;
		for (pos1 = vehicle_lst.GetHeadPosition(); pos1 != NULL;)
		{
			if (vehicle_lst.GetAt(pos1)->getid() == id)
			{
				return 1;
			}
			vehicle_lst.GetNext(pos1);
		}
		return 0;
}


int CMFCApplication2Dlg::is_rent_car_exist(int id)
{
	POSITION pos1;
	for (pos1 =rent_lst.GetHeadPosition(); pos1 != NULL;)
	{
		if (rent_lst.GetAt(pos1)->getrentid() == id)
		{
			return rent_lst.GetAt(pos1)->getcarid();
		}
		rent_lst.GetNext(pos1);
	}
	return 0;
}


int CMFCApplication2Dlg::there_is_available()
{

		POSITION pos1;
	
		for (pos1 = vehicle_lst.GetHeadPosition(); pos1 != NULL;)
		{
			if (vehicle_lst.GetAt(pos1)->getisrent() == FALSE)
			{
				return 1;
			}
			vehicle_lst.GetNext(pos1);
		}
		return 0;
	
}


BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);        
	SetIcon(m_hIcon, FALSE);      
	
	vehicle_view.InsertColumn(0,L"ID",LVCFMT_LEFT,  35);           
	vehicle_view.InsertColumn(1, L"TYPE", LVCFMT_CENTER, 60);
	vehicle_view.InsertColumn(2, L"COMPANY", LVCFMT_CENTER, 110);
	vehicle_view.InsertColumn(3, L"GAS/BATTERY", LVCFMT_LEFT, 95);
	vehicle_view.InsertColumn(4, L"FUEL AMOUNT", LVCFMT_LEFT, 100);
	vehicle_view.InsertColumn(5, L"CAPACITY", LVCFMT_LEFT, 80);
	vehicle_view.InsertColumn(6, L"ON RENT?", LVCFMT_LEFT, 80);
	vehicle_view.InsertColumn(7, L"PRICE TAG", LVCFMT_LEFT, 85);
	vehicle_view.InsertColumn(8, L"VEHICLE TREATMENT", LVCFMT_LEFT, 130);
	vehicle_view.InsertColumn(9, L"MAX SPEED", LVCFMT_LEFT, 80);
	vehicle_view.InsertColumn(10, L"MAX PEOPLE CAPACITY", LVCFMT_LEFT, 135);


	rent_view.InsertColumn(0, L"RENT ID", LVCFMT_LEFT, 70);
	rent_view.InsertColumn(1, L"CAR ID", LVCFMT_CENTER, 100);
	rent_view.InsertColumn(2, L"VEHICLE", LVCFMT_CENTER, 70);
	rent_view.InsertColumn(3, L"GAS/BATTERY USED", LVCFMT_LEFT, 140);
	rent_view.InsertColumn(4, L"KM USED", LVCFMT_LEFT, 100);
	rent_view.InsertColumn(5, L"RETURN?", LVCFMT_LEFT, 100);


	return TRUE;  // return TRUE  unless you set the focus to a control
	
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}


void CMFCApplication2Dlg::OnPaint()
{

	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CFont font;
	font.CreatePointFont(515, _T("David"));
	CFont* oldFont = dc.SelectObject(&font);
	dc.SetBkMode(TRANSPARENT);
	CString string = _T("C.S. Rent");
	dc.SetTextColor(RGB(0, 0, 0));
	dc.DrawText(string, &rect, DT_SINGLELINE |
		DT_TOP | DT_CENTER);
	dc.SelectObject(oldFont);


}


HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplication2Dlg::OnBnClickedRadio1()
{
	car_radio = 1;
}


void CMFCApplication2Dlg::OnBnClickedRadio2()
{
	car_radio = 2;
}


void CMFCApplication2Dlg::OnBnClickedRadio3()
{
	car_radio = 3;
}


void CMFCApplication2Dlg::OnBnClickedRadio4()
{
	car_radio = 4;
}


void CMFCApplication2Dlg::OnCbnSelchangeCombo1()
{
	this->month_added = add_mont.GetCurSel()+1;
}


void CMFCApplication2Dlg::OnBnClickedButton1()
{
	char arr[1000];
	if (car_radio == -1 || this->month_added == 0 || sizeoftankmfc <= 0||price_t<=0||m_speed<=0||m_people<=0||company_name.GetLength()==0)
	{
		MessageBox(L"one or more of your input are invalid!!!!!!",L"invalid insert");	
	}
	else
	{
		if (car_radio==1)
		{
			Private* p = new Private(sizeoftankmfc, month_added,1,price_t,m_speed,m_people,company_name);
			vehicle_lst.AddHead(p);
			sprintf_s(arr, "%d", p->getid());
			MessageBox(L"your vehicle is added succesfully id: " + (CString)arr,L"vehicle added");
		}
		else if (car_radio==2)
		{
			SUV * s = new SUV(sizeoftankmfc, month_added,2,price_t, m_speed, m_people, company_name);
			vehicle_lst.AddHead(s);
			sprintf_s(arr, "%d", s->getid());
			MessageBox(L"your vehicle is added succesfully id: " + (CString)arr, L"vehicle added");
		}
		else if (car_radio==3)
		{
			Bicycle * b = new Bicycle(sizeoftankmfc, month_added,3, price_t, m_speed, m_people, company_name);
			vehicle_lst.AddHead(b);
			sprintf_s(arr, "%d", b->getid());
			MessageBox(L"your vehicle is added succesfully id: " + (CString)arr, L"vehicle added");
		}
		else if (car_radio==4)
		{
			Scooter * sc = new Scooter(sizeoftankmfc, month_added,4, price_t, m_speed, m_people, company_name);
			vehicle_lst.AddHead(sc);
			sprintf_s(arr, "%d", sc->getid());
			MessageBox(L"your vehicle is added succesfully id: " + (CString)arr, L"vehicle added");
		}
		OnBnClickedButton5();
	}

}


void CMFCApplication2Dlg::OnEnChangeEdit1()
{
	sizeoftankmfc = GetDlgItemInt(IDC_EDIT1);
}


void CMFCApplication2Dlg::OnBnClickedButton5()
{
	int nItem=0;
	vehicle_view.DeleteAllItems();
	POSITION pos;
	last_vehicle_view = 1;
	for (pos = vehicle_lst.GetHeadPosition(); pos != NULL; vehicle_lst.GetNext(pos))
		nItem = vehicle_lst.GetAt(pos)->print(vehicle_view, nItem);

}


void CMFCApplication2Dlg::OnBnClickedButton2()
{
	int flag = 0;
	Vehicle* pa = NULL;
	POSITION pos1;
	if (selected_id <= 0)
	{
		MessageBox(L"your id is invalid", L"invalid input");
		return;
	}
	for (pos1 = vehicle_lst.GetHeadPosition(); pos1 != NULL;)
	{
		if (vehicle_lst.GetAt(pos1)->getid() == selected_id)
		{
			if (vehicle_lst.GetAt(pos1)->getisrent() == TRUE)
			{
				MessageBox(L"you cant remove vehicle on rent", L"cant remove");
				return;
			}
			flag = 1;
			pa = vehicle_lst.GetAt(pos1);
			vehicle_lst.RemoveAt(pos1);
			break;
		}
		vehicle_lst.GetNext(pos1);
	}
	if (flag == 1) {
		OnBnClickedButton5();
		MessageBox(L"your selected id has been removed succesfully!!!", L"vehicle is removed");
		delete(pa);
	}
	else

	{
		MessageBox(L"your selected id is not found on the database", L"vehicle is not foud");
	}
}


void CMFCApplication2Dlg::OnEnChangeEdit2()
{
	selected_id= GetDlgItemInt(IDC_EDIT2);
}


void CMFCApplication2Dlg::OnBnClickedButton3()
{
	int nItem=0,flag=0;
	POSITION pos;
	if (selected_id <= 0) {
	
		MessageBox(L"your id is invalid", L"invalid input");
		return;
	}
	if (is_id_exist(selected_id)==0)
	{
		if (last_vehicle_view == 3)
			vehicle_view.DeleteAllItems();
		MessageBox(L"your selected id is not found on the database", L"vehicle is not foud");
		return;
	}
	last_vehicle_view = 3;
	vehicle_view.DeleteAllItems();
	for (pos = vehicle_lst.GetHeadPosition(); pos != NULL; vehicle_lst.GetNext(pos))
		if (vehicle_lst.GetAt(pos)->getid() == selected_id)
		{
			nItem = vehicle_lst.GetAt(pos)->print(vehicle_view, nItem);
		}
}


void CMFCApplication2Dlg::OnCbnSelchangeCombo2()
{
	this->month_treatment = treatment_month.GetCurSel() + 1;
}


void CMFCApplication2Dlg::OnBnClickedButton4()
{
	int nItem=0;
	POSITION pos;
	if (this->month_treatment == 0)
	{
		MessageBox(L"you should select month", L"select month");
		return;
	}
	if (is_month_exist(month_treatment) == 0)
	{
		if (last_vehicle_view == 2)
			vehicle_view.DeleteAllItems();
		MessageBox(L"there is no vehicle on the selected month", L"no vehicle found");
		return;
	}
	last_vehicle_view = 2;
	vehicle_view.DeleteAllItems();
	for (pos = vehicle_lst.GetHeadPosition(); pos != NULL; vehicle_lst.GetNext(pos))
		if (vehicle_lst.GetAt(pos)->getmonthofcare() == month_treatment)
		{
			nItem = vehicle_lst.GetAt(pos)->print(vehicle_view, nItem);
		}
}


void CMFCApplication2Dlg::OnBnClickedButton6()
{
	POSITION pos;
	int nItem=0;
	if (there_is_available() == 0)
	{
		if(last_vehicle_view==4)
		vehicle_view.DeleteAllItems();
		MessageBox(L"we dont have available car", L"available allert");
		return;
	}
	last_vehicle_view = 4;
	vehicle_view.DeleteAllItems();
	for (pos = vehicle_lst.GetHeadPosition(); pos != NULL; vehicle_lst.GetNext(pos))
		if (vehicle_lst.GetAt(pos)->getisrent() == FALSE)
		nItem = vehicle_lst.GetAt(pos)->print(vehicle_view, nItem);
}


void CMFCApplication2Dlg::OnBnClickedRadio6()
{
	car_rent_radio = 2;
}


void CMFCApplication2Dlg::OnBnClickedRadio8()
{
	car_rent_radio = 4;
}


void CMFCApplication2Dlg::OnBnClickedRadio5()
{
	car_rent_radio = 1;
}


void CMFCApplication2Dlg::OnBnClickedRadio7()
{
	car_rent_radio = 3;
}


void CMFCApplication2Dlg::OnBnClickedButton7()
{
	int flag = 0;
	POSITION pos;
	char arr[1000];
	char arr1[1000];
	if (car_rent_radio == 0)
	{
		MessageBox(L"you have to select vehicle!!!!!", L"invalid insert");
	}
	else
	{
		for (pos = vehicle_lst.GetTailPosition(); pos != NULL; vehicle_lst.GetPrev(pos))
		{
			if (car_rent_radio == vehicle_lst.GetAt(pos)->get_type() && vehicle_lst.GetAt(pos)->getisrent() == FALSE 
				&& vehicle_lst.GetAt(pos)->get_tank() / (double)vehicle_lst.GetAt(pos)->get_quantity() <= 4&& vehicle_lst.GetAt(pos)->get_max_speed()>=Speed_demand&&
				vehicle_lst.GetAt(pos)->get_max_people()>=People_demand)
			{
				flag = 1;
				rent* p = new rent(vehicle_lst.GetAt(pos)->getid(), vehicle_lst.GetAt(pos)->getprice(),car_rent_radio);
				rent_lst.AddHead(p);
				sprintf_s(arr1, "%d", p->getcarid());
				sprintf_s(arr, "%d", p->getrentid());
				MessageBox(L"your vehicle id is: " + (CString)arr1 + L" your rent id: " + (CString)arr, L"rent succesfull");
				vehicle_lst.GetAt(pos)->setisrent(1);
				break;
			}
		}
		if (flag == 0)
		{
			MessageBox(L"According to your input there is no vehicle to rent please try again later", L"rent eror");
		}
		OnBnClickedButton11();
		switch (last_vehicle_view)
		{
		case 1:
			{
			OnBnClickedButton5();
				break;
			}
		case 2:
			{OnBnClickedButton4();
				break; }
		case 3:
		{OnBnClickedButton3();
		break;
		}
		case 4:
			{OnBnClickedButton6();
				break; }
		case 5:
		{OnBnClickedButton15();
		break; }
		default:
			if (last_vehicle_view >= 6 && last_vehicle_view <= 9)
			{
				fromlastview = 1;
				OnBnClickedButton18();
			}
			break;
		}
	}
}


void CMFCApplication2Dlg::OnBnClickedButton11()
{
	char arr[1000];
	int nItem;
	POSITION pos;
	rent_view.DeleteAllItems();
	for (pos = rent_lst.GetHeadPosition(); pos != NULL; rent_lst.GetNext(pos))
	{
		sprintf_s(arr, "%d", rent_lst.GetAt(pos)->getrentid());
		nItem = rent_view.InsertItem(0, (CString)arr);
		sprintf_s(arr, "%d", rent_lst.GetAt(pos)->getcarid());
		rent_view.SetItemText(nItem, 1, (CString)arr);
		int x = rent_lst.GetAt(pos)->gettypeofvehicle();
		rent_view.SetItemText(nItem, 2, x == 1 ? L"private" : x == 2 ? L"SUV":x==3?L"bicycle":L"scooter");
		sprintf_s(arr, "%d", rent_lst.GetAt(pos)->getbatgasused());
		rent_view.SetItemText(nItem, 3, (CString)arr);
		sprintf_s(arr, "%d", rent_lst.GetAt(pos)->getkmused());
		rent_view.SetItemText(nItem, 4, (CString)arr) ;
		rent_view.SetItemText(nItem, 5, rent_lst.GetAt(pos)->getisreturned()? L"yes":L"no");
	}
}


void CMFCApplication2Dlg::OnEnChangeEdit4()
{
	rent_id_return = GetDlgItemInt(IDC_EDIT4);
}


void CMFCApplication2Dlg::OnEnChangeEdit5()
{
	km_used_return = GetDlgItemInt(IDC_EDIT5);
}


void CMFCApplication2Dlg::OnEnChangeEdit6()
{
	batgas_used_return = GetDlgItemInt(IDC_EDIT6);

}


void CMFCApplication2Dlg::OnBnClickedButton8()
{
	POSITION pos,vehicle_pos;

	if(rent_id_return<=0 || km_used_return <= 0 || batgas_used_return <= 0)
	{
		MessageBox(L"one or more of your input are invalid",L"wrong input");
		return;
	}
	int carrentid = is_rent_car_exist(rent_id_return);
	if (carrentid==0)
	{
		MessageBox(L"your input id is not exist",L"id isnt exist");
		return;
	}
	for (pos = rent_lst.GetHeadPosition(); pos != NULL; rent_lst.GetNext(pos))
		if (rent_lst.GetAt(pos)->getrentid() == rent_id_return)
		{
			
			if (rent_lst.GetAt(pos)->getisreturned() == 1)
			{
				MessageBox(L"your vehicle is already returned", L"vehicle return");
				return;
			}
			break;
		}
	for (vehicle_pos = vehicle_lst.GetHeadPosition(); vehicle_pos != NULL; vehicle_lst.GetNext(vehicle_pos))
		if (vehicle_lst.GetAt(vehicle_pos)->getid() == carrentid)
		{
			if (vehicle_lst.GetAt(vehicle_pos)->get_quantity() < batgas_used_return)
			{
				MessageBox(L"you cant use more fuel than what you got", L"wrong input");
				return;
			}
			vehicle_lst.GetAt(vehicle_pos)->setisrent(0);
			vehicle_lst.GetAt(vehicle_pos)->set_quantity(vehicle_lst.GetAt(vehicle_pos)->get_quantity() - batgas_used_return);
		}
	rent_lst.GetAt(pos)->setbatgasused(batgas_used_return);
	rent_lst.GetAt(pos)->setkmused(km_used_return);
	rent_lst.GetAt(pos)->setisreturned(1);

	OnBnClickedButton11();
	switch (last_vehicle_view)
	{
	case 1:
	{
		OnBnClickedButton5();
		break;
	}
	case 2:
	{OnBnClickedButton4();
	break; }
	case 3:
	{OnBnClickedButton3();
	break;
	}
	case 4:
	{OnBnClickedButton6();
	break; }
	case 5:
	{OnBnClickedButton15();
	break; }
	default:if (last_vehicle_view >= 6 && last_vehicle_view <= 9)
	{
		fromlastview = 1;
		OnBnClickedButton18();
	};
		break;
	}
}


void CMFCApplication2Dlg::OnEnChangeEdit3()
{
	rent_id_view= GetDlgItemInt(IDC_EDIT3);
}


void CMFCApplication2Dlg::OnBnClickedButton9()
{
	int nItem;
	char arr[1000];
	POSITION pos;
	if (rent_id_view <= 0 )
	{
		MessageBox(L"one or more of your input are invalid", L"wrong input");
		return;
	}
	if (is_rent_car_exist(rent_id_view)==0)
	{
		MessageBox(L"your rent id isnt found in the database", L"id eror");
		return;
	}
	rent_view.DeleteAllItems();
	for (pos = rent_lst.GetHeadPosition(); pos != NULL; rent_lst.GetNext(pos))
		if (rent_lst.GetAt(pos)->getrentid() == rent_id_view)
		{
			sprintf_s(arr, "%d", rent_lst.GetAt(pos)->getrentid());
			nItem = rent_view.InsertItem(0, (CString)arr);
			sprintf_s(arr, "%d", rent_lst.GetAt(pos)->getcarid());
			rent_view.SetItemText(nItem, 1, (CString)arr);
			int x = rent_lst.GetAt(pos)->gettypeofvehicle();
			rent_view.SetItemText(nItem, 2, x == 1 ? L"private" : x == 2 ? L"SUV" : x == 3 ? L"bicycle" : L"scooter");
			sprintf_s(arr, "%d", rent_lst.GetAt(pos)->getbatgasused());
			rent_view.SetItemText(nItem, 3, (CString)arr);
			sprintf_s(arr, "%d", rent_lst.GetAt(pos)->getkmused());
			rent_view.SetItemText(nItem, 4, (CString)arr);
			rent_view.SetItemText(nItem, 5, rent_lst.GetAt(pos)->getisreturned() ? L"yes" : L"no");
			
		}
}


void CMFCApplication2Dlg::OnBnClickedButton10()
{
	char arr[1000];
	if (rent_id_view <= 0)
	{
		MessageBox(L"one or more of your input are invalid", L"wrong input");
		return;
	}
	int x = is_rent_car_exist(rent_id_view);
	if (x == 0)
	{
		MessageBox(L"your rent id isnt found in the database", L"id eror");
		return;
	}
	int y = get_rent_price(rent_id_view);
	if (y == 0)
	{
		MessageBox(L"you have to return the vehicle before getting price!!!" , L"unreturned vwhicle");
		return;
	}
	sprintf_s(arr, "%d", y);
	MessageBox(L"your rent price is:  "+(CString)arr, L"rent price");
}


void CMFCApplication2Dlg::OnBnClickedButton12()
{
	char arr[1000];
	POSITION pos;
	int sum = 0;
	for (pos = rent_lst.GetHeadPosition(); pos != NULL; rent_lst.GetNext(pos))
		sum += get_rent_price(rent_lst.GetAt(pos)->getrentid());
	sprintf_s(arr, "%d", sum);
	MessageBox(L"price of all rent together is:  " + (CString)arr,L"all price");
}


void CMFCApplication2Dlg::OnBnClickedButton13()
{
	CFileDialog dlg(FALSE, _T(".chsh"), NULL, 0, _T("chsh (*.chsh)|*.chsh|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive arr(&file, CArchive::store);
		rent_lst.Serialize(arr);
		vehicle_lst.Serialize(arr);
		arr.Close();
		file.Close();
	}
}


void CMFCApplication2Dlg::OnBnClickedButton14()
{
	CFileDialog dlg(TRUE, _T(".chsh"), NULL, 0, _T("chsh (*.chsh)|*.chsh|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		vehicle_lst.RemoveAll();
		rent_lst.RemoveAll();
		filename = dlg.GetPathName(); 
		CFile file(filename, CFile::modeRead);
		CArchive arr(&file, CArchive::load);
		rent_lst.Serialize(arr);
		vehicle_lst.Serialize(arr);
		arr.Close();
		file.Close();
		OnBnClickedButton5();
		OnBnClickedButton11();
	}
}


void CMFCApplication2Dlg::OnBnClickedButton15()
{
	{
		int nItem = 0;
		vehicle_view.DeleteAllItems();

		POSITION pos;
		last_vehicle_view = 5;
		for (pos = vehicle_lst.GetHeadPosition(); pos != NULL; vehicle_lst.GetNext(pos))
			if((vehicle_lst.GetAt(pos)->get_tank()/(double)vehicle_lst.GetAt(pos)->get_quantity())>=4)
			{
			nItem = vehicle_lst.GetAt(pos)->print(vehicle_view, nItem);
	}

	}
}


void CMFCApplication2Dlg::OnBnClickedButton16()
{
	{

		POSITION pos;
		if (selected_id <= 0) {

			MessageBox(L"your id is invalid", L"invalid input");
			return;
		}
		if (is_id_exist(selected_id) == 0)
		{
			MessageBox(L"your selected id is not found on the database", L"vehicle is not foud");
			return;
		}
		for (pos = vehicle_lst.GetHeadPosition(); pos != NULL; vehicle_lst.GetNext(pos))
			if (vehicle_lst.GetAt(pos)->getid() == selected_id)
			{
				if (vehicle_lst.GetAt(pos)->getisrent() == TRUE)
				{
					MessageBox(L"you cant full vehicle on rent", L"cant remove");
					break;
				}
				vehicle_lst.GetAt(pos)->tofull();
				break;
			}
		switch (last_vehicle_view)
		{
		case 1:
		{
			OnBnClickedButton5();
			break;
		}
		case 2:
		{OnBnClickedButton4();
		break; }
		case 3:
		{OnBnClickedButton3();
		break;
		}
		case 4:
		{OnBnClickedButton6();
		break; }
		case 5:
		{OnBnClickedButton15();
		break; }
		default:
			if (last_vehicle_view >= 6 && last_vehicle_view <= 9)
			{
				fromlastview = 1;
				OnBnClickedButton18();
			};
			break;
		}
	}
}


void CMFCApplication2Dlg::printview(int flag)
{
	POSITION pos;
	int nItem = 0;
	int selection;
	if (flag == 1)
	{
		selection = view_combo_box - 1;
	}
	else
	{
		selection = last_vehicle_view - 5;
	}
	last_vehicle_view = selection + 5;
	vehicle_view.DeleteAllItems();
	
	for (pos = vehicle_lst.GetHeadPosition(); pos != NULL; vehicle_lst.GetNext(pos))
		if(selection==vehicle_lst.GetAt(pos)->get_type())
			nItem = vehicle_lst.GetAt(pos)->print(vehicle_view, nItem);

}


void CMFCApplication2Dlg::OnEnChangeEdit7()
{
	GetDlgItemText(IDC_EDIT7, company_name);
	
}


void CMFCApplication2Dlg::OnEnChangeEdit10()
{
	price_t = GetDlgItemInt(IDC_EDIT10);
}


void CMFCApplication2Dlg::OnEnChangeEdit8()
{
	m_speed = GetDlgItemInt(IDC_EDIT8);
}


void CMFCApplication2Dlg::OnEnChangeEdit9()
{
	m_people = GetDlgItemInt(IDC_EDIT9);
}


void CMFCApplication2Dlg::OnBnClickedButton17()

{
	POSITION pos1;
	if (is_id_exist(selected_id) == 0)
	{
		MessageBox(L"your selected id is not found on the database", L"vehicle is not found");
		return;
	}

	for (pos1 = vehicle_lst.GetHeadPosition(); pos1 != NULL; vehicle_lst.GetNext(pos1))
	{
		if (vehicle_lst.GetAt(pos1)->getid() == selected_id)
		{
			if (vehicle_lst.GetAt(pos1)->getisrent() == TRUE)
			{
				MessageBox(L"you cant change vehicle on rent", L"cant change");
				return;
			}
			switch (atribute_selection)
			{
			case 1: {
				if (str_value_selection.GetLength() == 0)
				{
					MessageBox(L"you need to input name", L"input eror");
					return;

				}
				vehicle_lst.GetAt(pos1)->set_comapny_name(str_value_selection);
				break;
			}
			case 2: {
				if (value_selection <= 0)
				{
					MessageBox(L"your input is invalid", L"input eror");
					return;

				}
				if (vehicle_lst.GetAt(pos1)->get_tank() - value_selection >= 0)
				{
					MessageBox(L"you cant change your tank to less than your amount", L"input error");
					return;

				}
				vehicle_lst.GetAt(pos1)->set_size_of_tank(value_selection);
				break;
			}
			case 3: {
				if (value_selection <= 0)
				{
					MessageBox(L"your input is invalid", L"input eror");
					return;

				}
				vehicle_lst.GetAt(pos1)->set_price(value_selection);
				break;
			}
			case 4: {
				if (value_selection <= 0)
				{
					MessageBox(L"your input is invalid", L"input eror");
					return;

				}
				vehicle_lst.GetAt(pos1)->set_max_speed(value_selection);
				break;
			}
			case 5: {
				if (value_selection <= 0)
				{
					MessageBox(L"your input is invalid", L"input eror");
					return;

				}
				vehicle_lst.GetAt(pos1)->set_max_people(value_selection);
				break;
			}
			default:
			{
				MessageBox(L"please select atribute to change", L"input eror");
				return;
			}
			break;
			}
			break;
		}
	}
	switch (last_vehicle_view)
	{
	case 1:
	{
		OnBnClickedButton5();
		break;
	}
	case 2:
	{OnBnClickedButton4();
	break; }
	case 3:
	{OnBnClickedButton3();
	break;
	}
	case 4:
	{OnBnClickedButton6();
	break; }
	case 5:
	{OnBnClickedButton15();
	break; }
	default:
		if (last_vehicle_view >= 6 && last_vehicle_view <= 9)
		{
			fromlastview = 1;
			OnBnClickedButton18();
		}
		break;
	}
}



void CMFCApplication2Dlg::OnCbnSelchangeCombo3()
{
	atribute_selection = atribute_sel.GetCurSel() + 1;
}


void CMFCApplication2Dlg::OnEnChangeEdit11()
{
	if(atribute_selection==1)
	{
		GetDlgItemText(IDC_EDIT11, str_value_selection);
	}
	else
	{
		value_selection = GetDlgItemInt(IDC_EDIT11);
	}
}


void CMFCApplication2Dlg::OnCbnSelchangeCombo4()
{
	view_combo_box = view_combo.GetCurSel() + 1;
}


void CMFCApplication2Dlg::OnBnClickedButton18()
{
	POSITION pos;
	int nItem = 0;
	int selection;
	if (fromlastview != 1)
	{
		if (view_combo_box==0)
		{
			MessageBox(L"You have to select View", L"Input error");
				return;
		}
		selection = view_combo_box;
	}
	else
	{
		selection = last_vehicle_view - 5;
	}
	last_vehicle_view = selection + 5;
	vehicle_view.DeleteAllItems();

	for (pos = vehicle_lst.GetHeadPosition(); pos != NULL; vehicle_lst.GetNext(pos))
		if (selection == vehicle_lst.GetAt(pos)->get_type())
			nItem = vehicle_lst.GetAt(pos)->print(vehicle_view, nItem);
	fromlastview = 0;
}


void CMFCApplication2Dlg::OnEnChangeEdit13()
{
	Speed_demand = GetDlgItemInt(IDC_EDIT13);
}


void CMFCApplication2Dlg::OnEnChangeEdit14()
{
	People_demand = GetDlgItemInt(IDC_EDIT14);
}
