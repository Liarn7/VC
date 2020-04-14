
// Week8(2)View.h : CWeek82View 类的接口
//

#pragma once


class CWeek82View : public CView
{
protected: // 仅从序列化创建
	CWeek82View();
	DECLARE_DYNCREATE(CWeek82View)

// 特性
public:
	CWeek82Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWeek82View();
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
};

#ifndef _DEBUG  // Week8(2)View.cpp 中的调试版本
inline CWeek82Doc* CWeek82View::GetDocument() const
   { return reinterpret_cast<CWeek82Doc*>(m_pDocument); }
#endif

