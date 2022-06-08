
// MFCApplication2Dlg.h : header file
//

#pragma once
#include "Bicycle.h"
#include "Vehicle.h"
#include "Private.h"
#include "scooter.h"
#include "SUV.h"
#include "rent.h"


// CMFCApplication2Dlg dialog
class CMFCApplication2Dlg : public CDialogEx
{
	
// Construction
public:
	CMFCApplication2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int get_rent_price(int id);
	int is_month_exist(int month);
	int is_id_exist(int id);
	int is_rent_car_exist(int id);
	int there_is_available();
	afx_msg void OnBnClickedRadio8();
	afx_msg void OnBnClickedRadio5();
	int car_radio;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox add_mont;
	int month_added;
	int sizeoftankmfc;
	afx_msg void OnBnClickedButton1();
	CTypedPtrList< CObList, Vehicle* > vehicle_lst;
	CTypedPtrList< CObList, rent* > rent_lst;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton5();
	CListCtrl vehicle_view;
	CListCtrl rent_view;
	int selected_id;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton3();
	CComboBox treatment_month;
	afx_msg void OnCbnSelchangeCombo2();
	int month_treatment;
	afx_msg void OnBnClickedButton4();
	int last_vehicle_view;
	int car_rent_radio;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton11();
	int rent_id_return;
	int km_used_return;
	int batgas_used_return;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnBnClickedButton8();
	int rent_id_view;
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
//	afx_msg void OnLvnEndlabeleditList1(NMHDR* pNMHDR, LRESULT* pResult);
	CString company_name;
	int price_t;
	int m_speed;
	int m_people;
	int view_combo_box;
	void printview(int flag);
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnEnChangeEdit10();
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnEnChangeEdit9();
	int atribute_selection;
	CString str_value_selection;
	int value_selection;
	afx_msg void OnBnClickedButton17();
	CEdit value_set;
	afx_msg void OnCbnSelchangeCombo3();
	CComboBox atribute_sel;
	afx_msg void OnEnChangeEdit11();
	CComboBox view_combo;
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnBnClickedButton18();
	int fromlastview;
	int Speed_demand;
	int People_demand;
	afx_msg void OnEnChangeEdit13();
	afx_msg void OnEnChangeEdit14();
};
