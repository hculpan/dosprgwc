#include <conio.h>
#include <stdlib.h>

#include "graphics.h"

typedef unsigned char  byte;
typedef unsigned short word;

word *my_clock = (word *)0x046C;      /* this points to the 18.2hz system
                                         clock. */

    void main() {
    int i = 0;
    
    srand(*my_clock);

    SetupGraphicsMode();

    for (i = 0; i < 10000; i++) {
        int x = rand()%SCREEN_WIDTH,
            y = rand()%SCREEN_HEIGHT,
            z = rand()%NUM_COLORS;
        
        PlotPixel(x, y, z);
    }
    
    getch();

    SetupTextMode();
}
