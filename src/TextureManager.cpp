//
// Created by brendena on 8/25/18.
//

#include "TextureManager.h"

SDL_Texture * TextureManager::loadTexture(const char* filename){
    SDL_Surface * tmpSurface = IMG_Load(filename);
    SDL_Texture * playerTex = SDL_CreateTextureFromSurface(StaticGamePropertys::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return playerTex;
}