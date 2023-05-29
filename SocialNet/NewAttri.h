#pragma once
#include "afxdialogex.h"


// NewAttri 对话框

class NewAttri : public CDialogEx
{
	DECLARE_DYNAMIC(NewAttri)

public:
	NewAttri(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~NewAttri();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	bool isschool;
	int school_choice;
	string name;
	CString message;
	afx_msg void OnBnClickedOk();
	CComboBox edit;
};
