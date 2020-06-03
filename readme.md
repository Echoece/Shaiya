**contents**
* ps_login ct file that solves the issue of the ps_login allowing client version -1 to pass through the service
* ps_login ct file that will decrease the amount of failed logins allowed before the client gets disconnected
* ps_login with the aforementioned mods applied plus anti-injection (nubness) and handshake fix (anton)
* Insert_Action_Log_E procedure that changes the mapid and coordinates of characters that log off in D2
* apostrophe removal query for mobs, skills, and items that should be executed after updating the tables

**connection overflow workaround**
* 00411ABD - nop jnl (not applied to ps_login)

**todo**
* solve this error with server files prior to ep5 (with ep5 files, apostrophes are escaped with underscores)
```
2020-06-03 17:14:58 err=-1, [Microsoft][ODBC SQL Server Driver][SQL Server]Incorrect syntax near 's'., SQL STATE: 42000, NATIVE ERROR: 102 (0x66)

2020-06-03 17:14:58 DBWrite::LogGame: err=-1, query=EXEC usp_Insert_Action_Log_E 'aaa',1,1,'ranger', 3,700,1, 656.637634,77.363625,1770.744751, '2020-06-03 17:14:58' ,131, 5,8,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'Billie's Favor','Billie Lake',NULL,NULL
```
* failing to insert quest details in the action log when there's an apostrophe in the npc or quest name
