
// Week6(1)View.cpp: CWeek61View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week6(1).h"
#endif

#include "Week6(1)Doc.h"
#include "Week6(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek61View

IMPLEMENT_DYNCREATE(CWeek61View, CView)

BEGIN_MESSAGE_MAP(CWeek61View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CWeek61View 构造/析构

CWeek61View::CWeek61View() noexcept
{
	// TODO: 在此处添加构造代码

}

CWeek61View::~CWeek61View()
{
}

BOOL CWeek61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWeek61View 绘图

void CWeek61View::OnDraw(CDC* pDC)
{
	CWeek61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->cr);
	//pDC->TextOutW(51,51, pDoc->s);
	// TODO: 在此处为本机数据添加绘制代码
}


// CWeek61View 诊断

#ifdef _DEBUG
void CWeek61View::AssertValid() const
{
	CView::AssertValid();
}

void CWeek61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek61Doc* CWeek61View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek61Doc)));
	return (CWeek61Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek61View 消息处理程序


void CWeek61View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CWeek61Doc* pDoc = GetDocument();
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	pDoc->s += TCHAR(nChar);
	CSize sz = dc.GetTextExtent(pDoc->s);
	CPoint pt;
	pt.x = pDoc->point .x+ sz.cx;
	pt.y = pDoc->point.y;
	SetCaretPos(pt);
	dc.TextOutW(pDoc->point.x, pDoc->point.y, pDoc->s);
	//Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CWeek61View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CWeek61Doc* pDoc = GetDocument();
	SetCaretPos(point);
	pDoc->s.Empty();
	pDoc->point = point;
	CView::OnLButtonDown(nFlags, point);
}


int CWeek61View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO:  在此添加您专用的创建代码
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CreateSolidCaret(tm.tmAveCharWidth / 8, tm.tmHeight);
	ShowCaret();
	return 0;
}
