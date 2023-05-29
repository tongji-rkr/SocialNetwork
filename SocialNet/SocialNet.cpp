
// SocialNet.cpp: 定义应用程序的类行为。
//

#include "pch.h"
#include "framework.h"
#include "SocialNet.h"
#include "SocialNetDlg.h"
#include<ctime>
#include<cstring>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSocialNetApp

BEGIN_MESSAGE_MAP(CSocialNetApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CSocialNetApp 构造

CSocialNetApp::CSocialNetApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的 CSocialNetApp 对象

CSocialNetApp theApp;


// CSocialNetApp 初始化

BOOL CSocialNetApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 激活“Windows Native”视觉管理器，以便在 MFC 控件中启用主题
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CSocialNetDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
		TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

bool cmp(Score& s1, Score& s2)
{
	return s1.score > s2.score;
}
int Hash(char s[])
{
	int ans = 0;
	for (int i = 0; s[i]; i++)
	{
		ans = (ans * 123 + int(s[i])) % MOD;
	}
	return ans;
}
void SocialNet::random(vector<int>& ids,int num)//self的意义是产生除自身的随机数,用于初始化
{
	int startArray[100] = { 0 };
	for (int i = 0; i < num; i++)
	{
		startArray[i] = i;
	}
	int m = (num - 1) / 2;
	int N = rand() % num > m ? m : m + 1;//好友一半可能是4个，一半可能是3个 
	for (int i = 0; i < N; i++)
	{
		int seed = rand() % (num - i);
		ids.push_back(startArray[seed]);
		startArray[seed] = startArray[num - i - 1];//把随机数产生过的位置替换为未被选中的值。  
	}
}
void SocialNet::init()
{
	srand(unsigned int(time(NULL)));
	//初始化地区
	for (int i = 0; i < place_init_num; i++)
	{
		Place p;
		p.serial_num = i;
		char str[5] = "地区";
		memcpy(p.placename, str, sizeof(str));
		p.placename[4] = char('a' + i);
		p.placename[5] = '\0';
		Places.push_back(p);
	}
	//初始化小学
	for (int i = 0; i < primary_school_init_num; i++)
	{
		School s;
		s.serial_num = i;
		char str[5] = "小学";
		memcpy(s.schoolname, str, sizeof(str));
		s.schoolname[4] = char('a' + i);
		s.schoolname[5] = '\0';
		primary_schools.push_back(s);
	}
	//初始化小学
	for (int i = 0; i < middle_school_init_num; i++)
	{
		School s;
		s.serial_num = i;
		char str[5] = "中学";
		memcpy(s.schoolname, str, sizeof(str));
		s.schoolname[4] = char('a' + i);
		s.schoolname[5] = '\0';
		middle_schools.push_back(s);
	}
	//初始化小学
	for (int i = 0; i < university_init_num; i++)
	{
		School s;
		s.serial_num = i;
		char str[5] = "大学";
		memcpy(s.schoolname, str, sizeof(str));
		s.schoolname[4] = char('a' + i);
		s.schoolname[5] = '\0';
		universities.push_back(s);
	}
	//初始化工作单位
	for (int i = 0; i < workplace_init_num; i++)
	{
		Place p;
		p.serial_num = i;
		char str[5] = "公司";
		memcpy(p.placename, str, sizeof(str));
		p.placename[4] = char('a' + i);
		p.placename[5] = '\0';
		WorkPlaces.push_back(p);
	}
	//初始化群组
	for (int i = 0; i < group_init_num; i++)
	{
		Group g;
		g.serial_num = i;
		char str[5] = "群组";
		memcpy(g.groupname, str, sizeof(str));
		g.groupname[4] = char('a' + i);
		g.groupname[5] = '\0';
		Groups.push_back(g);
	}
	//初始化爱好
	for (int i = 0; i < hobby_init_num; i++)
	{
		Hobby h;
		h.serial_num = i;
		memcpy(h.hobbyname, hobby_names[i], sizeof(hobby_names[i]));
		Hobbies.push_back(h);
	}
	//初始化用户
	for (int i = 0; i < user_init_num; i++)
	{
		User u;
		char str[5] = "用户";
		memcpy(u.username, str, sizeof(str));
		u.username[4] = char('a' + i);
		u.username[5] = '\0';
		//添加地区
		u.place_id = rand() % place_init_num;
		Places[u.place_id].placemates.push_back(i);
		//添加小学
		u.primary_school_id = rand() % primary_school_init_num; 
		primary_schools[u.primary_school_id].schoolmates.push_back(i);
		//添加中学
		u.middle_school_id = rand() % middle_school_init_num;
		middle_schools[u.middle_school_id].schoolmates.push_back(i);
		//添加大学
		u.university_id = rand() % university_init_num;
		universities[u.university_id].schoolmates.push_back(i);
		//添加工作单位
		u.workplace_id = rand() % workplace_init_num;
		WorkPlaces[u.workplace_id].placemates.push_back(i);
		//添加群组
		random(u.groups, group_init_num);
		for (int j = 0; j < u.groups.size(); j++)
		{
			Groups[u.groups[j]].groupmates.push_back(i);
		}
		//添加爱好
		random(u.hobbies, hobby_init_num);
		for (int j = 0; j < u.hobbies.size(); j++)
		{
			Hobbies[u.hobbies[j]].hobbymates.push_back(i);
		}
		Users.push_back(u);
	}
	//添加好友关系
	for (int i = 0; i < user_init_num; i++)
	{
		for (int j = i + 1; j < user_init_num; j++)
		{
			if (rand() % 2)
			{
				Users[i].friends.push_back(j);
				Users[j].friends.push_back(i);
			}
		}
	}
}
void SocialNet::AddUser(const User& u)
{
	Users.push_back(u);
}
void SocialNet::AddPlace(const Place& p)
{
	Places.push_back(p);
}
void SocialNet::AddSchool(const School& s, int flag)
{
	if (flag == 1)
		primary_schools.push_back(s);
	else if (flag == 2)
		middle_schools.push_back(s);
	else
		universities.push_back(s);
}
void SocialNet::AddGroup(const Group& g)
{
	Groups.push_back(g);
}
void SocialNet::AddWorkPlace(const Place& wp)
{
	WorkPlaces.push_back(wp);
}
void SocialNet::Recommend(int user_id,Score*& user_score,Score*& match_degree)
{
	int user_num = Users.size();
	user_score = new Score[user_num](); 
	match_degree = new Score[user_num]();
	User& u = Users[user_id];
	int friend_num = u.friends.size();
	int group_num = u.groups.size();
	int hobby_num = u.hobbies.size();
	int cnt = 0;
	user_score[user_id].is_friend = true;
	match_degree[user_id].is_friend = true;
	for (int i = 0; i < friend_num; i++)
	{
		user_score[u.friends[i]].is_friend = true;
		match_degree[u.friends[i]].is_friend = true;
	}
	for (int i = 0; i < user_num; i++)
	{
		memcpy(user_score[i].name, Users[i].username, sizeof(Users[i].username));
		user_score[i].serial_num = i;
		memcpy(match_degree[i].name, Users[i].username, sizeof(Users[i].username));
		match_degree[i].serial_num = i;
	}
	//地区
	cnt = Places[u.place_id].placemates.size();
	for (int i = 0; i < cnt; i++)
	{
		user_score[Places[u.place_id].placemates[i]].score += scores[Hash("placemate")];
	}
	//小学
	cnt = primary_schools[u.primary_school_id].schoolmates.size();
	for (int i = 0; i < cnt; i++)
	{
		user_score[primary_schools[u.primary_school_id].schoolmates[i]].score += scores[Hash("schoolmate")];
	}
	//中学
	cnt = middle_schools[u.middle_school_id].schoolmates.size();
	for (int i = 0; i < cnt; i++)
	{
		user_score[middle_schools[u.middle_school_id].schoolmates[i]].score += scores[Hash("schoolmate")];
	}
	//大学
	cnt = universities[u.university_id].schoolmates.size();
	for (int i = 0; i < cnt; i++)
	{
		user_score[universities[u.university_id].schoolmates[i]].score += scores[Hash("schoolmate")];
	}
	//工作单位
	cnt = WorkPlaces[u.workplace_id].placemates.size();
	for (int i = 0; i < cnt; i++)
	{
		user_score[WorkPlaces[u.workplace_id].placemates[i]].score += scores[Hash("workplacemate")];
	}
	//好友
	for (int i = 0; i < friend_num; i++)
	{
		cnt = Users[u.friends[i]].friends.size();
		for (int j = 0; j < cnt; j++)
		{
			user_score[Users[u.friends[i]].friends[j]].score += scores[Hash("friend")];
			match_degree[Users[u.friends[i]].friends[j]].score += 1;
		}
	}
	//群组
	for (int i = 0; i < group_num; i++)
	{
		cnt = Groups[i].groupmates.size();
		for (int j = 0; j < cnt; j++)
		{
			user_score[Groups[i].groupmates[j]].score += scores[Hash("groupmate")];
		}
	}
	//爱好
	for (int i = 0; i < hobby_num; i++)
	{
		cnt = Hobbies[i].hobbymates.size();
		for (int j = 0; j < cnt; j++)
		{
			user_score[Hobbies[i].hobbymates[j]].score += scores[Hash("hobbymate")];
		}
	}
	sort(user_score, user_score + user_num, cmp);
	sort(match_degree, match_degree + user_num, cmp);
}