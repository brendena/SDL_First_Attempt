//
// Created by brendena on 9/5/18.
//

#ifndef SDL2TEST_COLLISION_H
#define SDL2TEST_COLLISION_H

#include <SDL.h>

class Collision {
public:
    //Axis Aligned bounding box
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
};


#endif //SDL2TEST_COLLISION_H
