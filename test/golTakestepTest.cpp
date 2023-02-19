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


TEST_CASE( "Take_step_function_test", "[ImplementGol]" ) {
    string file_path = "/workspaces/game-of-life-Ablert1213/test/data/oscillators.txt";
    gol::ImplementGol file_input = gol::ImplementGol (file_path);
    file_input.TakeStep();

    int error = 0;

    // check if the takeStep function follow the Game of life rule to generate cells on the next iteration
    if (file_input.GetIndividualCell(0, 9) != 'o'){ ++error;}
    if (file_input.GetIndividualCell(1, 2) != '-'){ ++error;}
    if (file_input.GetIndividualCell(7, 9) != 'o'){ ++error;}
    if (file_input.GetIndividualCell(6, 9) != '-'){ ++error;}
    if (file_input.GetIndividualCell(8, 2) != '-'){ ++error;}
    
    REQUIRE( error == 0);
    }