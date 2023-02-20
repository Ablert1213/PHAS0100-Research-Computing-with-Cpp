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

int main(int argc, char* argv[])
{
// print useful help message when run with no arguments and also when run with "--help" or "-h"
    if (argc <= 2 ){
        if (argc == 1 || std::strcmp(argv[1],"--help") == 0 || std::strcmp(argv[1],"-h") == 0){
        cerr << "Help message: right format of input arguments to use this command line" << "\n"
            << "(1) " << "Application Path: " << argv[0] << " Arguments Inputs:"<<" text_file_path.txt, number of generations to simulate" << "\n"
            << "(2) " << "Application Path: " << argv[0] << " Arguments Inputs:"<<" number of rows, number of columns, number of generations to simulate" << "\n"
            << "(3) " << "Application Path: " << argv[0] << " Arguments Inputs:"<<" number of rows, number of columns, number of alive cells, number of generations to simulate" << "\n"
            << "More hints: " << "the size of grid and total number of initial alive cells should be reasonable"
            << std::endl;
            }
        else{
            throw invalid_argument("Please enter input with right and reasonable arguments");
            return 0;
        }
    }

    // (1) configure the Game of Life class of file_path input  
    else if (argc == 3){
        string file_path = "../test/data/";
        file_path =file_path.append(argv[1]);
        // cout << argv[2]<< typeid(argv[2]).name()
        //      << std::stoi(argv[2]) << typeid(std::stoi(argv[2])).name()<<std::endl;
        
        // input file path and number of iterations, initialized the first grid and print it out
        int num_generations = std::stoi(argv[2]);
        gol::ImplementGol current_grid = gol::ImplementGol(file_path);
        cout<< "Current grid: " << "\n";
        current_grid.PrintGrid();

        // set loop for number of iterations and print the grid out every time
        // cout<< 'apple'<< std::endl;
        for (int iteration = 1; iteration <= num_generations; ++iteration){
            // cout<< 'dog'<< std::endl;
            current_grid.TakeStep();
            cout<< iteration<< " generation grid: "<< std::endl;
            current_grid.PrintGrid();

            // adding a sleep (500 milliseconds) between each generation
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

    // (2) configure the Game of Life class of grid size numbers input  
    else if (argc == 4){
        int num_rows = std::stoi(argv[1]);
        int num_columns = std::stoi(argv[2]);
        int num_generations = std::stoi(argv[3]);

        // input file path and number of iterations, initialized the first grid and print it out
        gol::ImplementGol current_grid = gol::ImplementGol(num_rows, num_columns);
        cout<< "Current grid: " << "\n";
        current_grid.PrintGrid();

        // set loop for number of iterations and print the grid out every time
        for (int iteration = 1; iteration <= num_generations; ++iteration){
            current_grid.TakeStep();
            cout<< iteration<< " generation grid: "<< std::endl;
            current_grid.PrintGrid();

            // adding a sleep (500 milliseconds) between each generation
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

    // (3) configure the Game of Life class of grid size numbers and number of alive cells input
    else if (argc == 5){
        int num_rows = std::stoi(argv[1]);
        int num_columns = std::stoi(argv[2]);
        int num_alive_cells = std::stoi(argv[3]);
        int num_generations = std::stoi(argv[4]);

        // input file path and number of iterations, initialized the first grid and print it out
        gol::ImplementGol current_grid = gol::ImplementGol(num_rows, num_columns, num_alive_cells);
        cout<< "Current grid: " << "\n";
        current_grid.PrintGrid();

        // set loop for number of iterations and print the grid out every time
        for (int iteration = 1; iteration <= num_generations; ++iteration){
            current_grid.TakeStep();
            cout<< iteration<< " generation grid: "<< std::endl;
            current_grid.PrintGrid();

            // adding a sleep (500 milliseconds) between each generation
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

    // throw invalid argument when the input argument is wrong
    else {
        throw invalid_argument("Please enter input with right and reasonable arguments");
        return 0;
    }

}
