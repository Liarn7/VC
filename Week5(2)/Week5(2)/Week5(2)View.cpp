
// Week5(2)View.cpp: CWeek52View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week5(2).h"
#endif

#include "Week5(2)Doc.h"
#include "Week5(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek52View

IMPLEMENT_DYNCREATE(CWeek52View, CView)

BEGIN_MESSAGE_MAP(CWeek52View, CView)
END_MESSAGE_MAP()

// CWeek52View 构造/析构

CWeek52View::CWeek52View() noexcept
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmapW(IDB_BITMAP2);
	m_Bitmap.GetBitmap(&BM);
	width = BM.bmWidth;
	height = BM.bmHeight;


}

CWeek52View::~CWeek52View()
{
}

BOOL CWeek52View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWeek52View 绘图

void CWeek52View::OnDraw(CDC* pDC)
{
	CWeek52Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, width, height, &MemDC, 0, 0, SRCCOPY);
		

	// TODO: 在此处为本机数据添加绘制代码
}


// CWeek52View 诊断

#ifdef _DEBUG
void CWeek52View::AssertValid() const
{
	CView::AssertValid();
}

void CWeek52View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek52Doc* CWeek52View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek52Doc)));
	return (CWeek52Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek52View 消息处理程序
