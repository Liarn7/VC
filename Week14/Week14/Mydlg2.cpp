// Mydlg2.cpp : 实现文件
//

#include "stdafx.h"
#include "Week14.h"
#include "Mydlg2.h"
#include "afxdialogex.h"


// Mydlg2 对话框

IMPLEMENT_DYNAMIC(Mydlg2, CDialogEx)

Mydlg2::Mydlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, x(_T(""))
{

}

Mydlg2::~Mydlg2()
{
}

void Mydlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
}


BEGIN_MESSAGE_MAP(Mydlg2, CDialogEx)
END_MESSAGE_MAP()


// Mydlg2 消息处理程序
