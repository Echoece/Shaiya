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
	   HRESULT hr1 = m_pConnect.CreateInstance(L"ADODB.Connection");
	   if (FAILED(hr1))
	   {
		   return FALSE;
	   }
   }
	catch (_com_error)
	{
		OutputDebugString(L"");
	}
	LPCTSTR szPath = L".\\ncash.ini"; //define the path of Db.ini as the current directory and create a variable
	WCHAR szUsername[32]; //initialize the username variable
	WCHAR szPassword[32]; //initialize the password variable
	GetPrivateProfileString(L"NCash", L"Uid", L"", szUsername, 32, szPath); //parse the ini and return the username
	GetPrivateProfileString(L"NCash", L"Pwd", L"", szPassword, 32, szPath); //parse the ini and return the password
	CString szLink;
	szLink.Format(L"Provider=SQLOLEDB;Server=127.0.0.1;Database=PS_UserData;"); //define the provider, ip, and database
	CString szUid = szUsername; //convert the username from wchar_t to a string
	CString szPwd = szPassword; //convert the password from wchar_t to a string
	m_pConnect->Open(_bstr_t(szLink), _bstr_t(szUid), _bstr_t(szPwd), NULL); //pass the string and the login variables
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