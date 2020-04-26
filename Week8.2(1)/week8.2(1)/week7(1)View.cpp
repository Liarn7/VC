
// week7(1)View.cpp: Cweek71View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "week7(1).h"
#endif

#include "week7(1)Doc.h"
#include "week7(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cweek71View

IMPLEMENT_DYNCREATE(Cweek71View, CView)

BEGIN_MESSAGE_MAP(Cweek71View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cweek71View 构造/析构

Cweek71View::Cweek71View() noexcept
{
	// TODO: 在此处添加构造代码

}

Cweek71View::~Cweek71View()
{
}

BOOL Cweek71View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cweek71View 绘图

void Cweek71View::OnDraw(CDC* pDC)
{
	Cweek71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDC->Ellipse(pDoc->rect);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cweek71View 诊断

#ifdef _DEBUG
void Cweek71View::AssertValid() const
{
	CView::AssertValid();
}

void Cweek71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cweek71Doc* Cweek71View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cweek71Doc)));
	return (Cweek71Doc*)m_pDocument;
}
#endif //_DEBUG


// Cweek71View 消息处理程序


void Cweek71View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cweek71Doc* pDoc = GetDocument();
	pDoc->rect.left = point.x ;
	pDoc->rect.right = point.x +100;
	pDoc->rect.bottom = point.y+30 ;
	pDoc->rect.top = point.y ;
	pDoc->x = 1;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void Cweek71View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cweek71Doc* pDoc = GetDocument();
	pDoc->rect.left = point.x;
	pDoc->rect.right = point.x + 100;
	pDoc->rect.bottom = point.y + 30;
	pDoc->rect.top = point.y;
	if (pDoc->x == 1) {
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void Cweek71View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cweek71Doc* pDoc = GetDocument();
	pDoc->rect.left = point.x;
	pDoc->rect.right = point.x + 100;
	pDoc->rect.bottom = point.y + 30;
	pDoc->rect.top = point.y;
	pDoc->x = 0;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
