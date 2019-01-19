#include "GameManager.h"
//#include "pch.h"

using namespace std;

GameManager::GameManager() {
	reset();
}

void GameManager::reset() {
	gameFinished = false;
	board.reset();
	player = true;
}

void GameManager::draw() {
	board.draw();
}

void GameManager::update() {
	int end = board.checkEnd();
	if (end == -1) {
		int col;
		cout << endl << "Please select a column: ";
		cin >> col;
		board.doMove(col, player);
		switchPlayer();
	}
	else {
		gameFinished = true;
		if (end != 3) {
			cout << endl << "Player " << end << " has won!" << endl;
		}
		else {
			cout << "It's a tie!" << endl;
		}
		
	}
}

bool GameManager::getEnd() {
	return gameFinished;
}

void GameManager::switchPlayer() {
	if (player == 1) {
		player = 2;
	}
	else {
		player = 1;
	}
}