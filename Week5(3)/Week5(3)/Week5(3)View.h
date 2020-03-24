
// Week5(3)View.h: CWeek53View 类的接口
//

#pragma once


class CWeek53View : public CView
{
protected: // 仅从序列化创建
	CWeek53View() noexcept;
	DECLARE_DYNCREATE(CWeek53View)

// 特性
public:
	CWeek53Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWeek53View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnMove(int x, int y);
};

#ifndef _DEBUG  // Week5(3)View.cpp 中的调试版本
inline CWeek53Doc* CWeek53View::GetDocument() const
   { return reinterpret_cast<CWeek53Doc*>(m_pDocument); }
#endif

