#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

Queen::Queen()
{
}
Queen::~Queen()
{
	// Nothing to free or clean up.
}
bool Queen::isClearPath(const std::string& boardStr, const int& srcIndex, const int& dstIndex) const
{
	Rook rook;
	Bishop bishop;
	// Check if the move is valid for a rook (straight line) or a bishop (diagonal)
	if (rook.isClearPath(boardStr, srcIndex, dstIndex) || bishop.isClearPath(boardStr, srcIndex, dstIndex))
	{
		return true;
	}
	return false; // Illegal move for a queen
}