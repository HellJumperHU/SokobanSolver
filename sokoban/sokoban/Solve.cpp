#ifndef Solve_CPP
#define Solve_CPP
#include "Solve.h"
#endif // !Solve_CPP

void Solve(char** sokobanmap, const unsigned int row, unsigned int column) {
	State* state_head;
	State* state_current;
	State* state_tmp;
	state_current = new State();
	state_head = state_current;
	state_tmp = state_current;

	//SetStateHead(state_current, sokobanmap, row, column);
}

void SetStateHead(State* state_head, const char** sokomap, const unsigned int row, const unsigned int column) {
	for (int _rowindex = 0; _rowindex < row; _rowindex++)
	{
		for (int _columnIndex = 0; _columnIndex < column; _columnIndex++)
		{
			switch (sokomap[_rowindex][_columnIndex])
			{
			case '.':state_head->targetPos.push_back({ _rowindex,_columnIndex }); break;
			case '$':state_head->cratePos.push_back({ _rowindex,_columnIndex }); break;
			case '@':state_head->PlayerPos = { _rowindex,_columnIndex }; break;
			default:
				break;
			}
		}

	}
}