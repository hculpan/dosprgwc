#include <conio.h>
#include <stdlib.h>
#include <graph.h>

//#include "graphics.h"

//typedef unsigned char  byte;
typedef unsigned short word;

word *my_clock = (word *)0x046C;      /* this points to the 18.2hz system
                                         clock. */

void main() {
  struct videoconfig vconfig;
  int width;
  int height;
    // int i = 0, j = 0, color = 0;
    //
    // srand(*my_clock);
    //
    // SetupGraphicsMode();
    //
    // while (1) {
    //   for (j = 10; j < SCREEN_HEIGHT - 10; j++) {
    //     for (i = 10; i < SCREEN_WIDTH - 10; i++) {
    //       vbuff[(j << 8) + (j << 6) + i] = color;
    //     }
    //   }
    //
    //   DisplayBuffer();
    //
    //   if (kbhit()) {
    //     char c = getch();
    //     if (c == 27) {
    //       break;
    //     }
    //   }
    //
    //   color = (color + 1) % 16;
    // }
    //
    // SetupTextMode();

    _setvideomode(_XRES256COLOR);

    _getvideoconfig(&vconfig);
    width = vconfig.numxpixels;
    height = vconfig.numypixels;
    _setcolor(10);
    _moveto(0, 0);
    _lineto(width - 1, 0);

    getch();

    _setvideomode(_TEXTC80);

    cprintf("Dim: %dx%d\n", vconfig.numxpixels, vconfig.numypixels);

}
