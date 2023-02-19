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

TEST_CASE( "Diff_instances_generate_diff_num_alive_cells_and_patterns_Test", "[GridDataStructure]" ) {
  int random_check = 0;
  // check that the different instances generate different patterns of alive cells
  while (random_check == 0){
    gol::GridDataStructure random_1 = gol::GridDataStructure(200,200);
    gol::GridDataStructure random_2 = gol::GridDataStructure(200,200);
    if (random_1.RetAliveCellNumber() == random_2.RetAliveCellNumber()){
      continue;
    }
    else{
      ++random_check;
      break;
    }
  }
  // check if different instance generate different alive cells pattern
  while (random_check == 1){
    gol::GridDataStructure random_3 = gol::GridDataStructure(200,200,100);
    gol::GridDataStructure random_4 = gol::GridDataStructure(200,200,100);
    int check = 0;
    for (int count_row = 0;count_row < 200; ++count_row){
        for (int count_cols = 0;count_cols < 200; ++count_cols){
          if (random_3.GetIndividualCell(count_row,count_cols) == random_4.GetIndividualCell(count_row,count_cols)){
            ++check; 
          }
        }
    }
    if (check == 200*200){
      continue;
    }
    else{
      ++random_check;
      break;
    }
  }
  // check if the grid generate given number of alive cells
  while (random_check == 2){
    gol::GridDataStructure random_5 = gol::GridDataStructure(200,200,100);
    // gol::GridDataStructure random_4 = gol::GridDataStructure(200,200,100);
    int num_alive_cells = 0;
    for (int count_row = 0;count_row < 200; ++count_row){
        for (int count_cols = 0;count_cols < 200; ++count_cols){
          if (random_5.GetIndividualCell(count_row,count_cols) == 'o'){
            ++num_alive_cells;                       
          }
          
        }
    }
    if (num_alive_cells == 100){
      ++random_check;
      break;    
      }
    else{
      continue;
    }
  }
  REQUIRE( random_check == 3);
}

