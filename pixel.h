//
//  pixel.h
//  Game (Final Project)
//
//  Created by Paul Yu on 11/27/18.
//  Copyright © 2018 Paul Yu. All rights reserved.
//

#ifndef pixel_h
#define pixel_h


class Pixels{
private:
    int r;
    int g;
    int b;
public:
    Pixels();
    Pixels(int, int, int);
    void setr(int);
    void setg(int);
    void setb(int);
    int getr();
    int getg();
    int getb();
};


#endif /* pixel_h */
