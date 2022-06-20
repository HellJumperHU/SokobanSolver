// sokoban.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifndef Main_CPP
#define Main_CPP
#include "MapInputHandler.h"
#include "State.h"
#include "Solve.h"
#endif // !Main_CPP


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


    bool iserrorpresent = false;
    unsigned int row=0, column=0;    
    std::string filepath;
    filepath = "map.skb";
    char** sokobanmap;
    SokobanMapReader(row, column, sokobanmap, iserrorpresent, filepath);
    if (iserrorpresent) return 1;
    WriteOutMap(sokobanmap, column, row);   
    Solve(sokobanmap, row,column);
    SokobanMapDelete(row, column, sokobanmap);
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
