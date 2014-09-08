//
//  LifeGame.h
//  GameOfLife2804
//
//  Created by Brent on 5/18/14.
//  Copyright (c) 2014 Brent. All rights reserved.
//

#ifndef __GameOfLife2804__LifeGame__
#define __GameOfLife2804__LifeGame__

#include "LifeMap.h"
#include "BadFile.h"
#include <fstream>

namespace conway {
    
    //Compiler is generating the constructor, destructor, assignment operator and copy constructor
    
    class LifeGame {
        
    public:
        /**
         * Swap the current and future maps and reset the future map to all dead
         */
        void swap_maps_reset (LifeMap& a, LifeMap& b);
        
        /**
         * Execute 1 turn of the simulation
         */
        void take_turn(int h, int w);
        
        /**
         * Initialize the current map to start the simulation
         */
        void initialize(std::ifstream&, int h, int w);
        
        /**
         * Execute the simulation
         */
        void play_game(std::ifstream&);
        
    };
}

#endif /* defined(__GameOfLife2804__LifeGame__) */

