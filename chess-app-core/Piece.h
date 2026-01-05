#pragma once
#include <string>
#include <iostream>

#define BLACK_TURN '1'
#define WHITE_TURN '0'
#define BOARD_LEN_AND_WID 8
#define EMPTY_SQUARE '#'
#define TURN_INDEX 64

// Abstract base class for chess pieces
//Src and Dst positions are represented as integers (0-63) corresponding to board squares
//will be given as a chess cordinate and converted to int in the btor of each piece
class Piece
{
public: 
	Piece();
	~Piece();
	void move(int srcIndex, int dstIndex, std::string& boardStr);
	virtual bool isClearPath(const std::string& boardStr, const int& srcIndex, const int& dstIndex) const = 0;
};