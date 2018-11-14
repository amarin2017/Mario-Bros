#include <iostream>
#include "player.h"
#include "SDL_Plotter.h"

using namespace std;

int main(int argc, char ** argv)
{
    const int windowHeight = 600;
    const int windowWidth = 600;
    //random pixels
    SDL_Plotter g (windowHeight, windowWidth);

    int rectPosX=300;
    int rectPosY=300;
    int width=10;
    int height=10;


    while (!g.getQuit()) //loop goes forever until user puts exit
    {
     //grab input
        if (g.getKey() == UP_ARROW)
        {
            rectPosY = max(rectPosY -2, 0);

        }
        else if (g.getKey()== DOWN_ARROW)
        {
            rectPosY = min (rectPosY +2, windowHeight - height);
        }
        else if(g.getKey() == LEFT_ARROW)
        {
            rectPosX = max (rectPosX-2,0);
        }
        else if (g.getKey() == RIGHT_ARROW)
        {
            rectPosX = min (rectPosX+2, windowWidth-width);
        }



        //draw loop

        //reset background color
        for (int col = 0; col < windowWidth; col++)
        {
            for (int row=0; row < windowHeight; row++)
            {
                g.plotPixel(col, row, 0, 0, 0);
            }
        }

        //draw rectangle
        for (int col = rectPosX; col < width +rectPosX; col++)
        {
            for (int row=rectPosY; row < height+rectPosY; row++)
            {
                g.plotPixel(col, row, 250, 32, 5);
            }
        }
        
        if (g.getKey() != UP_ARROW || rectPosY != windowHeight)
        {
            rectPosY = min(rectPosY + 2, windowHeight-height);
        }

        if(g.kbhit()){
            g.getKey();
        }



        g.update();
    }
}

