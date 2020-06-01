// Mydlg4.cpp : 实现文件
//

#include "stdafx.h"
#include "Week14.h"
#include "Mydlg4.h"
#include "afxdialogex.h"


// Mydlg4 对话框

IMPLEMENT_DYNAMIC(Mydlg4, CDialogEx)

Mydlg4::Mydlg4(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, y(_T(""))
{

}

Mydlg4::~Mydlg4()
{
}

void Mydlg4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, y);
}


BEGIN_MESSAGE_MAP(Mydlg4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Mydlg4::OnBnClickedButton1)
END_MESSAGE_MAP()


// Mydlg4 消息处理程序


void Mydlg4::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}
