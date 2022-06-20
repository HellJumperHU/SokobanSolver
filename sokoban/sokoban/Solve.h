#pragma once
#ifndef Solve_H
#define Solve_H
#include "PathFinder.h"
#include "State.h"
#include <math.h>
#endif // !Solve_H

void Solve(char** sokobanmap, const unsigned int row, unsigned int column);

void SetStateHead(State* state_head, const char** sokomap, const unsigned int row, const unsigned int column);

void CreateNextState(State* state_previous);