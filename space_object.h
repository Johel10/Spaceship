#ifndef SPACE_OBJECT_H
#define SPACE_OBJECT_H

#include <iostream>
#include <vector>
#include <utility>
#include "space.h"

// Arrows / controls / direction
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SHOOT 113
// MIN / MAX valid positions for space objects
#define MIN_X 1
#define MAX_X 118
#define MIN_Y 3
#define MAX_Y 28

class Space_Object{
    protected:
        int x;
        int y;
        Space* space;
    public:
        Space_Object(int, int, Space*);
        virtual ~Space_Object();
        virtual void print() = 0;
        virtual void erase() = 0;
        virtual bool moveValid(int) = 0;
};

#endif
