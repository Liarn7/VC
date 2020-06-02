// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC9.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg �Ի���

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
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg ��Ϣ�������


BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void MyDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString filename;
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK) {
		filename = cfd.GetPathName();
		CImage img;
        img.Load(filename);
		int w, h, sx, sy;
		CRect rect;
		GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
		float rect_ratio = 1.0*rect.Width() / rect.Height();
		float img_ratio = 1.0* img.GetWidth() / img.GetHeight();
		if (rect_ratio > img_ratio)
		{
			h = rect.Height();
			w = img_ratio*h;
			sx = (rect.Width() - w) / 2;
			sy = 0;
		}
		else
		{
			w = rect.Width();
			h = w / img_ratio;
			sx = 0;
			sy = (rect.Height() - h) / 2;
		}	
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
		pDC->SetStretchBltMode(HALFTONE); //ͼ��ʧ��
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}

}
