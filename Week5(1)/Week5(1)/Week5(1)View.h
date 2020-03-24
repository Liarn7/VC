
// Week5(1)View.h: CWeek51View 类的接口
//

#pragma once


class CWeek51View : public CView
{
protected: // 仅从序列化创建
	CWeek51View() noexcept;
	DECLARE_DYNCREATE(CWeek51View)

// 特性
public:
	CWeek51Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWeek51View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // Week5(1)View.cpp 中的调试版本
inline CWeek51Doc* CWeek51View::GetDocument() const
   { return reinterpret_cast<CWeek51Doc*>(m_pDocument); }
#endif

