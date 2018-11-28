
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
 
    int R, G, B;
    int mariox = 20, marioy = 22;
   
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
    floor.close();
    int baseline = 420;

    double jump_time = 0;
    //    floor.close();
    int high = 350;
    
    int high1= 290;
    
    
    //Platforms
    ifstream top1;
    int sizex1 = 0, sizey1= 10;
    top1.open("floor.txt");
    Pixels top[sizey1][sizex1];
    for (int col=0; col < sizey1; col++)
    {
        for (int row = 120; row < sizex1; row++)
        {
            top1 >> R >> G >> B;
            top[col][row].setr(R);
            top[col][row].setg(G);
            top[col][row].setb(B);
        }
        getline(top1, buffer);
    }
    top1.close();
    
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

        for(int x = high; x < sizey1 + high; x++){
            for(int y = 0; y <sizex1; y++){
                g.plotPixel(y,x, top[x-high][y].getr(),
                            top[x-high][y].getg(),top[x-high][y].getb());
            }
        }
        for(int x = high; x < sizey1 + high; x++){
            for(int y = sizex1; y <sizex1 + sizex1; y++){
                g.plotPixel(y,x, top[x-high][y-sizex1].getr(),
                            top[x-high][y-sizex1].getg(),top[x-high][y-sizex1].getb());
            }
        }
        for(int x = high; x < sizey1+ high; x++){
            for(int y =600; y <sizex1+600; y++){
                g.plotPixel(y,x, top[x-high][y-600].getr(),
                            top[x-high][y-600].getg(),top[x-high][y-600].getb());
            }
        }
        for(int x = high; x < sizey1 + high; x++){
            for(int y =0; y <sizex +0; y++){
                g.plotPixel(y,x, top[x-high][y-0].getr(),
                            top[x-high][y-0].getg(),top[x-high][y-0].getb());
            }
        }
        //setting boundaries
        if (rectPosX == 370 && rectPosY >= 0 && rectPosY <= 200)
        {
            rectPosX = 436;
        }
        
        if (rectPosX == 330 && rectPosY >= 0 && rectPosY <= 200)
        {
            rectPosX = 329;
        }
        
        
        ///////////////////////////////////////////////////
        for(int x = high; x < sizey1 + high; x++){
            for(int y = 0; y <sizex1; y++){
                g.plotPixel(y,x, top[x-high][y].getr(),
                        top[x-high][y].getg(),top[x-high][y].getb());
            }
        }
        for(int x = high; x < sizey1 + high; x++){
            for(int y = sizex1; y <sizex1 + sizex1; y++){
                g.plotPixel(y,x, top[x-high][y-sizex1].getr(),
                            top[x-high][y-sizex1].getg(),top[x-high][y-sizex1].getb());
            }
        }
//                        for(int x = high; x < sizey1+ high; x++){
//                            for(int y =300; y <sizex1+350; y++){
//                                g.plotPixel(y,x, top[x-high][y-350].getr(),
//                                            top[x-high][y-350].getg(),top[x-high][y-350].getb());
//                            }
//                        }
//
        for(int x = high; x < sizey1+high; x++)
        {
            for(int y =469; y <sizex +470; y++)
            { //higher the num, longer it gets horizontally on the right side
                g.plotPixel(y,x, top[x-high][y-470].getr(),
                top[x-high][y-470].getg(),top[x-high][y-470].getb());
            }
        }
        //boundaries
        if (rectPosX == 370 && rectPosY >= 465 && rectPosY <= 673)
        {
            rectPosX = 436;
        }
        
        if (rectPosX == 330 && rectPosY >= 465 && rectPosY <= 673)
        {
            rectPosX = 329;
        }
        
        
        //////////////////////////////
        for(int x = high1; x < sizey1 + high1; x++){
            for(int y = 0; y <sizex1; y++){
                g.plotPixel(y,x, top[x-high1][y].getr(),
                            top[x-high1][y].getg(),top[x-high1][y].getb());
            }
        }
        for(int x = high1; x < sizey1 + high1; x++){
            for(int y = sizex1; y <sizex1 + sizex1; y++){
                g.plotPixel(y,x, top[x-high1][y-sizex1].getr(),
                            top[x-high1][y-sizex1].getg(),top[x-high1][y-sizex1].getb());
            }
        }
        for(int x = high1; x < sizey1+ high1; x++){
            for(int y =600; y <sizex1+600; y++){
                g.plotPixel(y,x, top[x-high1][y-600].getr(),
                            top[x-high1][y-600].getg(),top[x-high1][y-600].getb());
            }
        }
        for(int x = high1; x < sizey1 + high1; x++){
            for(int y =230; y <sizex +230; y++){
                g.plotPixel(y,x, top[x-high1][y-230].getr(),
                            top[x-high1][y-230].getg(),top[x-high1][y-230].getb());
            }
        }
        
        //boundaries
        if (rectPosX == 290 && rectPosY >= 212 && rectPosY <= 420)
        {
            rectPosX = 436;
        }
        
        if (rectPosX == 270 && rectPosY >= 212 && rectPosY <= 420)
        {
            rectPosX = 269;
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
//        }
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




