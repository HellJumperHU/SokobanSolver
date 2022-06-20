#pragma once
#ifndef States_H
#define States_H

#include "Position.h"
#include <vector>

#endif // States

class State {
public:
	position PlayerPos;
	std::vector<position> cratePos;
	std::vector<position> targetPos;
	std::vector<char> playermovedirection;
	std::vector<char> PathFromPreviousState;
	std::vector<position> freecrateside;
	State* firststate;
	State* previousstate;
	State* nextstate;

	bool SolutionState() {
		bool targetreach = false;
		for (int _crateposIndex = 0; _crateposIndex < this->cratePos.size(); _crateposIndex++)
		{
			targetreach = false;
			for (int _targetposIndex = 0; _targetposIndex < this->targetPos.size(); _targetposIndex++)
			{
				if (this->cratePos[_crateposIndex].x == this->targetPos[_targetposIndex].x &&
					this->cratePos[_crateposIndex].y == this->targetPos[_targetposIndex].y)
				{
					targetreach = true;
					break;
				}
			}
			if (!targetreach)
			{
				return targetreach;
			}
		}
		return targetreach;
	}

	bool AtLeastOneOppositeSiteOfCrateIsNotWall(const char** sokobanmap) {

		for (unsigned int crateIndex = 0; crateIndex < cratePos.size(); crateIndex++)
		{
			break;
		}
	}

	void CollectFreeSideOfChests(const char** sokomap, const std::vector<position> cratePos, std::vector<position> freecrateside) {
		for (int i = 0; i < cratePos.size(); i++)
		{
			if (sokomap[cratePos[i].x - 1][cratePos[i].y] == ' ') {
				freecrateside.push_back({ cratePos[i].x - 1,cratePos[i].y });
			}
			if (sokomap[cratePos[i].x + 1][cratePos[i].y] == ' ') {
				freecrateside.push_back({ cratePos[i].x + 1,cratePos[i].y });
			}
			if (sokomap[cratePos[i].x][cratePos[i].y - 1] == ' ') {
				freecrateside.push_back({ cratePos[i].x,cratePos[i].y - 1 });
			}
			if (sokomap[cratePos[i].x][cratePos[i].y] + 1 == ' ') {
				freecrateside.push_back({ cratePos[i].x,cratePos[i].y + 1 });
			}

		}
	}

	void DeleteAllStates(State* lastState) {
		while (lastState != NULL)
		{
			State* tmpfordelete = lastState;
			lastState = lastState->previousstate;
			delete tmpfordelete;
		}
	}

	State() {
		PlayerPos = { 0,0 };
		firststate = NULL;
		previousstate = NULL;
		nextstate = NULL;
	}
	~State() {}
};
