# mabuse Custom Planck Layout

* Forked from AJP10304 with little alterations.
* Still unfinished. I've swapped z and y (German layout) and made umlauts available in the function layer. 
* See complete layout [here](http://www.keyboard-layout-editor.com/#/gists/6b6e85da261d4b7a0772c268d0364416)
* Layout:

![mabuse layout](https://i.imgur.com/Z68z6df.png)


**Note:** In the tables below where there are two characters on a key, 
the second is the output when shift is applied.
  
**Note:** The below tables assume a UK layout.

**Note:** If you a bit older then you probly think of the Commodore 64 when recognizing only two cursor keys (the others, Up and Left are shifted by Raise). This is intentional. There's no need for four cursor keys.

Build and burn with `make planck/rev4:mabuse:dfu`

##### Main Qwerty Layer 

* Enter: when held, operates as shift.
* Only Cursor keys <Cursor Down> and <Cursor Right> here

```
| Tab  | Q      | W     | E     | R     | T     | Z     | U     | I     | O     | P     | Bksp  |
| Esc  | A      | S     | D     | F     | G     | H     | J     | K     | L     | ;:    | '"    |
| Shft | Y      | X     | C     | V     | B     | N     | M     | ,<    | .>    | /?    | Enter |
| Fn   | Ctrl   | Alt   | OS    | Lower | Space         | Raise | Down  | Right | PgDn  | Del   |
```
##### Function Layer
Activated when `fn` held in the above `qwerty` layer.

* Euro sign and German umlauts

```
|      |   €   |       |       |       |       |       |   ü   |       |       |       |       |
|      |   ä   |   ß   |       |       |       |       |       |       |   ö   |       |       |
| Shft |       |       |       |       |       |       |       |       |       |       |       |
|      |       |       |       |       |               |       |       |       |       |       |
```

##### Lower Layer
Activated when `Lower` is held in the above `qwerty` layer.

* Shifted numbers, _, +, (, ), {, }

```
| `    | !     | @     | #     | $     | %     | ^     | &     | *     | (     | )     | Del   |
| Del  |       |       |       |       |       |       | _     | =     | {     | }     |       |
| Shft |       |       |       |       |       |       |       |       |       |       |       |
|      |       |       |       |       | Space         | Pos1  | End   | Home  | End   |       |
```
 
 ##### Raise Layer
 Activated when `Raise` is held in the above `qwerty` layer.
 
 * Mainly numbers and function keys, +, -, <, > and [, ].
 * <Cursor Up> and <Cursor Left> are available here.

```
| ~   | 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 0     |        |
|     | F1    | F2    | F3    | F4    | F5    | F6    | -     | +     | [     | ]     | '      |
|     | F7    | F8    | F9    | F10   | F11   | F12   |       | <     | >     | \     |        |
|     |       |       |       |       | Space         | Up    | Left  | PgUp  |       |        |
```
 
##### Lower + Raise
Activated when `Lower` and `Raise` are held together the above `qwerty` layer.

* Audio controls in the same position as cursor keys from the `Raise` layer.  
* ????: Runs a macro for outputting sensitive information.  Do not use this store passwords.
* Reset: Enter bootloader for flashing firmware to the keyboard.
* CAPS: Toggle caps lock.

```
| ???? |Reset |Qwerty |       |       |       |       |       |       |       |       | Del   |
| CAPS |      |       |       |       |       |       | Mute  | Vol+  | Play  |       |       |
|      |      |       |       |       |       |       | Prev  | Vol-  | Next  |       |       |
|      |      |       |       |       |               |       |       |       |       |       |
``` 
