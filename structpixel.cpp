//
//  structpixel.cpp
//  Game (Final Project)
//
//  Created by Paul Yu on 11/27/18.
//  Copyright © 2018 Paul Yu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <zconf.h>
#include "pixel.h"
Pixels::Pixels() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
}
Pixels::Pixels(int x, int y, int z) {
    this->r = x;
    this->g = y;
    this->b = z;
}

void Pixels::setr(int x) {
    this->r = x;
}
int Pixels::getr() {
    return r;
}
void Pixels::setg(int y) {
    this->g = y;
}
int Pixels::getg(){
    return g;
}
void Pixels::setb(int z) {
    this->b = z;
}
int Pixels::getb() {
    return b;
}
