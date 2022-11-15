#ifndef BULLET_H
#define BULLET_H

#include "space_object.h"

#define BULLET static_cast<char>(250)

class Bullet : public Space_Object{
    public:
        Bullet(int, int, Space*);
        ~Bullet();
        void print();
        void erase();
        void move();
        bool moveValid(int);
        std::pair<int, int> getHitbox();
        bool limit();
}; 

#endif