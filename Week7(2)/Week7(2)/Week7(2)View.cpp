
// Week7(2)View.cpp : CWeek72View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week7(2).h"
#endif

#include "Week7(2)Doc.h"
#include "Week7(2)View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek72View

IMPLEMENT_DYNCREATE(CWeek72View, CView)

BEGIN_MESSAGE_MAP(CWeek72View, CView)
//	ON_BN_CLICKED(IDC_BUTTON1, &CWeek72View::OnBnClickedButton1)
	ON_COMMAND(ID_VIEW, &CWeek72View::OnView)
END_MESSAGE_MAP()

// CWeek72View 构造/析构

CWeek72View::CWeek72View()
{
	// TODO: 在此处添加构造代码

}

CWeek72View::~CWeek72View()
{
}

BOOL CWeek72View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWeek72View 绘制

void CWeek72View::OnDraw(CDC* /*pDC*/)
{
	CWeek72Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CWeek72View 诊断

#ifdef _DEBUG
void CWeek72View::AssertValid() const
{
	CView::AssertValid();
}

void CWeek72View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek72Doc* CWeek72View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek72Doc)));
	return (CWeek72Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek72View 消息处理程序


/*void CWeek72View::OnBnClickedButton1()
{
	MyDlg dlg;
	this->UpdateData(true);
	CString s;
	s = dlg.x;
	dlg.x = dlg.y;
	dlg.y = s;


	// TODO: 在此添加控件通知处理程序代码
}*/


void CWeek72View::OnView()
{
	MyDlg dlg;
	int t = dlg.DoModal();
	// TODO: 在此添加命令处理程序代码
}
