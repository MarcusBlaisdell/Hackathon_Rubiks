//
//  Cube.cpp
//  Cube_Project
//
//  Created by Heidi Lyons on 3/26/16.
//  Copyright © 2016 Heidi Lyons. All rights reserved.
//

#include "Cube.h"
#include "Side.h"
#include <iostream>

Cube::Cube()
{
    Side yellow('Y');
    Side blue('B');
    Side white('W');
    Side orange('O');
    Side green('G');
    Side red('R');
    
    container[0] = yellow;
    container[1] = blue;
    container[2] = white;
    container[3] = orange;
    container[4] = green;
    container[5] = red;
}

void Cube::create_cube()
{
    Side yellow('Y');
    Side blue('B');
    Side white('W');
    Side orange('O');
    Side green('G');
    Side red('R');
    
    container[0] = yellow;
    container[1] = blue;
    container[2] = white;
    container[3] = orange;
    container[4] = green;
    container[5] = red;
}

Cube::~Cube()
{
    // inside destructor
}

void Cube::print_cube()
{
    for (int h = 0; h < 6; h++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cout << container[h].get_matrix(i, j);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}