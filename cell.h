#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Cell
{
    bool state;

public:
// CONSTRUCTOR --------------------------------------------------------------------------------------------
    Cell(bool state = false) : state(state) {} // true - cell is alive, false - cell is dead

// DESTRUCTOR ---------------------------------------------------------------------------------------------
    virtual ~Cell() {}

// METHODS ------------------------------------------------------------------------------------------------
    void setState(bool state) {this -> state = state;}
    bool getState() const {return state;}

// OVERLOADED OPERATORS -----------------------------------------------------------------------------------
    friend ostream& operator<<(ostream& os, const Cell& C) // Displaying alive cells on screen
    {
        os << (C.state?(char)(219):' ');
        return os;
    }
};

#endif // CELL_H_INCLUDED
