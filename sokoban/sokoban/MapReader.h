
#include <iostream>
#include <string>
#include <fstream>


bool IsMapElement(const std::string actualrowofmap);

bool IsANumber(std::string input);

void GetMapSize(unsigned int& column, unsigned int& row, const std::string filepath, std::ifstream& sokobanmapsizereader);

void GetMap(char** storedmap, const unsigned int column, const unsigned int row, const std::string filepath, std::ifstream& sokobanmapreader, bool& iserrorpresent);

void WriteOutMap(char** storedmap, const unsigned int column, const unsigned int row);
