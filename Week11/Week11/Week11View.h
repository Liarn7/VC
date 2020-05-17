
// Week11View.h : CWeek11View 类的接口
//

#pragma once

class CWeek11Set;

class CWeek11View : public CRecordView
{
protected: // 仅从序列化创建
	CWeek11View();
	DECLARE_DYNCREATE(CWeek11View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_WEEK11_FORM };
#endif
	CWeek11Set* m_pSet;

// 特性
public:
	CWeek11Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CWeek11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString no;
	CString age;
};

#ifndef _DEBUG  // Week11View.cpp 中的调试版本
inline CWeek11Doc* CWeek11View::GetDocument() const
   { return reinterpret_cast<CWeek11Doc*>(m_pDocument); }
#endif

