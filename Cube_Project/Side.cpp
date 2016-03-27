//
//  Side.cpp
//  Cube_Project
//
//  Created by Heidi Lyons on 3/26/16.
//  Copyright © 2016 Heidi Lyons. All rights reserved.
//

#include "Side.h"

Side::Side()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = '0';
        }
    }
}

Side::Side(char color)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = color;
        }
    }
}


Side::~Side()
{
    // inside destructor
}

char Side::get_matrix(int i, int j)
{
    return matrix[i][j];
}

void Side::set_matrix(int i, int j, char color)
{
    matrix[i][j] = color;
}


