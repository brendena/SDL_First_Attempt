//
// Created by brendena on 8/27/18.
//

#ifndef SDL2TEST_COMPONENTS_H
#define SDL2TEST_COMPONENTS_H
#include "ECS.h"

class PositionComponent : public Component{
public:
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

#endif //SDL2TEST_COMPONENTS_H
