#include "grid.h"

// CONSTRUCTORS -------------------------------------------------------------------------------------------
Grid::Grid(int sizeOfGrid)
{
    this -> sizeOfGrid = sizeOfGrid;
    cellArray = new Cell*[sizeOfGrid];

    for(int i=0; i<sizeOfGrid; i++)
    {
        cellArray[i] = new Cell[sizeOfGrid];
    }

    for(int j=1; j<sizeOfGrid - 1; ++j)
    {
        for(int i=1; i<sizeOfGrid - 1; i++)
        {
            cellArray[i][j].setState(rand() % 2);
        }
    }
}

Grid::Grid(const Grid& G)
{
    this -> sizeOfGrid = G.sizeOfGrid;
    cellArray = new Cell*[G.sizeOfGrid];

    for(int i =0; i< G.sizeOfGrid; i++)
    {
        cellArray[i] = new Cell[G.sizeOfGrid];
    }

    for(int j=1; j<G.sizeOfGrid-1; ++j)
    {
        for(int i=1; i<G.sizeOfGrid-1; i++)
        {
            cellArray[i][j].setState(G.cellArray[i][j].getState());
        }
    }
}

// DESTRUCTOR ---------------------------------------------------------------------------------------------
Grid::~Grid()
{
    for(int i=0; i<sizeOfGrid; i++)
    {
        delete [] cellArray[i];
    }

    delete [] cellArray;
}

// COPY CONSTRUCTOR ---------------------------------------------------------------------------------------
Grid& Grid::operator=(const Grid& G)
{
    if(this == &G) return *this;

    for(int i=0; i<G.sizeOfGrid; i++)
    {
        delete [] cellArray[i];
    }

    delete [] cellArray;

    this -> sizeOfGrid = G.sizeOfGrid;
    cellArray = new Cell*[G.sizeOfGrid];

    for(int i =0; i< G.sizeOfGrid; i++)
    {
        cellArray[i] = new Cell[G.sizeOfGrid];
    }

    for(int j=1; j<G.sizeOfGrid-1; ++j)
    {
        for(int i=1; i<G.sizeOfGrid-1; i++)
        {
            cellArray[i][j].setState(G.cellArray[i][j].getState());
        }
    }

    return *this;
}

// OVERLOADED OPERATOR ------------------------------------------------------------------------------------
ostream& operator<<(ostream& os, const Grid& G) // Displaying grid
{
    for(int j=0; j<G.sizeOfGrid; ++j)
    {
        for(int i=0; i<G.sizeOfGrid; i++)
        {
            os<<G.cellArray[i][j];
        }
        os << endl;
    }
    return os;
}

// METHODS ------------------------------------------------------------------------------------------------
void Grid::cycle() // Cycle of cell's life
{
    Grid gridCopy = *this;

    for(int i=1; i<sizeOfGrid-1; ++i)
    {
        for(int j=1; j<sizeOfGrid-1; ++j)
        {
            // Live cell with fewer than 2 live neighbors:
            if ((gridCopy.cellArray[i][j].getState() == true) && (gridCopy.numOfNeighbors(i,j) < 2))
            {
                gridCopy.cellArray[i][j].setState(false); // Death (underpopulation)
            }

            // Live cell with more than 3 live neighbors:
            else if((gridCopy.cellArray[i][j].getState() == true) && (gridCopy.numOfNeighbors(i,j) > 3))
            {
                gridCopy.cellArray[i][j].setState(false); // Death (overpopulation)
            }

            // Dead cell with 3 live neighbors:
            else if((gridCopy.cellArray[i][j].getState() == false) && (gridCopy.numOfNeighbors(i,j) == 3))
            {
                gridCopy.cellArray[i][j].setState(true); // Life (reproduction)
            }

            // Any live cell with 2 or 3 live neighbors automatically survives
        }
    }
    *this = gridCopy;
}

int Grid::numOfNeighbors(int i, int j) // Counting number of live cell's neighbors
{
    Grid gridCopy = *this;
    int num = 0;

    for(int a=i-1; a<i+2; a++)
    {
        for(int b=j-1; b<j+2; b++)
        {
            if(a!=i || b!=j)
            {
                if(gridCopy.cellArray[a][b].getState() == true)
                    num++;
            }
        }
    }
    return num;
}
