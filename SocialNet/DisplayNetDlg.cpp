// DisplayNetDlg.cpp: 实现文件
//

#include "pch.h"
#include "SocialNet.h"
#include "afxdialogex.h"
#include "DisplayNetDlg.h"
#include "ChoosePerson.h"
#include "SocialNetDlg.h"

// DisplayNetDlg 对话框

IMPLEMENT_DYNAMIC(DisplayNetDlg, CDialogEx)

DisplayNetDlg::DisplayNetDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	user_score = NULL;
	match_degree = NULL;
}

DisplayNetDlg::~DisplayNetDlg()
{
	if (user_score)delete[]user_score,user_score=NULL;
	if (match_degree)delete[]match_degree,match_degree=NULL;
}

void DisplayNetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DisplayNetDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DisplayNetDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DisplayNetDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &DisplayNetDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// DisplayNetDlg 消息处理程序


BOOL DisplayNetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString s = _T("关联度\r\n"), s1;
	for (int i = 0; i < user_num; i++)
	{
		if (!match_degree[i].is_friend)
		{
			s += CString(match_degree[i].name);
			s1.Format(_T(" : %d\r\n"), match_degree[i].score);
			s += s1;
		}
	}
	SetDlgItemText(IDC_EDIT1, s);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void DisplayNetDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void DisplayNetDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	int r_num = 0;
	double alpha = 0.0;
	CRect rect;
	CWnd* pWin = GetDlgItem(IDC_STATIC);
	pWin->GetClientRect(rect);
	int x = rect.Width();
	int y = rect.Height();
	CDC* pDC = pWin->GetDC();
	CPen pen_red(PS_SOLID, 3, RGB(255, 0, 0));
	CPen pen_green(PS_SOLID, 3, RGB(0, 255, 0));
	CPen pen_blue(PS_SOLID, 3, RGB(0, 0, 255));
	CPen pen_grey(PS_SOLID, 3, RGB(125, 125, 125));
	CSocialNetDlg* pDlg = (CSocialNetDlg*)AfxGetMainWnd();
	pDlg->PrintRecommend(pDC, x / 2, y / 2, pen_red, pen_green, user_id);
	pDC->SelectObject(&pen_blue);
	int x1 = 0, y1 = 0, relate_num = (user_num - friend_num - 1) / 2, cnt = 0;
	for (int i = 0; i < user_num; i++)
	{
		if (user_score[i].is_friend)continue;
		r_num = (cnt + friend_num) / NUM;
		alpha = 360 / NUM * (cnt + friend_num) + (r_num % 2 ? (180 / NUM) : 0);
		x1 = int(0.5 * x + (0.5 * r_num + 1) * R * cos(alpha * pi / 180.0));
		y1 = int(0.5 * y + (0.5 * r_num + 1) * R * sin(alpha * pi / 180.0));
		pDC->Ellipse(x1- 30, y1 - 30, x1 + 30, y1 + 30);
		str = CString(user_score[i].name);
		pDC->TextOutW(x1 - 20, y1 - 5, str);
		cnt++;
		if(cnt==relate_num)
			pDC->SelectObject(&pen_grey);
	}
}


void DisplayNetDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	ChoosePerson dlg4;
	dlg4.message = _T("选择用户");
	dlg4.usernames = friendnames;
	dlg4.DoModal();
	for (int i = 0; i < user_num; i++)
	{
		if (!user_score[i].is_friend && CString(user_score[i].name) == dlg4.newfriendname)
		{
			newfriends.push_back(user_score[i].serial_num);
			break;
		}
	}
}
