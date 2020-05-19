
// Weeek11View.cpp : CWeeek11View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Weeek11.h"
#include "Mydlg.h"
#endif

#include "Weeek11Set.h"
#include "Weeek11Doc.h"
#include "Weeek11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeeek11View

IMPLEMENT_DYNCREATE(CWeeek11View, CRecordView)

BEGIN_MESSAGE_MAP(CWeeek11View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CWeeek11View::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_FIRST, &CWeeek11View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CWeeek11View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CWeeek11View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CWeeek11View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON2, &CWeeek11View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CWeeek11View 构造/析构

CWeeek11View::CWeeek11View()
	: CRecordView(IDD_WEEEK11_FORM)
	, id(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CWeeek11View::~CWeeek11View()
{
}

void CWeeek11View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, ID_EDIT1,m_pSet->m_1);
}

BOOL CWeeek11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CWeeek11View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Weeek11Set;
	CRecordView::OnInitialUpdate();

}


// CWeeek11View 诊断

#ifdef _DEBUG
void CWeeek11View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CWeeek11View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CWeeek11Doc* CWeeek11View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeeek11Doc)));
	return (CWeeek11Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeeek11View 数据库支持
CRecordset* CWeeek11View::OnGetRecordset()
{
	return m_pSet;
}



// CWeeek11View 消息处理程序


void CWeeek11View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	GetDlgItemText(ID_EDIT1, s);
	draw_pic(s);
}

 void CWeeek11View::draw_pic(CString file)
{
	
	//pDC->TextOutW(0, 0, file);
	CImage img;
	img.Load(file);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
    int  sx=0, sy, w, h;
    CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio) {
		h = rect.Height();
		w = img_ratio * h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / img_ratio;
		sy = 0;
		sy = (rect.Height() - h) / 2;
	}
	img.Draw(pDC->m_hDC, sx, sy, w, h);
}





 void CWeeek11View::OnRecordFirst()
 {
	 // TODO: 在此添加命令处理程序代码
	 m_pSet->MoveFirst();
	 UpdateData(false);
	 CString s;
	 GetDlgItemText(ID_EDIT1, s);
	 draw_pic(s);
	 
 }


 void CWeeek11View::OnRecordPrev()
 {
	 // TODO: 在此添加命令处理程序代码
	 m_pSet->MovePrev();
	 if (m_pSet->IsBOF())
		 m_pSet->MoveFirst();
	 UpdateData(false);
	 CString s;
	 GetDlgItemText(ID_EDIT1, s);
	 draw_pic(s);
	 
 }


 void CWeeek11View::OnRecordNext()
 {
	 // TODO: 在此添加命令处理程序代码
	 m_pSet->MoveNext();
	 if (m_pSet->IsEOF())
		 m_pSet->MoveLast();
	 UpdateData(false);
	 CString s;
	 GetDlgItemText(ID_EDIT1, s);
	 draw_pic(s);
	 
 }


 void CWeeek11View::OnRecordLast()
 {
	 // TODO: 在此添加命令处理程序代码
	 m_pSet->MoveLast();
	 UpdateData(false);
	 CString s;
	 GetDlgItemText(ID_EDIT1, s);
	 draw_pic(s);
	
 }


 void CWeeek11View::OnBnClickedButton2()
 {
	 // TODO: 在此添加控件通知处理程序代码
	 this->UpdateData(true);
	 Mydlg dlg;
	 GetDlgItemText(ID_EDIT1, dlg.s);
	 int t = dlg.DoModal();
	
	 UpdateData(false);
 }
