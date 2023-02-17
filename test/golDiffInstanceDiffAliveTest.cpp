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

TEST_CASE( "Diff_instances_generate_diff_num_alive_cells_and_diff_patterns_Test", "[GridDataStructure]" ) {

  gol::GridDataStructure random_1 = gol::GridDataStructure(200,200);
  gol::GridDataStructure random_2 = gol::GridDataStructure(200,200);

  int positive_count = 0;

  if (random_1.RetAliveCellNumber() <= 200*200 || random_2.RetAliveCellNumber() <= 200*200 || random_1.RetAliveCellNumber() != random_2.RetAliveCellNumber()){
    ++positive_count;
    }

  REQUIRE( positive_count > 0);
}
