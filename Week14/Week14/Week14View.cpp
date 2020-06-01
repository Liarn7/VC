
// Week14View.cpp : CWeek14View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week14.h"
#endif

#include "Week14Set.h"
#include "Week14Doc.h"
#include "Week14View.h"
#include "Mydlg.h"
#include "Mydlg2.h"
#include "Mydlg4.h"
#include "Mydlg7.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek14View

IMPLEMENT_DYNCREATE(CWeek14View, CRecordView)

BEGIN_MESSAGE_MAP(CWeek14View, CRecordView)
	//ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CWeek14View::OnTvnSelchangedTree1)
	ON_COMMAND(ID_RECORD_FIRST, &CWeek14View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CWeek14View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CWeek14View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CWeek14View::OnRecordLast)
	ON_COMMAND(ID_RECORD_FIRST, &CWeek14View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CWeek14View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CWeek14View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CWeek14View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON2, &CWeek14View::OnBnClickedButton2)
	ON_COMMAND(ID_32772, &CWeek14View::OnOrder)
	ON_COMMAND(ID_32773, &CWeek14View::OnSelect)
	ON_COMMAND(ID_32777, &CWeek14View::OnRecord)
	
	ON_COMMAND(ID_32774, &CWeek14View::On32774)
	ON_COMMAND(ID_32775, &CWeek14View::OnDelete)
	ON_COMMAND(ID_32776, &CWeek14View::OnChange)
	ON_BN_CLICKED(IDC_BUTTON3, &CWeek14View::OnBack)
END_MESSAGE_MAP()

// CWeek14View 构造/析构

CWeek14View::CWeek14View()
	: CRecordView(IDD_WEEK14_FORM)
	, a(_T(""))
	, b(_T(""))
	, d(_T(""))
	, e(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码


}

CWeek14View::~CWeek14View()
{

}

void CWeek14View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
}

BOOL CWeek14View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CWeek14View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Week14Set;
	
	CRecordView::OnInitialUpdate();
	

}


// CWeek14View 诊断

#ifdef _DEBUG
void CWeek14View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CWeek14View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CWeek14Doc* CWeek14View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek14Doc)));
	return (CWeek14Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek14View 数据库支持
CRecordset* CWeek14View::OnGetRecordset()
{
	return m_pSet;
}



// CWeek14View 消息处理程序


void CWeek14View::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
void CWeek14View::draw_pic(CString file)

{


	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC1)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);

}





void CWeek14View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();

	UpdateData(false);

	CString s;

	GetDlgItemText(IDC_EDIT4, s);

	draw_pic(s);
	Invalidate();
}


void CWeek14View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();

	if (m_pSet->IsBOF())

		m_pSet->MoveFirst();

	UpdateData(false);

	CString s;

	GetDlgItemText(IDC_EDIT4, s);

	draw_pic(s);
	Invalidate();
}


void CWeek14View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();

	if (m_pSet->IsEOF())

		m_pSet->MoveLast();

	UpdateData(false);

	CString s;

	GetDlgItemText(IDC_EDIT4, s);

	draw_pic(s);
	Invalidate();
}


void CWeek14View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();

	UpdateData(false);

	CString s;

	GetDlgItemText(IDC_EDIT4, s);

	draw_pic(s);
	Invalidate();


}


void CWeek14View::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);

	Mydlg dlg;

	GetDlgItemText(IDC_EDIT4, dlg.s);

	int t = dlg.DoModal();



	UpdateData(false);

}


void CWeek14View::OnDraw(CDC* pDC)
{
	// TODO: 在此添加专用代码和/或调用基类
	CString s;

	GetDlgItemText(IDC_EDIT4, s);

	draw_pic(s);
}


void CWeek14View::OnOrder()
{
	// TODO: 在此添加命令处理程序代码
	Mydlg2 dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {
		UpdateData();
		m_pSet->m_strSort = dlg.x;
		m_pSet->Requery();
		UpdateData(false);
	
	}
	
}


void CWeek14View::OnSelect()
{
	// TODO: 在此添加命令处理程序代码
	Mydlg2 dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {
		UpdateData();
		m_pSet->m_strFilter = dlg.x;
		m_pSet->Requery();
		UpdateData(false);
	}	
}


void CWeek14View::OnRecord()
{
	// TODO: 在此添加命令处理程序代码
	Mydlg4 dlg;
	//this->UpdateData(true);
	CString x;
	int n = m_pSet->GetODBCFieldCount();
	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF()) {
		for (int i = 0; i < n; i++) {
			m_pSet->GetFieldValue(short(i), x);
			dlg.y = dlg.y + ' ' + ' ';
			dlg.y = dlg.y + x;
			
		}
		m_pSet->MoveNext();
	}


	int r = dlg.DoModal();
	if (r == IDOK) {
	}
}



void CWeek14View::On32774()
{
	// TODO: 在此添加命令处理程序代码
	Mydlg7 dlg;

	int t = dlg.DoModal();

	if (t == IDOK) {

		

		m_pSet->AddNew();


		m_pSet->m_ID = dlg.a;
		m_pSet->m_1 = dlg.b;
		m_pSet->m_2 = dlg.c;
		m_pSet->m_3 = dlg.d;

		m_pSet->Update();

		UpdateData();

	}
}


void CWeek14View::OnDelete()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->Delete();

	m_pSet->MovePrev();

	if (m_pSet->IsBOF())

		m_pSet->MoveFirst();

	UpdateData(false);
}


void CWeek14View::OnChange()
{
	// TODO: 在此添加命令处理程序代码
	Mydlg7 dlg;

	int t = dlg.DoModal();

	if (t == IDOK) {

		m_pSet->Edit();

		m_pSet->m_ID = dlg.a;
		m_pSet->m_1 = dlg.b;
		m_pSet->m_2 = dlg.c;
		m_pSet->m_3 = dlg.d;

		m_pSet->Update();

		UpdateData();

	}
}


void CWeek14View::OnBack()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_pSet->m_strFilter = _T("");
	m_pSet->Requery();
	UpdateData(false);
}
