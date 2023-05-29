// NewPersonDlg.cpp: 实现文件
//

#include "pch.h"
#include "SocialNet.h"
#include "afxdialogex.h"
#include "NewPersonDlg.h"
#include <string>


// NewPersonDlg 对话框

IMPLEMENT_DYNAMIC(NewPersonDlg, CDialogEx)

NewPersonDlg::NewPersonDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

NewPersonDlg::~NewPersonDlg()
{
}

void NewPersonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_COMBO1, edit1);
	DDX_Control(pDX, IDC_COMBO2, edit2);
	DDX_Control(pDX, IDC_COMBO3, edit3);
	DDX_Control(pDX, IDC_COMBO4, edit4);
	DDX_Control(pDX, IDC_COMBO5, edit5);
	DDX_Control(pDX, IDC_COMBO6, edit6);
}


BEGIN_MESSAGE_MAP(NewPersonDlg, CDialogEx)	
	ON_BN_CLICKED(IDOK, &NewPersonDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// NewPersonDlg 消息处理程序


void initCombo(CString& strSrc, CComboBox& edit)
{
	CString strGap = _T("#");
	int nPos = strSrc.Find(strGap);
	CString strLeft = _T("");

	while (0 <= nPos)
	{
		strLeft = strSrc.Left(nPos);
		if (!strLeft.IsEmpty())
		{
			edit.AddString(strLeft);
		}
		strSrc = strSrc.Right(strSrc.GetLength() - nPos - strGap.GetLength());
		nPos = strSrc.Find(strGap);
	}
	edit.SetCurSel(0);
}

BOOL NewPersonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	initCombo(placenames, edit2);
	initCombo(schoolnames1, edit3);
	initCombo(schoolnames2, edit4);
	initCombo(schoolnames3, edit5);
	initCombo(workplacenames, edit6);
	SetDlgItemText(IDC_EDIT2, friendnames);
	SetDlgItemText(IDC_EDIT4, groupnames);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void NewPersonDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString name;
	GetDlgItem(IDC_EDIT5)->GetWindowText(name);
	string p = CT2A(name.GetString()), p_num = "";
	int len = 0;
	memcpy(newuser.username, p.c_str(), sizeof(p.c_str()));
	newuser.place_id = ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetCurSel();
	newuser.primary_school_id = ((CComboBox*)GetDlgItem(IDC_COMBO3))->GetCurSel();
	newuser.middle_school_id = ((CComboBox*)GetDlgItem(IDC_COMBO4))->GetCurSel();
	newuser.university_id = ((CComboBox*)GetDlgItem(IDC_COMBO5))->GetCurSel();
	newuser.workplace_id = ((CComboBox*)GetDlgItem(IDC_COMBO6))->GetCurSel();
	GetDlgItem(IDC_EDIT1)->GetWindowText(name);
	p = CT2A(name.GetString());
	len = int(p.length());
	p_num = "";
	for (int i = 0; i < len; i++)
	{
		if (p[i] != ',')p_num += p[i];
		else
		{
			newuser.friends.push_back(stoi(p_num));
			p_num = "";
		}
	}
	if(p_num!="")newuser.friends.push_back(stoi(p_num));
	GetDlgItem(IDC_EDIT3)->GetWindowText(name);
	p = CT2A(name.GetString());
	len = int(p.length());
	p_num = "";
	for (int i = 0; i < len; i++)
	{
		if (p[i] != ',')p_num += p[i];
		else
		{
			newuser.groups.push_back(stoi(p_num));
			p_num = "";
		}
	}
	if (p_num != "")newuser.groups.push_back(stoi(p_num));
	if (((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
		newuser.hobbies.push_back(0);
	if (((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck())
		newuser.hobbies.push_back(1);
	if (((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck())
		newuser.hobbies.push_back(2);
	if (((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck())
		newuser.hobbies.push_back(3);
	if (((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck())
		newuser.hobbies.push_back(4);
	if (((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck())
		newuser.hobbies.push_back(5);
	if (((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck())
		newuser.hobbies.push_back(6);
	if (((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck())
		newuser.hobbies.push_back(7);
	if (((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck())
		newuser.hobbies.push_back(8);
	CDialogEx::OnOK();
}
