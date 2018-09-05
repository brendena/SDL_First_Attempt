//
// Created by brendena on 9/2/18.
//

#ifndef SDL2TEST_SPRITECOMPONENT_H
#define SDL2TEST_SPRITECOMPONENT_H

#include <SDL.h>
#include "Components.h"
#include "../TextureManager.h"

class SpriteComponent : public Component
{
public:
    SpriteComponent() = default;
    SpriteComponent(const char* path){
        setText(path);
    }

    void setText(const char* path){
        texture = TextureManager::loadTexture(path);
    }

    void init() override {

        transform = &entity->getComponent<TransformComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 32;
        destRect.w = destRect.h = 64;

    }

    void update() override {
        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
    }

    void draw() override {
        TextureManager::Draw(texture, srcRect, destRect);
    }

private:
    TransformComponent *transform;
    SDL_Texture * texture;
    SDL_Rect srcRect, destRect;


};


#endif //SDL2TEST_SPRITECOMPONENT_H
