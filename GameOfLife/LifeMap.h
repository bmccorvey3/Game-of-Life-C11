//
//  LifeMap.h
//  GameOfLife2804
//
//  Created by Brent on 5/18/14.
//  Copyright (c) 2014 Brent. All rights reserved.
//

#ifndef __GameOfLife2804__LifeMap__
#define __GameOfLife2804__LifeMap__

#include <iostream>
#include <iomanip>

namespace conway {
    class LifeMap {
        
        //Compiler is generating the constructor, destructor, assignment operator and copy constructor
        
    private:
        char game_array[100][100];
        
    public:
        
        /**
         * Takes in the x, y grid coordinate and counts the number of live cells in the 8 surrounding cell
         * Returns the number of live adjoining cells!
         */
        int get_neighbor_count (int x, int y, int h, int w);
        
        /**
         * Print out the map in a 10 x 10 grid of integers!
         */
        void print_map(int h, int w);
        
        /**
         * Set all the cells in a grid to dead (0)
         */
        void reset();
        
        /**
         * Set the grid at x, y coordinate to alive
         */
        void set_cell_live(int x, int y);
        
        /**
         * Set the grid at x, y coordinate to dead!
         */
        void set_cell_dead(int x, int y);
        
        /*Extra helper functions*/
        char get_char_at_pos(int x, int y);
        char* add_at_i(int i);
        void start(int x, int y);
        int height(int);
        int width(int);
    };
}

#endif /* defined(__GameOfLife2804__LifeMap__) */

