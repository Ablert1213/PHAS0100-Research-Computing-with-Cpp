/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef golImplementGol_h
#define golImplementGol_h

#include <string>
#include <vector>
#include "golMyFunctions.h"

using std::string;
using std::vector;
/**
* \file golImplementGol.h
* \brief Various Utilities.
* \ingroup utilities
*/
namespace gol
{

class ImplementGol : public gol::GridDataStructure{
  public:
    using GridDataStructure::GridDataStructure;
    void TakeStep();
    void PrintGrid();
  protected:
    vector<vector<char>> Next_interation_Grid;

};

}
#endif