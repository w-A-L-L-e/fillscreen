/*=============================================================================
author        : Walter Schreppers
filename      : benchmarks/pixeldemo.cpp
created       : 10/5/2022 at 18:21:12
modified      :
version       :
copyright     : Walter Schreppers
description   : Show full screen filled with random pixels and circle drawn
                and some lines. This was optimized so that 60FPS can be done
                with < 10% cpu load.
=============================================================================*/

#include "screen.h"
#include <cstring>
#include <iostream>
#include <random>

int randint(int maxVal) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(0, maxVal);

  return dis(gen);
}

int main(int argc, char **argv) {
  Screen screen(640, 400);
  unsigned int count = 0;
  int red = 255, green = 255, blue = 255;

  bool animate = false;
  if (argc == 4) {
    red = atoi(argv[1]);
    green = atoi(argv[2]);
    blue = atoi(argv[3]);
  } else {
    std::cout << "USAGE: " << argv[0]
              << " <red> <green> <blue> with color value 0-255. If omitted we "
                 "use 255 255 255 (which is white)"
              << std::endl;
    animate = true;
  }

  SDL_ShowCursor(SDL_DISABLE);
  screen.setFullscreen(true);
  int rdir = -1, bdir = -1, gdir = -1;
  while (screen.opened()) {
    screen.clear();
    screen.handle_events();

    if (animate) {
      red = (red + randint(2) * rdir);
      if (red < 10) {
        red = 10;
        rdir = 1;
      }
      if (red > 250) {
        red = 250;
        rdir = -1;
      }

      green = (green + randint(3) * gdir);
      if (green < 10) {
        green = 10;
        gdir = 1;
      }
      if (green > 250) {
        green = 250;
        gdir = -1;
      }

      blue = (blue + randint(5) * bdir);
      if (blue < 10) {
        blue = 10;
        bdir = 1;
      }
      if (blue > 250) {
        blue = 250;
        bdir = -1;
      }
    }

    // fill screen with given color or random color if no params given
    for (unsigned int y = 0; y < screen.height; y++) {
      screen.setColor(red, green, blue);
      screen.line(0, y, screen.width, y);
    }

    screen.draw();
  }

  return 0;
}
