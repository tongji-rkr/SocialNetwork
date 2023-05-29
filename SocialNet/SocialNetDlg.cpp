
// SocialNetDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "SocialNet.h"
#include "SocialNetDlg.h"
#include "afxdialogex.h"
#include "ChoosePerson.h"
#include "NewPersonDlg.h"
#include "DisplayNetDlg.h"
#include "NewAttri.h"
#include <windows.h>
#include <cmath>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CSocialNetDlg 对话框



CSocialNetDlg::CSocialNetDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SOCIALNET_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSocialNetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSocialNetDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_SHOW, &CSocialNetDlg::OnEnChangeShow)
	ON_BN_CLICKED(IDC_BUTTON1, &CSocialNetDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSocialNetDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CSocialNetDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CSocialNetDlg::OnBnClickedButton4)
	ON_COMMAND(ID_INITUSER, &CSocialNetDlg::OnInituser)
	ON_COMMAND(ID_NEWSCHOOL, &CSocialNetDlg::OnNewschool)
	ON_COMMAND(ID_NEWPLACE, &CSocialNetDlg::OnNewplace)
	ON_COMMAND(ID_NEWGROUP, &CSocialNetDlg::OnNewgroup)
	ON_COMMAND(ID_NEWWORKPLACE, &CSocialNetDlg::OnNewworkplace)
	ON_COMMAND(ID_HOBBYMATE, &CSocialNetDlg::OnHobbymate)
	ON_COMMAND(ID_GROUPMATE, &CSocialNetDlg::OnGroupmate)
	ON_COMMAND(ID_PLACEMATE, &CSocialNetDlg::OnPlacemate)
	ON_COMMAND(ID_WORKPLACEMATE, &CSocialNetDlg::OnWorkplacemate)
	ON_COMMAND(ID_SCHOOL1, &CSocialNetDlg::OnSchool1)
	ON_COMMAND(ID_SCHOOL2, &CSocialNetDlg::OnSchool2)
	ON_COMMAND(ID_SCHOOL3, &CSocialNetDlg::OnSchool3)
END_MESSAGE_MAP()


// CSocialNetDlg 消息处理程序

BOOL CSocialNetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	CMenu menu;
	menu.LoadMenu(IDR_MENU1);  //IDR_MENU1为菜单栏ID号
	SetMenu(&menu);

	CString hinter = _T("欢迎使用TJ社交网络系统，功能如下：\r\n");
	hinter += _T("1.输出社交网络信息\r\n");
	hinter += _T("2.新建用户\r\n");
	hinter += _T("3.寻找可能认识的人\r\n");
	hinter += _T("4.显示社交网络的图形化\r\n");
	hinter += _T("5.查看非好友用户关联度\r\n");
	hinter += _T("6.添加好友\r\n");
	hinter += _T("7.添加新的地区选项\r\n");
	hinter += _T("8.添加新的学校选项\r\n");
	hinter += _T("9.添加新的群组选项\r\n");
	hinter += _T("10.添加新的工作单位选项\r\n");
	hinter += _T("11.查看相同地区用户\r\n");
	hinter += _T("12.查看相同学校用户\r\n");
	hinter += _T("13.查看相同群组用户\r\n");
	hinter += _T("14.查看相同工作单位用户\r\n");
	hinter += _T("15.查看相同爱好用户\r\n");
	SetDlgItemText(IDC_SHOW, hinter);
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSocialNetDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSocialNetDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSocialNetDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSocialNetDlg::OnEnChangeShow()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CSocialNetDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s=_T("");
	CString end = _T("\r\n");
	int user_num = net.Users.size();
	for (int i = 0; i < user_num; i++)
	{
		User& u = net.Users[i];
		s += _T("用户姓名:") + CString(u.username) + end;
		s += _T("用户地区:") + CString(net.Places[u.place_id].placename) + end;
		s += _T("用户小学:") + CString(net.primary_schools[u.primary_school_id].schoolname) + end;
		s += _T("用户中学:") + CString(net.middle_schools[u.middle_school_id].schoolname) + end;
		s += _T("用户大学:") + CString(net.universities[u.university_id].schoolname) + end;
		s += _T("用户工作单位:") + CString(net.WorkPlaces[u.workplace_id].placename) + end;
		s += _T("用户好友:");
		for (int k = 0; k < u.friends.size(); k++)
		{ 
			s += CString(net.Users[u.friends[k]].username) + _T(", ");
		}
		s += end;
		s += _T("用户群组:");
		for (int k = 0; k < u.groups.size(); k++)
		{
			s += CString(net.Groups[u.groups[k]].groupname) + _T(", ");
		}
		s += end;
		s += _T("用户爱好:");
		for (int k = 0; k < u.hobbies.size(); k++)
		{
			s += CString(net.Hobbies[u.hobbies[k]].hobbyname) + _T(", ");
		}
		s += end;
		s += end;
	}
	SetDlgItemText(IDC_SHOW, s);
}


void CSocialNetDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	NewPersonDlg dlg1;
	int Placenum = net.Places.size();
	int Schoolnum1 = net.primary_schools.size();
	int Schoolnum2 = net.middle_schools.size();
	int Schoolnum3 = net.universities.size();
	int WorkPlacenum = net.WorkPlaces.size();
	int Friendnum = net.Users.size();
	int Groupnum = net.Groups.size();
	for (int i = 0; i < Placenum; i++)
	{
		dlg1.placenames += CString(net.Places[i].placename) + _T("#");
	}
	for (int i = 0; i < Schoolnum1; i++)
	{
		dlg1.schoolnames1 +=  CString(net.primary_schools[i].schoolname) + _T("#");
	}
	for (int i = 0; i < Schoolnum2; i++)
	{
		dlg1.schoolnames2 += CString(net.middle_schools[i].schoolname) + _T("#");
	}
	for (int i = 0; i < Schoolnum3; i++)
	{
		dlg1.schoolnames3 += CString(net.universities[i].schoolname) + _T("#");
	}
	for (int i = 0; i < WorkPlacenum; i++)
	{
		dlg1.workplacenames += CString(net.WorkPlaces[i].placename) + _T("#");
	}
	for (int i = 0; i < Friendnum; i++)
	{
		CString serial;
		serial.Format(_T("%d."), i);
		dlg1.friendnames += serial + CString(net.Users[i].username) + _T("\r\n");
	}
	for (int i = 0; i < Groupnum; i++)
	{
		CString serial;
		serial.Format(_T("%d."), i);
		dlg1.groupnames += serial + CString(net.Groups[i].groupname) + _T("\r\n");
	}
	dlg1.DoModal();
	CString s = _T("新建用户\r\n"), end = _T("\r\n");
	User& u = dlg1.newuser;
	int new_id = net.Users.size();
	net.Users.push_back(u);
	s += _T("用户姓名:") + CString(u.username) + end;
	net.Places[u.place_id].placemates.push_back(new_id);
	s += _T("用户地区:") + CString(net.Places[u.place_id].placename) + end;
	net.primary_schools[u.primary_school_id].schoolmates.push_back(new_id);
	s += _T("用户小学:") + CString(net.primary_schools[u.primary_school_id].schoolname) + end;
	net.primary_schools[u.primary_school_id].schoolmates.push_back(new_id);
	s += _T("用户中学:") + CString(net.middle_schools[u.middle_school_id].schoolname) + end;
	net.universities[u.university_id].schoolmates.push_back(new_id);
	s += _T("用户大学:") + CString(net.universities[u.university_id].schoolname) + end;
	net.WorkPlaces[u.workplace_id].placemates.push_back(new_id);
	s += _T("用户工作单位:") + CString(net.WorkPlaces[u.workplace_id].placename) + end;
	s += _T("用户好友:");
	for (int k = 0; k < u.friends.size(); k++)
	{
		int friend_id = u.friends[k];
		net.Users[friend_id].friends.push_back(net.Users.size() - 1);
		s += CString(net.Users[friend_id].username) + _T(", ");
	}
	s += end;
	s += _T("用户群组:");
	for (int k = 0; k < u.groups.size(); k++)
	{
		int group_id = u.groups[k];
		net.Groups[group_id].groupmates.push_back(net.Groups.size() - 1);
		s += CString(net.Groups[group_id].groupname) + _T(", ");
	}
	s += end;
	s += _T("用户爱好:");
	for (int k = 0; k < u.hobbies.size(); k++)
	{
		int hobby_id = u.hobbies[k];
		net.Hobbies[hobby_id].hobbymates.push_back(net.Hobbies.size() - 1);
		s += CString(net.Hobbies[u.hobbies[k]].hobbyname) + _T(", ");
	}
	s += end;
	s += end;
	SetDlgItemText(IDC_SHOW, s);
}


void CSocialNetDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	ChoosePerson dlg2;
	dlg2.message = _T("选择用户");
	int Usernum = net.Users.size();
	for (int i = 0; i < Usernum; i++)
	{
		dlg2.usernames += CString(net.Users[i].username) + _T("#");
	}
	dlg2.DoModal();
	int user_id = dlg2.user_id;

	DisplayNetDlg dlg3;
	int is_friend[100] = { 0 },friend_num=net.Users[user_id].friends.size();
	is_friend[user_id] = 1;
	for (int i = 0; i < friend_num; i++)
	{
		is_friend[net.Users[user_id].friends[i]] = 1;
	}
	for (int i = 0; i < Usernum; i++)
	{
		if (!is_friend[i])
		{
			dlg3.friendnames += CString(net.Users[i].username) + _T("#");
		}
	}
	dlg3.user_num = net.Users.size();
	dlg3.friend_num = friend_num;
	dlg3.user_id = user_id;
	net.Recommend(user_id, dlg3.user_score, dlg3.match_degree);
	dlg3.DoModal();
	int newfriend_num = dlg3.newfriends.size();
	for (int i = 0; i < newfriend_num; i++)
	{
		net.Users[user_id].friends.push_back(dlg3.newfriends[i]);
	}
}

void CSocialNetDlg::process(double& x,double& y,double& x1,double& y1)
{
	int dx = int(x1 - x), dy = int(y1 - y);
	double k = r / sqrt(dx * dx + dy * dy);
	x += k * dx;
	y += k * dy;
	x1 -= k * dx;
	y1 -= k * dy;
}
void CSocialNetDlg::PrintSocialNet(CDC* pDC, int x0, int y0, int user_id, bool is_delay, int delay_time)
{
	// TODO: 在此处添加实现代码.
	int user_num = net.Users.size();
	double alpha = 0.0;
	int r_num = 0;
	CString str;
	if (user_id != -1)
	{
		net.Users[user_id].x = x0;
		net.Users[user_id].y = y0;
		pDC->Ellipse(x0 - r, y0 - r, x0 + r, y0 + r);
		str = CString(net.Users[user_id].username);
		pDC->TextOutW(net.Users[user_id].x - 20, net.Users[user_id].y - 5, str);
	}
	for (int i = 0; i < user_num; i++)
	{
		if (user_id == i)continue;
		if (is_delay)Sleep(delay_time);
		r_num = i / NUM;
		alpha = 360 / NUM * i + (r_num % 2 ? (180 / NUM) : 0);
		net.Users[i].x = x0 + int((0.5 * r_num + 1) * R * cos(alpha * pi / 180.0));
		net.Users[i].y = y0 + int((0.5 * r_num + 1) * R * sin(alpha * pi / 180.0));
		pDC->Ellipse(net.Users[i].x - 30, net.Users[i].y - 30, net.Users[i].x + 30, net.Users[i].y + 30);
		str = CString(net.Users[i].username);
		pDC->TextOutW(net.Users[i].x - 20, net.Users[i].y - 5, str);
	}
	if (is_delay)Sleep(delay_time);
	if (user_id == -1)
	{
		for (int i = 0; i < user_num; i++)
		{
			int friend_num = net.Users[i].friends.size();
			for (int j = 0; j < friend_num; j++)
			{
				int id = net.Users[i].friends[j];
				if (i < id)
				{
					double x = double(net.Users[i].x);
					double y = double(net.Users[i].y);
					double x1 = double(net.Users[id].x);
					double y1 = double(net.Users[id].y);
					process(x, y, x1, y1);
					pDC->MoveTo(int(x), int(y));
					pDC->LineTo(int(x1), int(y1));
				}
			}
		}
	}
	else
	{
		int friend_num = net.Users[user_id].friends.size();
		for (int j = 0; j < friend_num; j++)
		{
			int id = net.Users[user_id].friends[j];
			double x = double(net.Users[user_id].x);
			double y = double(net.Users[user_id].y);
			double x1 = double(net.Users[id].x);
			double y1 = double(net.Users[id].y);
			process(x, y, x1, y1);
			pDC->MoveTo(int(x), int(y));
			pDC->LineTo(int(x1), int(y1));
		}
	}
}
void CSocialNetDlg::PrintRecommend(CDC* pDC, int x0, int y0, CPen& pen_red, CPen& pen_green, int user_id, bool is_delay, int delay_time)
{
	// TODO: 在此处添加实现代码.
	int user_num = net.Users.size();
	int friend_num = net.Users[user_id].friends.size();
	double alpha = 0.0;
	int r_num = 0;
	CString str;
	pDC->SelectObject(&pen_red);
	net.Users[user_id].x = x0;
	net.Users[user_id].y = y0;
	pDC->Ellipse(x0 - r, y0 - r, x0 + r, y0 + r);
	str = CString(net.Users[user_id].username);
	pDC->TextOutW(net.Users[user_id].x - 20, net.Users[user_id].y - 5, str);
	pDC->SelectObject(&pen_green);
	for (int i = 0; i < friend_num; i++)
	{
		if (is_delay)Sleep(delay_time);
		int id = net.Users[user_id].friends[i];
		r_num = i / NUM;
		alpha = 360 / NUM * i + (r_num % 2 ? (180 / NUM) : 0);
		net.Users[id].x = x0 + int((0.5 * r_num + 1) * R * cos(alpha * pi / 180.0));
		net.Users[id].y = y0 + int((0.5 * r_num + 1) * R * sin(alpha * pi / 180.0));
		pDC->Ellipse(net.Users[id].x - 30, net.Users[id].y - 30, net.Users[id].x + 30, net.Users[id].y + 30);
		str = CString(net.Users[id].username);
		pDC->TextOutW(net.Users[id].x - 20, net.Users[id].y - 5, str);
		if (is_delay)Sleep(delay_time);
		double x = double(net.Users[user_id].x);
		double y = double(net.Users[user_id].y);
		double x1 = double(net.Users[id].x);
		double y1 = double(net.Users[id].y);
		process(x, y, x1, y1);
		pDC->MoveTo(int(x), int(y));
		pDC->LineTo(int(x1), int(y1));
	}
}
void CSocialNetDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CRect rect;
	CWnd* pWin = GetDlgItem(IDC_STATIC);
	pWin->GetClientRect(rect);
	int x = rect.Width();
	int y = rect.Height();
	CDC* pDC = pWin->GetDC();
	CPen pen(PS_SOLID, 3, RGB(0, 0, 0));
	pDC->SelectObject(&pen);
	PrintSocialNet(pDC, x / 2, y / 2);
}


void CSocialNetDlg::OnInituser()
{
	// TODO: 在此添加命令处理程序代码
	OnBnClickedButton2();
}


void CSocialNetDlg::OnNewschool()
{
	// TODO: 在此添加命令处理程序代码
	NewAttri dlg;
	dlg.isschool = true;
	dlg.message = _T("学校名称");
	dlg.DoModal();
	School newschool;
	memcpy(newschool.schoolname, dlg.name.c_str(), sizeof(dlg.name.c_str()));
	if (dlg.school_choice == 0)
	{
		newschool.serial_num = net.primary_schools.size();
		net.primary_schools.push_back(newschool);
	}
	else if (dlg.school_choice == 1)
	{
		newschool.serial_num = net.middle_schools.size();
		net.middle_schools.push_back(newschool);
	}
	else
	{
		newschool.serial_num = net.universities.size();
		net.universities.push_back(newschool);
	}
}


void CSocialNetDlg::OnNewplace()
{
	// TODO: 在此添加命令处理程序代码
	NewAttri dlg;
	dlg.isschool = false;
	dlg.message = _T("地区名称");
	dlg.DoModal();
	Place newplace;
	memcpy(newplace.placename, dlg.name.c_str(), sizeof(dlg.name.c_str()));
	newplace.serial_num = net.Places.size();
	net.Places.push_back(newplace);
}


void CSocialNetDlg::OnNewgroup()
{
	// TODO: 在此添加命令处理程序代码
	NewAttri dlg;
	dlg.isschool = false;
	dlg.message = _T("群组名称");
	dlg.DoModal();
	Group newgroup;
	memcpy(newgroup.groupname, dlg.name.c_str(), sizeof(dlg.name.c_str()));
	newgroup.serial_num = net.Groups.size();
	net.Groups.push_back(newgroup);
}


void CSocialNetDlg::OnNewworkplace()
{
	// TODO: 在此添加命令处理程序代码
	NewAttri dlg;
	dlg.isschool = false;
	dlg.message = _T("工作单位名称");
	dlg.DoModal();
	Place newworkplace;
	memcpy(newworkplace.placename, dlg.name.c_str(), sizeof(dlg.name.c_str()));
	newworkplace.serial_num = net.WorkPlaces.size();
	net.WorkPlaces.push_back(newworkplace);
}


void CSocialNetDlg::OnHobbymate()
{
	// TODO: 在此添加命令处理程序代码
	ChoosePerson dlg;
	dlg.message = _T("选择爱好");
	int Hobbynum = net.Hobbies.size();
	for (int i = 0; i < Hobbynum; i++)
	{
		dlg.usernames += CString(net.Hobbies[i].hobbyname) + _T("#");
	}
	dlg.DoModal();
	int hobby_id=dlg.user_id;
	Hobby& h = net.Hobbies[hobby_id];
	CString ans = _T("爱好名称：") + CString(h.hobbyname)+_T("\n相同爱好用户名称：\n");
	for (int i = 0; i < h.hobbymates.size(); i++)
	{
		int user_id = h.hobbymates[i];
		ans += CString(net.Users[user_id].username)+_T("\n");
	}
	MessageBox(ans);
}


void CSocialNetDlg::OnGroupmate()
{
	// TODO: 在此添加命令处理程序代码
	ChoosePerson dlg;
	dlg.message = _T("选择群组");
	int Groupnum = net.Groups.size();
	for (int i = 0; i < Groupnum; i++)
	{
		dlg.usernames += CString(net.Groups[i].groupname) + _T("#");
	}
	dlg.DoModal();
	int group_id = dlg.user_id;
	Group& g = net.Groups[group_id];
	CString ans = _T("群组名称：") + CString(g.groupname) + _T("\n相同群组用户名称：\n");
	for (int i = 0; i < g.groupmates.size(); i++)
	{
		int user_id = g.groupmates[i];
		ans += CString(net.Users[user_id].username) + _T("\n");
	}
	MessageBox(ans);
}


void CSocialNetDlg::OnPlacemate()
{
	// TODO: 在此添加命令处理程序代码
	ChoosePerson dlg;
	dlg.message = _T("选择地区");
	int Placenum = net.Places.size();
	for (int i = 0; i < Placenum; i++)
	{
		dlg.usernames += CString(net.Places[i].placename) + _T("#");
	}
	dlg.DoModal();
	int place_id = dlg.user_id;
	Place& p = net.Places[place_id];
	CString ans = _T("地区名称：") + CString(p.placename) + _T("\n相同地区用户名称：\n");
	for (int i = 0; i < p.placemates.size(); i++)
	{
		int user_id = p.placemates[i];
		ans += CString(net.Users[user_id].username) + _T("\n");
	}
	MessageBox(ans);
}

void CSocialNetDlg::OnWorkplacemate()
{
	// TODO: 在此添加命令处理程序代码
	ChoosePerson dlg;
	dlg.message = _T("选择工作地点");
	int Workplacenum = net.WorkPlaces.size();
	for (int i = 0; i < Workplacenum; i++)
	{
		dlg.usernames += CString(net.WorkPlaces[i].placename) + _T("#");
	}
	dlg.DoModal();
	int place_id = dlg.user_id;
	Place& p = net.WorkPlaces[place_id];
	CString ans = _T("工作地点名称：") + CString(p.placename) + _T("\n相同工作地点用户名称：\n");
	for (int i = 0; i < p.placemates.size(); i++)
	{
		int user_id = p.placemates[i];
		ans += CString(net.Users[user_id].username) + _T("\n");
	}
	MessageBox(ans);
}


void CSocialNetDlg::OnSchool1()
{
	// TODO: 在此添加命令处理程序代码
	ChoosePerson dlg;
	dlg.message = _T("选择学校");
	int Schoolnum = net.primary_schools.size();
	for (int i = 0; i < Schoolnum; i++)
	{
		dlg.usernames += CString(net.primary_schools[i].schoolname) + _T("#");
	}
	dlg.DoModal();
	int school_id = dlg.user_id;
	School& s = net.primary_schools[school_id];
	CString ans = _T("学校名称：") + CString(s.schoolname) + _T("\n相同学校用户名称：\n");
	for (int i = 0; i < s.schoolmates.size(); i++)
	{
		int user_id = s.schoolmates[i];
		ans += CString(net.Users[user_id].username) + _T("\n");
	}
	MessageBox(ans);
}


void CSocialNetDlg::OnSchool2()
{
	// TODO: 在此添加命令处理程序代码
	ChoosePerson dlg;
	dlg.message = _T("选择学校");
	int Schoolnum = net.middle_schools.size();
	for (int i = 0; i < Schoolnum; i++)
	{
		dlg.usernames += CString(net.middle_schools[i].schoolname) + _T("#");
	}
	dlg.DoModal();
	int school_id = dlg.user_id;
	School& s = net.middle_schools[school_id];
	CString ans = _T("学校名称：") + CString(s.schoolname) + _T("\n相同学校用户名称：\n");
	for (int i = 0; i < s.schoolmates.size(); i++)
	{
		int user_id = s.schoolmates[i];
		ans += CString(net.Users[user_id].username) + _T("\n");
	}
	MessageBox(ans);
}


void CSocialNetDlg::OnSchool3()
{
	// TODO: 在此添加命令处理程序代码
	ChoosePerson dlg;
	dlg.message = _T("选择学校");
	int Schoolnum = net.universities.size();
	for (int i = 0; i < Schoolnum; i++)
	{
		dlg.usernames += CString(net.universities[i].schoolname) + _T("#");
	}
	dlg.DoModal();
	int school_id = dlg.user_id;
	School& s = net.universities[school_id];
	CString ans = _T("学校名称：") + CString(s.schoolname) + _T("\n相同学校用户名称：\n");
	for (int i = 0; i < s.schoolmates.size(); i++)
	{
		int user_id = s.schoolmates[i];
		ans += CString(net.Users[user_id].username) + _T("\n");
	}
	MessageBox(ans);
}
