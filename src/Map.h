//
// Created by brendena on 8/25/18.
//



#ifndef SDL2TEST_MAP_H
#define SDL2TEST_MAP_H


#include <SDL2/SDL.h>
#include <SDL_image.h>

#include "TextureManager.h"
#include "StaticGamePropertys.h"

class Map {
public:
    Map();
    ~Map();

    void loadMap(int arr[20][25]);
    void drawMap();

private:

    SDL_Rect src, dest;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[20][25];

};


#endif //SDL2TEST_MAP_H
