/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef golMyFunctions_h
#define golMyFunctions_h

#include <string>
#include <vector>

using std::string;
using std::vector;
/**
* \file golMyFunctions.h
* \brief Various Utilities.
* \ingroup utilities
*/
namespace gol
{

/**
* \brief My first function, adds two integers.
*/
int MyFirstAddFunction(int a, int b);

// Create a class to store the status of cells, and with some functionalities
class GridDataStructure
{
  public: 
    GridDataStructure(const int& num_rows, const int& num_columns);
    GridDataStructure(const int& num_rows, const int& num_columns, const int& num_alive_cells);
    GridDataStructure(string& file_path);
  private:
    int row_input;
    int columns_input;
    int alive_cell_input;
};
} // end namespace

#endif
