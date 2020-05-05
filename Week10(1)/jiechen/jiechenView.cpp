
// jiechenView.cpp : CjiechenView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "jiechen.h"
#endif

#include "jiechenDoc.h"
#include "jiechenView.h"
#include "factorial.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CjiechenView

IMPLEMENT_DYNCREATE(CjiechenView, CView)

BEGIN_MESSAGE_MAP(CjiechenView, CView)
END_MESSAGE_MAP()

// CjiechenView 构造/析构

CjiechenView::CjiechenView()
{
	// TODO: 在此处添加构造代码

}

CjiechenView::~CjiechenView()
{
}

BOOL CjiechenView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CjiechenView 绘制

void CjiechenView::OnDraw(CDC* pDC)
{
	CjiechenDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s,t;
	FAC x;
	s .Format(_T("%d"),pchar(5));
	pDC->TextOutW(200, 150, s);
	t.Format(_T("%f"),x.convert(30.0) );
	pDC->TextOutW(200, 200, t);
	// TODO: 在此处为本机数据添加绘制代码
}


// CjiechenView 诊断

#ifdef _DEBUG
void CjiechenView::AssertValid() const
{
	CView::AssertValid();
}

void CjiechenView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CjiechenDoc* CjiechenView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CjiechenDoc)));
	return (CjiechenDoc*)m_pDocument;
}
#endif //_DEBUG


// CjiechenView 消息处理程序
