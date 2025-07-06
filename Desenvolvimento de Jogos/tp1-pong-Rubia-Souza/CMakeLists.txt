cmake_minimum_required(VERSION 3.26)
# Configurando o padrão c++
set(CMAKE_CXX_STANDARD 17)

# Configurando o nome e executável do projeto
set(PROJECT_NAME "tp1-pong")
project(${PROJECT_NAME})

find_package(SDL2 2.32.2 EXACT REQUIRED)
add_executable(${PROJECT_NAME}
        Source/Main.cpp
        Source/Math.cpp
        Source/Actors/Actor.cpp
        Source/Components/Component.cpp
        Source/Game.cpp
        Source/Actors/Paddle.cpp
        Source/Components/DrawComponent.cpp
        Source/Components/DrawComponent.h
        Source/Actors/Ball.cpp
        Source/Actors/Ball.h
        Source/Actors/Wall.cpp
        Source/Actors/Wall.h)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
