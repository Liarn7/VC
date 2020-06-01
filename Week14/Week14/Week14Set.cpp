
// Week14Set.cpp : CWeek14Set 类的实现
//

#include "stdafx.h"
#include "Week14.h"
#include "Week14Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek14Set 实现

// 代码生成在 2020年5月25日, 22:01

IMPLEMENT_DYNAMIC(CWeek14Set, CRecordset)

CWeek14Set::CWeek14Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = L"";
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CWeek14Set::GetDefaultConnect()
{
	return _T("DSN=\x4fe1\x606f\x8868;DBQ=D:\\\x65b0\x5efa\x6587\x4ef6\x5939 (2)\\Database2.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CWeek14Set::GetDefaultSQL()
{
	return _T("[信息表]");
}

void CWeek14Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[姓名]"), m_1);
	RFX_Text(pFX, _T("[字段2]"), m_2);
	RFX_Text(pFX, _T("[字段3]"), m_3);

}
/////////////////////////////////////////////////////////////////////////////
// CWeek14Set 诊断

#ifdef _DEBUG
void CWeek14Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CWeek14Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

