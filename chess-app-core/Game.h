#pragma once
#include <string>
#include <iostream>
#include "Board.h"

class Game
{
private:
	Board* board;

public:
	Game(const std::string& boardStr);
	~Game();
	void run() const;
	bool checkCurrentTurn();

};