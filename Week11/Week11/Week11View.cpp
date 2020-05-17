
// Week11View.cpp : CWeek11View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Week11.h"
#endif

#include "Week11Set.h"
#include "Week11Doc.h"
#include "Week11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek11View

IMPLEMENT_DYNCREATE(CWeek11View, CRecordView)

BEGIN_MESSAGE_MAP(CWeek11View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CWeek11View 构造/析构

CWeek11View::CWeek11View()
	: CRecordView(IDD_WEEK11_FORM)
	, ID(0)
	, name(_T(""))
	, no(_T(""))
	, age(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CWeek11View::~CWeek11View()
{
}

void CWeek11View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
}

BOOL CWeek11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CWeek11View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Week11Set;
	CRecordView::OnInitialUpdate();

}


// CWeek11View 打印

BOOL CWeek11View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CWeek11View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CWeek11View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CWeek11View 诊断

#ifdef _DEBUG
void CWeek11View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CWeek11View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CWeek11Doc* CWeek11View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek11Doc)));
	return (CWeek11Doc*)m_pDocument;
}
#endif //_DEBUG


// CWeek11View 数据库支持
CRecordset* CWeek11View::OnGetRecordset()
{
	return m_pSet;
}



// CWeek11View 消息处理程序
