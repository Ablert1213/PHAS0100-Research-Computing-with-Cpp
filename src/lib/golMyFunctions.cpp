/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "golMyFunctions.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using std::string;
using std::vector;
using std::invalid_argument;
namespace gol {

//-----------------------------------------------------------------------------
int MyFirstAddFunction(int a, int b)
{
  return a + b;
}
//-----------------------------------------------------------------------------
GridDataStructure::GridDataStructure(const int& num_rows, const int num_columns){
  // filter rows and columns inputs 
  if (num_rows < 0 || num_columns < 0)
    throw invalid_argument("Row and Column inputs should be positive");
  if (typeid(num_rows).name()!= "i" || typeid(num_columns).name()!= "i");
    throw invalid_argument("Row and Column inputs should be integer");
  // store the grid
  row_input = num_rows;
  columns_input = num_columns;
  // initialize random seed:
  srand (time(NULL));
  // randomly choose number of alive cells
  alive_cell_input = rand() % row_input * columns_input;
}

} // end namespace
