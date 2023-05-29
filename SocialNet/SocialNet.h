	
// SocialNet.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once
#define MOD 1007
#include<iostream>
#include<algorithm>
#include<cstring>
#include"vector.h"//自己写的vector
#include"Dict.h"
using namespace std;

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CSocialNetApp:
// 有关此类的实现，请参阅 SocialNet.cpp
//

class CSocialNetApp : public CWinApp
{
public:
	CSocialNetApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CSocialNetApp theApp;


int Hash(char s[]);
struct User
{
	char username[20];//用户名称
	int place_id;//地区序号
	int primary_school_id;//小学序号
	int middle_school_id;//中学序号
	int university_id;//大学序号
	int workplace_id;//工作单位序号
	vector<int> friends;//存储个人好友的序号，例如：好友1，好友2
	vector<int> groups;//存储包含于群组的序号，例如：1，2，3
	vector<int> hobbies;//兴趣爱好序号
	int x, y;
	User() :friends(), groups(), hobbies() 
	{ 
		memset(username, 0, sizeof(username));
		place_id = primary_school_id = middle_school_id = university_id = workplace_id = 0;
		x = y = 0;
	}
};
struct Place
{
	char placename[20];//地区名称
	int serial_num;//该地区的序号
	vector<int> placemates;//存储地区里面的人员序号，便于寻找附近的人
	Place() :placemates() 
	{ 
		memset(placename, 0, sizeof(placename)); 
		serial_num = 0; 
	}
};
struct School
{
	char schoolname[20];//学校名称
	int serial_num;//学校的序号
	vector<int> schoolmates;//存储学校里面的人员序号，便于寻找校友
	School() :schoolmates()
	{
		memset(schoolname, 0, sizeof(schoolname));
		serial_num = 0;
	}
};
struct Group
{
	char groupname[20];//群的名称
	int serial_num;//群组的序号
	vector<int> groupmates;//存储群组里面的人员序号，便于寻找群友
	Group() :groupmates()
	{
		memset(groupname, 0, sizeof(groupname));
		serial_num = 0;
	}
};
struct Hobby
{
	char hobbyname[20];//爱好的名称
	int serial_num;//爱好的序号
	vector<int> hobbymates;//存储相同爱好的人员序号，便于寻找相同爱好的人
	Hobby() :hobbymates()
	{
		memset(hobbyname, 0, sizeof(hobbyname));
		serial_num = 0;
	}
};
struct Score
{
	char name[20];
	int serial_num;
	int score;
	bool is_friend;
	Score() 
	{ 
		memset(name, 0, sizeof(name)); 
		serial_num = score = 0;
		is_friend = false;
	}
};
bool cmp(Score& s1, Score& s2);
struct SocialNet
{
	const int user_init_num = 10;
	const int group_init_num = 3;
	const int place_init_num = 4;
	const int primary_school_init_num = 3;
	const int middle_school_init_num = 3;
	const int university_init_num = 2;
	const int workplace_init_num = 5;
	const int hobby_init_num = 9;
	const char hobby_names[9][20] = {"游泳","编程","跑步","足球","电子游戏","钓鱼","篮球","阅读" ,"欣赏电影"};
	Dict<int,int> scores;
	vector<User> Users;
	vector<Place> Places;
	vector<School> primary_schools;
	vector<School> middle_schools;
	vector<School> universities;
	vector<Place> WorkPlaces;
	vector<Group> Groups;
	vector<Hobby> Hobbies;
	SocialNet()
		:scores(), Users(), Places(), primary_schools(), middle_schools(), universities(), Groups(), Hobbies()
	{
		scores.insert(Hash("placemate"), 20);
		scores.insert(Hash("schoolmate"), 20);
		scores.insert(Hash("workplacemate"), 30);
		scores.insert(Hash("friend"), 50);
		scores.insert(Hash("groupmate"), 10);
		scores.insert(Hash("hobbymate"), 30);
		init();
	}
	void random(vector<int>& ids, int num);
	void init();
	void AddUser(const User& u);
	void AddPlace(const Place& p);
	void AddSchool(const School& s, int flag);
	void AddGroup(const Group& g);
	void AddWorkPlace(const Place& wp);
	void DisplayUserNet();
	void Recommend(int user_id, Score*& user_score, Score*& match_degree);
};
