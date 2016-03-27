//
//  Cube.h
//  Cube_Project
//
//  Created by Heidi Lyons on 3/26/16.
//  Copyright © 2016 Heidi Lyons. All rights reserved.
//

#include <iostream>
#pragma once
class Side
{
private:
    char matrix[3][3];
    
public:
    Side();
    Side(char color);
    ~Side();
    
    char get_matrix(int i, int j);
    void set_matrix(int i, int j, char color);
};