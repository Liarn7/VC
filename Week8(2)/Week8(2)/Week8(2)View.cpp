
// Week8(2)View.cpp : CWeek82View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week8(2).h"
#endif

#include "Week8(2)Doc.h"
#include "Week8(2)View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek82View

IMPLEMENT_DYNCREATE(CWeek82View, CView)

BEGIN_MESSAGE_MAP(CWeek82View, CView)
	ON_COMMAND(ID_32771, &CWeek82View::On32771)
END_MESSAGE_MAP()

// CWeek82View 构造/析构

CWeek82View::CWeek82View()
{
	// TODO: 在此处添加构造代码

}

CWeek82View::~CWeek82View()
{
}

BOOL CWeek82View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWeek82View 绘制

void CWeek82View::OnDraw(CDC* /*pDC*/)
{
	CWeek82Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CWeek82View 诊断

#ifdef _DEBUG
void CWeek82View::AssertValid() const
{
	CView::AssertValid();
}

void CWeek82View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek82Doc* CWeek82View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek82Doc)));
	return (CWeek82Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek82View 消息处理程序


void CWeek82View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int r = dlg.DoModal();

}
