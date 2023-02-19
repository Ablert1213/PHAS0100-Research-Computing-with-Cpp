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

TEST_CASE( "Fetch_live_neighbour_test", "[GridDataStructure]" ) {
    string file_path = "/workspaces/game-of-life-Ablert1213/test/data/oscillators.txt";
    gol::GridDataStructure file_input = gol::GridDataStructure (file_path);
    int error = 0;
    int check = 0;

    // check if the function find the neighbors correct
    // points at corner
    if (file_input.FetchLiveNeighbors(0, 0) != 0){ ++error;}
    if (file_input.FetchLiveNeighbors(11, 11) != 0){ ++error;}
    if (file_input.FetchLiveNeighbors(0, 11) != 1){ ++error;}
    // points at center
    if (file_input.FetchLiveNeighbors(1, 1) != 2){ ++error;}
    if (file_input.FetchLiveNeighbors(7, 1) != 3){ ++error;}

    REQUIRE( error == 0);
}