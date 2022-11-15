#include "asteroid.h"

Asteroid::Asteroid(int x, int y, Space* space) : Space_Object(x, y, space){}

Asteroid::~Asteroid(){}

void Asteroid::print(){
    space->gotoxy(x, y);
    std::cout << ASTEROID;
}

void Asteroid::erase(){
    space->gotoxy(x, y);
    std::cout << " ";
}

void Asteroid::move(){
    if(moveValid(DOWN)){
        erase();
        ++y;
        print();
    } else {
        reset();
    }
}

bool Asteroid::moveValid(int direction){
    return (direction == DOWN && y+1 <= MAX_Y) ? true : false;
}

std::pair<int, int> Asteroid::getHitbox(){
    std::pair<int, int> hitbox;
    hitbox.first = x;
    hitbox.second = y;
    return hitbox;
}

void Asteroid::reset(){
    erase();
    y = randomSpawn('y');
    x = randomSpawn('x');
    print();
}

int Asteroid::randomSpawn(char coordinate){
    if(coordinate == 'x'){
        return rand()%(MAX_X - MIN_X)+MIN_X; // Random valid "x" position
    } else if(coordinate == 'y'){
        return rand()%(4)+MIN_Y+1; // Random logic "y" position
    }
    return MIN_Y; // Rasonable valid position for x and y
}
