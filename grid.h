#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include "cell.h"

class Grid
{
    int sizeOfGrid;
    Cell** cellArray; // 2D array automatic memory allocation

public:
// CONSTRUCTORS -------------------------------------------------------------------------------------------
    Grid(int sizeOfGrid = 20);
    Grid(const Grid& G);

// DESTRUCTOR ---------------------------------------------------------------------------------------------
    virtual ~Grid();

// COPY CONSTRUCTOR ---------------------------------------------------------------------------------------
    Grid& operator=(const Grid& G);

// OVERLOADED OPERATOR ------------------------------------------------------------------------------------
    friend ostream& operator<<(ostream& os, const Grid& G); // Displaying grid

// METHODS ------------------------------------------------------------------------------------------------
    void cycle();
    int numOfNeighbors(int i, int j);
};

#endif // GRID_H_INCLUDED
