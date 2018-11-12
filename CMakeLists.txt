cmake_minimum_required(VERSION 3.9)

project(GroupProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(GroupProject main.cpp SDL_Plotter.h)
target_link_libraries(GroupProject SDL2main SDL2 SDL2_mixer)