//
// Created by brendena on 8/25/18.
//

#ifndef SDL2TEST_STATICGAMEOBJECT_H
#define SDL2TEST_STATICGAMEOBJECT_H

#include <vector>
#include <SDL2/SDL.h>
#include <SDL_image.h>

class ColliderComponent;

class StaticGamePropertys {
public:
    static SDL_Renderer * renderer;
    static SDL_Event event;
    static std::vector<ColliderComponent*> colliders;

    static void AddTile(int i, int x, int y);
};


#endif //SDL2TEST_STATICGAMEOBJECT_H
