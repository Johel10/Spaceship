#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <conio.h>
#include "space_object.h"

// Chars to print the ship
#define CORNERS static_cast<char>(30)
#define LEFT_MID static_cast<char>(40)
#define CENTER static_cast<char>(207)
#define RIGHT_MID static_cast<char>(41)
#define BACK static_cast<char>(190)
// Lives
#define LIVES 3

class Spaceship : public Space_Object{
    private:
        int lives;
    public:
        Spaceship(int, int, Space*);
        ~Spaceship();
        void print();
        void erase();
        void move(int);
        bool moveValid(int);
        void die();
        int getLives();
        std::vector<std::pair<int, int>> getHitbox();
        bool shoot();
        std::pair<int, int> getCoordinates();
};

#endif
