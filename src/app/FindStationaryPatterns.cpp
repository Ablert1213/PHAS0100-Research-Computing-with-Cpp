/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <golMyFunctions.h>
#include <golExceptionMacro.h>
#include <golImplementGol.h>
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
#include <fstream>
#include <cstring>
#include <thread>
#include <chrono>

using std::string;
using std::vector;
using std::invalid_argument;
using std::cout;
using std::cerr;

int main(int argc, char* argv[]){
    // print useful help message when run with no arguments and also when run with "--help" or "-h"
    if (argc <= 2 ){
        if (argc == 1 || std::strcmp(argv[1],"--help") == 0 || std::strcmp(argv[1],"-h") == 0){
        cerr << "Help message: right format of input arguments to use this command line" << "\n"
            << "(1) " << "First argument: " << argv[0] << " arguments:"<<" number of rows, number of columns, number of generations to simulate, number of alive cells" << "\n"
            << std::endl;
            }
        }

    else if (argc == 6){
        int num_rows = std::stoi(argv[1]);
        int num_columns = std::stoi(argv[2]);
        int num_alive_cells = std::stoi(argv[3]);
        int num_generations = std::stoi(argv[4]);
        int num_stills = std::stoi(argv[5]);
        int stills_found = 0;
    
        // initial enter arguments to run the user specified number of calls to the Game of Life class' takeStep method 
        while (stills_found < num_stills){
            // initial current grid and next grid vector
            vector<vector<char>> Next_grid(num_rows, vector<char>(num_columns,'-'));
            gol::ImplementGol current_grid = gol::ImplementGol(num_rows, num_columns,num_alive_cells);

            // iteration to generate next generation
            for (int iteration = 1; iteration <= num_generations; ++iteration){
                current_grid.TakeStep();
                // cout<< "iteration: "<< iteration <<std::endl;
                int count = 0;

                // loop to check if the current grid equal to the previous one
                for (int count_row = 0;count_row < num_rows; ++count_row){
                    for (int count_cols = 0;count_cols < num_columns; ++count_cols){
                        if (Next_grid[count_row][count_cols] == current_grid.GetIndividualCell(count_row,count_cols)){
                            ++count;
                        }
                    }
                }    

                // if it equal to the previous one, break the loop, add stills_found
                if (count == num_rows*num_columns){
                    ++stills_found;
                    cout<< stills_found<< " stationary patterns found at iteration " << iteration << std::endl;
                    current_grid.PrintGrid();
                    break;
                }

                // if it's not, update Next_grid vector
                else{
                    // Next_grid = current_grid.GetVector();
                    for (int count_row = 0;count_row < num_rows; ++count_row){
                        for (int count_cols = 0;count_cols < num_columns; ++count_cols){
                            Next_grid[count_row][count_cols] = current_grid.GetIndividualCell(count_row,count_cols);
                            }
                        }
                    continue;
                }
            }   
        }
    return 0;
    }
    else{
        cout<< " incorrect input arguments, please check the help message." << std::endl;
    }
}