#include "bullet.h"

Bullet::Bullet(int x, int y, Space* space) : Space_Object(x, y, space){}

Bullet::~Bullet(){}

void Bullet::print(){
    if(moveValid(UP)){
        space->gotoxy(x, y);
        std::cout << BULLET;
    }
}

void Bullet::erase(){
    space->gotoxy(x, y);
    std::cout << " ";
}

void Bullet::move(){
    erase();
    if(moveValid(UP)){
        --y;
        print();
    }
}

bool Bullet::moveValid(int direction){
    return (direction == UP && y-1 <= MAX_Y) ? true : false;
}

std::pair<int, int> Bullet::getHitbox(){
    std::pair<int, int> hitbox;
    hitbox.first = x;
    hitbox.second = y;
    return hitbox;
}

bool Bullet::limit(){
    return y == MIN_Y ? true : false;
}
