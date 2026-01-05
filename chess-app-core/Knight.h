#pragma once
#include <string>
#include <iostream>
#include "Piece.h"

class Knight : public Piece
{
public: 
	Knight();
	~Knight();
	virtual bool isClearPath(const std::string& boardStr, const int& srcIndex, const int& dstIndex) const override;
};