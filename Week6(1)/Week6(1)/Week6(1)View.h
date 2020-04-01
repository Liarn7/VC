
// Week6(1)View.h: CWeek61View 类的接口
//

#pragma once


class CWeek61View : public CView
{
protected: // 仅从序列化创建
	CWeek61View() noexcept;
	DECLARE_DYNCREATE(CWeek61View)

// 特性
public:
	CWeek61Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWeek61View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // Week6(1)View.cpp 中的调试版本
inline CWeek61Doc* CWeek61View::GetDocument() const
   { return reinterpret_cast<CWeek61Doc*>(m_pDocument); }
#endif

