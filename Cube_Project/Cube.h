//
//  Cube.hpp
//  Cube_Project
//
//  Created by Heidi Lyons on 3/26/16.
//  Copyright © 2016 Heidi Lyons. All rights reserved.
//

#include "Side.h"
#include <time.h>

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
	void randomize();

	void pretty_print();
	void RotateSide(unsigned int side, bool cw);
};


