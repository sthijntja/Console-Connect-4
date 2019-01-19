#pragma once

#ifndef BOARD_H
#define BOARD_H
#include "Cell.h"
#include "constants.h"
#include "iostream"

class Board {
public:
	Board();
	void reset();
	void doMove(int collumn, int color);
	void draw();
	int checkEnd();

private:
	Cell cells[BOARD_WIDTH][BOARD_HEIGHT];
	int filledCells;
};
#endif