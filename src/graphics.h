#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#define SCREEN_WIDTH    320
#define SCREEN_HEIGHT   200
#define NUM_COLORS      256

typedef unsigned char byte;

extern byte *vbuff;

void SetupGraphicsMode();

void SetupTextMode();

void PlotPixel(int x, int y, unsigned char color);

void DrawLine(int x1, int y1, int x2, int y2, byte color);

void FillRectangle(int x1, int y1, int x2, int y2, byte color);

void PlotPixelBuffer(int x, int y, unsigned char color);

void DisplayBuffer();

#endif
