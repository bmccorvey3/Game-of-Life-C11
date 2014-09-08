//
//  LifeMap.cpp
//  GameOfLife2804
//
//  Created by Brent on 5/18/14.
//  Copyright (c) 2014 Brent. All rights reserved.
//

#include "LifeMap.h"
#include "LifeGame.h"

namespace conway {
        
    int LifeMap::get_neighbor_count (int x, int y, int HEIGHT, int WIDTH) {
        int neighbors = 0;
        if (x>=1 && y>=1 && x<WIDTH-1 && y<HEIGHT-1) {
            if(game_array[x][y-1] == '1') {++neighbors;}
            if(game_array[x][y+1] == '1') {++neighbors;}
            if(game_array[x-1][y] == '1') {++neighbors;}
            if(game_array[x+1][y] == '1') {++neighbors;}
            if(game_array[x-1][y+1] == '1') {++neighbors;}
            if(game_array[x-1][y-1] == '1') {++neighbors;}
            if(game_array[x+1][y-1] == '1') {++neighbors;}
            if(game_array[x+1][y+1] == '1') {++neighbors;}
        }
        
        /**********Code for edge cases.*********/
        
        if(x==0 && y==0) {
            if(game_array[x+1][y] == '1') {++neighbors;}
            if(game_array[x+1][y+1] == '1') {++neighbors;}
            if(game_array[x][y+1] == '1') {++neighbors;}
        }
        
        if(x==0 && (y>=1 && y<HEIGHT-1)) {
            if(game_array[x][y+1] == '1') {++neighbors;}
            if(game_array[x+1][y+1] == '1') {++neighbors;}
            if(game_array[x+1][y] == '1') {++neighbors;}
            if(game_array[x][y-1] == '1') {++neighbors;}
            if(game_array[x+1][y-1] == '1') {++neighbors;}
        }
        
        if(x==0 && y==HEIGHT-1) {
            if(game_array[x][y-1] == '1') {++neighbors;}
            if(game_array[x+1][y-1] == '1') {++neighbors;}
            if(game_array[x+1][y] == '1') {++neighbors;}
        }
        
        else if(y==HEIGHT-1 && (x>=1 && x<WIDTH-1)) {
            if(game_array[x-1][y] == '1') {++neighbors;}
            if(game_array[x-1][y-1] == '1') {++neighbors;}
            if(game_array[x][y-1] == '1') {++neighbors;}
            if(game_array[x+1][y-1] == '1') {++neighbors;}
            if(game_array[x+1][y] == '1') {++neighbors;}
        }
        
        if(x==WIDTH-1 && y==HEIGHT-1) {
            if(game_array[x-1][y] == '1') {++neighbors;}
            if(game_array[x-1][y-1] == '1') {++neighbors;}
            if(game_array[x][y-1] == '1') {++neighbors;}
        }
        
        if(x==WIDTH-1 && (y>=1 && y<HEIGHT-1)) {
            if(game_array[x][y-1] == '1') {++neighbors;}
            if(game_array[x-1][y-1] == '1') {++neighbors;}
            if(game_array[x-1][y] == '1') {++neighbors;}
            if(game_array[x-1][y+1] == '1') {++neighbors;}
            if(game_array[x][y+1] == '1') {++neighbors;}
        }
        
        if(x==WIDTH-1 && y==0) {
            if(game_array[x][y+1] == '1') {++neighbors;}
            if(game_array[x-1][y+1] == '1') {++neighbors;}
            if(game_array[x-1][y] == '1') {++neighbors;}
        }
        
        if(y==0 && (x>=1 && x<WIDTH-1)) {
            if(game_array[x-1][y] == '1') {++neighbors;}
            if(game_array[x-1][y+1] == '1') {++neighbors;}
            if(game_array[x][y+1] == '1') {++neighbors;}
            if(game_array[x+1][y+1] == '1') {++neighbors;}
            if(game_array[x+1][y] == '1') {++neighbors;}
        }
        
        /**********Code for edge cases.*********/
        
        return neighbors;
    }
    
    void LifeMap::print_map(int HEIGHT, int WIDTH) {
        for(int i = 0; i<HEIGHT; ++i) {
            for (int j = 0; j<WIDTH; ++j) {
                std::cout <<std::setw(5)<< game_array[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    void LifeMap::reset() {
        for(int i = 0; i<100; ++i) {
            for(int j = 0; j<100; ++j) {
                LifeMap::set_cell_dead(i,j);
            }
        }
    }
    
    void LifeMap::set_cell_live (int x, int y) {
        game_array[x][y] = '1';
    }
    
    void LifeMap::set_cell_dead (int x, int y) {
        game_array[x][y] = '0';
    }
    
    /*Extra helper functions*/
    
    char LifeMap::get_char_at_pos(int x, int y) {
        return game_array[x][y];
    }
    
    char* LifeMap::add_at_i(int i) {
        return game_array[i];
    }
    
    void LifeMap::start(int height, int width) {
        for(int i = 0; i<height; ++i) {
            for(int j = 0; j<width; ++j) {
                game_array[i][j] = '0';
            }
        }
    }
    
    int LifeMap::height(int h) {
        return h;
    }
    
    int LifeMap::width(int w) {
        return w;
    }
}
