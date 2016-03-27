//
//  main.cpp
//  Cube_Project
//
//  Created by Heidi Lyons on 3/26/16.
//  Copyright © 2016 Heidi Lyons. All rights reserved.
//

#include <iostream>
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
            start.print_cube();
        }
        else if (line.compare(0, 4, "quit") == 0) // end program
        {
            break;
        }
    }
    cout << "Done\n";
    return 0;
}
