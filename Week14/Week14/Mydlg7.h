#pragma once


// Mydlg7 对话框

class Mydlg7 : public CDialogEx
{
	DECLARE_DYNAMIC(Mydlg7)

public:
	Mydlg7(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Mydlg7();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString a;
	CString b;
	CString c;
	CString d;
};
