/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Pipe.h"
#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"
#include <iostream>
#include <thread>
#include <stdlib.h>
#include <string.h>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;
using std::string;


int main()
{
	srand(time_t(NULL));

	// dict of all pieces
	Rook myRook;
	Bishop myBishop;
	Queen myQueen;
	Knight myKnight;
	Pawn myPawn;
	King myKing;

	// creating map for each piece
	std::unordered_map<char, Piece*> pieceMap = {
		{'r', &myRook},
		{'b', &myBishop},
		{'q', &myQueen},
		{'n', &myKnight},
		{'p', &myPawn},
		{'k', &myKing}
	};

	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return 0;
		}
	}
	

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy(msgToGraphics, "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0"); // just example...
	//Board
	Board myBoard(msgToGraphics);

	p.sendMessageToGraphics(msgToGraphics); // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	char keyNumber = '0'; // defualt value

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		string srcPos = msgFromGraphics.substr(0, 2);
		string dstPos = msgFromGraphics.substr(2, 2);

		int srcIndex = myBoard.calcIndex(srcPos);
		int dstIndex = myBoard.calcIndex(dstPos);

		try
		{
			myBoard.checkValidationOfMove(srcIndex, dstIndex, &keyNumber, pieceMap);
			myPawn.move(srcIndex, dstIndex, myBoard.getBoard());

		}
		catch (const std::exception& e)
		{
			
			//std::cout << e.what() << std::endl;
		}

	   // converting keyNumber to new var named keyStr that is char* because sendMessageToGraphics gets only char* type argument.
	   // converting keyNumber to new var named keyStr that is char* because sendMessageToGraphics gets only char* type argument.
		char keyStr[2];
		keyStr[0] = keyNumber;
		keyStr[1] = '\0';
		strcpy(msgToGraphics, keyStr); // msgToGraphics should contain the result of the operation
		//std::cout << msgToGraphics << std::endl;

		/******* JUST FOR EREZ DEBUGGING ******/
		//int r = rand() % 10; // just for debugging......
		//msgToGraphics[0] = (char)(1 + '0');
		//msgToGraphics[1] = 0;
		/******* JUST FOR EREZ DEBUGGING ******/


		// return result to graphics
		p.sendMessageToGraphics(msgToGraphics); 

		// get message from graphics	
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}