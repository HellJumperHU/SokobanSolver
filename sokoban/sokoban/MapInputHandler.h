#ifndef Map_Input_Handler
#define Map_Input_Handler

#include <iostream>
#include <string>
#include <fstream>


bool IsANumber(std::string input);

void GetMapSize(unsigned int& column, unsigned int& row, const std::string filepath, std::ifstream& sokobanmapsizereader);

void AllocateMemoryForMap(const unsigned int row, const unsigned int column, char**& sokobanmap);

bool IsMapElement(const std::string actualrowofmap, unsigned int rowindex, unsigned short& numberofplayercharacter, unsigned short& numberofcrates, unsigned short& numberofdestination);

void FillTheGapInTheActualRow(std::string& actualrowofmap, const unsigned int column);

void GetMap(char** storedmap, const unsigned int column, const unsigned int row, unsigned short& numberofplayercharacter, unsigned short& numberofcrates, unsigned short& numberofdestination, const std::string filepath, std::ifstream& sokobanmapreader, bool& iserrorpresent);

void SokobanMapReader(unsigned int& row, unsigned int& column, char**& sokobanmap, bool& iserrorpresent, const std::string filepath);

bool IsMapBorderedWithWall(const char** sokobanmap, const int row, const int column);

void SokobanMapDelete(const unsigned int row, const unsigned int column, char**& sokobanmap);

void GiveWallBorderToMap(char**& sokobanmap, unsigned int& row, unsigned int& column);

void WriteOutMap(char** storedmap, const unsigned int column, const unsigned int row);

#endif