
// Week8(3)View.cpp : CWeek83View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week8(3).h"
#endif

#include "Week8(3)Doc.h"
#include "Week8(3)View.h"
#include "MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek83View

IMPLEMENT_DYNCREATE(CWeek83View, CView)

BEGIN_MESSAGE_MAP(CWeek83View, CView)
	ON_COMMAND(ID_VIEW, &CWeek83View::OnView)
END_MESSAGE_MAP()

// CWeek83View 构造/析构

CWeek83View::CWeek83View()
{
	// TODO: 在此处添加构造代码

}

CWeek83View::~CWeek83View()
{
}

BOOL CWeek83View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWeek83View 绘制

void CWeek83View::OnDraw(CDC* /*pDC*/)
{
	CWeek83Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CWeek83View 诊断

#ifdef _DEBUG
void CWeek83View::AssertValid() const
{
	CView::AssertValid();
}

void CWeek83View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek83Doc* CWeek83View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek83Doc)));
	return (CWeek83Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek83View 消息处理程序


void CWeek83View::OnView()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t = dlg.DoModal();
}
