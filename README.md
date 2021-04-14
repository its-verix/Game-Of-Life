# Game Of Life
Visualisation of zero-player game devised by John Horton Conway

## What is Game Of Life?
The Game of Life is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves.

## Rules
* Any live cell with fewer than two live neighbours dies (underpopulation).
* Any live cell with two or three live neighbours lives on to the next generation.
* Any live cell with more than three live neighbours dies (overpopulation).
* Any dead cell with exactly three live neighbours becomes a live cell (reproduction).

## Programming language
* C++

## How it works?
User enters the size of the grid that stores the cells. Then new created grid is generating cells with random state (each cell could be live or death).
In each cycle every cell's state is refreshed according to the rules of Game Of Life.
