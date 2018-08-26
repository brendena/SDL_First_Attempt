//
// Created by brendena on 8/25/18.
//

#ifndef SDL2TEST_TEXTUREMANAGER_H
#define SDL2TEST_TEXTUREMANAGER_H

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include "StaticGamePropertys.h"

class TextureManager{
public:
    static SDL_Texture * loadTexture(const char* filename);
};



#endif //SDL2TEST_TEXTUREMANAGER_H
