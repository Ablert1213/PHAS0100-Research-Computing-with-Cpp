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
  gol::GridDataStructure random_1 = gol::GridDataStructure(8,9);
  gol::GridDataStructure random_2 = gol::GridDataStructure(8,9);
  gol::GridDataStructure random_3 = gol::GridDataStructure(8,9,25);
  gol::GridDataStructure random_4 = gol::GridDataStructure(8,9,25);

  int error = 0;
  int count_1 = 0;
  for (int count_row = 0;count_row < 8; ++count_row){
    for (int count_cols = 0;count_cols < 9; ++count_cols){
        if (random_1.GetIndividualCell(count_row,count_cols) == random_2.GetIndividualCell(count_row,count_cols)){
            ++count_1;
        }
    }
}
  int count_2 = 0;
  for (int count_row = 0;count_row < 8; ++count_row){
    for (int count_cols = 0;count_cols < 9; ++count_cols){
        if (random_3.GetIndividualCell(count_row,count_cols) == random_4.GetIndividualCell(count_row,count_cols)){
            ++count_2;
        }
    }
}
  if (count_1 == 72){
    ++error;
}
  if (count_2 == 72){
    ++error;
}
  REQUIRE( error == 0);
}