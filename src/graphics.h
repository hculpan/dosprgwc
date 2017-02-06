#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#define SCREEN_WIDTH    320
#define SCREEN_HEIGHT   200
#define NUM_COLORS      256

void SetupGraphicsMode();

void SetupTextMode();

void PlotPixel(int x, int y, unsigned char color);

#endif
