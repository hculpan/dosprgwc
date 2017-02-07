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
        int x1 = rand()%SCREEN_WIDTH,
            y1 = rand()%SCREEN_HEIGHT,
            x2 = rand()%SCREEN_WIDTH,
            y2 = rand()%SCREEN_HEIGHT,
            z = rand()%NUM_COLORS;
        
        DrawLine(x1, y1, x2, y2, z);
        if (i % 100 == 0 && kbhit()) {
            char c = getch();
            if (c == 27) {
                i = 20001;
                break;
            }
        }
    }

    if (i < 20000) { // we were not prematurely interrupted
        getch();
    }

    SetupTextMode();
}
