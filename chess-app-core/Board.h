#pragma once
#include <string>
#include <iostream>
#include "Piece.h"
#include <cctype>
#include <unordered_map>
#include "MoveException.h"


class Board
{
public:
	Board(const std::string& boardStr);
	~Board();
	std::string& getBoard();
	void printBoard() const;
	int calcIndex(const std::string& location) const;
	bool isCorrectTurn(const int& srcPos) const;
	void checkValidationOfMove(int srcPos, int dstPos, char* keyNumber, std::unordered_map<char, Piece*>& pieceMap) const;
	bool isOwnPlayerOnCheck(const std::unordered_map<char, Piece*>& pieceMap, int srcIndex, int dstIndex) const;
	bool isEnemyPlayerOnCheck(const std::unordered_map<char, Piece*>& pieceMap, int srcIndex, int dstIndex) const;
	bool isOwnPieceExistInSrc(int srcPos) const;
	bool isOwnPieceNotInDst(int dstPos) const;
	bool isSrcEqualDst(int srcPos, int dstPos) const;

private:
	std::string _boardStr;
};

