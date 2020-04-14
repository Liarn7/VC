
// Week8(1)View.h : CWeek81View 类的接口
//

#pragma once


class CWeek81View : public CView
{
protected: // 仅从序列化创建
	CWeek81View();
	DECLARE_DYNCREATE(CWeek81View)

// 特性
public:
	CWeek81Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWeek81View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Week8(1)View.cpp 中的调试版本
inline CWeek81Doc* CWeek81View::GetDocument() const
   { return reinterpret_cast<CWeek81Doc*>(m_pDocument); }
#endif

