
// MFC9View.h : CMFC9View ��Ľӿ�
//

#pragma once


class CMFC9View : public CView
{
protected: // �������л�����
	CMFC9View();
	DECLARE_DYNCREATE(CMFC9View)

// ����
public:
	CMFC9Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // MFC9View.cpp �еĵ��԰汾
inline CMFC9Doc* CMFC9View::GetDocument() const
   { return reinterpret_cast<CMFC9Doc*>(m_pDocument); }
#endif

