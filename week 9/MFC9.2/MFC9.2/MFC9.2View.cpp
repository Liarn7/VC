
// MFC9.2View.cpp : CMFC92View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC9.2.h"
#endif

#include "MFC9.2Doc.h"
#include "MFC9.2View.h"
#include "fstream"
#include "string"
#include "iostream"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC92View

IMPLEMENT_DYNCREATE(CMFC92View, CView)

BEGIN_MESSAGE_MAP(CMFC92View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//ON_COMMAND(ID_FILE_OPEN, &CMFC92View::OnFileOpen)
END_MESSAGE_MAP()

// CMFC92View ����/����

CMFC92View::CMFC92View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC92View::~CMFC92View()
{
}

BOOL CMFC92View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC92View ����

void CMFC92View::OnDraw(CDC* pDC)
{
	CMFC92Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	pDC->Ellipse(pDoc->re);
	for (int i = 0; i < pDoc->ca.GetSize(); i++) {
		pDC->Ellipse(pDoc->ca[i]);
	}
}


// CMFC92View ���

#ifdef _DEBUG
void CMFC92View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC92View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC92Doc* CMFC92View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC92Doc)));
	return (CMFC92Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC92View ��Ϣ�������


void CMFC92View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC92Doc* pDoc = GetDocument();
	pDoc->re.left = point.x;
	pDoc->re.top = point.y;
	pDoc->a = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC92View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC92Doc* pDoc = GetDocument();
	if (pDoc->a) {
        pDoc->re.right = point.x;
	    pDoc->re.bottom = point.y;
		InvalidateRect(pDoc->re);
	}
	CView::OnMouseMove(nFlags, point);
}


void CMFC92View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC92Doc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->re.right = point.x;
	pDoc->re.bottom = point.y;
	pDoc->a = 0;
	pDoc->ca.Add(pDoc->re);
	int b = pDoc->ca.GetSize();
	dc.Ellipse(pDoc->ca[b-1]);
	CView::OnLButtonUp(nFlags, point);
}


//void CMFC92View::Serialize(CArchive& ar)
//{
//	CMFC92Doc* pDoc = GetDocument();
//	CClientDC dc(this);
//    pDoc->ca.Serialize(ar);
//	if (ar.IsStoring())
//	{	// storing code
//		for (int i = 0; i < pDoc->ca.GetSize(); i++) {
//			/*ar << pDoc->ca[i];*/ar << pDoc->ca[i].left<< pDoc->ca[i].top<< pDoc->ca[i].right<< pDoc->ca[i].bottom;	
//		} 	
//
//	}
//	else
//	{	// loading code	
//		for (int i = 0; i < pDoc->ca.GetSize(); i++) {
//            /*ar >> pDoc->ca[i];*/ar >> pDoc->ca[i].left >> pDoc->ca[i].top >> pDoc->ca[i].right >> pDoc->ca[i].bottom;
//			dc.Ellipse(pDoc->ca[i]);
//		}
//			
//	}
//	
//	/*for (int i = 0; i < pDoc->ca.GetSize(); i++) {
//		ar >> pDoc->re;
//	}*/
//}


/*void CMFC92View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CMFC92Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK){
		CString filename = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		for (int i = 0; i < pDoc->ca.GetSize(); i++) {
			dc.Ellipse(pDoc->ca[i]);
		}
	}

}*/
