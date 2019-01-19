#pragma once

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Board.h"
#include "pch.h"
#include <iostream>
class GameManager {
public:
	GameManager();
	void reset();
	void draw();
	void update();
	bool getEnd();
	
private:
	Board board;
	int player;
	void switchPlayer();
	bool gameFinished;	
};
#endif