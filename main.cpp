#include <iostream>
#include "player.h"
#include "Collision.h"
#include "SDL_Plotter.h"
#include "Collision.h"
#include "Map.h"
#include <fstream>
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
  
    double jump_time = 0;
    while (!g.getQuit()) //loop goes forever until user puts exit
    {
        double horizontal = 0;

        if(g.kbhit()){
            g.getKey();
        }

        //grab input
        if (g.getKey() == UP_ARROW) {

            jump_time = 11.0;
        }

        else if (g.getKey()== DOWN_ARROW)
        {
            rectPosY = min (rectPosY +2, windowHeight - height);
        }
        else if(g.getKey() == LEFT_ARROW)
        {
            horizontal = -1;
        }
        else if (g.getKey() == RIGHT_ARROW)
        {
            horizontal = 1;
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

        //////with updated jumps/////
        if (g.getKey() != UP_ARROW || rectPosY != windowHeight)
        {
            rectPosY = min(rectPosY + 1, windowHeight-height);
        }

        if(jump_time > 0 && g.getKey() != UP_ARROW)
        {
            rectPosY = max(rectPosY - 2, 0);
            jump_time -= 0.125;
        }

        if (horizontal == -1)
        {
            rectPosX = max (rectPosX - 1,0);
        }
        else if (horizontal == 1)
        {
            rectPosX = min (rectPosX + 1, windowWidth-width);
        }

        g.update();

  

        
        
        
        
        
        //space for the bricks
        
        //1st row left
        for (int col=0; col < width+300; ++col)
        {
            for (int row = 120; row < width+ 130; ++row)
            {
                g.plotPixel(col, row, 139, 69, 13);
            }
            
        }
        
        for (int col=373; col < width+673; ++col)
        {
            for (int row = 120; row < width+ 130; ++row)
            {
                g.plotPixel(col, row, 139, 69, 13);
            }
            
        }
        
        
        
        ////////////////////////////////////////////////////
        
        
        
        //top left (2nd row)
        for (int col=0; col < width+80; ++col)
        {
            for (int row = 230; row < width+ 240; ++row)
            {
                g.plotPixel(col, row, 139, 69, 13);
            }
            
        }
        //2nd row middle
        for (int col=200; col <width+473 ; ++col)
        {
            for (int row = 230; row < width+ 240; ++row)
            {
                g.plotPixel(col, row, 139, 69, 13);
            }
            
        }
        
        //top right (2nd row)
        for (int col=593; col < width+673; ++col)
        {
            for (int row = 230; row < width+ 240; ++row)
            {
                g.plotPixel(col, row, 139, 69, 13);
            }
            
        }
        
        ///////////////////////////////////////////////////////
        
        //bottom left
        for (int col=0; col < width+300; ++col)
        {
            for (int row = 350; row < width + 360; ++row)
            {
                g.plotPixel(col, row, 139, 69, 13);
            }
            
        }
        
        //bottom right
        for (int col=373; col < width+673; ++col)
        {
            for (int row = 350; row < width + 360; ++row)
            {
                g.plotPixel(col, row, 139, 69, 13);
            }
            
        }
        
        
        
       /////making limits//////
        
        
        //limit to bottom left
        if (rectPosY == 360 && rectPosX <= 300)
        {
            rectPosY = 436;
        }
        
        //limit to bottom right
        if (rectPosY == 360 && rectPosX >= 373 && rectPosX <= 673)
        {
            rectPosY = 436;
        }
        
        
        
        
    
        //bottom left
        if (rectPosY == 340 && rectPosX <= 300 && rectPosX >=0)
        {
                rectPosY = 339;
        }
        //bottom right
        if (rectPosY == 340 && rectPosX >373 && rectPosX < 673)
        {
            rectPosY = 339;
        }
        
        
        
        
        
        
          //top right (2nd row)
        if (rectPosY == 220 && rectPosX <= 673 && rectPosX >= 593)
        {
                rectPosY = 219;
        }
        //limit to top right (2nd row)
        if (rectPosY == 250 && rectPosX <= 673 && rectPosX >= 593)
        {
            rectPosY = 339;
        }
       
        
        
        //middle (2nd row)
        if (rectPosY == 220 && rectPosX >= 200 && rectPosX <=473)
        {
            rectPosY = 219;
        }
        //limit middle(2nd row)
        if (rectPosY == 250 && rectPosX >= 200 && rectPosX <= 473)
        {
            rectPosY = 339;
        }
        
        
        //top left (2nd row)
        if (rectPosY == 220 && rectPosX >=0 && rectPosX <= 80)
        {
            rectPosY = 219;
        }
        //limit to top left (2nd row)
        if (rectPosY == 250 && rectPosX >= 0 && rectPosX <= 80 )
        {
            rectPosY = 339;
        }
        
        
        
        //top left (1st row)
        if (rectPosY == 110 && rectPosX >= 0 && rectPosX <= 300)
        {
            rectPosY = 109;
        }
        //limit to top left (1st row)
        if (rectPosY == 120 && rectPosX >= 0 && rectPosX <= 300 )
        {
            rectPosY = 219;
        }
        
        
        //top right (1st row)
        if (rectPosY == 110 && rectPosX >=373 && rectPosX <= 673)
        {
            rectPosY = 109;
        }
        //limit to top right (1st row)
        if (rectPosY == 120 && rectPosX >=373 && rectPosX <= 673)
        {
            rectPosY = 219;
        }
        
    
    

        if(g.kbhit()){
            g.getKey();
        }
        g.update();

    }

}
