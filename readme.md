**contents**
* ps_login ct file that solves the issue of the ps_login allowing client version -1 to pass through the service
* ps_login ct file that will decrease the amount of failed logins allowed before the client gets disconnected
* ps_login with the aforementioned mods applied plus anti-injection (nubness) and handshake fix (anton)

**connection overflow workaround**
```asm
00411ABD - nop jnl (not applied to ps_login)
```
