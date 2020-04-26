
// Week8.2(1)View.cpp : CWeek821View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week8.2(1).h"
#endif

#include "Week8.2(1)Doc.h"
#include "Week8.2(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek821View

IMPLEMENT_DYNCREATE(CWeek821View, CView)

BEGIN_MESSAGE_MAP(CWeek821View, CView)
END_MESSAGE_MAP()

// CWeek821View 构造/析构

CWeek821View::CWeek821View()
{
	// TODO: 在此处添加构造代码

}

CWeek821View::~CWeek821View()
{
}

BOOL CWeek821View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWeek821View 绘制

void CWeek821View::OnDraw(CDC* pDC)
{
	CWeek821Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(pDoc->rc);

	// TODO: 在此处为本机数据添加绘制代码
}


// CWeek821View 诊断

#ifdef _DEBUG
void CWeek821View::AssertValid() const
{
	CView::AssertValid();
}

void CWeek821View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek821Doc* CWeek821View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek821Doc)));
	return (CWeek821Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek821View 消息处理程序
