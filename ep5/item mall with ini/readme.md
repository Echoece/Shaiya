**contents**
* item mall dll that reads the username and password from an initialization file

**notes**
* the only difference in the source code is this database function
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
	GetPrivateProfileString(L"NCash", L"Uid", L"", szUsername, 255, L".\\ncash.ini"); //get username key
	GetPrivateProfileString(L"NCash", L"Pwd", L"", szPassword, 255, L".\\ncash.ini"); //get password key
	CString szLink; //initialize the query string variable
	CString szUid = szUsername; //convert the username to a string
	CString szPwd = szPassword; //convert the password to a string
	szLink.Format(L"Provider=SQLOLEDB;Server=127.0.0.1;Database=PS_UserData;"); //define the login string
	m_pConnect->Open(_bstr_t(szLink), _bstr_t(szUid), _bstr_t(szPwd), adModeUnknown); //execute the query
	return TRUE;
}
```
