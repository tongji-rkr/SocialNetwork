// NewAttri.cpp: 实现文件
//

#include "pch.h"
#include "SocialNet.h"
#include "afxdialogex.h"
#include "NewAttri.h"
#include<cstring>


// NewAttri 对话框

IMPLEMENT_DYNAMIC(NewAttri, CDialogEx)

NewAttri::NewAttri(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

NewAttri::~NewAttri()
{
}

void NewAttri::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, edit);
}


BEGIN_MESSAGE_MAP(NewAttri, CDialogEx)
	ON_BN_CLICKED(IDOK, &NewAttri::OnBnClickedOk)
END_MESSAGE_MAP()


// NewAttri 消息处理程序


BOOL NewAttri::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (isschool)
	{
		GetDlgItem(IDC_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO1)->ShowWindow(SW_SHOW);
		edit.AddString(_T("小学"));
		edit.AddString(_T("中学"));
		edit.AddString(_T("大学"));
		edit.SetCurSel(0);
	}
	SetDlgItemText(IDC_STATIC, _T("学校种类"));
	SetDlgItemText(IDC_STATIC2, message);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void NewAttri::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if(isschool)
		 school_choice= ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	CString name1;
	GetDlgItem(IDC_EDIT1)->GetWindowText(name1);
	name = CT2A(name1.GetString());
	CDialogEx::OnOK();
}
