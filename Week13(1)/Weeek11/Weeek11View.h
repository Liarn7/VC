
// Weeek11View.h : CWeeek11View 类的接口
//

#pragma once

class CWeeek11Set;

class CWeeek11View : public CRecordView
{
protected: // 仅从序列化创建
	CWeeek11View();
	DECLARE_DYNCREATE(CWeeek11View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_WEEEK11_FORM };
#endif
	CWeeek11Set* m_pSet;

// 特性
public:
	CWeeek11Doc* GetDocument() const;
	void draw_pic(CString file);


// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CWeeek11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString id;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // Weeek11View.cpp 中的调试版本
inline CWeeek11Doc* CWeeek11View::GetDocument() const
   { return reinterpret_cast<CWeeek11Doc*>(m_pDocument); }
#endif

