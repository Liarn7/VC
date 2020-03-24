
// Week5(1)View.cpp: CWeek51View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week5(1).h"
#endif

#include "Week5(1)Doc.h"
#include "Week5(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek51View

IMPLEMENT_DYNCREATE(CWeek51View, CView)

BEGIN_MESSAGE_MAP(CWeek51View, CView)
	ON_COMMAND(ID_SHOWNAME, &CWeek51View::OnShowname)
END_MESSAGE_MAP()

// CWeek51View 构造/析构

CWeek51View::CWeek51View() noexcept
{
	// TODO: 在此处添加构造代码

}

CWeek51View::~CWeek51View()
{
}

BOOL CWeek51View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWeek51View 绘图

void CWeek51View::OnDraw(CDC* /*pDC*/)
{
	CWeek51Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CWeek51View 诊断

#ifdef _DEBUG
void CWeek51View::AssertValid() const
{
	CView::AssertValid();
}

void CWeek51View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek51Doc* CWeek51View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek51Doc)));
	return (CWeek51Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek51View 消息处理程序


void CWeek51View::OnShowname()
{
	// TODO: 在此添加命令处理程序代码
	CString s = _T("田中宇");
		CClientDC dc(this);
		dc.TextOutW(77, 77, s);
}
