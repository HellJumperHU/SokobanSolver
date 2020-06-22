// sokoban.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "MapReader.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    bool iserrorpresent = false;
    unsigned int row=0, column=0;
    std::string filepath;
    filepath = "map.txt";
    std::ifstream sokobanfilereader;

    GetMapSize(column, row, filepath,sokobanfilereader);

    char ** sokobanmap = new char*[row];
    for (unsigned int i = 0; i < row; i++)
    {
        sokobanmap[i] = new char [column];
    }

    GetMap(sokobanmap, column, row, filepath,sokobanfilereader,iserrorpresent);
    if (iserrorpresent)
    {
        return 1;
    }

    WriteOutMap(sokobanmap, column, row);

    sokobanfilereader.close();
    for (unsigned int i = 0; i < row; i++)
    {
        delete [] sokobanmap[i];
    }
    delete [] sokobanmap;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
