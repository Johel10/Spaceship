#ifndef SPACE_H
#define SPACE_H

#include <windows.h>
#include <iostream>

#define DEFAULT_SIZE_CURSOR 1

class Space{
    private:
        // Handle to print into the terminal
        const HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        // Struct to set the coordinates
        COORD dwPos;
        // Struct to configure the cursor
        CONSOLE_CURSOR_INFO cci;
    public:
        Space();
        void gotoxy(int, int);
};

#endif
