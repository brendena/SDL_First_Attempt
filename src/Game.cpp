//
// Created by brendena on 8/25/18.
//

#include "Game.h"

Map* map;

Manager manager;
auto& player(manager.addEntity());


Game::Game(){

}
Game::~Game(){

}

void Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }


    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "SubZsystems initialised!.." << std::endl;
        window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
        if(window){
            std::cout << "Window created!" << std::endl;
        }
        StaticGamePropertys::renderer = SDL_CreateRenderer(window, -1, 0);
        if(StaticGamePropertys::renderer){
            SDL_SetRenderDrawColor(StaticGamePropertys::renderer, 255,255,255,255);
            std::cout << "Renderer Created!" << std::endl;
        }

        isRunning = true;
    } else{
        isRunning = false;
    }

    //player = new GameObject("../assets/santa.png", 0, 0);
    //enemy  = new GameObject("../assets/santa.png", 200, 0);
    map = new Map();

    player.addComponent<PositionComponent>();
    player.getComponent<PositionComponent>().setPos(100,100);
    player.addComponent<SpriteComponent>("../assets/santa.png");

}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }
}
void Game::update(){
    manager.update();
    manager.update();
}
void Game::render(){
    SDL_RenderClear(StaticGamePropertys::renderer);
    map->drawMap();
    manager.draw();
    SDL_RenderPresent(StaticGamePropertys::renderer);
}
void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(StaticGamePropertys::renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

bool Game::running(){
    return isRunning;
}