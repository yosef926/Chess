#pragma once
#include "Board.h"
#include "Pawn.h"

Board::Board(const std::string& boardStr)
{
    this->_boardStr = boardStr;
}

Board::~Board()
{
}

bool Board::isOwnPlayerOnCheck(const std::unordered_map<char, Piece*>& pieceMap, int srcIndex, int dstIndex) const
{
    int KingIndex = 0;
    char kingUnderCheck = '0'; // 0 for white, 1 for black

    // find the required king index
    for (int index = 0; index < this->_boardStr.size(); index++)
    {
        if (this->_boardStr[index] == 'K' && this->_boardStr[TURN_INDEX] == WHITE_TURN)
        {
            KingIndex = index;
            kingUnderCheck = WHITE_TURN;
        }
        else if (this->_boardStr[index] == 'k' && this->_boardStr[TURN_INDEX] == BLACK_TURN)
        {
            KingIndex = index;
            kingUnderCheck = BLACK_TURN;
        }
    }
    
    std::string tmpBoard = this->_boardStr;
    pieceMap.at('p')->move(srcIndex, dstIndex, tmpBoard);

    for (int index = 0; index < tmpBoard.size(); index++) {
        char piece = tmpBoard[index];
        if (piece == EMPTY_SQUARE) continue;

        bool isEnemy = (kingUnderCheck == WHITE_TURN && islower(piece)) ||
            (kingUnderCheck == BLACK_TURN && isupper(piece));
        if (!isEnemy) continue;

        char pieceType = tolower(piece);
        switch (pieceType) {
            case 'q':
            case 'r':
            case 'n':
            case 'b':
            case 'p':
                if (pieceMap.at(pieceType)->isClearPath(tmpBoard, index, KingIndex)) {
                    return true;
                }
                    break;
            default:
                 break;
        }
    }
    return false;
}

bool Board::isEnemyPlayerOnCheck(const std::unordered_map<char, Piece*>& pieceMap, int srcIndex, int dstIndex) const
{
    int KingIndex = 0;
    char kingUnderCheck = '0'; // 0 for white, 1 for black

    // find the required king index
    for (int index = 0; index < this->_boardStr.size(); index++)
    {
        if (this->_boardStr[index] == 'k' && this->_boardStr[TURN_INDEX] == WHITE_TURN)
        {
            KingIndex = index;
            kingUnderCheck = BLACK_TURN;
        }
        else if (this->_boardStr[index] == 'K' && this->_boardStr[TURN_INDEX] == BLACK_TURN)
        {
            KingIndex = index;
            kingUnderCheck = WHITE_TURN;
        }
    }

    std::string tmpBoard = this->_boardStr;
    pieceMap.at('p')->move(srcIndex, dstIndex, tmpBoard);

    for (int index = 0; index < tmpBoard.size(); index++) {
        char piece = tmpBoard[index];
        if (piece == EMPTY_SQUARE) continue;

        bool isOwnPiece = (kingUnderCheck == WHITE_TURN && islower(piece)) ||
            (kingUnderCheck == BLACK_TURN && isupper(piece));
        if (!isOwnPiece) continue;

        char pieceType = tolower(piece);
        switch (pieceType) {
        case 'q':
        case 'r':
        case 'n':
        case 'b':
        case 'p':
            if (pieceMap.at(pieceType)->isClearPath(tmpBoard, index, KingIndex)) {
                return true;
            }
            break;
        default:
            break;
        }
    }
    return false;
}

// Convert chess notation (e.g., "e2") to integer positions (0-63)
int Board::calcIndex(const std::string& location) const
{
    int col = location[0] - 'a';
    int row = '8' - location[1];

    int index = row * 8 + col;
    return index;
}

std::string& Board::getBoard()
{
    return this->_boardStr;
}

void Board::printBoard() const
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int x = 1;
            //std::cout << this->_boardStr[i * BOARD_LEN_AND_WID + j] << " ";
        }
        //std::cout << std::endl;
    }
}

bool Board::isOwnPieceExistInSrc(int srcPos) const
{
    char piece = this->_boardStr[srcPos];
    if (piece != EMPTY_SQUARE && ((isupper(this->_boardStr[srcPos]) && this->_boardStr[TURN_INDEX] == '0') || (islower(this->_boardStr[srcPos]) && this->_boardStr[TURN_INDEX] == '1'))) // Is there a own piece in the source position
    {
        return true;
    }
	return false; // No piece in the source position
}

bool Board::isOwnPieceNotInDst(int dstPos) const
{
    char piece = this->_boardStr[dstPos];
    if (piece == EMPTY_SQUARE) // No piece in the destination position
    {
        return true;
    }
	// Check if the piece at dstPos is the same color (illegal) or of the opposite color (legal)
    if( (isupper(this->_boardStr[dstPos]) && this->_boardStr[TURN_INDEX] == '1') || (islower(this->_boardStr[dstPos]) && this->_boardStr[TURN_INDEX] == '0') )
    {
        return true; // Illegal move, same color
	}
    return false;
}

bool Board::isSrcEqualDst(int srcPos, int dstPos) const
{
    if (srcPos == dstPos)
    {
        return true; // Source and destination are the same
    }
    return false; // Source and destination are different
}

bool Board::isCorrectTurn(const int& srcPos) const
{
    if ( (this->_boardStr[srcPos] == EMPTY_SQUARE) || (isupper(this->_boardStr[srcPos]) && this->_boardStr[64] == '0') || (islower(this->_boardStr[srcPos]) && this->_boardStr[64] == '1'))
    {
        return true;
    }
    return false;
}

// Function that will run all the validation checks for a move and will use the MoveException class to throw exceptions when needed
void Board::checkValidationOfMove(int srcPos, int dstPos, char* keyNumber, std::unordered_map<char, Piece*>& pieceMap) const
{

    if (!isCorrectTurn(srcPos))
    {
        *keyNumber = '2';
        throw WrongTurn();
        return;
    }
    if (!isOwnPieceExistInSrc(srcPos))
    {
        *keyNumber = '2';
        throw NoPieceInSrc();
        return;
    }
    if (!isOwnPieceNotInDst(dstPos))
    {
        *keyNumber = '3';
        throw OwnPieceInDst();
        return;
    }
    if (isSrcEqualDst(srcPos, dstPos))
    {
        *keyNumber = '7';
        throw SrcAndDstAreTheSame();
        return;
    }
    if (isOwnPlayerOnCheck(pieceMap, srcPos, dstPos))
    {
        *keyNumber = '4';
        throw PutOwnPlayerOnCheck();
        return;
    }
    if (isEnemyPlayerOnCheck(pieceMap, srcPos, dstPos))
    {
        *keyNumber = '1';
        throw PutEnemyPlayerOnCheck();
        return;
    }
    if (!pieceMap.at(tolower(this->_boardStr[srcPos]))->isClearPath(this->_boardStr, srcPos, dstPos))
    {
        *keyNumber = '6';
        throw IllegalMove();
        return;
    }

    *keyNumber = '0'; // Move is valid
}