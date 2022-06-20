#pragma once
#ifndef PathFinder_CPP
#define PathFinder_CPP
#include "PathFinder.h"
#endif // !PathFinder_CPP

void FindPathFromChestToTarget(char** sokomap, State* state_current,const int row, const int column) {
	std::vector<position> _nearesttargetPos;
	CollectCoords(_nearesttargetPos,sokomap, state_current,row,column);

}

void BuildPath(char** sokomap, State* state_current) {

}

void FindPathFromPlayerToChest(char** sokomap, State* state_current) {

}

bool IsCrateMovable(char** sokomap, State* state_current) {
	return 1;
}

void CollectCoords(std::vector<position> _nearesttargetPos, char** sokomap, State* state_current, const int row, const int column) {
	for (int chestIndex = 0; chestIndex < state_current->cratePos.size(); chestIndex++)
	{
		position closestTargetPos = { -1,-1 };
		float disctance = row * column;	// set a value that is definitely higher than the highest distance betwenne a chest and a target

		for (int targetIndex = 0; targetIndex < state_current->targetPos.size(); targetIndex++)
		{
			float a = (state_current->cratePos[chestIndex].x - state_current->targetPos[targetIndex].x) ^ 2;
			//a = Rounding(a, 8);
			float b = (state_current->cratePos[chestIndex].y - state_current->targetPos[targetIndex].y) ^ 2;
			//b = Rounding(b, 8);

			if (disctance > (sqrt(a + b))) {
				disctance = sqrt(a + b);
				closestTargetPos = state_current->targetPos[targetIndex];
			}
		}
		_nearesttargetPos.push_back(closestTargetPos);
	}
}

float Rounding(float value,int place) {
	return ((float)((int)(value * place))) / place;
}
