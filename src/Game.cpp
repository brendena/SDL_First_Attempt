//
// Created by brendena on 8/25/18.
//

#include "Game.h"

Map* map;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

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

    map = new Map();

    player.addComponent<TransformComponent>(2);
    player.addComponent<KeyboardController>();
    player.addComponent<SpriteComponent>("../assets/santa.png");
    player.addComponent<ColliderComponent>("player");

    wall.addComponent<TransformComponent>(300.0f, 300.0f,300,20,1);
    wall.addComponent<SpriteComponent>("../assets/dirt.png");
    wall.addComponent<ColliderComponent>("wall");
}

void Game::handleEvents()
{
    SDL_PollEvent(&StaticGamePropertys::event);

    switch(StaticGamePropertys::event.type){
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }
}
void Game::update(){
    manager.refresh();
    manager.update();


    auto wallCollision = wall.getComponent<ColliderComponent>().collider;
    auto playerCollision = player.getComponent<ColliderComponent>().collider;
    if(Collision::AABB(playerCollision,wallCollision)){
        std::cout << "wall hit" << std::endl;
    }

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