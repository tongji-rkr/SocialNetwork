// ChoosePerson.cpp: 实现文件
//

#include "pch.h"
#include "SocialNet.h"
#include "afxdialogex.h"
#include "ChoosePerson.h"
#include "NewPersonDlg.h"


// ChoosePerson 对话框

IMPLEMENT_DYNAMIC(ChoosePerson, CDialogEx)

ChoosePerson::ChoosePerson(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

ChoosePerson::~ChoosePerson()
{
}

void ChoosePerson::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, edit);
}


BEGIN_MESSAGE_MAP(ChoosePerson, CDialogEx)
	ON_BN_CLICKED(IDOK, &ChoosePerson::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ChoosePerson::OnBnClickedCancel)
END_MESSAGE_MAP()


// ChoosePerson 消息处理程序


void ChoosePerson::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	user_id=((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetLBText(user_id, newfriendname);
	CDialogEx::OnOK();
}


BOOL ChoosePerson::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetDlgItemText(IDC_STATIC, message);
	initCombo(usernames, edit);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ChoosePerson::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
