
// Week8(3)View.h : CWeek83View 类的接口
//

#pragma once


class CWeek83View : public CView
{
protected: // 仅从序列化创建
	CWeek83View();
	DECLARE_DYNCREATE(CWeek83View)

// 特性
public:
	CWeek83Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWeek83View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnView();
};

#ifndef _DEBUG  // Week8(3)View.cpp 中的调试版本
inline CWeek83Doc* CWeek83View::GetDocument() const
   { return reinterpret_cast<CWeek83Doc*>(m_pDocument); }
#endif

