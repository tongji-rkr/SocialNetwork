
// SocialNetDlg.h: 头文件
//

#pragma once
const int R=200;
const int r=30;
const double pi = 3.1415926;
const int NUM = 5;

// CSocialNetDlg 对话框
class CSocialNetDlg : public CDialogEx
{
// 构造
public:
	CSocialNetDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SOCIALNET_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	SocialNet net;
	afx_msg void OnEnChangeShow();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	void PrintSocialNet(CDC* pDC, int x0, int y0, int user_id = -1, bool is_delay = false, int delay_time = 200);
	void PrintRecommend(CDC* pDC, int x0, int y0, CPen& pen_red, CPen& pen_green, int user_id, bool is_delay = false, int delay_time = 200);
	void process(double& x, double& y, double& x1, double& y1);
	afx_msg void OnInituser();
	afx_msg void OnNewschool();
	afx_msg void OnNewplace();
	afx_msg void OnNewgroup();
	afx_msg void OnNewworkplace();
	afx_msg void OnHobbymate();
	afx_msg void OnGroupmate();
	afx_msg void OnPlacemate();
	afx_msg void OnWorkplacemate();
	afx_msg void OnSchool1();
	afx_msg void OnSchool2();
	afx_msg void OnSchool3();
};
