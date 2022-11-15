#ifndef ASTEROID_H
#define ASTEROID_H

#include <stdlib.h>
#include "space_object.h"

#define ASTEROID static_cast<char>(42)

class Asteroid : public Space_Object{
    public:
        Asteroid(int, int, Space*);
        ~Asteroid();
        void print();
        void erase();
        void move();
        bool moveValid(int);
        std::pair<int, int> getHitbox();
        void reset();
        int randomSpawn(char);
};

#endif
