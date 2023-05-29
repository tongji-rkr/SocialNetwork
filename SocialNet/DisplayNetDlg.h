#pragma once
#include "afxdialogex.h"


// DisplayNetDlg 对话框

class DisplayNetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DisplayNetDlg)

public:
	DisplayNetDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DisplayNetDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	Score* user_score;
	Score* match_degree;
	int user_num;
	int user_id;
	int friend_num;
	vector<int> newfriends;
	CString friendnames;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

