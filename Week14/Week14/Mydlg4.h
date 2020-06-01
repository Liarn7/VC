#pragma once


// Mydlg4 对话框

class Mydlg4 : public CDialogEx
{
	DECLARE_DYNAMIC(Mydlg4)

public:
	Mydlg4(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Mydlg4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString y;
	afx_msg void OnBnClickedButton1();
};
