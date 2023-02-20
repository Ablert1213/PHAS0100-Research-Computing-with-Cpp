[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-f4981d0f882b2a3f0472912d15f9806d57e124e0fc890972558857b51b24a6f9.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=10102203)
PHAS0100ASSIGNMENT1
------------------

Purpose
-------

This project serves as a starting point for the PHAS0100 2022/23 Assignment 1 Game of Life Simulation coursework. It has a reasonable folder structure for [CMake](https://cmake.org/) based projects that use [CTest](https://cmake.org/) to run unit tests via [Catch](https://github.com/catchorg/Catch2). 

In this coursework I create a simulation program that models Conway’s Game of Life, a 2D cellular automaton devised in 1970 by the mathematician John Conway. By following 3 simple rules of the game: 
i), A dead cell with exactly three live neighbours should become a live cell. 
ii), A live cell with two or three live neighbours should stay alive.
iii), A live cell with less than two or more than three live neighbours should die.

In the 'golMyFunctions.cpp' file, I created the 'GridDataStructure' class to start the game with different initial conditions based on either a set of random starting cell values or by reading in the initial conditions from a text input file. And in the 'golImplementGol.cpp' file, I created the 'ImplementGol' class with 'TakeStep' function that takes the current grid of cells and works out whether each cell should be alive or dead on the next iteration based on the game rules.

Besides that, I also created two ccommand-line applications. The first one name 'gol_simulator' that can run the Game of Life Simulation on given arguments and requested number of steps. Second one named 'FindStationaryPatterns' that can find still lifes by comparing the current and next generation of cells and calculating if there has been no change between them. I will introduce how to use them with examples blow.

Finally, in the test folder, I have defined several essential tests to check all the functions in the file work perfectly, and all the classes can generate correct grid based on users' inputs.

Credits
-------

This project is maintained by [Dr. Jamie Quinn](http://jamiejquinn.com/). It is based on [CMakeCatch2](https://github.com/UCL/CMakeCatch2.git) that was originally developed as a teaching aid for UCL's ["Research Computing with C++"](https://github-pages.ucl.ac.uk/research-computing-with-cpp/) course developed by [Dr. James Hetherington](http://www.ucl.ac.uk/research-it-services/people/james) and [Dr. Matt Clarkson](https://iris.ucl.ac.uk/iris/browse/profile?upi=MJCLA42).

Build Instructions
------------------

At the beginning, in order to run all the command-line applications, we have to build fuction, run cmake and compile under the right directory(under 'PHAS0100Assignment1' directory).  
Type these following commands in terminal under the correct directory:
```
$ cmake -B build
$ cmake --build build
```

To run two command-line applications:
- Introduction of using 'gol_simulator' to run the Game of Life simulation:
i), print a useful help message when run with no arguments and also when run with --help or -h options, command examples blow:
```
$ ./build/bin/gofSimulator 
$ ./build/bin/gofSimulator --help
$ ./build/bin/gofSimulator -h
```

ii), starting with random cell contents for the initial conditions. Input format: 'number of rows, number of columns, number of generations to simulate'(This will generate random number of alive cells under number of rows*number of columns), or 'number of rows, number of columns, number of alive cells, number of generations to simulate'. Note: 'number of alive cells' input should be under 'number of rows*number of columns'.
Command examples:
Example inputs: '5 rows, 6 columns, 7 generations to simulate'
```
$ ./build/bin/gofSimulator 5 6 7
```
Example inputs: '5 rows, 6 columns, 7 alive cells, 8 generations to simulate'
```
$ ./build/bin/gofSimulator 5 6 7 8
```

iii), specifying a text file input. Input format: 'text_file_path.txt, number of generations to simulate'. (As we put data file under test/data, so we the function will read file under this path as default. If there is any new data file, it should be put under this path. And we have to move under build/ path in advance.)
Example inputs: 'glider.txt, 3 generations to simulate'
```
$ cd build/
$ ./bin/gofSimulator glider.txt 3
```

- Introduction of using 'FindStationaryPatterns' to find still lifes:
i), print a useful help message when run with no arguments and also when run with --help or -h options, command examples blow:
```
$ ./build/bin/FindStationaryPatterns 
$ ./build/bin/FindStationaryPatterns --help
$ ./build/bin/FindStationaryPatterns -h
```

ii), starting with random cell contents for the initial conditions. Input format: 'number of rows, number of columns, number of alive cells, number of generations to simulate, number of stills patterns to find'. Note: 'number of alive cells' input should be under 'number of rows*number of columns'.
Command examples:
Example inputs: '5 rows, 6 columns, 7 alive cells, 8 generations to simulate, 4 still lifes to find'
```
$ ./build/bin/gofSimulator 5 6 7 8 4
```

To Run Test:
Using ctest inside build directory:
```
$ cd build/
$ ctest
```

Coursework Results
------------------
Screenshots:
- Running with glider.txt input file after 4 evolutions:
 ![238df346a544c95d84ed057730bc0ef](https://user-images.githubusercontent.com/114681287/220139573-eff805a1-ba26-4e0a-b9b1-6945e34eb75d.jpg)
 
- Starting a 7 by 7 grid with random initial cell values (15 alive cells) after 4 evolutions:
![de4cfde9fb66fb43f3fcda58d938339](https://user-images.githubusercontent.com/114681287/220139837-a6118f10-31c9-48ed-ac37-e87e2bc2f57a.png)

- Running the program for a 4 by 4 grid of cells, and 4 still lifes have be found:
![89423ebf52e3adde09baa2962830e48](https://user-images.githubusercontent.com/114681287/220140189-7998b5d5-c826-4cfa-9a34-6596f2ab643e.png)

results:
I found 4 different still lifes. According to the (https://conwaylife.com/wiki/List_of_common_still_lifes) list on Wiki, 3 of them names are 'Loaf', 'Boat' and 'Block'. As I observed, most of the cells went 'dead' through generations. But in some cases, all of cells in the grid have 2 or 3 alive neighbours, which causing all of them 'live' forever with no 'new born' or 'new killed'.

