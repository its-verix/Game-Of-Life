#include <iostream>
#include <windows.h>
#include "cell.h"
#include "grid.h"

using namespace std;

int main()
{
    int gridSize;

    cout << "Please enter size of grid: ";
    cin >> gridSize;

    srand(time(0));
    Grid G(gridSize);

    while(true)
    {
        cout << G << endl;
        Sleep(10);
        G.cycle();
        system("cls");
    }

    return 0;
}
