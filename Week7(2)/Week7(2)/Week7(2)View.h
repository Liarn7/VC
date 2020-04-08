
// Week7(2)View.h : CWeek72View 类的接口
//

#pragma once


class CWeek72View : public CView
{
protected: // 仅从序列化创建
	CWeek72View();
	DECLARE_DYNCREATE(CWeek72View)

// 特性
public:
	CWeek72Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWeek72View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnBnClickedButton1();
	afx_msg void OnView();
};

#ifndef _DEBUG  // Week7(2)View.cpp 中的调试版本
inline CWeek72Doc* CWeek72View::GetDocument() const
   { return reinterpret_cast<CWeek72Doc*>(m_pDocument); }
#endif

