
// Week7(1）View.h: CWeek71View 类的接口
//

#pragma once


class CWeek71View : public CView
{
protected: // 仅从序列化创建
	CWeek71View() noexcept;
	DECLARE_DYNCREATE(CWeek71View)

// 特性
public:
	CWeek71Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWeek71View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnView();
};

#ifndef _DEBUG  // Week7(1）View.cpp 中的调试版本
inline CWeek71Doc* CWeek71View::GetDocument() const
   { return reinterpret_cast<CWeek71Doc*>(m_pDocument); }
#endif

