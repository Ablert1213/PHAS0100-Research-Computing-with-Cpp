/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "catch.hpp"
#include "golCatchMain.h"
#include "golMyFunctions.h"
#include "golImplementGol.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>

using std::string;
using std::vector;
using std::cout;

TEST_CASE( "Inital_grid_from_file_test", "[GridDataStructure]" ) {
    string file_path = "/workspaces/PHAS0100Assignment1/test/data/oscillators.txt";
    gol::GridDataStructure file_input = gol::GridDataStructure (file_path);
    int error = 0;
    int check = 0;
    for (int count_row = 0;count_row < 12; ++count_row){
        for (int count_cols = 0;count_cols < 12; ++count_cols){
            if (file_input.GetIndividualCell(count_row,count_cols) == 'o'){
            ++check; 
            }
        }
    }
    // check if the file data inputs are correct
    if (check != 23){ ++error;}
    if (file_input.GetVectorSize()[0] != 12){ ++error;}
    if (file_input.GetVectorSize()[1] != 12){ ++error;}
    REQUIRE( error == 0);
    }