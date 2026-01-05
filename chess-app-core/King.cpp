#include "King.h"

King::King()
{
}

King::~King()
{
	// Nothing to free or clean up.
}

bool King::isClearPath(const std::string& boardStr, const int& srcIndex, const int& dstIndex) const
{
	int srcRow = srcIndex / BOARD_LEN_AND_WID;
	int srcCol = srcIndex % BOARD_LEN_AND_WID;
	int dstRow = dstIndex / BOARD_LEN_AND_WID;
	int dstCol = dstIndex % BOARD_LEN_AND_WID;

	int rowDiff = std::abs(dstRow - srcRow);
	int colDiff = std::abs(dstCol - srcCol);
	
	// Check if the move is within one square in any direction
	if ((rowDiff <= 1) && (colDiff <= 1))
	{
		if (std::abs(dstRow - srcRow) <= 1 && std::abs(dstCol - srcCol) <= 1)
		{
			return true; // The path is clear for a king's move
		}
	}

	return false; // Illegal move for a king
}