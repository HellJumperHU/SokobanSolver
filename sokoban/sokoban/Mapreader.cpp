#include "MapReader.h"

bool IsANumber(std::string input) {
    return !input.empty() && std::find_if(input.begin(),
        input.end(), [](unsigned char c) { return !std::isdigit(c); }) == input.end();
}

void GetMapSize(unsigned int& column, unsigned int& row, bool& iserrorpresent, const std::string filepath, std::ifstream& sokobanmapsizereader) {

    try {
        sokobanmapsizereader.open(filepath);
        if (!sokobanmapsizereader.is_open()) {
            throw std::logic_error("File does not exist or interrupted\n");
        }


        std::string line;
        std::getline(sokobanmapsizereader, line);
        if (!IsANumber(line))
        {
            iserrorpresent = true;
            std::cout << line << std::endl;
            throw std::invalid_argument("The first value must be a number that determine the column of the map\n");
        }
        column = std::stoi(line);

        std::getline(sokobanmapsizereader, line);
        if (!IsANumber(line))
        {
            iserrorpresent = true;
            std::cout << line << std::endl;
            throw std::invalid_argument("The second value must be a number that determine the row of the map\n");
        }
        row = std::stoi(line);
    }
    catch (const std::logic_error& logicerr) {
        std::cerr << logicerr.what();
    }
    catch (const std::exception& exc) {
        std::cerr << exc.what();
    }
}

void AllocateMemoryForMap(const unsigned int row,const unsigned int column, char**& sokobanmap) {

    sokobanmap = new char* [row];
    for (unsigned int i = 0; i < row; i++)
    {
        sokobanmap[i] = new char[column];
    }
}

bool IsMapElement(const std::string actualrowofmap, unsigned int rowindex, unsigned short& numberofplayercharacter, unsigned short& numberofcrates, unsigned short& numberofdestination) {
    for (unsigned int index = 0; index < actualrowofmap.length(); index++)
    {
        switch (actualrowofmap[index])
        {
        case 'x': break;
        case 'd':numberofdestination++; break;
        case 'c':numberofcrates++; break;
        case 'p':numberofplayercharacter++; break;
        case '.': break;
        default:    std::cout << "Error at the "
            << rowindex + 1 << ". row's "
            << index + 1 << ". element --> '"
            << actualrowofmap[index] << "'"
            << std::endl;
            return false; break;
        }
    }
    return true;
}

void FillTheGapInTheActualRow(std::string& actualrowofmap, const unsigned int column) {
    unsigned int ammountofmissingcharacters = column - actualrowofmap.length();
    for (unsigned int numberofwallsadded = 0; numberofwallsadded < ammountofmissingcharacters; numberofwallsadded++)
    {
        actualrowofmap.append("x");
    }

}

void GetMap(char** storedmap, const unsigned int column, const unsigned int row, unsigned short& numberofplayercharacter, unsigned short& numberofcrates, unsigned short& numberofdestination, const std::string filepath, std::ifstream& sokobanmapreader, bool& iserrorpresent) {
    try
    {
        for (unsigned int rowindex = 0; rowindex < row; rowindex++)
        {
            std::string actualrowofmap;
            std::getline(sokobanmapreader, actualrowofmap);
            if (actualrowofmap.length() > column) {
                iserrorpresent = true;
                std::cout << "Error at " << rowindex + 1 << ". row" << std::endl;
                throw std::length_error("The row length should be equal or be lesser than the map's column\n");
            }
            if (!IsMapElement(actualrowofmap,rowindex,numberofplayercharacter,numberofcrates,numberofdestination)){
                iserrorpresent = true;
                throw std::invalid_argument("The character is not part of the map's values");

            }
            if (column - actualrowofmap.length())
                FillTheGapInTheActualRow(actualrowofmap, column);

            for (unsigned int columnindex = 0; columnindex < column; columnindex++)
            {
                storedmap[rowindex][columnindex] = actualrowofmap[columnindex];
            }
        }
    }
    catch (const std::invalid_argument& invarg) {
        std::cerr << invarg.what();
    }
    catch (const std::length_error& leng) {
        std::cerr << leng.what();
    }
}

bool ExactlyOnePlayerCharacterPresent(const short numberofplayercharacter) {
    if (numberofplayercharacter != 1)
    {
        std::cout << "1 player character must be present" << std::endl;
        return false;
    }
    return true;
}

bool NumberOfCratesMatchTheNumberOfDestination(const short numberofcrates, const short numberofdestination) {
    if (numberofcrates != numberofdestination)
    {
        std::cout << "Number of crate(s) must match the number of destination(s)" << std::endl;
        return false;
    }
    return true;
}

void SokobanMapReader(unsigned int& row, unsigned int& column, char**& sokobanmap, bool& iserrorpresent, const std::string filepath) {
    std::ifstream sokobanfilereader;
    unsigned short numberofplayercharacter = 0, numberofcrates = 0, numberofdestination = 0;
    GetMapSize(column, row,iserrorpresent, filepath, sokobanfilereader);
    if (!iserrorpresent) {
        AllocateMemoryForMap(row, column, sokobanmap);
        GetMap(sokobanmap, column, row,numberofplayercharacter,numberofcrates,numberofdestination, filepath, sokobanfilereader, iserrorpresent);
    }
    if (!iserrorpresent)
        if (!ExactlyOnePlayerCharacterPresent(numberofplayercharacter) || !NumberOfCratesMatchTheNumberOfDestination(numberofcrates, numberofdestination))
            iserrorpresent = true;

    sokobanfilereader.close();


}

void WriteOutMap(char** storedmap, const unsigned int column, const unsigned int row) {
    for (unsigned int rowindex = 0; rowindex < row; rowindex++)
    {
        for (unsigned int columnindex = 0; columnindex < column; columnindex++)
        {
            std::cout << storedmap[rowindex][columnindex] << " ";
        }
        std::cout << std::endl;
    }
}

void SokobanMapDelete(const unsigned int row, const unsigned int column, char**& sokobanmap) {
    for (unsigned int i = 0; i < row; i++)
    {
        delete[] sokobanmap[i];
    }
    delete[] sokobanmap;
}

