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
void Cube::RotateSide(unsigned int side, bool cw)
{
	char tmp1[3] = { NULL };
	char tmp2[3] = { NULL };
	if (cw)
	{
		int i = 0;
		int j = 0;
		
		tmp1[0] = this->container[side].get_matrix(i, j);
		tmp1[1] = this->container[side].get_matrix(i + 1, j);
		tmp1[2] = this->container[side].get_matrix(i + 2, j);
		
		i = 2;

		tmp2[0] = this->container[side].get_matrix(i, j);
		tmp2[1] = this->container[side].get_matrix(i, j + 1);
		tmp2[2] = this->container[side].get_matrix(i, j + 2);
		
		this->container[side].set_matrix(i, j, tmp1[0]);
		this->container[side].set_matrix(i, j, tmp1[1]);
		this->container[side].set_matrix(i, j, tmp1[2]);
		//wip
		tmp1[0] = this->container[side].get_matrix(i, j);
		tmp1[1] = this->container[side].get_matrix(i + 1, j);
		tmp1[2] = this->container[side].get_matrix(i + 2, j);


	}
}
