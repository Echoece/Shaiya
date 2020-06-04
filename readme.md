**contents**
* ps_login ct file that solves the issue of the ps_login allowing client version -1 to pass through the service
* ps_login ct file that will decrease the amount of failed logins allowed before the client gets disconnected
* ps_login with the aforementioned mods applied plus anti-injection (nubness) and handshake fix (anton)

**notes**
```
00406A30 - jmp to fix sql injection - nubness
00404542 - jne to fix bad handshakes - anton

00F91238 - login attempt count
004045F4 - login attempt comparison - default is 10
004045FB - login attempt conditional jump

version check addresses
00404460 - call to version check
0044D488 - version check on/off value
00407400 - version check procedure
00407400 - compare version check on/off value
00407409 - compare client version to -01
00407418 - compare server version to -01
0040741D - compare client version to server version

connections
00411AAB - move max user value into eax
00411AB7 - compare max user value to client connections
00411ABD - jump if not less to close the connection

ignore max users
00411ABD - nop to remove conditional jump

solution for the -1 client version check exploit
0040740C - change to je 00407421
0040741B - change to je 00407421

values
0044DAE2 - login port value
0044EC60 - logged in users
00477CEC - max users
004785F8 - leave users

/uc command output
connections/leave users/max users
example: 1/0/1000
values come from:
00477CF8/004785F8/00477CEC
```
