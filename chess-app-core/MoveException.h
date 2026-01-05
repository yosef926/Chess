#pragma once
#include <exception>

class NoPieceInSrc : public std::exception
{
	public:
		const char* what() const noexcept override
		{
			return "No piece in Src - error";
		}
};

class OwnPieceInDst : public std::exception
{
	public:
		const char* what() const noexcept override
		{
			return "Own piece in Dst - error";
		}
};

class PutOwnPlayerOnCheck : public std::exception
{
	public:
		const char* what() const noexcept override
		{
			return "Put own player on Check - error";
		}
};

class PutEnemyPlayerOnCheck : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Put own player on Check - error";
	}
};

class SquareIllegal : public std::exception
{
	public:
		const char* what() const noexcept override
		{
			return "Square illegal - error";
		}
};

class IllegalMove : public std::exception
{
	public:
		const char* what() const noexcept override
		{
			return "Illegal move - error";
		}
};

class SrcAndDstAreTheSame : public std::exception
{
	public:
		const char* what() const noexcept override
		{
			return "Src and Dst are the same - error";
		}
};

class WrongTurn : public std::exception
{
	public:
		const char* what() const noexcept override
		{
			return "Wrong turn - error";
		}
};