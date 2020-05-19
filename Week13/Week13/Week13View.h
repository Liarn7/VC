
// Week13View.h : CWeek13View 类的接口
//

#pragma once

class CWeek13Set;

class CWeek13View : public CRecordView
{
protected: // 仅从序列化创建
	CWeek13View();
	DECLARE_DYNCREATE(CWeek13View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_WEEK13_FORM };
#endif
	CWeek13Set* m_pSet;

// 特性
public:
	CWeek13Doc* GetDocument() const;

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
	virtual ~CWeek13View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CString x;
	afx_msg void OnBnClickedButtonAdd();
};

#ifndef _DEBUG  // Week13View.cpp 中的调试版本
inline CWeek13Doc* CWeek13View::GetDocument() const
   { return reinterpret_cast<CWeek13Doc*>(m_pDocument); }
#endif

