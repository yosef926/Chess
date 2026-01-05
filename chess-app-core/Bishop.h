#pragma once
#include <string>
#include <iostream>
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop();
	~Bishop();
	virtual bool isClearPath(const std::string& boardStr, const int& srcIndex, const int& dstIndex) const override;
};

