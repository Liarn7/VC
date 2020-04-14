
// week(2)View.h : Cweek2View 类的接口
//

#pragma once


class Cweek2View : public CView
{
protected: // 仅从序列化创建
	Cweek2View();
	DECLARE_DYNCREATE(Cweek2View)

// 特性
public:
	Cweek2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cweek2View();
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

#ifndef _DEBUG  // week(2)View.cpp 中的调试版本
inline Cweek2Doc* Cweek2View::GetDocument() const
   { return reinterpret_cast<Cweek2Doc*>(m_pDocument); }
#endif

