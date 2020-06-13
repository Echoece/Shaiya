**contents**
* ct file that blocks pets, wings, and costumes from being equipped or switched in pvp zones
* item mall dll that reads the username and password from Db.ini

**notes**
* ct files in the ep5 folder can be used with ep6 because the ps_game is the same file
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
	Sleep(500); //delay the function for a bit
	wchar_t szUsername[255]; //initialize the username variable and declare a buffer size
	wchar_t szPassword[255]; //initialize the password variable and declare a buffer size
	GetPrivateProfileString(L"DbInfo", L"Account", L"", szUsername, 255, L".\\Db.ini"); //get username key
	GetPrivateProfileString(L"DbInfo", L"Pw", L"", szPassword, 255, L".\\Db.ini"); //get password key
	CString szLink; //initialize the query string variable
	CString szUid = szUsername; //convert the username to a string
	CString szPwd = szPassword; //convert the password to a string
	szLink.Format(L"Provider=SQLOLEDB;Server=127.0.0.1;Database=PS_UserData;"); //define the login string
	m_pConnect->Open(_bstr_t(szLink), _bstr_t(szUid), _bstr_t(szPwd), adModeUnknown); //execute the query
	return TRUE;
}
```
