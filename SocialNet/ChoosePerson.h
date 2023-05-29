#pragma once
#include "afxdialogex.h"


// ChoosePerson 对话框

class ChoosePerson : public CDialogEx
{
	DECLARE_DYNAMIC(ChoosePerson)

public:
	ChoosePerson(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChoosePerson();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox edit;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CString usernames;
	int user_id;
	bool is_check;
	CString newfriendname;
	CString message;
	afx_msg void OnBnClickedCancel();
};
