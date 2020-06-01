
// Week14View.h : CWeek14View 类的接口
//

#pragma once
#include "afxwin.h"

class CWeek14Set;

class CWeek14View : public CRecordView
{
protected: // 仅从序列化创建
	CWeek14View();
	DECLARE_DYNCREATE(CWeek14View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_WEEK14_FORM };
#endif
	CWeek14Set* m_pSet;

// 特性
public:
	CWeek14Doc* GetDocument() const;
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
	virtual ~CWeek14View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	CString a;
	CString b;
	CString d;
	CString e;
	
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton2();
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void OnOrder();
	afx_msg void OnSelect();
	afx_msg void OnRecord();

	afx_msg void On32774();
	afx_msg void OnDelete();
	afx_msg void OnChange();
	afx_msg void OnBack();
};

#ifndef _DEBUG  // Week14View.cpp 中的调试版本
inline CWeek14Doc* CWeek14View::GetDocument() const
   { return reinterpret_cast<CWeek14Doc*>(m_pDocument); }
#endif

