
// Week5(2)View.h: CWeek52View 类的接口
//

#pragma once


class CWeek52View : public CView
{
protected: // 仅从序列化创建
	CWeek52View() noexcept;
	DECLARE_DYNCREATE(CWeek52View)

// 特性
public:
	CWeek52Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;
	int width;
	int height;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWeek52View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Week5(2)View.cpp 中的调试版本
inline CWeek52Doc* CWeek52View::GetDocument() const
   { return reinterpret_cast<CWeek52Doc*>(m_pDocument); }
#endif

