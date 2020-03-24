
// Week5(3)View.cpp: CWeek53View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week5(3).h"
#endif

#include "Week5(3)Doc.h"
#include "Week5(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek53View

IMPLEMENT_DYNCREATE(CWeek53View, CView)

BEGIN_MESSAGE_MAP(CWeek53View, CView)
	ON_COMMAND(ID_32771, &CWeek53View::On32771)
	ON_COMMAND(ID_32772, &CWeek53View::On32772)
	ON_COMMAND(ID_32773, &CWeek53View::On32773)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
//	ON_WM_MOVE()
END_MESSAGE_MAP()

// CWeek53View 构造/析构

CWeek53View::CWeek53View() noexcept
{
	// TODO: 在此处添加构造代码

}

CWeek53View::~CWeek53View()
{
}

BOOL CWeek53View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWeek53View 绘图

void CWeek53View::OnDraw(CDC* pDC)
{
	CWeek53Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->rect);
	pDC->Ellipse(pDoc->circle);
	pDC->MoveTo(pDoc->point1);
	pDC->LineTo(pDoc->point2);

	// TODO: 在此处为本机数据添加绘制代码
}


// CWeek53View 诊断

#ifdef _DEBUG
void CWeek53View::AssertValid() const
{
	CView::AssertValid();
}

void CWeek53View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek53Doc* CWeek53View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek53Doc)));
	return (CWeek53Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek53View 消息处理程序


void CWeek53View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	CWeek53Doc* pDoc = GetDocument();
	pDoc->n = 1;
}


void CWeek53View::On32772()
{
	
	// TODO: 在此添加命令处理程序代码
	CWeek53Doc* pDoc = GetDocument();
	pDoc->n = 2;
}


void CWeek53View::On32773()
{
	// TODO: 在此添加命令处理程序代码
	CWeek53Doc* pDoc = GetDocument();
	pDoc->n = 3;
}


void CWeek53View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CWeek53Doc* pDoc = GetDocument();
	if (pDoc->n == 1) {
		pDoc->point1.x = point.x;
		pDoc->point1.y = point.y;

	}
	if (pDoc->n ==3) {
		pDoc->rect.left = point.x;
		pDoc->rect.top = point.y;
	}
	if (pDoc->n == 2) {
		pDoc->circle.left = point.x;
		pDoc->circle.top = point.y;
	}
	CView::OnLButtonDown(nFlags, point);

	
}


void CWeek53View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CWeek53Doc* pDoc = GetDocument();
	if (pDoc->n == 1) {
		pDoc->point2.x = point.x;
		pDoc->point2.y = point.y;
	}
	if (pDoc->n == 3) {
		pDoc->rect.right = point.x;
		pDoc->rect.bottom = point.y;
	}
	if (pDoc->n == 2) {
		pDoc->circle.right = point.x;
		pDoc->circle.bottom = point.y;
	}
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
	
}


