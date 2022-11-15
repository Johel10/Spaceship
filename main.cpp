#include "game.h"
#include "space_object.h"
#include "spaceship.h"
#include "asteroid.h"
#include "bullet.h"
#include "space.h"

#define DEFAULT_X 58
#define DEFAULT_Y 26

int main(){

    // Game area and logic
    system("cls");
    Space* space = new Space();
    Spaceship* spaceship = new Spaceship(DEFAULT_X, DEFAULT_Y, space);
    std::vector<Bullet*> bullets;
    std::vector<Asteroid*> asteroids;
    // Asteroids
    for(int i = 0; i < 8; ++i){
        int x = rand()%(MAX_X - MIN_X)+MIN_X;
        int y = rand()%(MIN_Y+5 - MIN_Y)+MIN_Y;
        asteroids.push_back(new Asteroid(x, y, space));
    }

    Game game(space, spaceship, &bullets, &asteroids);
    game.printBounds();
    game.play();

    system("cls");

    delete spaceship;
    delete space;
    return 0;
}
