
// week(2)View.cpp : Cweek2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "week(2).h"
#endif

#include "week(2)Doc.h"
#include "week(2)View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cweek2View

IMPLEMENT_DYNCREATE(Cweek2View, CView)

BEGIN_MESSAGE_MAP(Cweek2View, CView)
	ON_COMMAND(ID_VIEW, &Cweek2View::OnView)
END_MESSAGE_MAP()

// Cweek2View 构造/析构

Cweek2View::Cweek2View()
{
	// TODO: 在此处添加构造代码

}

Cweek2View::~Cweek2View()
{
}

BOOL Cweek2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cweek2View 绘制

void Cweek2View::OnDraw(CDC* /*pDC*/)
{
	Cweek2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cweek2View 诊断

#ifdef _DEBUG
void Cweek2View::AssertValid() const
{
	CView::AssertValid();
}

void Cweek2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cweek2Doc* Cweek2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cweek2Doc)));
	return (Cweek2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cweek2View 消息处理程序


void Cweek2View::OnView()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int r = dlg.DoModal();
}
