//
// Created by brendena on 9/2/18.
//

#ifndef SDL2TEST_POSITIONCOMPONENT_H
#define SDL2TEST_POSITIONCOMPONENT_H

#include "Components.h"

class PositionComponent : public Component{
public:
    PositionComponent(){
        xpos = 0;
        ypos = 0;
    }
    PositionComponent(int x, int y){
        xpos = x;
        ypos = y;
    }


    int x() { return xpos; }
    int y() { return ypos; }

    void setPos(int x, int y){
        xpos = x;
        ypos = y;
    }

    void init() override
    {
        xpos = 0;
        ypos = 0;
    }

    void update() override
    {
        xpos++;
        ypos++;

    }

private:
    int xpos = 0;
    int ypos = 0;
};

#endif //SDL2TEST_POSITIONCOMPONENT_H
