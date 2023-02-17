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

TEST_CASE( "Get_Set_Cell_Test", "[GridDataStructure]" ) {
  gol::GridDataStructure row_col_input = gol::GridDataStructure(8,9);

  int error = 0;
  if (row_col_input.GetIndividualCell(4,4) != '-' && row_col_input.GetIndividualCell(4,4) != 'o'){ ++error;}
  row_col_input.SetIndividualCell(2,4,'-');
  if (row_col_input.GetIndividualCell(2,4) != '-'){ ++error;}

  REQUIRE( error == 0);
}