// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Week8(3).h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include "Week8(3)Doc.h"
#include "Week8(3)View.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, x);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
//	this->UpdateData(true);
		x.AddString(t);
	//	UpdateData(false);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void MyDlg::OnBnClickedButton1()
{
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r == IDOK) {
		this->UpdateData(true);
		t = cfd.GetPathName();
		x.AddString(t);
		UpdateData(false);
	}
	// TODO: 在此添加控件通知处理程序代码
}
