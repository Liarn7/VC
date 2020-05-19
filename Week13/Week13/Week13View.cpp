
// Week13View.cpp : CWeek13View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week13.h"
#endif

#include "Week13Set.h"
#include "Week13Doc.h"
#include "Week13View.h"
#include "Mydlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek13View

IMPLEMENT_DYNCREATE(CWeek13View, CRecordView)

BEGIN_MESSAGE_MAP(CWeek13View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON2, &CWeek13View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CWeek13View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CWeek13View::OnBnClickedButtonAdd)
END_MESSAGE_MAP()

// CWeek13View 构造/析构

CWeek13View::CWeek13View()
	: CRecordView(IDD_WEEK13_FORM)
	, x(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CWeek13View::~CWeek13View()
{
}

void CWeek13View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1,m_pSet->m_1);
}

BOOL CWeek13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CWeek13View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Week13Set;
	CRecordView::OnInitialUpdate();

}


// CWeek13View 打印

BOOL CWeek13View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CWeek13View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CWeek13View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CWeek13View 诊断

#ifdef _DEBUG
void CWeek13View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CWeek13View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CWeek13Doc* CWeek13View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek13Doc)));
	return (CWeek13Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek13View 数据库支持
CRecordset* CWeek13View::OnGetRecordset()
{
	return m_pSet;
}



// CWeek13View 消息处理程序


void CWeek13View::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	Mydlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK) {
		CString z = dlg.y;
		m_pSet->Edit();
		m_pSet->m_1 = z;
		m_pSet->Update();
		UpdateData();
	}
}


void CWeek13View::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void CWeek13View::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	Mydlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK) {
		CString z = dlg.y;
		m_pSet->AddNew();
		m_pSet->m_1=z;
		m_pSet->Update();
		UpdateData();
	}

}
