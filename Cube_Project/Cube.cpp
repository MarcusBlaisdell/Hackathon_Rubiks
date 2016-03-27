//
//  Cube.cpp
//  Cube_Project
//
//  Created by Heidi Lyons on 3/26/16.
//  Copyright � 2016 Heidi Lyons. All rights reserved.
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
	cout << "          /   " << container[2].get_matrix(0, 0) << "     "
		<< container[2].get_matrix(1, 0) <<
		"      " << container[2].get_matrix(2, 0) << "    /  \\             " << endl;
	cout << "         /                     / "
		<< container[4].get_matrix(2, 0) << "  \\            " << endl;
	cout << "        /   " << container[2].get_matrix(0, 1) << "     "
		<< container[2].get_matrix(1, 1) << "      "
		<< container[2].get_matrix(2, 1) << "    /      \\           " << endl;
	cout << "       /                     / " << container[4].get_matrix(1, 0) << "   "
		<< container[4].get_matrix(2, 1) << "  \\          " << endl;
	cout << "      /   " << container[2].get_matrix(0, 2) << "     "
		<< container[2].get_matrix(1, 2) << "      "
		<< container[2].get_matrix(2, 2) << "    /          \\         " << endl;
	cout << "     /_____________________/ "
		<< container[4].get_matrix(0, 0) << "   "
		<< container[4].get_matrix(1, 1) << "   "
		<< container[4].get_matrix(2, 2) << "  \\        " << endl;
	cout << "     \\                     \\           /        " << endl;
	cout << "      \\   " << container[0].get_matrix(0, 0) << "     "
		<< container[0].get_matrix(1, 0) << "      "
		<< container[0].get_matrix(2, 0) << "    \\ "
		<< container[4].get_matrix(0, 1) << "   "
		<< container[4].get_matrix(1, 2) << "   /         " << endl;
	cout << "       \\                     \\       /          " << endl;
	cout << "        \\   " << container[0].get_matrix(0, 1) << "     "
		<< container[0].get_matrix(1, 1) << "      "
		<< container[0].get_matrix(2, 1) << "    \\ "
		<< container[4].get_matrix(0, 2) << "   /           " << endl;
	cout << "         \\                     \\   /            " << endl;
	cout << "          \\   " << container[0].get_matrix(0, 2) << "     "
		<< container[0].get_matrix(1, 2) << "      "
		<< container[0].get_matrix(2, 2) << "    \\ /             " << endl;
	cout << "           ----------------------                 " << endl;


	cout << endl << endl << endl;
	cout << "          BACK SIDE                   " << endl;





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

		if (side == 1)
		{
			char tmp3_1 = this->container[3].get_matrix(2, 0);
			char tmp3_2 = this->container[3].get_matrix(2, 1);
			char tmp3_3 = this->container[3].get_matrix(2, 2);

			char tmp5_1 = this->container[5].get_matrix(0, 0);
			char tmp5_2 = this->container[5].get_matrix(1, 0);
			char tmp5_3 = this->container[5].get_matrix(2, 0);

			char tmp4_1 = this->container[4].get_matrix(0, 2);
			char tmp4_2 = this->container[4].get_matrix(0, 1);
			char tmp4_3 = this->container[4].get_matrix(0, 0);

			char tmp2_1 = this->container[2].get_matrix(2, 2);
			char tmp2_2 = this->container[2].get_matrix(1, 2);
			char tmp2_3 = this->container[2].get_matrix(0, 2);

			this->container[1].set_matrix(2, 0, tmp2_1);
			this->container[1].set_matrix(2, 1, tmp2_2);
			this->container[1].set_matrix(2, 2, tmp2_3);

			this->container[5].set_matrix(0, 0, tmp3_1);
			this->container[5].set_matrix(1, 0, tmp3_2);
			this->container[5].set_matrix(2, 0, tmp3_3);

			this->container[4].set_matrix(0, 2, tmp5_1);
			this->container[4].set_matrix(0, 1, tmp5_2);
			this->container[4].set_matrix(0, 0, tmp5_3);

			this->container[2].set_matrix(2, 2, tmp4_1);
			this->container[2].set_matrix(1, 2, tmp4_2);
			this->container[2].set_matrix(0, 2, tmp4_3);

		} // end if side 1

		if (side == 2)
		{
			char tmp3_1 = this->container[3].get_matrix(0, 0);
			char tmp3_2 = this->container[3].get_matrix(1, 0);
			char tmp3_3 = this->container[3].get_matrix(2, 0);

			char tmp1_1 = this->container[1].get_matrix(0, 0);
			char tmp1_2 = this->container[1].get_matrix(1, 0);
			char tmp1_3 = this->container[1].get_matrix(2, 0);

			char tmp4_1 = this->container[4].get_matrix(0, 0);
			char tmp4_2 = this->container[4].get_matrix(1, 0);
			char tmp4_3 = this->container[4].get_matrix(2, 0);

			char tmp6_1 = this->container[6].get_matrix(2, 2);
			char tmp6_2 = this->container[6].get_matrix(1, 2);
			char tmp6_3 = this->container[6].get_matrix(0, 2);

			this->container[3].set_matrix(0, 0, tmp6_1);
			this->container[3].set_matrix(1, 0, tmp6_2);
			this->container[3].set_matrix(2, 0, tmp6_3);

			this->container[1].set_matrix(0, 0, tmp3_1);
			this->container[1].set_matrix(1, 0, tmp3_2);
			this->container[1].set_matrix(2, 0, tmp3_3);

			this->container[4].set_matrix(0, 0, tmp1_1);
			this->container[4].set_matrix(1, 0, tmp1_2);
			this->container[4].set_matrix(2, 0, tmp1_3);

			this->container[6].set_matrix(2, 2, tmp4_1);
			this->container[6].set_matrix(1, 2, tmp4_2);
			this->container[6].set_matrix(0, 2, tmp4_3);

		} // end if side 2

		if (side == 3)
		{
			char tmp2_1 = this->container[2].get_matrix(0, 2);
			char tmp2_2 = this->container[2].get_matrix(0, 1);
			char tmp2_3 = this->container[2].get_matrix(0, 0);

			char tmp6_1 = this->container[6].get_matrix(0, 2);
			char tmp6_2 = this->container[6].get_matrix(0, 1);
			char tmp6_3 = this->container[6].get_matrix(0, 0);

			char tmp5_1 = this->container[5].get_matrix(0, 2);
			char tmp5_2 = this->container[5].get_matrix(0, 1);
			char tmp5_3 = this->container[5].get_matrix(0, 0);

			char tmp1_1 = this->container[1].get_matrix(0, 2);
			char tmp1_2 = this->container[1].get_matrix(0, 1);
			char tmp1_3 = this->container[1].get_matrix(0, 0);

			this->container[2].set_matrix(0, 2, tmp1_1);
			this->container[2].set_matrix(0, 1, tmp1_2);
			this->container[2].set_matrix(0, 0, tmp1_3);

			this->container[6].set_matrix(0, 2, tmp2_1);
			this->container[6].set_matrix(0, 1, tmp2_2);
			this->container[6].set_matrix(0, 0, tmp2_3);

			this->container[5].set_matrix(0, 2, tmp6_1);
			this->container[5].set_matrix(0, 1, tmp6_2);
			this->container[5].set_matrix(0, 0, tmp6_3);

			this->container[1].set_matrix(0, 2, tmp5_1);
			this->container[1].set_matrix(0, 1, tmp5_2);
			this->container[1].set_matrix(0, 0, tmp5_3);

		} // end if side 3

		if (side == 4)
		{
			char tmp2_1 = this->container[2].get_matrix(2, 2);
			char tmp2_2 = this->container[2].get_matrix(2, 1);
			char tmp2_3 = this->container[2].get_matrix(2, 0);

			char tmp1_1 = this->container[1].get_matrix(2, 2);
			char tmp1_2 = this->container[1].get_matrix(2, 1);
			char tmp1_3 = this->container[1].get_matrix(2, 0);

			char tmp5_1 = this->container[5].get_matrix(2, 2);
			char tmp5_2 = this->container[5].get_matrix(2, 1);
			char tmp5_3 = this->container[5].get_matrix(2, 0);

			char tmp6_1 = this->container[6].get_matrix(2, 2);
			char tmp6_2 = this->container[6].get_matrix(2, 1);
			char tmp6_3 = this->container[6].get_matrix(2, 0);

			this->container[2].set_matrix(2, 2, tmp6_1);
			this->container[2].set_matrix(2, 1, tmp6_2);
			this->container[2].set_matrix(2, 0, tmp6_3);

			this->container[1].set_matrix(2, 2, tmp2_1);
			this->container[1].set_matrix(2, 1, tmp2_2);
			this->container[1].set_matrix(2, 0, tmp2_3);

			this->container[5].set_matrix(2, 2, tmp1_1);
			this->container[5].set_matrix(2, 1, tmp1_2);
			this->container[5].set_matrix(2, 0, tmp1_3);

			this->container[6].set_matrix(2, 2, tmp5_1);
			this->container[6].set_matrix(2, 1, tmp5_2);
			this->container[6].set_matrix(2, 0, tmp5_3);

		} // end if side 4

		if (side == 5)
		{
			char tmp1_1 = this->container[1].get_matrix(2, 2);
			char tmp1_2 = this->container[1].get_matrix(1, 2);
			char tmp1_3 = this->container[1].get_matrix(0, 2);

			char tmp3_1 = this->container[3].get_matrix(2, 2);
			char tmp3_2 = this->container[3].get_matrix(1, 2);
			char tmp3_3 = this->container[3].get_matrix(0, 2);

			char tmp6_1 = this->container[6].get_matrix(0, 0);
			char tmp6_2 = this->container[6].get_matrix(1, 0);
			char tmp6_3 = this->container[6].get_matrix(2, 0);

			char tmp4_1 = this->container[4].get_matrix(0, 0);
			char tmp4_2 = this->container[4].get_matrix(1, 0);
			char tmp4_3 = this->container[4].get_matrix(2, 0);

			this->container[1].set_matrix(2, 2, tmp4_1);
			this->container[1].set_matrix(1, 2, tmp4_2);
			this->container[1].set_matrix(0, 2, tmp4_3);

			this->container[3].set_matrix(2, 2, tmp1_1);
			this->container[3].set_matrix(1, 2, tmp1_2);
			this->container[3].set_matrix(0, 2, tmp1_3);

			this->container[6].set_matrix(0, 0, tmp3_1);
			this->container[6].set_matrix(1, 0, tmp3_2);
			this->container[6].set_matrix(2, 0, tmp3_3);

			this->container[4].set_matrix(0, 0, tmp6_1);
			this->container[4].set_matrix(1, 0, tmp6_2);
			this->container[4].set_matrix(2, 0, tmp6_3);

		} // end if side 5

		if (side == 6)
		{
			char tmp3_1 = this->container[3].get_matrix(0, 0);
			char tmp3_2 = this->container[3].get_matrix(0, 1);
			char tmp3_3 = this->container[3].get_matrix(0, 2);

			char tmp5_1 = this->container[5].get_matrix(0, 2);
			char tmp5_2 = this->container[5].get_matrix(1, 2);
			char tmp5_3 = this->container[5].get_matrix(2, 2);

			char tmp4_1 = this->container[4].get_matrix(2, 2);
			char tmp4_2 = this->container[4].get_matrix(2, 1);
			char tmp4_3 = this->container[4].get_matrix(2, 0);

			char tmp2_1 = this->container[2].get_matrix(2, 0);
			char tmp2_2 = this->container[2].get_matrix(1, 0);
			char tmp2_3 = this->container[2].get_matrix(0, 0);

			this->container[3].set_matrix(0, 0, tmp2_1);
			this->container[3].set_matrix(0, 1, tmp2_2);
			this->container[3].set_matrix(0, 2, tmp2_3);

			this->container[5].set_matrix(0, 2, tmp3_1);
			this->container[5].set_matrix(1, 2, tmp3_2);
			this->container[5].set_matrix(2, 2, tmp3_3);

			this->container[4].set_matrix(2, 2, tmp5_1);
			this->container[4].set_matrix(2, 1, tmp5_2);
			this->container[4].set_matrix(2, 0, tmp5_3);

			this->container[2].set_matrix(2, 0, tmp4_1);
			this->container[2].set_matrix(1, 0, tmp4_2);
			this->container[2].set_matrix(0, 0, tmp4_3);

		} // end if side 6

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

	if (side == 1)
	{
		char tmp3_1 = this->container[3].get_matrix(2, 0);
		char tmp3_2 = this->container[3].get_matrix(2, 1);
		char tmp3_3 = this->container[3].get_matrix(2, 2);

		char tmp5_1 = this->container[5].get_matrix(0, 0);
		char tmp5_2 = this->container[5].get_matrix(1, 0);
		char tmp5_3 = this->container[5].get_matrix(2, 0);

		char tmp4_1 = this->container[4].get_matrix(0, 2);
		char tmp4_2 = this->container[4].get_matrix(0, 1);
		char tmp4_3 = this->container[4].get_matrix(0, 0);

		char tmp2_1 = this->container[2].get_matrix(2, 2);
		char tmp2_2 = this->container[2].get_matrix(1, 2);
		char tmp2_3 = this->container[2].get_matrix(0, 2);

		this->container[3].set_matrix(2, 0, tmp5_1);
		this->container[3].set_matrix(2, 1, tmp5_2);
		this->container[3].set_matrix(2, 2, tmp5_3);

		this->container[5].set_matrix(0, 0, tmp4_1);
		this->container[5].set_matrix(1, 0, tmp4_2);
		this->container[5].set_matrix(2, 0, tmp4_3);

		this->container[4].set_matrix(0, 2, tmp2_1);
		this->container[4].set_matrix(0, 1, tmp2_2);
		this->container[4].set_matrix(0, 0, tmp2_3);

		this->container[2].set_matrix(2, 2, tmp3_1);
		this->container[2].set_matrix(1, 2, tmp3_2);
		this->container[2].set_matrix(0, 2, tmp3_3);

	} // end if side 1

	if (side == 2)
	{
		char tmp3_1 = this->container[3].get_matrix(0, 0);
		char tmp3_2 = this->container[3].get_matrix(1, 0);
		char tmp3_3 = this->container[3].get_matrix(2, 0);

		char tmp1_1 = this->container[1].get_matrix(0, 0);
		char tmp1_2 = this->container[1].get_matrix(1, 0);
		char tmp1_3 = this->container[1].get_matrix(2, 0);

		char tmp4_1 = this->container[4].get_matrix(0, 0);
		char tmp4_2 = this->container[4].get_matrix(1, 0);
		char tmp4_3 = this->container[4].get_matrix(2, 0);

		char tmp6_1 = this->container[6].get_matrix(2, 2);
		char tmp6_2 = this->container[6].get_matrix(1, 2);
		char tmp6_3 = this->container[6].get_matrix(0, 2);

		this->container[3].set_matrix(0, 0, tmp1_1);
		this->container[3].set_matrix(1, 0, tmp1_2);
		this->container[3].set_matrix(2, 0, tmp1_3);

		this->container[1].set_matrix(0, 0, tmp4_1);
		this->container[1].set_matrix(1, 0, tmp4_2);
		this->container[1].set_matrix(2, 0, tmp4_3);

		this->container[4].set_matrix(0, 0, tmp6_1);
		this->container[4].set_matrix(1, 0, tmp6_2);
		this->container[4].set_matrix(2, 0, tmp6_3);

		this->container[6].set_matrix(2, 2, tmp3_1);
		this->container[6].set_matrix(1, 2, tmp3_2);
		this->container[6].set_matrix(0, 2, tmp3_3);

	} // end if side 2

	if (side == 3)
	{
		char tmp2_1 = this->container[2].get_matrix(0, 2);
		char tmp2_2 = this->container[2].get_matrix(0, 1);
		char tmp2_3 = this->container[2].get_matrix(0, 0);

		char tmp6_1 = this->container[6].get_matrix(0, 2);
		char tmp6_2 = this->container[6].get_matrix(0, 1);
		char tmp6_3 = this->container[6].get_matrix(0, 0);

		char tmp5_1 = this->container[5].get_matrix(0, 2);
		char tmp5_2 = this->container[5].get_matrix(0, 1);
		char tmp5_3 = this->container[5].get_matrix(0, 0);

		char tmp1_1 = this->container[1].get_matrix(0, 2);
		char tmp1_2 = this->container[1].get_matrix(0, 1);
		char tmp1_3 = this->container[1].get_matrix(0, 0);

		this->container[2].set_matrix(0, 2, tmp6_1);
		this->container[2].set_matrix(0, 1, tmp6_2);
		this->container[2].set_matrix(0, 0, tmp6_3);

		this->container[6].set_matrix(0, 2, tmp5_1);
		this->container[6].set_matrix(0, 1, tmp5_2);
		this->container[6].set_matrix(0, 0, tmp5_3);

		this->container[5].set_matrix(0, 2, tmp1_1);
		this->container[5].set_matrix(0, 1, tmp1_2);
		this->container[5].set_matrix(0, 0, tmp1_3);

		this->container[1].set_matrix(0, 2, tmp2_1);
		this->container[1].set_matrix(0, 1, tmp2_2);
		this->container[1].set_matrix(0, 0, tmp2_3);

	} // end if side 3

	if (side == 4)
	{
		char tmp2_1 = this->container[2].get_matrix(2, 2);
		char tmp2_2 = this->container[2].get_matrix(2, 1);
		char tmp2_3 = this->container[2].get_matrix(2, 0);

		char tmp1_1 = this->container[1].get_matrix(2, 2);
		char tmp1_2 = this->container[1].get_matrix(2, 1);
		char tmp1_3 = this->container[1].get_matrix(2, 0);

		char tmp5_1 = this->container[5].get_matrix(2, 2);
		char tmp5_2 = this->container[5].get_matrix(2, 1);
		char tmp5_3 = this->container[5].get_matrix(2, 0);

		char tmp6_1 = this->container[6].get_matrix(2, 2);
		char tmp6_2 = this->container[6].get_matrix(2, 1);
		char tmp6_3 = this->container[6].get_matrix(2, 0);

		this->container[2].set_matrix(2, 2, tmp1_1);
		this->container[2].set_matrix(2, 1, tmp1_2);
		this->container[2].set_matrix(2, 0, tmp1_3);

		this->container[1].set_matrix(2, 2, tmp5_1);
		this->container[1].set_matrix(2, 1, tmp5_2);
		this->container[1].set_matrix(2, 0, tmp5_3);

		this->container[5].set_matrix(2, 2, tmp6_1);
		this->container[5].set_matrix(2, 1, tmp6_2);
		this->container[5].set_matrix(2, 0, tmp6_3);

		this->container[6].set_matrix(2, 2, tmp2_1);
		this->container[6].set_matrix(2, 1, tmp2_2);
		this->container[6].set_matrix(2, 0, tmp2_3);

	} // end if side 4

	if (side == 5)
	{
		char tmp1_1 = this->container[1].get_matrix(2, 2);
		char tmp1_2 = this->container[1].get_matrix(1, 2);
		char tmp1_3 = this->container[1].get_matrix(0, 2);

		char tmp3_1 = this->container[3].get_matrix(2, 2);
		char tmp3_2 = this->container[3].get_matrix(1, 2);
		char tmp3_3 = this->container[3].get_matrix(0, 2);

		char tmp6_1 = this->container[6].get_matrix(0, 0);
		char tmp6_2 = this->container[6].get_matrix(1, 0);
		char tmp6_3 = this->container[6].get_matrix(2, 0);

		char tmp4_1 = this->container[4].get_matrix(0, 0);
		char tmp4_2 = this->container[4].get_matrix(1, 0);
		char tmp4_3 = this->container[4].get_matrix(2, 0);

		this->container[1].set_matrix(2, 2, tmp3_1);
		this->container[1].set_matrix(1, 2, tmp3_2);
		this->container[1].set_matrix(0, 2, tmp3_3);

		this->container[3].set_matrix(2, 2, tmp6_1);
		this->container[3].set_matrix(1, 2, tmp6_2);
		this->container[3].set_matrix(0, 2, tmp6_3);

		this->container[6].set_matrix(0, 0, tmp4_1);
		this->container[6].set_matrix(1, 0, tmp4_2);
		this->container[6].set_matrix(2, 0, tmp4_3);

		this->container[4].set_matrix(0, 0, tmp1_1);
		this->container[4].set_matrix(1, 0, tmp1_2);
		this->container[4].set_matrix(2, 0, tmp1_3);

	} // end if side 5

	if (side == 6)
	{
		char tmp3_1 = this->container[3].get_matrix(0, 0);
		char tmp3_2 = this->container[3].get_matrix(0, 1);
		char tmp3_3 = this->container[3].get_matrix(0, 2);

		char tmp5_1 = this->container[5].get_matrix(0, 2);
		char tmp5_2 = this->container[5].get_matrix(1, 2);
		char tmp5_3 = this->container[5].get_matrix(2, 2);

		char tmp4_1 = this->container[4].get_matrix(2, 2);
		char tmp4_2 = this->container[4].get_matrix(2, 1);
		char tmp4_3 = this->container[4].get_matrix(2, 0);

		char tmp2_1 = this->container[2].get_matrix(2, 0);
		char tmp2_2 = this->container[2].get_matrix(1, 0);
		char tmp2_3 = this->container[2].get_matrix(0, 0);

		this->container[3].set_matrix(0, 0, tmp5_1);
		this->container[3].set_matrix(0, 1, tmp5_2);
		this->container[3].set_matrix(0, 2, tmp5_3);

		this->container[5].set_matrix(0, 2, tmp4_1);
		this->container[5].set_matrix(1, 2, tmp4_2);
		this->container[5].set_matrix(2, 2, tmp4_3);

		this->container[4].set_matrix(2, 2, tmp2_1);
		this->container[4].set_matrix(2, 1, tmp2_2);
		this->container[4].set_matrix(2, 0, tmp2_3);

		this->container[2].set_matrix(2, 0, tmp3_1);
		this->container[2].set_matrix(1, 0, tmp3_2);
		this->container[2].set_matrix(0, 0, tmp3_3);

	} // end if side 6
}
