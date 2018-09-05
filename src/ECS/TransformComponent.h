//
// Created by brendena on 9/2/18.
//

#ifndef SDL2TEST_POSITIONCOMPONENT_H
#define SDL2TEST_POSITIONCOMPONENT_H

#include "Components.h"
#include "../Vector2D.h"
#include "../StaticGamePropertys.h"

class TransformComponent : public Component{
public:
    TransformComponent(){
        position.x = 0;
        position.y = 0;
    }
    TransformComponent(float x, float y){
        position.x = x;
        position.y = y;
    }


    void update() override
    {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
    void init() override
    {
        velocity.x = 0;
        velocity.y = 0;
    }
    Vector2D position;
    Vector2D velocity;
    int speed = 3;
private:

};

#endif //SDL2TEST_POSITIONCOMPONENT_H
