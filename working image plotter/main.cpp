#include <iostream>
#include <fstream>

#include "SDL_Plotter.h"

using namespace std;

int main(int argc, char ** argv)
{
    ifstream in;
    int height = 463, width = 673;
    SDL_Plotter g(height,width);
    bool stopped = false;
    bool colored = false;
    int x = 0,y = 0,xd=0,yd=0;
    int R,G,B;
    bool stoptitle = true;

    while (!g.getQuit())
    {
        if(stoptitle){


        in.open("mario.txt");
        while(in>>R>>G>>B){
                    g.plotPixel( x + xd, y + yd, R, G, B);
                    xd++;
                    if (xd==436){
                        xd = 0;
                        yd++;
                    }
                }stoptitle = false;
        }
		in.close();
		g.update();
    }

}
