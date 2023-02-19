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
using std::cout;
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
  // if (typeid(num_rows).name()!= "i" || typeid(num_columns).name()!= "i");
  //   throw invalid_argument("Row and Column inputs should be integer");
  // store the grid
  row_input = num_rows;
  columns_input = num_columns;
  // initialize random seed:
	srand((unsigned) time(NULL));
  // randomly choose number of alive cells
  alive_cell_input = rand() % row_input * columns_input;
  // initialised the grid vector
  vector<vector<char>> InitialGridCellInput(num_rows, vector<char>(num_columns,'-'));
  // set random x,y coordinates
  for (int count = 0; count < alive_cell_input; ++count){
    int rows_coord = rand() % row_input;
    int columns_coord = rand() % columns_input;
    if (InitialGridCellInput[rows_coord][columns_coord] == 'o'){--count; continue;}
    else{
      InitialGridCellInput[rows_coord][columns_coord] = 'o';
    }
  }
  GridCellInput = InitialGridCellInput;
}

//-----------------------------------------------------------------------------
GridDataStructure::GridDataStructure(const int& num_rows, const int& num_columns, const int& num_alive_cells){
  // filter rows and columns inputs 
  if (num_rows < 0 || num_columns < 0 || num_alive_cells < 0)
    throw invalid_argument("Row, Column and alive cells inputs should be positive");
  // if (typeid(num_rows).name()!= "i" || typeid(num_columns).name()!= "i" || typeid(num_alive_cells).name()!= "i");
  //   throw invalid_argument("Row, Column and alive cells inputs should be integer");
  // if (num_alive_cells > num_rows*num_columns);
  //     throw invalid_argument("The alive cells input can not larger than the total number of cells");
  // store the grid
  row_input = num_rows;
  columns_input = num_columns;
  alive_cell_input = num_alive_cells;
  // initialised the grid vector
  vector<vector<char>> InitialGridCellInput(num_rows, vector<char>(num_columns,'-'));
  // initialize random seed:
	srand((unsigned) time(NULL));
  // set random x,y coordinates
  for (int count = 0; count < alive_cell_input; ++count){
    int rows_coord = rand() % row_input;
    int columns_coord = rand() % columns_input;
    if (InitialGridCellInput[rows_coord][columns_coord] == 'o'){--count; continue;}
    else{
      InitialGridCellInput[rows_coord][columns_coord] = 'o';
    }
  }
  GridCellInput = InitialGridCellInput;
  }

//-----------------------------------------------------------------------------
GridDataStructure::GridDataStructure(string& file_path){
  std::ifstream file_handle(file_path);
  int count = 0;
  if (file_handle.is_open()) {
    string file_line;
    while (std::getline(file_handle, file_line)) {
      vector<char> file_row_input;
      
      for (char &element : file_line){
        if (element == ' '){
          continue;
        }
        else if (element == 'o')
        {
          file_row_input.push_back('o');
          // count alive cells
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
// get individual cell content 
char GridDataStructure::GetIndividualCell(const int& rows_coord, const int& columns_coord){
  // if (rows_coord <= 0 || columns_coord <= 0)
  //   throw invalid_argument("Row and Column coordinates inputs should be positive");
  // if (typeid(rows_coord).name()!= "i" || typeid(columns_coord).name()!= "i");
  //   throw invalid_argument("Row and Column inputs should be integer");
  // if (rows_coord > row_input || columns_coord > columns_input);
  //   throw invalid_argument("Row or Column coordinates inputs are out of range");
  return GridCellInput[rows_coord][columns_coord];
}

//-----------------------------------------------------------------------------
// set individual cell content 
void GridDataStructure::SetIndividualCell(const int& rows_coord, const int& columns_coord, const char& cell_content){
  // if (rows_coord <= 0 || columns_coord <= 0)
  //   throw invalid_argument("Row and Column coordinates inputs should be positive");
  // if (typeid(rows_coord).name()!= "i" || typeid(columns_coord).name()!= "i");
  //   throw invalid_argument("Row and Column coordinates inputs should be integer");
  // if (rows_coord > row_input || columns_coord > columns_input);
  //   throw invalid_argument("Row or Column coordinates inputs are out of range");  
  // if (typeid(cell_content).name()!= "c");
  //   throw invalid_argument("Type of cell content input should be char");
  // if (cell_content != '-' && cell_content != 'o')
  //   throw invalid_argument("Row and Column inputs are wrong");
  GridCellInput[rows_coord][columns_coord] = cell_content;
}

//-----------------------------------------------------------------------------
void GridDataStructure::PrintGrid(){
  for (int count_row = 0; count_row < row_input; ++count_row){
    for (int count_cols = 0; count_cols < columns_input; ++count_cols){
      cout << GridCellInput[count_row][count_cols] <<" ";
    }
  cout << std::endl;
  }
}

//-----------------------------------------------------------------------------
int GridDataStructure::FetchLiveNeighbors(int& rows_coord, int& columns_coord){
  // if (rows_coord < 0 || columns_coord < 0)
  //   throw invalid_argument("Row and Column coordinates inputs should be positive");
  // if (typeid(rows_coord).name()!= "i" || typeid(columns_coord).name()!= "i");
  //   throw invalid_argument("Row and Column coordinates inputs should be integer");
  // if (rows_coord > row_input || columns_coord > columns_input);
    // throw invalid_argument("Row or Column coordinates inputs are out of range");


  // initialised number of alive neighbors
  int num_alive_neighbors = 0; 
  // fetching left live neighbour
  if (rows_coord >= 0 && rows_coord < row_input && columns_coord-1 >= 0 && columns_coord-1 < columns_input && GridCellInput[rows_coord][columns_coord-1] == 'o'){
    ++num_alive_neighbors;
  }
  // fetching left upper diagonally live neighbour
  if (rows_coord-1 >= 0 && rows_coord-1 < row_input && columns_coord-1 >= 0 && columns_coord-1 < columns_input && GridCellInput[rows_coord-1][columns_coord-1] == 'o'){
    ++num_alive_neighbors;
  }
  // fetching upper live neighbour  
  if (rows_coord-1 >= 0 && rows_coord-1 < row_input && columns_coord >= 0 && columns_coord < columns_input && GridCellInput[rows_coord-1][columns_coord] == 'o'){
    ++num_alive_neighbors;
  }
  // fetching right upper diagonally live neighbour
  if (rows_coord-1 >= 0 && rows_coord-1 < row_input && columns_coord+1 >= 0 && columns_coord+1 < columns_input && GridCellInput[rows_coord-1][columns_coord+1] == 'o'){
    ++num_alive_neighbors;
  }
  // fetching right live neighbour
  if (rows_coord >= 0 && rows_coord < row_input && columns_coord+1 >= 0 && columns_coord+1 < columns_input && GridCellInput[rows_coord][columns_coord+1] == 'o'){
    ++num_alive_neighbors;
  }
  // fetching right lower diagonally live neighbour
  if (rows_coord+1 >= 0 && rows_coord+1 < row_input && columns_coord+1 >= 0 && columns_coord+1 < columns_input && GridCellInput[rows_coord+1][columns_coord+1] == 'o'){
    ++num_alive_neighbors;
  }
  // fetching lower live neighbour
  if (rows_coord+1 >= 0 && rows_coord+1 < row_input && columns_coord >= 0 && columns_coord < columns_input && GridCellInput[rows_coord+1][columns_coord] == 'o'){
    ++num_alive_neighbors;
  }
  // fetching left lower diagonally live neighbour
  if (rows_coord+1 >= 0 && rows_coord+1 < row_input && columns_coord-1 >= 0 && columns_coord-1 < columns_input && GridCellInput[rows_coord+1][columns_coord-1] == 'o'){
    ++num_alive_neighbors;
  }              
  return num_alive_neighbors;
}

//-----------------------------------------------------------------------------
vector<int> GridDataStructure::GetVectorSize (){
  vector<int> size_count;
  int row_size = row_input;
  size_count.push_back(row_size);
  int col_size = columns_input;
  size_count.push_back(col_size);
  return size_count;
}
//-----------------------------------------------------------------------------
int GridDataStructure::RetAliveCellNumber (){
  return alive_cell_input;
}

}

 // end namespace
