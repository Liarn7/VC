
// Week6(1)View.cpp: CWeek61View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week6(1).h"
#endif

#include "Week6(1)Doc.h"
#include "Week6(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek61View

IMPLEMENT_DYNCREATE(CWeek61View, CView)

BEGIN_MESSAGE_MAP(CWeek61View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CWeek61View::OnFileOpen)
END_MESSAGE_MAP()

// CWeek61View 构造/析构

CWeek61View::CWeek61View() noexcept
{
	// TODO: 在此处添加构造代码

}

CWeek61View::~CWeek61View()
{
}

BOOL CWeek61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWeek61View 绘图

void CWeek61View::OnDraw(CDC* pDC)
{
	CWeek61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	


	// TODO: 在此处为本机数据添加绘制代码
}


// CWeek61View 诊断

#ifdef _DEBUG
void CWeek61View::AssertValid() const
{
	CView::AssertValid();
}

void CWeek61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek61Doc* CWeek61View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek61Doc)));
	return (CWeek61Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek61View 消息处理程序


void CWeek61View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC=new CDC();
	CFileDialog cfd(true);  //建立对象
	int r = cfd.DoModal(); 
		CClientDC dc(this);
	if (r == IDOK)        //如果退出对话框时选项为OK的话
	{
		CString filename = cfd.GetPathName();

		dc.TextOutW(300, 200, filename);
		CImage img;
		img.Load(filename);

		img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(), img.GetHeight());
		
	}
	


}
