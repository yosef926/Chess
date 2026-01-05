#include "Rook.h"

Rook::Rook()
{

}
Rook::~Rook()
{
	//nothing to delete or clean up
}

bool Rook::isClearPath(const std::string& boardStr, const int& srcIndex, const int& dstIndex) const
{
    int srcRow = srcIndex / BOARD_LEN_AND_WID;
    int srcCol = srcIndex % BOARD_LEN_AND_WID;
    int dstRow = dstIndex / BOARD_LEN_AND_WID;
    int dstCol = dstIndex % BOARD_LEN_AND_WID;

    // Check if the rook is moving in a straight line
    if (srcRow != dstRow && srcCol != dstCol)
        return false;

    // Moving horizontally
    if (srcRow == dstRow)
    {
        int startCol = std::min(srcCol, dstCol) + 1;
        int endCol = std::max(srcCol, dstCol);

        for (int col = startCol; col < endCol; col++)
        {
            if (boardStr[srcRow * BOARD_LEN_AND_WID + col] != EMPTY_SQUARE)
                return false; // Path blocked
        }
        return true;
    }

    // Moving vertically
    if (srcCol == dstCol)
    {
        int startRow = std::min(srcRow, dstRow) + 1;
        int endRow = std::max(srcRow, dstRow);

        for (int row = startRow; row < endRow; row++)
        {
            if (boardStr[row * BOARD_LEN_AND_WID + srcCol] != EMPTY_SQUARE)
                return false; // Path blocked
        }
        return true;
    }

    return false; // Should never reach here
}
