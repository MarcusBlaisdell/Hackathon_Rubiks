//
//  main.cpp
//  Cube_Project
//
//  Created by Heidi Lyons on 3/26/16.
//  Copyright © 2016 Heidi Lyons. All rights reserved.
//

#include <iostream>
#include <cstdlib> // for clearing screen
#include "Cube.h"
#include "Side.h"
#include <string>

using std::cout;
using std::string;
using std::endl;

int main(int argc, const char * argv[])
{
    
    cout << "Cube Puzzle Simulator:" << endl;
    cout << "Type 'start' to begin " << endl;
    
    while(true)
    {
        string line;
        getline(std::cin, line);
        Cube start;
        
        if (line.compare(0, 5, "start") == 0) // add(student name,student_id)
        {
            // build a cube
            start.create_cube();
            start.pretty_print();
        }
        else if (line.compare(0, 9, "cw bottom") == 0)
        {
            start.RotateSide(3, true);
            system("CLS");
            start.pretty_print();
        }
        else if (line.compare(0, 10, "ccw bottom") == 0)
        {
            start.RotateSide(3, false);
            system("CLS");
            start.pretty_print();
        }
        else if (line.compare(0, 7, "cw left") == 0)
        {
            start.RotateSide(1, true);
            system("CLS");
            start.pretty_print();
        }
        else if (line.compare(0, 8,"ccw left") == 0)
        {
            start.RotateSide(1, false);
            system("CLS");
            start.pretty_print();
        }
        else if (line.compare(0, 7, "cw back") == 0)
        {
            start.RotateSide(5, true);
            system("CLS");
            start.pretty_print();
        }
        else if (line.compare(0, 8, "ccw back") == 0)
        {
            start.RotateSide(5, false);
            system("CLS");
            start.pretty_print();
        }
        else if (line.compare(0, 8, "cw front") == 0)
        {
            start.RotateSide(0, true);
            system("CLS");
            start.pretty_print();
        }
        else if (line.compare(0, 9, "ccw front") == 0)
        {
            start.RotateSide(0, false);
            system("CLS");
            start.pretty_print();
        }
        else if (line.compare(0, 8, "cw right") == 0)
        {
            start.RotateSide(4, true);
            system("CLS");
            start.pretty_print();
        }
        else if (line.compare(0, 9, "ccw right") == 0)
        {
            start.RotateSide(4, false);
            system("CLS");
            start.pretty_print();
        }
        else if (line.compare(0, 6, "cw top") == 0)
        {
            start.RotateSide(2, true);
            system("CLS");
            start.pretty_print();
        }
        else if (line.compare(0, 7, "ccw top") == 0)
        {
            start.RotateSide(2, false);
            system("CLS");
            start.pretty_print();
        }
        else if (line.compare(0, 4, "quit") == 0) // end program
        {
            break;
        }
    }
    cout << "Done\n";
    return 0;
}
