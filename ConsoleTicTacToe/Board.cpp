#include "Board.h"
//#include "pch.h"

using namespace std;

Board::Board() {
	reset();
}

void Board::reset() {
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			cells[i][j].setColor(-1);
		}
	}
	filledCells = 0;
}

void Board::doMove(int collumn, int color) {
	if (collumn > BOARD_WIDTH || collumn < 0) return;

	for (int i = BOARD_HEIGHT - 1; i >= 0; i--) {
		if (cells[collumn][i].getColor() == -1) {
			cells[collumn][i].setColor(color);
			filledCells++;
			break;
		}
	}
}

void Board::draw() {
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			cout << cells[j][i].getColor();
			cout << " | ";
		}
		cout << endl;
	}
}

int Board::checkEnd() {
	//check horizontal
	int previousPlayer;
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		int connected = 1;
		for (int j = 0; j < BOARD_WIDTH; j++) {
			int currentPlayer = cells[j][i].getColor();
			if (connected == 1) {
				previousPlayer = currentPlayer;
			}
			if (currentPlayer != -1 && currentPlayer == previousPlayer) {
				connected++;
				if (connected > 4) {
					return previousPlayer;
				}
			}
			else {
				connected = 1;
			}
			previousPlayer = currentPlayer;
		}
	}

	// check vertical
	for (int i = 0; i < BOARD_WIDTH; i++) {
		int connected = 1;
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			int currentPlayer = cells[i][j].getColor();
			if (connected == 1) {
				previousPlayer = currentPlayer;
			}
			if (currentPlayer != -1 && currentPlayer == previousPlayer) {
				connected++;
				if (connected > 4) {
					return previousPlayer;
				}
			}
			else {
				connected = 1;
			}
			previousPlayer = currentPlayer;
		}
	}
	//check diagonal
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {

		}
	}

	//check for tie
	if (filledCells >= BOARD_HEIGHT * BOARD_WIDTH) {
		return 3;
	}
	return -1;
}