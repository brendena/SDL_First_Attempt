//
// Created by brendena on 9/2/18.
//

#ifndef SDL2TEST_POSITIONCOMPONENT_H
#define SDL2TEST_POSITIONCOMPONENT_H

#include "Components.h"
#include "../Vector2D.h"

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

    }
    Vector2D position;
private:

};

#endif //SDL2TEST_POSITIONCOMPONENT_H
