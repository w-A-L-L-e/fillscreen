# fillscreen

Tiny sdl program that fills screen with random fading colors or any specific rgb color passed.

# INSTALLATION

Make install puts fillscreen binary in ~/bin

```
make
make install
```

# Running

Without arguments we fade the screen to random rgb colors

```
./fillscreen
```

Passing in red, green blue fills screen with your specified color (hides mouse and is fullscreen on startup)

For instance dark blue:

```
./fillscreen 20 20 200
```

Pressing q or escape exits the program. Pressing f toggles fullscreen mode.
