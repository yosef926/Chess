#include "Pawn.h"

Pawn::Pawn()
{
}

Pawn::~Pawn()
{
	// Nothing to free or clean up.
}

bool Pawn::isClearPath(const std::string& boardStr, const int& srcIndex, const int& dstIndex) const
{
    int srcRow = srcIndex / BOARD_LEN_AND_WID;
    int srcCol = srcIndex % BOARD_LEN_AND_WID;
    int dstRow = dstIndex / BOARD_LEN_AND_WID;
    int dstCol = dstIndex % BOARD_LEN_AND_WID;

    if (boardStr[dstIndex] != EMPTY_SQUARE &&
        abs(dstCol - srcCol) == 1 &&
        (((dstRow - srcRow == -1) && boardStr[TURN_INDEX] == WHITE_TURN) ||
            ((dstRow - srcRow == 1) && boardStr[TURN_INDEX] == BLACK_TURN)))
    {
        return true;
    }

    // Pawns move straight forward in the same column
    if (srcCol != dstCol)
        return false;

    // White pawn
    if (boardStr[srcIndex] == 'P')
    {
        // Single square forward
        if (dstRow == srcRow - 1 && boardStr[dstIndex] == EMPTY_SQUARE)
        {
            return true;
        }
        // Two squares forward on first move
        if (srcRow == 6 && dstRow == srcRow - 2)
        {
            if (boardStr[srcIndex - 8] == EMPTY_SQUARE && boardStr[dstIndex] == EMPTY_SQUARE)
            {
                return true;
            }
        }
    }
    // Black pawn
    else if (boardStr[srcIndex] == 'p')
    {
        // Single square forward
        if (dstRow == srcRow + 1 && boardStr[dstIndex] == EMPTY_SQUARE)
        {
            return true;
        }
        // Two squares forward on first move
        if (srcRow == 1 && dstRow == srcRow + 2)
        {
            if (boardStr[srcIndex + 8] == EMPTY_SQUARE && boardStr[dstIndex] == EMPTY_SQUARE)
            {
                return true;
            }
        }
    }

    return false; // Path blocked or illegal move
}
