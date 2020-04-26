
// Week8.2(1)View.h : CWeek821View 类的接口
//

#pragma once


class CWeek821View : public CView
{
protected: // 仅从序列化创建
	CWeek821View();
	DECLARE_DYNCREATE(CWeek821View)

// 特性
public:
	CWeek821Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWeek821View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Week8.2(1)View.cpp 中的调试版本
inline CWeek821Doc* CWeek821View::GetDocument() const
   { return reinterpret_cast<CWeek821Doc*>(m_pDocument); }
#endif

