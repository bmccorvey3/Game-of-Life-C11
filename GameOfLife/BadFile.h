//
//  BadFile.h
//  GameOfLife2804
//
//  Created by Brent on 7/7/14.
//  Copyright (c) 2014 Brent. All rights reserved.
//

#ifndef GameOfLife2804_BadFile_h
#define GameOfLife2804_BadFile_h

class BadFile : public std::exception {
public:
    BadFile() {}
    std::string what() noexcept {
        return "Bad file error!!!\n";
    }
};


#endif
