////
////  player.h
////  Game (Final Project)
////
////  Created by Paul Yu on 11/12/18.
////  Copyright © 2018 Paul Yu. All rights reserved.
////
//
//#ifndef player_h
//#define player_h
//
//#include <SDL2/SDL.h>
//#include <SDL2_mixer/SDL_mixer.h>
//#include <SDL2/SDL_thread.h>
//
//
//using namespace std;
//const int windowHeight = 200;
//const int windowWidth = 200;
//
//class Player
//{
//private:
//    int posX=50;
//    int posY=0;
//    int width=10;
//    int height=10;
//    
//    
//public:
//    void move(int xOffset, int yOffset){
//        
//        posX= min (max(posX+ xOffset,0),windowWidth-width);
//        posY = min (max(posY + yOffset,0), windowHeight-height);
//    
//        
//    }
//    
//    void draw()
//    {
//        
//        for (int col = posX; col < width + posX; col++)
//        {
//            for (int row= posY; row < height+ posY; row++)
//            {
//                
//            }
//        }
//        
//       
//    }
//};
//
////The square
//class Square
//{
//private:
//    //The collision box of the square
//    SDL_Rect box;
//    
//    //The velocity of the square
//    int xVel, yVel;
//    
//public:
//    //Initializes the variables
//    Square();
//    
//    //Takes key presses and adjusts the square's velocity
//    void handle_input();
//    
//    //Moves the square
//    void move();
//    
//    //Shows the square on the screen
//    void show();
//};
//
//
//
//
//#endif /* player_h */
