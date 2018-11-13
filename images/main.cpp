#include <iostream>

#include "SDL_Plotter.h"

using namespace std;

int main(int argc, char ** argv)
{
    const int windowHeight = 600;
    const int windowWidth = 1000;

    SDL_Plotter g(windowHeight,windowWidth);

    int rectPosX = 200;
    int rectPosY = 220;
    int width = 100;
    int height = 100;

    while (!g.getQuit())
    {
        if (g.getKey() == UP_ARROW){
            rectPosY = max(rectPosY - 1,0);
        } else if (g.getKey() == DOWN_ARROW){
            rectPosY = min(rectPosY + 1, windowHeight-height);
        } else if (g.getKey() == RIGHT_ARROW){
            rectPosX = max(rectPosX + 1,0);
        } else if (g.getKey() == LEFT_ARROW){
            rectPosX = min(rectPosX - 1, windowWidth-width);
        }

        for (int col = rectPosX; col < width + rectPosX; ++col){
            for(int row = rectPosY; row < height + rectPosY; ++row){
                g.plotPixel(col,row,0,0,220);
            }
        }
        g.update();

        if(g.kbhit()){
            g.getKey();
        }
    }
}