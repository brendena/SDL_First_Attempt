//
// Created by brendena on 8/25/18.
//

#ifndef SDL2TEST_GAMEOBJECT_H
#define SDL2TEST_GAMEOBJECT_H

#include "TextureManager.h"

class GameObject {
public:
    GameObject(const char * texturesheet, int x, int y);
    ~GameObject();

    void Update();
    void Render();

private:
    int xpos;
    int ypos;
    SDL_Texture * objTexture;
    SDL_Rect srcRect, destRect;
};


#endif //SDL2TEST_GAMEOBJECT_H
