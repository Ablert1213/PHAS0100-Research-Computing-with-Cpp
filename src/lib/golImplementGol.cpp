/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "golImplementGol.h"
#include "golMyFunctions.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
#include <fstream>

using std::string;
using std::vector;
using std::invalid_argument;
using std::cout;

namespace gol {

void ImplementGol::TakeStep(){
    int num_alive_neighbors = 0;
    vector<vector<char>> Next_interation_Grid(row_input, vector<char>(columns_input,'-'));

    for (int count_row = 0;count_row < row_input; ++count_row){
        for(int count_cols = 0;count_cols < columns_input; ++count_cols){
            num_alive_neighbors = GridDataStructure::FetchLiveNeighbors(count_row, count_cols);
            // when the current cell is dead and with 3 neighbors
            if (GridCellInput[count_row][count_cols] == '-' && num_alive_neighbors == 3){
                Next_interation_Grid[count_row][count_cols] = 'o';
            }
            // when the current cell is alive
            else if (GridCellInput[count_row][count_cols] == 'o'){
                // with 2 or 3 neighbors
                if (num_alive_neighbors == 2 || num_alive_neighbors == 3){
                    Next_interation_Grid[count_row][count_cols] = 'o';
                }
                // other cases
                else{
                    Next_interation_Grid[count_row][count_cols] = '-';
                }
            }
        }
    }
    // Next_interation_Grid = Next_interation_Grid;
    Next_interation_Grid.swap(GridCellInput);
  }

//-----------------------------------------------------------------------------
void ImplementGol::PrintNextGrid(){
  for (int count_row = 0; count_row < row_input; ++count_row){
    for (int count_cols = 0; count_cols < columns_input; ++count_cols){
      cout << Next_interation_Grid[count_row][count_cols] <<" ";
    }
  cout << std::endl;
  }
}
}