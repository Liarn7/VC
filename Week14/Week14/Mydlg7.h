#pragma once


// Mydlg7 �Ի���

class Mydlg7 : public CDialogEx
{
	DECLARE_DYNAMIC(Mydlg7)

public:
	Mydlg7(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Mydlg7();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString a;
	CString b;
	CString c;
	CString d;
};
