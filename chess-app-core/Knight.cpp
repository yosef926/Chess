#include "Knight.h"

Knight::Knight()
{
}
Knight::~Knight()
{
	// Nothing to free or clean up.
}
bool Knight::isClearPath(const std::string& boardStr, const int& srcIndex, const int& dstIndex) const
{
	int srcRow = srcIndex / BOARD_LEN_AND_WID;
	int srcCol = srcIndex % BOARD_LEN_AND_WID;
	int dstRow = dstIndex / BOARD_LEN_AND_WID;
	int dstCol = dstIndex % BOARD_LEN_AND_WID;
	int rowDiff = std::abs(dstRow - srcRow);
	int colDiff = std::abs(dstCol - srcCol);
	// Check for L-shaped move: 2 squares in one direction and 1 square in the other
	// No need to check for blocking pieces since knights can jump over them
	if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2))
	{
		return true; // The path is clear for a knight's move
	}
	return false; // Illegal move for a knight
}