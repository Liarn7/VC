
// Week8(1)View.cpp : CWeek81View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week8(1).h"
#endif

#include "Week8(1)Doc.h"
#include "Week8(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek81View

IMPLEMENT_DYNCREATE(CWeek81View, CView)

BEGIN_MESSAGE_MAP(CWeek81View, CView)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CWeek81View 构造/析构

CWeek81View::CWeek81View()
{
	// TODO: 在此处添加构造代码

}

CWeek81View::~CWeek81View()
{
}

BOOL CWeek81View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWeek81View 绘制

void CWeek81View::OnDraw(CDC* /*pDC*/)
{
	CWeek81Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CWeek81View 诊断

#ifdef _DEBUG
void CWeek81View::AssertValid() const
{
	CView::AssertValid();
}

void CWeek81View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek81Doc* CWeek81View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek81Doc)));
	return (CWeek81Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek81View 消息处理程序


void CWeek81View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r == IDOK) {
		CString filename = cfd.GetPathName();
		dc.TextOutW(200, 300, filename);
	}
	CView::OnLButtonDblClk(nFlags, point);
}
