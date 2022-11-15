#include "spaceship.h"

Spaceship::Spaceship(int x, int y, Space* space) : Space_Object(x, y, space){
    lives = LIVES;
}

Spaceship::~Spaceship(){
    lives = 0;
}

void Spaceship::print(){
    space->gotoxy(x, y);
    std::cout << CORNERS;
    space->gotoxy(x-1, y+1);
    std::cout << LEFT_MID << CENTER << RIGHT_MID;
    space->gotoxy(x-2, y+2);
    std::cout << CORNERS << BACK << " " << BACK << CORNERS;
}

void Spaceship::erase(){
    space->gotoxy(x, y);
    std::cout << " ";
    space->gotoxy(x-2, y+1);
    std::cout << "     ";
    space->gotoxy(x-2, y+2);
    std::cout << "     ";
}

void Spaceship::move(int direction){
    
    if(moveValid(direction)){
        erase();
        switch(direction){
            case UP:
                --y;
                break;
            case LEFT:
                --x;
                break;
            case RIGHT:
                ++x;
                break;
            case DOWN:
                ++y;
                break;
            default:
                break;
        }
        print();
    }
}

bool Spaceship::moveValid(int direction){
    switch(direction){
        case UP:
            return y-1 >= MIN_Y ? true : false;
        case LEFT:
            return x-3 >= MIN_X ? true : false;
        case RIGHT:
            return x+3 <= MAX_X ? true : false;
        case DOWN:
            return y+3 <= MAX_Y ? true : false;
        defalut:
            break;
    }
    return false;
}

void Spaceship::die(){
    // First explosion
    erase();
    space->gotoxy(x, y);
    std::cout << "*";
    space->gotoxy(x-1, y+1);
    std::cout << "*" << CENTER << "*";
    space->gotoxy(x-2, y+2);
    std::cout << CORNERS << BACK << "*" << BACK << CORNERS;
    Sleep(600);

    // Second explosion
    erase();
    space->gotoxy(x, y);
    std::cout << "*";
    space->gotoxy(x-2, y+1);
    std::cout << "* * *";
    space->gotoxy(x-2, y+2);
    std::cout << "** **";
    Sleep(600);
    erase();

    // One live less
    this->lives = lives-1;
    if(lives) print();
}

int Spaceship::getLives(){
    return lives;
}

std::vector<std::pair<int, int>> Spaceship::getHitbox(){
    std::vector<std::pair<int, int>> hitbox;
    // Front -> 1 char
    hitbox.push_back(std::pair<int, int>(x, y));
    // Mid -> 3 chars
    for(int i = 0; i < 3; ++i){
        hitbox.push_back(std::pair<int, int>(x-1+i, y+1));
    }
    // Back -> 5 chars
    for(int i = 0; i < 5; ++i){
        hitbox.push_back(std::pair<int, int>(x-2+i, y+2));
    }

    return hitbox;
}

bool Spaceship::shoot(){
    if(kbhit()){
        return getch() == 'q' ? true : false;
    }
    return false;
}

std::pair<int, int> Spaceship::getCoordinates(){
    std::pair<int, int> coordinates;
    coordinates.first = x;
    coordinates.second = y;
    return coordinates;
}
