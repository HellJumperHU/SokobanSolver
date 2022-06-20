#ifndef PathFinder_H
#define PathFinder_H
#include "State.h"
#endif // !Path_Finder_To_Chest

void FindPathFromPlayerToChest(char** sokomap, State* state_current);

bool IsCrateMovable(char** sokomap, State* state_current);

void BuildPath(char** sokomap, State* state_current);

void CollectCoords(std::vector<position> _nearesttargetPos, char** sokomap, State* state_current, const int row, const int column);

float Rounding(float value, int place);

void FindPathFromChestToTarget(char** sokomap, State* state_current);