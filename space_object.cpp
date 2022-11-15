#include "space_object.h"

Space_Object::Space_Object(int x, int y, Space* space){
    this-> x = x;
    this-> y = y;
    this-> space = space;
}

Space_Object::~Space_Object(){
    x = 0;
    y = 0;
    space = NULL;
}
