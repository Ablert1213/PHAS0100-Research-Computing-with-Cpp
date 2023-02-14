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
#include <fstream>

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
GridDataStructure::GridDataStructure(const int& num_rows, const int& num_columns){
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

//-----------------------------------------------------------------------------
GridDataStructure::GridDataStructure(const int& num_rows, const int& num_columns, const int& num_alive_cells){
  // filter rows and columns inputs 
  if (num_rows < 0 || num_columns < 0 || num_alive_cells < 0)
    throw invalid_argument("Row, Column and alive cells inputs should be positive");
  if (typeid(num_rows).name()!= "i" || typeid(num_columns).name()!= "i" || typeid(num_alive_cells).name()!= "i");
    throw invalid_argument("Row, Column and alive cells inputs should be integer");
  if (num_alive_cells > num_rows*num_columns);
  throw invalid_argument("The alive cells input can larger than the total number of cells");
  // store the grid
  row_input = num_rows;
  columns_input = num_columns;
  alive_cell_input = num_alive_cells;
  }

//-----------------------------------------------------------------------------
GridDataStructure::GridDataStructure(string& file_path){
  std::ifstream file_handle(file_path);
  int count = 0;
  if (file_handle.is_open()) {
    string file_line;
    // std::cout << file_line;
    while (std::getline(file_handle, file_line)) {
      vector<char> file_row_input;
      
      for (char &element : file_line){
        if (element == ' '){
          continue;
        }
        else if (element == 'o')
        {
          file_row_input.push_back('o');
          ++count;
        }
        else if (element == '-'){
          file_row_input.push_back('-');
        }
      }
    GridCellInput.push_back(file_row_input);
    }
  row_input = GridCellInput.size();
  // as number of columns will be the same in one text, so we only take first line to measure.
  columns_input = GridCellInput[0].size();
  alive_cell_input = count;
  }
  else {
    // show message:
    throw invalid_argument("Error opening file");
  }
}

//-----------------------------------------------------------------------------
void GridDataStructure::PrintGrid(){
  for (int count_row = 0; count_row < row_input; ++count_row){
    for (int count_cols = 0; count_cols < columns_input; ++count_cols){
      std::cout << GridCellInput[count_row][count_cols] <<" ";
    }
  std::cout << std::endl;
  }
}

//-----------------------------------------------------------------------------
} // end namespace
