// ConsoleTicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "GameManager.h"
using namespace std;
int main()
{
	GameManager * game = new GameManager();
	bool continueGame = true;
	while (continueGame) {
		while (!game->getEnd()) {
			game->draw();
			game->update();
		}
		
		cout << "Do you wish to continue? (Y/N): ";
		bool answerGiven = false;
		while (!answerGiven) {
			char answer;
			cin >> answer;
			if (answer == 'Y' || answer == 'y') {
				continueGame = true;
				answerGiven = true;
				game->reset();
			}
			else if (answer == 'N' || answer == 'n') {
				continueGame = false;
				answerGiven = true;
				return 1;
			}
			else {
				cout << "Please give a valid answer. (Y/N): ";
			}
		}
	}
}