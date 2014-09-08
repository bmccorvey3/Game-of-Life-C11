//
//  main.cpp
//  GameOfLife2804
//
//  Created by Brent on 5/17/14.
//  Copyright (c) 2014 Brent. All rights reserved.
//

#include <iostream>
#include "LifeGame.h"
#include "LifeMap.h"
#include <fstream>

using std::ifstream;

int main(int argc, const char * argv[])
{
    ifstream file {"config.txt"};
    conway::LifeGame newGame;
    newGame.play_game(file);
    return 0;
}

