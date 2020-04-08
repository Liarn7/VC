
// Week7(1）View.cpp: CWeek71View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week7(1）.h"
#endif

#include "Week7(1）Doc.h"
#include "Week7(1）View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek71View

IMPLEMENT_DYNCREATE(CWeek71View, CView)

BEGIN_MESSAGE_MAP(CWeek71View, CView)
	ON_BN_CLICKED(IDCANCEL, &CWeek71View::OnBnClickedCancel)
	ON_COMMAND(ID_VIEW, &CWeek71View::OnView)
END_MESSAGE_MAP()

// CWeek71View 构造/析构

CWeek71View::CWeek71View() noexcept
{
	// TODO: 在此处添加构造代码

}

CWeek71View::~CWeek71View()
{
}

BOOL CWeek71View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWeek71View 绘图

void CWeek71View::OnDraw(CDC* /*pDC*/)
{
	CWeek71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CWeek71View 诊断

#ifdef _DEBUG
void CWeek71View::AssertValid() const
{
	CView::AssertValid();
}

void CWeek71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek71Doc* CWeek71View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek71Doc)));
	return (CWeek71Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek71View 消息处理程序


void CWeek71View::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码

	CString s = _T("你已退出对话框");

	CClientDC dc(this);

	dc.TextOutW(77, 77, s);
}


void CWeek71View::OnView()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDCANCEL) {

	
	CString s = _T("你已退出对话框");

	CClientDC dc(this);

	dc.TextOutW(77, 77, s);}
}
