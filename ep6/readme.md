**contents**
* ct file that blocks pets, wings, and costumes from being equipped or switched in pvp zones
* item mall dll that reads the username and password from Db.ini (file name case-insensitive)

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
	wchar_t szPath[255]; //initialize a variable and set a buffer for the initialization file path
	GetCurrentDirectory(MAX_PATH, szPath); //read the current directory
	wcscat(szPath, L".\\Db.ini"); //get the absolute path to the initialization file
	wchar_t szUsername[255]; //initialize a variable and buffer for the username key
	wchar_t szPassword[255]; //initialize a variable and buffer for the password key
	GetPrivateProfileString(L"DbInfo", L"Account", L"", szUsername, 255, szPath); //return the username key
	GetPrivateProfileString(L"DbInfo", L"Pw", L"", szPassword, 255, szPath); //return the password key
	CString szLink; //initialize the connection string variable
	CString szUid = szUsername; //convert the username to a string
	CString szPwd = szPassword; //convert the password to a string
	szLink.Format(L"Provider=SQLOLEDB;Server=127.0.0.1;Database=PS_UserData;"); //define the connection string
	m_pConnect->Open(_bstr_t(szLink), _bstr_t(szUid), _bstr_t(szPwd), adModeUnknown); //login with the account
	return TRUE;
}
```
