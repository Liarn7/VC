
// MFC9View.cpp : CMFC9View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC9.h"
#endif

#include "MFC9Doc.h"
#include "MFC9View.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC9View

IMPLEMENT_DYNCREATE(CMFC9View, CView)

BEGIN_MESSAGE_MAP(CMFC9View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFC9View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &CMFC9View::OnFileSave)
	ON_COMMAND(ID_POPOUT, &CMFC9View::OnPopout)
END_MESSAGE_MAP()

// CMFC9View ����/����

CMFC9View::CMFC9View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC9View::~CMFC9View()
{
}

BOOL CMFC9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC9View ����

void CMFC9View::OnDraw(CDC* /*pDC*/)
{
	CMFC9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

}


// CMFC9View ���

#ifdef _DEBUG
void CMFC9View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC9Doc* CMFC9View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC9Doc)));
	return (CMFC9Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC9View ��Ϣ�������


void CMFC9View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK) {
		CString filename = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		CClientDC dc(this);
		while (ifs >> s) {
			dc.TextOutW(10,10,CString(s.c_str()));
		}
		

	}
}


void CMFC9View::OnFileSave()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK) {
		ofstream ofs(cfd.GetPathName());
		CString s = cfd.GetPathName();
		ofs <<CT2A(s.GetString()) << endl;
	}
}


void CMFC9View::OnPopout()
{
	// TODO: �ڴ���������������
	MyDlg dlg;
	int r = dlg.DoModal();
	if (r==IDOK) {

	}
}
