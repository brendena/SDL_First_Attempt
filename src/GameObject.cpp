//
// Created by brendena on 8/25/18.
//

#include "GameObject.h"


GameObject::GameObject(const char * texturesheet, int x, int y){
    objTexture = TextureManager::loadTexture(texturesheet);

    xpos = x;
    ypos = y;
}

GameObject::~GameObject(){

}

void GameObject::Update(){
    xpos++;
    ypos++;

    srcRect.h = 3000;
    srcRect.w = 3000;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = 64;
    destRect.h = 64;
}

void GameObject::Render(){
    SDL_RenderCopy(StaticGamePropertys::renderer, objTexture, &srcRect, &destRect);
}