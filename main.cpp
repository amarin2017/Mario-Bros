#include <iostream>
#include "player.h"
#include "Collision.h"
#include "SDL_Plotter.h"
#include "Collision.h"
#include "Map.h"
using namespace std;

int main(int argc, char ** argv)
{
    const int windowHeight = 436;
    const int windowWidth = 673;
    //random pixels
    SDL_Plotter g (windowHeight, windowWidth);

    int rectPosX=300;
    int rectPosY=600;
    int width=10;
    int height=10;
    int gravity =0;
    int jump =0;
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
            rectPosX -= 1; //= max (rectPosX-2,0);
        }
        else if (g.getKey() == RIGHT_ARROW)
        {
            rectPosX +=1; //= min (rectPosX+2, windowWidth-width);
        }

//        if (rectPosX <0)
//        {
//            rectPosX =0;
//        }
//        if (rectPosY < 0)
//        {
//            rectPosY =0;
//        }


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


        //this sorta makes the block to jump??
        if (g.getKey() != UP_ARROW || rectPosY == windowHeight)
        {
                rectPosY = min (rectPosY +2, windowHeight - height);

        }


        
        //space for the bricks
        //top right
        for (int col=100; col < width+300; ++col)
        {
            for (int row = 200; row < width+ 200; ++row)
            {
                g.plotPixel(col, row, 255, 255, 255);
            }
            
        }
        
        //top left
        for (int col=500; col < width+600; ++col)
        {
            for (int row = 200; row < width+ 205; ++row)
            {
                g.plotPixel(col, row, 255, 255, 255);
            }
            
        }
        
        
//        for (int col=100; col < width+300; ++col)
//        {
//            for (int row = 400; row < width+ 400; ++row)
//            {
//                g.plotPixel(col, row, 255, 255, 0);
//            }
//
//        }
        
        //bottom left
        for (int col=0; col < width+300; ++col)
        {
            for (int row = 350; row < width + 370; ++row)
            {
                g.plotPixel(col, row, 255, 255, 255);
            }
            
        }
        
        //bottom right
        for (int col=450; col < width+673; ++col)
        {
            for (int row = 350; row < width + 370; ++row)
            {
                g.plotPixel(col, row, 255, 255, 255);
            }
            
        }
        
        
        
        
        
        
        //limit to bottom left
        if (rectPosY == 370 && rectPosX < 305)
        {
            rectPosY = 436;
        }
        
        //limit to bottom right
        if (rectPosY == 370 && rectPosX >450 && rectPosX < 673)
        {
            rectPosY = 436;
        }
        
        
        
        
        
        
    
        //bottom left
        if (rectPosY == 350 && rectPosX < 300)
        {
                rectPosY = 330;
        }
        //bottom right
        if (rectPosY == 350 && rectPosX >450 && rectPosX < 673)
        {
            rectPosY = 330;
        }
        
        
        
        
        //top right
        if (rectPosY == 200 && rectPosX < 600 && rectPosX > 500)
        {
                rectPosY = 180;
        }
        if (rectPosY == 210 && rectPosX <600 && rectPosX > 500)
        {
            rectPosY = 330;
        }
       
        
        
        
        
        //top left
        if (rectPosY == 200 && rectPosX > 100 && rectPosX < 300)
        {
            rectPosY = 180;
        }
        
        if (rectPosY == 210 && rectPosX > 100 && rectPosX < 300 )
        {
            rectPosY = 330;
        }
        
        
    
        

        if(g.kbhit()){
            g.getKey();
        }
        g.update();

    }
}
