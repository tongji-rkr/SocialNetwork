#pragma once
#include "afxdialogex.h"


// NewPersonDlg 对话框

class NewPersonDlg : public CDialogEx
{
	DECLARE_DYNAMIC(NewPersonDlg)

public:
	NewPersonDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~NewPersonDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	//CComboBox edit1;
	CComboBox edit2;
	CComboBox edit3;
	CComboBox edit4;
	CComboBox edit5;
	CComboBox edit6;
public:
	virtual BOOL OnInitDialog();
	CString placenames;
	CString schoolnames1;
	CString schoolnames2;
	CString schoolnames3;
	CString workplacenames;
	CString groupnames;
	CString friendnames; 
	User newuser;
	afx_msg void OnBnClickedOk();
};
void initCombo(CString& strSrc, CComboBox& edit);
