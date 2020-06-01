// Mydlg7.cpp : 实现文件
//

#include "stdafx.h"
#include "Week14.h"
#include "Mydlg7.h"
#include "afxdialogex.h"


// Mydlg7 对话框

IMPLEMENT_DYNAMIC(Mydlg7, CDialogEx)

Mydlg7::Mydlg7(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, a(_T(""))
	, b(_T(""))
	, c(_T(""))
	, d(_T(""))
{

}

Mydlg7::~Mydlg7()
{
}

void Mydlg7::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDX_Text(pDX, IDC_EDIT3, c);
	DDX_Text(pDX, IDC_EDIT4, d);
}


BEGIN_MESSAGE_MAP(Mydlg7, CDialogEx)
END_MESSAGE_MAP()


// Mydlg7 消息处理程序
