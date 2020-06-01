#include "pch.h"
#include "database.h"

CDataBase::CDataBase(void)
{
	m_vecDATABASE.clear();
	m_dwIndex=0;
}

BOOL CDataBase::LinkDataBase()
{
   CoInitialize(NULL);
   try
   {
	   HRESULT hr1 = m_pConnect.CreateInstance(_T("ADODB.Connection"));
	   if (FAILED(hr1))
	   {
		   return FALSE;
	   }
   }
	catch (_com_error)
	{
		OutputDebugString(L"");
	}
	CString szLink;
	szLink.Format(L"Provider=SQLOLEDB;Server=127.0.0.1;Database=PS_UserData;Uid=yourusername1234;Pwd=yourpassword1234;");
	m_pConnect->Open(_bstr_t(szLink), _bstr_t(L""), _bstr_t(L""), adModeUnknown);
	return TRUE;
}

BOOL CDataBase::ExeSqlByCon(CString szSql)
{
	try{
		m_pConnect->Execute(_bstr_t(szSql),NULL,1);
	}
	catch(_com_error)
	{
		return FALSE;
	}
	return TRUE;
}
