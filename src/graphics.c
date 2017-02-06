#include "graphics.h"

#include <dos.h>
#include <stdlib.h>

#define VIDEO_SEGMENT   0xA000

#define sgn(x) ((x<0)?-1:((x>0)?1:0)) /* macro to return the sign of a
                                         number */

union REGS regs;

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
    offset = (y << 8) + (y << 6) + x;
    VGA[offset] = color;
}

void DrawLine(int x1, int y1, int x2, int y2, byte color) {
  int i, dx, dy, sdx, sdy, dxabs, dyabs, x, y, px, py;

  dx = x2 - x1;      /* the horizontal distance of the line */
  dy = y2 -y1;      /* the vertical distance of the line */
  dxabs = abs(dx);
  dyabs = abs(dy);
  sdx = sgn(dx);
  sdy = sgn(dy);
  x = dyabs>>1;
  y = dxabs>>1;
  px = x1;
  py = y1;

  VGA[(py<<8)+(py<<6)+px] = color;

  if (dxabs >= dyabs) { /* the line is more horizontal than vertical */
    for(i=0;i<dxabs;i++) {
      y+=dyabs;
      if (y >= dxabs) {
        y -= dxabs;
        py += sdy;
      }
      px += sdx;
      VGA[(py<<8)+(py<<6)+px] = color;
    }
  } else { /* the line is more vertical than horizontal */
    for(i=0;i<dyabs;i++) {
      x+=dxabs;
      if (x>=dyabs) {
        x-=dyabs;
        px+=sdx;
      }
      py+=sdy;
      VGA[(py<<8)+(py<<6)+px] = color;
    }
  }
}
