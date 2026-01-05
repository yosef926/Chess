#include "Bishop.h"

Bishop::Bishop()
{
}
Bishop::~Bishop()
{
	// Nothing to free or clean up.
}
bool Bishop::isClearPath(const std::string& boardStr, const int& srcIndex, const int& dstIndex) const
{
	int srcRow = srcIndex / BOARD_LEN_AND_WID;
	int srcCol = srcIndex % BOARD_LEN_AND_WID;
	int dstRow = dstIndex / BOARD_LEN_AND_WID;
	int dstCol = dstIndex % BOARD_LEN_AND_WID;
	int rowDirection = (dstRow > srcRow) ? 1 : -1; // Determine the row direction
	int colDirection = (dstCol > srcCol) ? 1 : -1; // Determine the column direction
	// Check if the move is diagonal
	if (std::abs(dstRow - srcRow) != std::abs(dstCol - srcCol))
	{
		return false; // Not a diagonal move
	}
	int totalSteps = std::abs(dstRow - srcRow);
	// Check each square along the diagonal path
	for (int step = 1; step < totalSteps; ++step)
	{
		int currentRow = srcRow + step * rowDirection;
		int currentCol = srcCol + step * colDirection;
		if (boardStr[currentRow * 8 + currentCol] != EMPTY_SQUARE)
		{
			return false; // Path is blocked
		}
	}
	return true; // Path is clear
}