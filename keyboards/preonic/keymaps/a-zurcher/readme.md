# a-zurcher Preonic layout

German layout, with keymaps close to "regular" keyboards and a MIDI layer for music production.

Layers:
- **QWERTZ layer** (Lower+Raise+B)
- **MIDI layer** (Lower+Raise+N)
- **Raise**: F keys, media + volume control
- **Lower**: F keys, accents, Home, Pg Down, Pg Up, End
- **Adjust**: switch between QWERTZ and MIDI layers, use keyboard as a mouse

## Main layer
````
,-----------------------------------------------------------------------------------.
| Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Tab  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Del  |
|------+------+------+------+------+-------------+------+------+------+------+------|
| Caps |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   #  |Termin|
|------+------+------+------+------+------|------+------+------+------+------+------|
| Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  | Enter|
|------+------+------+------+------+------+------+------+------+------+------+------|
| Ctrl | SUPER| LAlt | RAlt | Lower|    Space    | Raise| Left | Down |  Up  | Right|
`-----------------------------------------------------------------------------------'
````
`Termin` key is Super + F12, used for dropdown terminal (Yakuake)

## MIDI layer
```
,-----------------------------------------------------------------------------------.
|      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |  n/a |  C#3 |  D#3 |  n/a |  F#3 |  G#3 |  A#3 | n/a  |  C#4 |  D#4 |      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|      |  C3  |  D3  |  E3  |  F3  |  G3  |  A3  |  B3  |  C4  |  D4  |  E4  |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      | Oct- | Oct+ |  n/a |  n/a |  n/a |  n/a |  n/a |  n/a | Vel- | Vel+ |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |
`-----------------------------------------------------------------------------------'
```
NOTE: here the `n/a` keys do nothing.

## Lower layer

````
,-----------------------------------------------------------------------------------.
|   ^  |      |      |      |      |      |      |      |      |   ß  |   '  |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |   Ü  |   +  |      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |   Ö  |   Ä  |   #  |      |
|------+------+------+------+------+------|------+------+------+------+------+------|
|      |   <  |   >  |   ¸  |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
| print|      |      |      |      |     Play    |      | Home | PgDn | PgUp | End  |
`-----------------------------------------------------------------------------------'
````

## Raise layer

```
,-----------------------------------------------------------------------------------.
|   °  |      |      |      |      |      |      |      |      |   ?  |   `  |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |   Ü  |   *  |      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |   Ö  |   Ä  |   '  |      |
|------+------+------+------+------+------|------+------+------+------+------+------|
|      |   |  |      |   ¸  |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
| print|      |      |      |      |     Play    |      | Prev | Vol- | Vol+ | Next |
`-----------------------------------------------------------------------------------'
```

## Adjust (lower + raise)
````
,-----------------------------------------------------------------------------------.
|      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |RESET |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------|------+------+------+------+------+------|
|      |      |      |      |      |QWERTZ| MIDI |      |mouse1|mouse2|      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |             |      |Lmouse|Dmouse|Umouse|Rmouse|
`-----------------------------------------------------------------------------------'
````

