**contents**
* ct file edited for ep5 (originally released for ep4) that prevents rune skill cutting (credit: Cups)
* ct file that stops all notice functions from injecting the database (/warning credit: Cups)
* revised version of shen's item mall solution for ep5 servers along with the source code
* ps_game that has been reversed to have no custom dll injections for those that don't want an item mall
* possible solution for capes being enchanted via client modification (probably packet injection)
* various cheat engine files that either solve bugs and exploits or add simple modifications to the game

**notes**
* ct files in this folder are also valid for "ep6" servers because they use an ep5 ps_game hooked with dlls
* the ps_game has an extra section beginning at address 04096000 that can be used for code caves ^_^

**game.exe**
* speed recreation
```
004AE1A4 - nop
004AE1A6 - nop
004AE1A8 - nop
004AE1AA - nop
004AE1AC - nop
004AE1AD - nop
004AE1AE - nop
004AE1B0 - nop
004AE1B2 - nop
004AE1B4 - nop
004AE1B9 - nop
004AE1BA - nop
004AE1BC - nop
004AE1C3 - nop
004AE1C9 - nop
004AE1D0 - nop
004AE1D6 - nop
004AE1E6 - nop
004AE1E8 - nop
```

* speed enchantment
```
004E2419 push 2
004E241B push 2
004E244A push 2
004E244C push 2
004E245D push 3
004E2466 push 3
```
