//
//  Cube.hpp
//  Cube_Project
//
//  Created by Heidi Lyons on 3/26/16.
//  Copyright © 2016 Heidi Lyons. All rights reserved.
//

#include "Side.h"

#pragma once

class Cube
{
private:
    
    Side container[6];
    
public:
    
    Cube();
    ~Cube();
    
    void create_cube();
    void print_cube();
    void pretty_print();
    
};


