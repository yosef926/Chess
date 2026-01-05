#pragma once
#include <string>
#include <iostream>
#include "Piece.h"


Piece::Piece()
{
    // nothing to create, cause it has no members.
}

Piece::~Piece()
{
    // nothing to delete or clean up
}

void Piece::move(int srcIndex, int dstIndex, std::string& boardStr)
{
    boardStr[dstIndex] = boardStr[srcIndex];
    boardStr[srcIndex] = EMPTY_SQUARE;
    boardStr[64] = (boardStr[64] == WHITE_TURN) ? BLACK_TURN : WHITE_TURN;
}
