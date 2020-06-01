**contents**

* ct file that blocks pets, wings, and costumes from being equipped or switched in pvp zones
* item mall dll that reads the account username and password from Db.ini (don't use it live)

**warning**

* ps_game may not start the first time
* ps_game occasionally crashes when making a purchase

**notes**

* the difference between this item mall dll and the one in the ep5 directory is this function

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
	WCHAR szUid[255];
	WCHAR szPwd[255];
	GetPrivateProfileString(L"DbInfo", L"Account", L"", szUid, 255, L".\\Db.ini");
	GetPrivateProfileString(L"DbInfo", L"Pw", L"", szPwd, 255, L".\\Db.ini");
	CString szLink; 
	CString szUsername = szUid;
	CString szPassword = szPwd;
	szLink.Format(L"Provider=SQLOLEDB;Server=127.0.0.1;Database=PS_UserData;");
	m_pConnect->Open(_bstr_t(szLink), _bstr_t(szUsername), _bstr_t(szPassword), adModeUnknown);
	return TRUE;
}
```
