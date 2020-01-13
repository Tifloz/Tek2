cmake_minimum_required(VERSION 3.13)
project(Graph)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -I. -lsfml-graphics -lsfml-window -lsfml-system")

add_executable(Graph
        main.cpp
        Core.cpp
        Core.hpp Scene.cpp Scene.hpp Sprite.cpp Sprite.hpp menu/Menu.cpp menu/Menu.hpp Socket.cpp Socket.hpp Error.hpp Game/Game.hpp Game/Game.cpp Game/Map.hpp Game/Map.cpp Game/Team.hpp Game/Team.cpp Game/Player.hpp Game/Player.cpp button/Button.hpp button/Button.cpp)
