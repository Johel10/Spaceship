#ifndef GAME_H
#define GMAE_H

#include <iostream>
#include <vector>
#include "space.h"
#include "space_object.h"
#include "spaceship.h"
#include "asteroid.h"
#include "bullet.h"

// HUD elements
#define FIRST_ROW 0
#define SECOND_ROW 1
#define LIVES_POSITION 108
#define LIVES_TEXT "Lives:    "
#define SCORE_POSITION 85
#define SCORE_TEXT "Score: "
#define HEART static_cast<char>(3)
// Borders
#define HORIZONTAL_BORDER static_cast<char>(205)
#define VERTICAL_BORDER static_cast<char>(186)
#define UPPER_LEFT_CORNER static_cast<char>(201)
#define LOWER_LEFT_CORNER static_cast<char>(200)
#define UPPER_RIGHT_CORNER static_cast<char>(187)
#define LOWER_RIGHT_CORNER static_cast<char>(188)

class Game{
    private:
        Space* space;
        Spaceship* spaceship;
        std::vector<Bullet*>* bullets; 
        std::vector<Asteroid*>* asteroids;
        int score;
    public:
        Game(Space*, Spaceship*, std::vector<Bullet*>*, std::vector<Asteroid*>*);
        ~Game();
        void printBounds();
        void printScore();
        void printLives();
        void crash();
        void destroyAsteroid();
        void action();
        void play();
};

#endif
