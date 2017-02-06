#include "graphics.h"

#include <dos.h>

#define VIDEO_SEGMENT   0xA000

union REGS regs;

typedef unsigned char byte;
byte far *VGA = (byte far*)0xA0000000L;     
unsigned short offset;

void SetupGraphicsMode() {
    regs.h.ah = 0x00;
    regs.h.al = 0x13;
    int86(0x10, &regs, &regs);
}

void SetupTextMode() {
    regs.h.ah = 0x00;
    regs.h.al = 0x03;
    int86(0x10, &regs, &regs);
}

void PlotPixel(int x, int y, unsigned char color) {
//    regs.h.ah = 0x0C;   /* function 0Ch = pixel plot */
//    regs.h.al = color;
//    regs.x.cx = x;      /* x location, from 0..319  */
//    regs.x.dx = y;      /* y location, from 0..199  */
//    int86(0x10,&regs,&regs);
//    offset = (SCREEN_WIDTH * y) + x;
    offset = (y << 8) + (y << 6) + x;
    VGA[offset] = color;
}
