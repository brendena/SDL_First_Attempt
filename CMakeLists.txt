cmake_minimum_required(VERSION 3.4)
project(SDL2Test)
set (CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(SDL2Test main.cpp src/Game.cpp src/TextureManager.cpp src/GameObject.cpp src/Map.cpp src/StaticGamePropertys.cpp src/StaticGamePropertys.h src/ECS.h src/Components.h)
target_link_libraries(SDL2Test ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})