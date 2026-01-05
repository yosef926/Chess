#pragma once
#include <string>
#include <iostream>
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn();
	~Pawn();
	virtual bool isClearPath(const std::string& boardStr, const int& srcIndex, const int& dstIndex) const override;
};

