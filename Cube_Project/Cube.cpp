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

using std::cout;
using std::endl;

Cube::Cube()
{
    Side yellow('Y');
    Side blue('B');
    Side white('W');
    Side orange('O');
    Side green('G');
    Side red('R');
    
    container[0] = white;
    container[1] = yellow;
    container[2] = blue;
    container[3] = green;
    container[4] = red;
    container[5] = orange;
}

void Cube::create_cube()
{
    Side yellow('Y');
    Side blue('B');
    Side white('W');
    Side orange('O');
    Side green('G');
    Side red('R');
    
    container[0] = white;
    container[1] = yellow;
    container[2] = blue;
    container[3] = green;
    container[4] = red;
    container[5] = orange;
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

void Cube::pretty_print()
{
    cout << "            FRONT SIDE                            " << endl;
    cout << "            ______________________                " << endl;
    cout << "           /                     /\\              " << endl;
    cout << "          /   " << container[2].get_matrix(0,0)  << "     "
                             << container[2].get_matrix(1,0)  <<
            "      "         << container[2].get_matrix(2, 0) << "    /  \\             "             << endl;
    cout << "         /                     / "
                             << container[4].get_matrix(2,0) << "  \\            "                    << endl;
    cout << "        /   "   << container[2].get_matrix(0,1) << "     "
                             << container[2].get_matrix(1,1) << "      "
                             << container[2].get_matrix(2,1) << "    /      \\           "            << endl;
    cout << "       /                     / " << container[4].get_matrix(1,0) << "   "
                             << container[4].get_matrix(2,1) << "  \\          "                      << endl;
    cout << "      /   "     << container[2].get_matrix(0,2) << "     "
                             << container[2].get_matrix(1,2) << "      "
                             << container[2].get_matrix(2,2) << "    /          \\         "          << endl;
    cout << "     /_____________________/ "
                             << container[4].get_matrix(0,0) << "   "
                             << container[4].get_matrix(1,1) << "   "
                             << container[4].get_matrix(2,2) << "  \\        "                        << endl;
    cout << "     \\                     \\           /        "                                      << endl;
    cout << "      \\   "    << container[0].get_matrix(0,0) << "     "
                             << container[0].get_matrix(1,0) << "      "
                             << container[0].get_matrix(2,0) << "    \\ "
                             << container[4].get_matrix(0,1) << "   "
                             << container[4].get_matrix(1,2) << "   /         "                       << endl;
    cout << "       \\                     \\       /          "                                      << endl;
    cout << "        \\   "  << container[0].get_matrix(0,1) << "     "
                             << container[0].get_matrix(1,1) << "      "
                             << container[0].get_matrix(2,1) << "    \\ "
                             << container[4].get_matrix(0,2) << "   /           "                     << endl;
    cout << "         \\                     \\   /            "                                      << endl;
    cout << "          \\   " << container[0].get_matrix(0,2) << "     "
                             << container[0].get_matrix(1,2) << "      "
                             << container[0].get_matrix(2,2) << "    \\ /             "               << endl;
    cout << "           ----------------------                 "                                      << endl;
    
    
    cout << endl << endl << endl;
    cout << "          BACK SIDE                   "                                                  << endl;
    
    
    .___________________.
    / \  				 \
    /   \		   	      \
    /    	\				   \
    / 	  	 \                  \
				/		  \__________________\
    /	  	 /				     /
    /         /                   /
    \	  	   /				   /
    \	  / 			      /
				\    /			         /
    \  /					/
    \/___________________/
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

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
		this->container[side].set_matrix(i, j + 1, tmp1[1]);
		this->container[side].set_matrix(i, j + 2, tmp1[2]);

		j = 2;

		tmp1[0] = this->container[side].get_matrix(i, j);
		tmp1[1] = this->container[side].get_matrix(i - 1, j);
		tmp1[2] = this->container[side].get_matrix(i - 2, j);

		this->container[side].set_matrix(i, j, tmp2[0]);
		this->container[side].set_matrix(i - 1, j, tmp2[1]);
		this->container[side].set_matrix(i - 2, j, tmp2[2]);

		i = 0;

		tmp2[0] = this->container[side].get_matrix(i, j);
		tmp2[1] = this->container[side].get_matrix(i, j - 1);
		tmp2[2] = this->container[side].get_matrix(i, j - 2);

		this->container[side].set_matrix(i, j, tmp2[0]);
		this->container[side].set_matrix(i, j - 1, tmp2[1]);
		this->container[side].set_matrix(i, j - 2, tmp2[2]);

		j = 0;

		this->container[side].set_matrix(i, j, tmp1[0]);
		this->container[side].set_matrix(i + 1, j, tmp1[1]);
		this->container[side].set_matrix(i + 2, j, tmp1[2]);
	}
	else
	{
		int i = 2;
		int j = 0;

		tmp1[0] = this->container[side].get_matrix(i, j);
		tmp1[1] = this->container[side].get_matrix(i - 1, j);
		tmp1[2] = this->container[side].get_matrix(i - 2, j);

		i = 0;

		tmp2[0] = this->container[side].get_matrix(i, j);
		tmp2[1] = this->container[side].get_matrix(i, j + 1);
		tmp2[2] = this->container[side].get_matrix(i, j + 2);


		this->container[side].set_matrix(i, j, tmp1[0]);
		this->container[side].set_matrix(i, j + 1, tmp1[1]);
		this->container[side].set_matrix(i, j + 2, tmp1[2]);

		j = 2;

		tmp1[0] = this->container[side].get_matrix(i, j);
		tmp1[1] = this->container[side].get_matrix(i + 1, j);
		tmp1[2] = this->container[side].get_matrix(i + 2, j);

		this->container[side].set_matrix(i, j, tmp2[0]);
		this->container[side].set_matrix(i + 1, j, tmp2[1]);
		this->container[side].set_matrix(i + 2, j, tmp2[2]);

		i = 2;

		tmp2[0] = this->container[side].get_matrix(i, j);
		tmp2[1] = this->container[side].get_matrix(i, j - 1);
		tmp2[2] = this->container[side].get_matrix(i, j - 2);

		this->container[side].set_matrix(i, j, tmp2[0]);
		this->container[side].set_matrix(i, j - 1, tmp2[1]);
		this->container[side].set_matrix(i, j - 2, tmp2[2]);

		j = 0;

		this->container[side].set_matrix(i, j, tmp1[0]);
		this->container[side].set_matrix(i - 1, j, tmp1[1]);
		this->container[side].set_matrix(i - 2, j, tmp1[2]);
	}
}

