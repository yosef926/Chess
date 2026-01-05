#pragma once
#include <string>
#include <iostream>
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook();
	~Rook();
	virtual bool isClearPath(const std::string& boardStr, const int& srcIndex, const int& dstIndex) const override;
};
