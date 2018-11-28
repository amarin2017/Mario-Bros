//#include <iostream>
//#include "player.h"
//#include "pixel.h"
//#include "SDL_Plotter.h"
//#include <fstream>
//#include <stdlib.h>
//using namespace std;
//
//int main(int argc, char ** argv)
//{
//    const int windowHeight = 436;
//    const int windowWidth = 673;
//    //random pixels
//    SDL_Plotter g (windowHeight, windowWidth);
//
//    int rectPosX=300;
//    int rectPosY=600;
//    int width=10;
//    int height=10;
//    ifstream in;
//
//        bool stopped = false;
//        bool colored = false;
//        int xd = 0, yd = 0;
//        int R, G, B;
//        int mariox = 20, marioy = 22;
//        bool stoptitle = true;
//   
//
//    double jump_time = 0;
//    while (!g.getQuit()) //loop goes forever until user puts exit
//    {
//
//
//        double horizontal = 0;
//
//        if(g.kbhit()){
//            g.getKey();
//        }
//
//        //grab input
//        if (g.getKey() == UP_ARROW) {
//
//            jump_time = 11.0;
//        }
//
//        else if (g.getKey()== DOWN_ARROW)
//        {
//            rectPosY = min (rectPosY +2, windowHeight - height);
//        }
//        else if(g.getKey() == LEFT_ARROW)
//        {
//            horizontal = -1;
//        }
//        else if (g.getKey() == RIGHT_ARROW)
//        {
//            horizontal = 1;
//        }
//
//
//
//        //draw loop
//
//        //reset background color
//        for (int col = 0; col < windowWidth; col++)
//        {
//            for (int row=0; row < windowHeight; row++)
//            {
//                g.plotPixel(col, row, 0, 0, 0);
//            }
//        }
//
//        //draw rectangle
//        for (int col = rectPosX; col < width +rectPosX; col++)
//        {
//            for (int row=rectPosY; row < height+rectPosY; row++)
//            {
//                g.plotPixel(col, row, 250, 32, 5);
//            }
//        }
//
//        //////with updated jumps/////
//        if (g.getKey() != UP_ARROW || rectPosY != windowHeight)
//        {
//            rectPosY = min(rectPosY + 1, windowHeight-height);
//        }
//
//        if(jump_time > 0 && g.getKey() != UP_ARROW)
//        {
//            rectPosY = max(rectPosY - 2, 0);
//            jump_time -= 0.125;
//        }
//
//        if (horizontal == -1)
//        {
//            rectPosX = max (rectPosX - 1,0);
//        }
//        else if (horizontal == 1)
//        {
//            rectPosX = min (rectPosX + 1, windowWidth-width);
//        }
//
//        g.update();
//
//
//
//
//
//
//
//
//        //space for the bricks
//
//        //1st row left
//        for (int col=0; col < width+300; ++col)
//        {
//            for (int row = 120; row < width+ 130; ++row)
//            {
//                g.plotPixel(col, row, 139, 69, 13);
//            }
//
//        }
//
//        for (int col=373; col < width+673; ++col)
//        {
//            for (int row = 120; row < width+ 130; ++row)
//            {
//                g.plotPixel(col, row, 139, 69, 13);
//            }
//
//        }
//
//
//
//        ////////////////////////////////////////////////////
//
//
//
//        //top left (2nd row)
//        for (int col=0; col < width+80; ++col)
//        {
//            for (int row = 230; row < width+ 240; ++row)
//            {
//                g.plotPixel(col, row, 139, 69, 13);
//            }
//
//        }
//        //2nd row middle
//        for (int col=200; col <width+473 ; ++col)
//        {
//            for (int row = 230; row < width+ 240; ++row)
//            {
//                g.plotPixel(col, row, 139, 69, 13);
//            }
//
//        }
//
//        //top right (2nd row)
//        for (int col=593; col < width+673; ++col)
//        {
//            for (int row = 230; row < width+ 240; ++row)
//            {
//                g.plotPixel(col, row, 139, 69, 13);
//            }
//
//        }
//
//        ///////////////////////////////////////////////////////
//
//        //bottom left
//        for (int col=0; col < width+300; ++col)
//        {
//            for (int row = 350; row < width + 360; ++row)
//            {
//                g.plotPixel(col, row, 139, 69, 13);
//            }
//
//        }
//
//        //bottom right
//        for (int col=373; col < width+673; ++col)
//        {
//            for (int row = 350; row < width + 360; ++row)
//            {
//                g.plotPixel(col, row, 139, 69, 13);
//            }
//
//        }
//
//
//
//       /////making limits//////
//
//
//        //limit to bottom left
//        if (rectPosY == 360 && rectPosX <= 300)
//        {
//            rectPosY = 436;
//        }
//
//        //limit to bottom right
//        if (rectPosY == 360 && rectPosX >= 373 && rectPosX <= 673)
//        {
//            rectPosY = 436;
//        }
//
//
//
//
//
//        //bottom left
//        if (rectPosY == 340 && rectPosX <= 300 && rectPosX >=0)
//        {
//                rectPosY = 339;
//        }
//        //bottom right
//        if (rectPosY == 340 && rectPosX >373 && rectPosX < 673)
//        {
//            rectPosY = 339;
//        }
//
//
//
//
//
//
//        //top right (2nd row)
//        if (rectPosY == 220 && rectPosX <= 673 && rectPosX >= 593)
//        {
//                rectPosY = 219;
//        }
//        //limit to top right (2nd row)
//        if (rectPosY == 250 && rectPosX <= 673 && rectPosX >= 593)
//        {
//            rectPosY = 339;
//        }
//
//
//        //middle (2nd row)
//        if (rectPosY == 220 && rectPosX >= 200 && rectPosX <=473)
//        {
//            rectPosY = 219;
//        }
//        //limit middle(2nd row)
//        if (rectPosY == 250 && rectPosX >= 200 && rectPosX <= 473)
//        {
//            rectPosY = 339;
//        }
//
//
//        //top left (2nd row)
//        if (rectPosY == 220 && rectPosX >=0 && rectPosX <= 80)
//        {
//            rectPosY = 219;
//        }
//        //limit to top left (2nd row)
//        if (rectPosY == 250 && rectPosX >= 0 && rectPosX <= 80 )
//        {
//            rectPosY = 339;
//        }
//
//
//
//        //top left (1st row)
//        if (rectPosY == 110 && rectPosX >= 0 && rectPosX <= 300)
//        {
//            rectPosY = 109;
//        }
//        //limit to top left (1st row)
//        if (rectPosY == 120 && rectPosX >= 0 && rectPosX <= 300 )
//        {
//            rectPosY = 219;
//        }
//
//
//        //top right (1st row)
//        if (rectPosY == 110 && rectPosX >=373 && rectPosX <= 673)
//        {
//            rectPosY = 109;
//        }
//        //limit to top right (1st row)
//        if (rectPosY == 120 && rectPosX >=373 && rectPosX <= 673)
//        {
//            rectPosY = 219;
//        }
//
//
//
//
//        if(g.kbhit()){
//            g.getKey();
//        }
//        g.update();
//
//    }
//
//}
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "SDL_Plotter.h"
#include "pixel.h"
using namespace std;

int main(int argc, char ** argv) {
    ifstream in;
    const int windowHeight = 436;
    const int windowWidth = 673;
    SDL_Plotter g(windowHeight, windowWidth);
    bool stopped = false;
    bool colored = false;
    int xd = 0, yd = 0;
    int R, G, B;
    int mariox = 20, marioy = 22;
    bool stoptitle = true;
    int rectPosX = 300;
    int rectPosY = 300;
    int frameCount = 0;
    Pixels leftEvenmario[mariox][marioy];
    Pixels leftOddmario[mariox][marioy];
    Pixels statMario[mariox][marioy];
    Pixels beginMario[mariox][marioy];
    Pixels endMario[mariox][marioy];
    Pixels rightEvenmario[mariox][marioy];
    Pixels rigthOddmario[mariox][marioy];
    in.open("marihoe.txt");

    string buffer;
    for (int f = 0; f < mariox; f++) {
        for (int h = 0; h < marioy; h++) {
            in >> R >> G >> B;
            statMario[f][h].setr(R);
            statMario[f][h].setg(G);
            statMario[f][h].setb(B);
        }
        getline(in, buffer);
    }
    for (int f = 0; f < mariox; f++) {
        for (int h = 0; h < marioy; h++) {
            rightEvenmario[f][h].setr(statMario[f][22-h].getr());
            rightEvenmario[f][h].setg(statMario[f][22-h].getg());
            rightEvenmario[f][h].setb(statMario[f][22-h].getb());
        }
        getline(in, buffer);
    }

//   for (int f = 0; f < mariox; f++) {
//        for (int h = 0; h < marioy; h++) {
//            in >> R >> G >> B;
//            beginMario[f][h].setr(R);
//            beginMario[f][h].setg(G);
//            beginMario[f][h].setb(B);
//        }
//        getline(in, buffer);
//    }
//    for (int f = 0; f < mariox; f++) {
//        for (int h = 0; h < marioy; h++) {
//            in >> R >> G >> B;
//            leftEvenmario[f][h].setr(R);
//            leftEvenmario[f][h].setg(G);
//            leftEvenmario[f][h].setb(B);
//        }
//        getline(in, buffer);
//    }
//    for (int e = 0; e < mariox; e++) {
//        for (int q = 0; q < marioy; q++) {
//            in >> R >> G >> B;
//            leftOddmario[e][q].setr(R);
//            leftOddmario[e][q].setg(G);
//            leftOddmario[e][q].setb(B);
//        }
//        getline(in, buffer);
//    }
//    for (int f = 0; f < mariox; f++) {
//        for (int h = 0; h < marioy; h++) {
//            in >> R >> G >> B;
//            endMario[f][h].setr(R);
//            endMario[f][h].setg(G);
//            endMario[f][h].setb(B);
//        }
//        getline(in, buffer);
//    }

    int sizex =200,sizey =16;
    ifstream floor;
    Pixels ground[sizey][sizex];
    floor.open("floor.txt");
    
    for (int range =0; range < sizey; range++){
        for(int hi =0; hi < sizex; hi++){
            floor >> R >> G >> B;
            ground[range][hi].setr(R);
            ground[range][hi].setg(G);
            ground[range][hi].setb(B);
        }
        getline(floor, buffer);
    }
    
    int baseline = 420;
    floor.close();
    double jump_time = 0;
    
    while (!g.getQuit()) //loop goes forever until user puts exit
    {
        int horizontalM = 0;
        g.clear();
        for (int col = 0; col < windowWidth; col++)
                    {
                        for (int row=0; row < windowHeight; row++)
                        {
                            g.plotPixel(col, row, 0, 0, 0);
                        }
                    }
        
        if (g.getKey() == UP_ARROW) {
            jump_time = 5;
        } else if (g.getKey() == DOWN_ARROW) {
            
        } else if (g.getKey() == LEFT_ARROW) {
            horizontalM = -1;
        } else if (g.getKey() == RIGHT_ARROW) {
            horizontalM = 1;
        }
        
        
        
        for(int x = baseline; x < sizey + baseline; x++){
            for(int y = 0; y <sizex; y++){
                g.plotPixel(y,x, ground[x-baseline][y].getr(),
                            ground[x-baseline][y].getg(),ground[x-baseline][y].getb());
            }
        }
        for(int x = baseline; x < sizey + baseline; x++){
            for(int y = sizex; y <sizex + sizex; y++){
                g.plotPixel(y,x, ground[x-baseline][y-sizex].getr(),
                            ground[x-baseline][y-sizex].getg(),ground[x-baseline][y-sizex].getb());
            }
        }
        for(int x = baseline; x < sizey + baseline; x++){
            for(int y =400; y <sizex+400; y++){
                g.plotPixel(y,x, ground[x-baseline][y-400].getr(),
                            ground[x-baseline][y-400].getg(),ground[x-baseline][y-400].getb());
            }
        }
        for(int x = baseline; x < sizey + baseline; x++){
            for(int y =520; y <sizex+520; y++){
                g.plotPixel(y,x, ground[x-baseline][y-520].getr(),
                            ground[x-baseline][y-520].getg(),ground[x-baseline][y-520].getb());
            }
        }
        if (horizontalM == 1)
        {
            rectPosY = min(rectPosY + 1, windowWidth - marioy);
            
            for(int col = rectPosX; col < 20 + rectPosX; col++){
                for(int row = rectPosY; row < 22 + rectPosY; row++){
                    g.plotPixel(row, col, rightEvenmario[col-rectPosX][row-rectPosY].getr(),
                                rightEvenmario[col-rectPosX][row-rectPosY].getg(),rightEvenmario[col-rectPosX][row-rectPosY].getb());
                }
            }
        }
        else if (horizontalM == - 1)
        {
             rectPosY = max(rectPosY - 1, 0);
            
            for(int col = rectPosX; col < 20 + rectPosX; col++){
                for(int row = rectPosY; row < 22 + rectPosY; row++){
                    g.plotPixel(row, col, statMario[col-rectPosX][row-rectPosY].getr(),
                                statMario[col-rectPosX][row-rectPosY].getg(),statMario[col-rectPosX][row-rectPosY].getb());
                }
            }
//            //Beginning the running animation
//            for (int i = 0; i < 20; i++)
//            {
//                for(int col = rectPosX; col < 20 + rectPosX; col++){
//                    for(int row = rectPosY; row < 22 + rectPosY; row++){
//                        g.plotPixel(row, col, beginMario[col-rectPosX][row-rectPosY].getr(),
//                                    beginMario[col-rectPosX][row-rectPosY].getg(),beginMario[col-rectPosX][row-rectPosY].getb());
//                    }
//                }
//            }
//            if(frameCount % 2 == 0)
//            {
//                //Giving the even running animation
//                for(int col = rectPosX; col < 20 + rectPosX; col++){
//                    for(int row = rectPosY; row < 22 + rectPosY; row++){
//                        g.plotPixel(row, col, leftEvenmario[col-rectPosX][row-rectPosY].getr(),
//                                leftEvenmario[col-rectPosX][row-rectPosY].getg(),leftEvenmario[col-rectPosX][row-rectPosY].getb());
//                    }
//                }
//            }
//            else
//            {
//                //Giving the odd running animation
//                for(int col = rectPosX; col < 20 + rectPosX; col++){
//                    for(int row = rectPosY; row < 22 + rectPosY; row++){
//                        g.plotPixel(row, col, leftOddmario[col-rectPosX][row-rectPosY].getr(),
//                                    leftOddmario[col-rectPosX][row-rectPosY].getg(),leftOddmario[col-rectPosX][row-rectPosY].getb());
//                    }
//                }
//            }
//
        }
        else
        {
            for(int col = rectPosX; col < 20 + rectPosX; col++){
                for(int row = rectPosY; row < 22 + rectPosY; row++){
                    g.plotPixel(row, col, rightEvenmario[col-rectPosX][row-rectPosY].getr(),
                                rightEvenmario[col-rectPosX][row-rectPosY].getg(),rightEvenmario[col-rectPosX][row-rectPosY].getb());
                }
            }
        }
        
        if (g.getKey() != UP_ARROW || rectPosX != baseline - mariox) {
            rectPosX = min(rectPosX + 1, baseline - mariox);
        }
        
        if (jump_time > 0 && g.getKey() != UP_ARROW)
        {
            rectPosX = max(rectPosX - 3, 0);
            jump_time -= 0.1;
        }
        if (g.kbhit()) {
            g.getKey();
        }

        g.update();
        frameCount++;

    }

}
