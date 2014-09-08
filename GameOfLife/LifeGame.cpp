//
//  LifeGame.cpp
//  GameOfLife2804
//
//  Created by Brent on 5/18/14.
//  Copyright (c) 2014 Brent. All rights reserved.
//

#include "LifeGame.h"
#include "LifeMap.h"
#include <string>
#include <thread>
#include <chrono>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::strcpy;
using std::getline;
using std::atoi;

namespace conway {
    
    LifeMap map, next_map;
    
    void LifeGame::swap_maps_reset (LifeMap& a, LifeMap& b){
        a = b;
        b.reset();
    }
    
    void LifeGame::take_turn(int h, int w) {
        cout << "Current map: " << endl;
        map.print_map(h,w);
        for(int i = 0; i<h; ++i) {
            for(int j = 0; j<w; ++j) {
                int num_neighbors = map.get_neighbor_count(i,j,h,w);
                /*Underpopulation*/
                if(map.get_char_at_pos(i,j) == '1' && num_neighbors < 2) {
                    next_map.set_cell_dead(i,j);
                }
                /*Live*/
                if(map.get_char_at_pos(i,j) == '1' && (num_neighbors == 2 || num_neighbors == 3)){
                    next_map.set_cell_live(i,j);
                }
                /*Overcrowding*/
                if(map.get_char_at_pos(i,j) == '1' && num_neighbors > 3) {
                    next_map.set_cell_dead(i,j);
                }
                /*Reproduction*/
                if(map.get_char_at_pos(i,j) == '0' && num_neighbors == 3) {
                    next_map.set_cell_live(i,j);
                }
            }
        }
        LifeGame::swap_maps_reset(map,next_map);
    }
    
    void LifeGame::initialize(std::ifstream& inptr, int h, int w) {
        
        //Put remaining lines of input here
    
        std::ostringstream os;
        std::copy(std::istream_iterator<string>(inptr),std::istream_iterator<string>(),std::ostream_iterator<string>(os, "\n"));
        
        string array = os.str();
        string line;
        std::stringstream ss(array);
        
        for(int i = 0; i<h; ++i) {
            try {
                getline(ss,line,'\n');
                if(line.find_first_not_of("23456789") || line.length() != w) {
                    throw BadFile();
                }
            }
            catch(BadFile& e) {
                std::cerr<<e.what()<<endl;
                exit(1);
            }
            strcpy(map.add_at_i(i), line.data());
            line = "";
        }
    }
    
    void LifeGame::play_game(std::ifstream& inptr) {
        char input_line[80];
        int end_game;
        cout << "Welcome to the Game of Life!!!" << endl;
        
        string sim;
        getline(inptr, sim);
        int step = atoi(sim.c_str());
        
        string height, width;
        string dim;
        string delim = " ";
        getline(inptr, dim);
        height = dim.substr(0,dim.find(delim));
        width = dim.substr(dim.find(delim),dim.length());
        int h = atoi(height.c_str());
        int w = atoi(width.c_str());
        
        map.start(h,w);
        next_map.start(h,w);
        
        LifeGame::initialize(inptr,h,w);
        
        try {
            if(step<0) {
                throw BadFile();
            }
        }
        catch(BadFile& e) {
            std::cerr<<e.what()<<endl;
            exit(1);
        }
        
        while(step == 0) {
            LifeGame::take_turn(h,w);
            cout << "Press any key to continue or q to exit" << endl;
            cin.getline(input_line,80);
            end_game = input_line[0];
            if(end_game == 'q' || end_game == 'Q') {
                break;
            }
        }
        
        while (step>0) {
            LifeGame::take_turn(h,w);
            std::chrono::seconds dura(2);
            std::this_thread::sleep_for(dura);
            step--;
        }
        
    }
    
}
