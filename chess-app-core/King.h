#pragma once
#include <string>
#include <iostream>
#include "Piece.h"

class King : public Piece
{
public:
	King();
	~King();
	virtual bool isClearPath(const std::string& boardStr, const int& srcIndex, const int& dstIndex) const override;
};

