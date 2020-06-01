**contents**
* ct file that blocks pets, wings, and costumes from being equipped or switched in pvp zones
* item mall dll that reads the username and password from Db.ini 

**notes**
* the only difference in the ep6 item mall dll and the ep5 version is this database function

```
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
	wchar_t szPath[255];
	GetCurrentDirectory(MAX_PATH, szPath);
	wcscat(szPath, L".\\Db.ini");
	wchar_t szUsername[255];
	wchar_t szPassword[255];
	GetPrivateProfileString(L"DbInfo", L"Account", L"", szUsername, 255, szPath);
	GetPrivateProfileString(L"DbInfo", L"Pw", L"", szPassword, 255, szPath);
	CString szLink; 
	CString szUid = szUsername;
	CString szPwd = szPassword;
	szLink.Format(L"Provider=SQLOLEDB;Server=127.0.0.1;Database=PS_UserData;");
	m_pConnect->Open(_bstr_t(szLink), _bstr_t(szUid), _bstr_t(szPwd), adModeUnknown);
	return TRUE;
}
```
