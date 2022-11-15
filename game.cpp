#include "game.h"

Game::Game(Space* space, Spaceship* spaceship, std::vector<Bullet*>* bullets, std::vector<Asteroid*>* asteroids){
    this-> space = space;
    this-> spaceship = spaceship;
    this-> bullets = bullets;
    this-> asteroids = asteroids;
    score = 0;
}

Game::~Game(){
    space = NULL;
    spaceship = NULL;
    bullets = NULL;
    asteroids = NULL;
    score = 0;
}

void Game::printBounds(){
    // Horizontal
    for(int i = MIN_X; i <= MAX_X; ++i){
        // Superior
        space->gotoxy(i, MIN_Y-1);
        std::cout << HORIZONTAL_BORDER;
        // Inferior
        space->gotoxy(i, MAX_Y+1);
        std::cout << HORIZONTAL_BORDER;
    }

    // Vertical
    for(int i = MIN_Y; i <= MAX_Y; ++i){
        // Left
        space->gotoxy(MIN_X-1, i);
        std::cout << VERTICAL_BORDER;
        // Right
        space->gotoxy(MAX_X+1, i);
        std::cout << VERTICAL_BORDER;
    }

    // Corners
    space->gotoxy(MIN_X-1, MIN_Y-1);
    std::cout << UPPER_LEFT_CORNER;
    space->gotoxy(MIN_X-1, MAX_Y+1);
    std::cout << LOWER_LEFT_CORNER;
    space->gotoxy(MAX_X+1, MIN_Y-1);
    std::cout << UPPER_RIGHT_CORNER;
    space->gotoxy(MAX_X+1, MAX_Y+1);
    std::cout << LOWER_RIGHT_CORNER;
}

void Game::printScore(){
    space->gotoxy(SCORE_POSITION, SECOND_ROW);
    std::cout << SCORE_TEXT;
    space->gotoxy(SCORE_POSITION+strlen(SCORE_TEXT), SECOND_ROW);
    std::cout << score;
}

void Game::printLives(){
    space->gotoxy(LIVES_POSITION, SECOND_ROW);
    std::cout << LIVES_TEXT;
    space->gotoxy(LIVES_POSITION+strlen(LIVES_TEXT)-3, SECOND_ROW);
    for(int i = 0; i < spaceship->getLives(); ++i){
        std::cout << HEART;
    }
}

void Game::crash(){
    // Get the hitboxes
    std::vector<std::pair<int, int>> spaceshipHitbox = spaceship->getHitbox();
    std::vector<std::pair<int, int>> asteroidsHitboxes;
    for(Asteroid* asteroid : *asteroids){
        asteroidsHitboxes.push_back(asteroid->getHitbox());
    }

    // Find if a crash was produced
    bool crash = false;
    std::vector<std::pair<int, int>>::iterator it_ship = spaceshipHitbox.begin();
    while(!crash && it_ship != spaceshipHitbox.end()){
        std::vector<std::pair<int, int>>::iterator it_ast = asteroidsHitboxes.begin();
        while(!crash && it_ast != asteroidsHitboxes.end()){
            if(*it_ship == *it_ast) crash = true;
            ++it_ast;
        }
        ++it_ship;
    }

    if(crash){
        for(Asteroid* asteroid : *asteroids){
            asteroid->reset();
        }
        spaceship->die();
    } 
}

void Game::destroyAsteroid(){
    // Get hitboxes
    std::vector<std::pair<int, int>> bulletsHitboxes;
    std::vector<std::pair<int, int>> asteroidsHitboxes;
    for(Bullet* bullet : *bullets){
        bulletsHitboxes.push_back(bullet->getHitbox());
    }
    for(Asteroid* asteroid : *asteroids){
        asteroidsHitboxes.push_back(asteroid->getHitbox());
    }

    // Find if a crash was produced
    bool destroyAsteroid = false;
    std::vector<std::pair<int, int>>::iterator it_bul = bulletsHitboxes.begin();
    while(!destroyAsteroid && it_bul != bulletsHitboxes.end()){
        std::vector<std::pair<int, int>>::iterator it_ast = asteroidsHitboxes.begin();
        while(!destroyAsteroid && it_ast != asteroidsHitboxes.end()){
            if(*it_bul == *it_ast ||
                it_bul->first == it_ast->first && it_bul->second-1 == it_ast->second){
                int bulletIndex = it_bul - bulletsHitboxes.begin();
                int asteroidIndex = it_ast - asteroidsHitboxes.begin();
                (*bullets)[bulletIndex]->erase();
                (*asteroids)[asteroidIndex]->reset();
                score += 10;
            }
            ++it_ast;
        }
        ++it_bul;
    }

    if(destroyAsteroid){
        for(Asteroid* asteroid : *asteroids){
            asteroid->reset();
        }
        spaceship->die();
    } 
}

void Game::action(){
    if(kbhit()){
        char key = getch();
        //reforma, pasar w a UP por ejemplo...
        if(key == UP || key == LEFT || key == RIGHT || key == DOWN){
            spaceship->move(static_cast<int>(key));
        } else if(key == SHOOT){
            std::pair<int, int> coordinates = spaceship->getCoordinates();
            bullets->push_back(new Bullet(coordinates.first, coordinates.second-1, space));
            bullets->back()->print();
        }
    }
}

void Game::play(){
    spaceship->print();
    bool gameOver = false;
    space->gotoxy(10, 0);
    std::cout << "C++ Spaceship Game";

    while(!gameOver){
        printLives();
        printScore();
        action();
        for(std::vector<Bullet*>::iterator it = (*bullets).begin(); it != (*bullets).end(); ++it){
            if((*it)->limit()){
                (*it)->erase();
                //bullets->erase(it);
            } else {
                (*it)->move();
            }
        }
        for(Asteroid* asteroid : *asteroids){
            asteroid->move();
        }
        destroyAsteroid();
        crash();
        Sleep(60);
        if(!spaceship->getLives()) gameOver = true;
    }
}
