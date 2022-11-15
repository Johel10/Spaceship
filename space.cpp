#include "space.h"

Space::Space(){
    // Hides the cursor
    cci.dwSize = DEFAULT_SIZE_CURSOR;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cci);
}

void Space::gotoxy(int x, int y){
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}
