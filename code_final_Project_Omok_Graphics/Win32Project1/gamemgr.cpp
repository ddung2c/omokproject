#include "stdafx.h"
#include "gamemgr.h"
#include "player.h"
#include <iostream>


Players p0;
Players p1;

char board[10][10];
bool xMove;
bool gameOver;
int counter = 0;
void GameReset() {  //if you click newGame, do this function
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = EMPTY;   //every row and column will be empty
		}
	}
	xMove = true;   //xMove is true ( X turn )
	gameOver = false;   // game is not over
	counter = 0;  // counter is reinstalized in 0
}



void GameDrawBoard(HWND hwnd, HDC hdc){     // what will you draw when the turn is 'X' or 'O'
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == X)         //if turn is 'X', GameDrawO will be excuted
				GameDrawO(hdc, i, j,xMove);
			else if(board[i][j] == O)	  //if turn is 'O', GameDrawX will be excuted
				GameDrawX(hdc, i, j,xMove);
		}
	}

	// Draw board - horizontal 
	MoveToEx(hdc, 100, 100, NULL);       
	LineTo(hdc, 100, 600);
	MoveToEx(hdc, 150, 100, NULL);
	LineTo(hdc, 150, 600);
	MoveToEx(hdc, 200, 100, NULL);
	LineTo(hdc, 200, 600);
	MoveToEx(hdc, 250, 100, NULL);
	LineTo(hdc, 250, 600);
	MoveToEx(hdc, 300, 100, NULL);
	LineTo(hdc, 300, 600);
	MoveToEx(hdc, 350, 100, NULL);
	LineTo(hdc, 350, 600);
	MoveToEx(hdc, 400, 100, NULL);
	LineTo(hdc, 400, 600);
	MoveToEx(hdc, 450, 100, NULL);
	LineTo(hdc, 450, 600);
	MoveToEx(hdc, 500, 100, NULL);
	LineTo(hdc, 500, 600);
	MoveToEx(hdc, 550, 100, NULL);
	LineTo(hdc, 550, 600);
	MoveToEx(hdc, 600, 100, NULL);
	LineTo(hdc, 600, 600);
	// Draw board - vertical
	MoveToEx(hdc, 100, 100, NULL);
	LineTo(hdc, 600, 100);
	MoveToEx(hdc, 100, 150, NULL);
	LineTo(hdc, 600, 150);
	MoveToEx(hdc, 100, 200, NULL);
	LineTo(hdc, 600, 200);
	MoveToEx(hdc, 100, 250, NULL);
	LineTo(hdc, 600, 250);
	MoveToEx(hdc, 100, 300, NULL);
	LineTo(hdc, 600, 300);
	MoveToEx(hdc, 100, 350, NULL);
	LineTo(hdc, 600, 350);
	MoveToEx(hdc, 100, 400, NULL);
	LineTo(hdc, 600, 400);
	MoveToEx(hdc, 100, 450, NULL);
	LineTo(hdc, 600, 450);
	MoveToEx(hdc, 100, 500, NULL);
	LineTo(hdc, 600, 500);
	MoveToEx(hdc, 100, 550, NULL);
	LineTo(hdc, 600, 550);
	MoveToEx(hdc, 100, 600, NULL);
	LineTo(hdc, 600, 600);
		
	SetTextColor(hdc, RGB(0, 0, 0));     //Set text color in black
	TextOut(hdc, 100, 10, _T("OMOK"), 11);	//Text out "OMOK"
	SetTextColor(hdc, RGB(200, 20, 5));	//Set text color in Red
	TextOut(hdc, 200, 620, _T("---------------------------"), 11);	//Text out "----------------------------"
	SetTextColor(hdc, RGB(20, 200, 5));	//Set text color in Blue
	TextOut(hdc, 260, 620, _T("MERRY "), 11);	//Text out "MERRY"
	SetTextColor(hdc, RGB(200, 20, 5));	//Set text color in Red
	TextOut(hdc, 330, 620, _T("CHRISTMAS!!:)"), 11);	//Text out "CHRISTMAS!!:)"
	SetTextColor(hdc, RGB(20, 200, 5));	//Set text color in Blue
	TextOut(hdc, 430, 620, _T("---------------------------"), 11);	//Text out "---------------------------"
		
	if (counter%2 == 0){	//if counter is an even number
		SetTextColor(hdc, RGB(255, 0, 0));	//Set text color red
		TextOut(hdc, 110, 70, _T("PLAYER 1"), 12);	//Text out "PLATYER 1"
		counter++;	//counter will be added 1
	}	
}

void GameSetMove(int i, int j) {	//GameSetMove function: how can we make rule for setting board state
	if (i >= 0 && i <= 9 && j >= 0 && j <= 9 && board[i][j]==EMPTY) {	//check every row and if board is empty then excute below
		if (gameOver == false) {	//until game over
			if (xMove) //if xMove is true
				board[i][j] = X;	//board's character is X
			else //if xMove is not true
				board[i][j] = O;	//board's character is O
			xMove = !xMove;	//if xMove is now false then it will alternate true 
		}
	}
}

void GameDrawX(HDC hdc, int i, int j,bool xMove) {     //draw White stone, Player 2, i and j is the position of you clicked
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));	//edge of circle's state is solid, thickness is 2, and color is black
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));	//color of inside circle is white
	HGDIOBJ penOld, brushOld;	

	penOld = SelectObject(hdc, pen);
	brushOld = SelectObject(hdc, brush);

	Ellipse(hdc, 110 + (50 * i), 110 + (50 * j), 140 + (50 * i), 140 + (50 * j));	//the position of ellipse 

	SelectObject(hdc, brushOld);
	SelectObject(hdc, penOld);

	DeleteObject(brush);
	DeleteObject(pen);

	if (xMove == true) {	//if xMove is true
		SetTextColor(hdc, RGB(255, 0, 0));	//set text color red
		TextOut(hdc, 110, 70, _T("PLAYER 1"), 12);	//text out "PLAYER 1"
	}
	
}

void GameDrawO(HDC hdc, int i, int j,bool xMove) {    //draw Black stone, Player 1, i and j is the position of you clicked
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));	//edge of circle's state is solid, thickness is 2, and color is black
	HBRUSH brush = CreateSolidBrush(RGB(0,0,0));	//color of inside circle is black
	HGDIOBJ penOld, brushOld;

	penOld = SelectObject(hdc, pen);
	brushOld = SelectObject(hdc, brush);

	Ellipse(hdc, 110 + (50 * i), 110 + (50 * j), 140 + (50 * i), 140 + (50 * j));	//the position of ellipse 

	SelectObject(hdc, brushOld);
	SelectObject(hdc, penOld);

	DeleteObject(brush);
	DeleteObject(pen);
	
	if (xMove!=true) {	//if xMove is not true
		SetTextColor(hdc, RGB(0, 255, 0));	//set text color blue
		TextOut(hdc, 530, 70, _T("PLAYER 2"), 12);	//text out "PLAYER 2"
	}
	
}

void GameCheckWinner(HWND hWnd) { //Checking who is winner
	int winner = 0;	//initialize winner is 0 
		int rowcycle = 0, colcycle = 0; //initialize new value of row and column
		for (int count = 0; count < 100; count++) {	//checking every board
			if (board[rowcycle][colcycle]!= EMPTY	//vertical
				&& board[rowcycle][colcycle] == board[rowcycle + 1][colcycle]     
				&& board[rowcycle + 1][colcycle] == board[rowcycle + 2][colcycle]
				&& board[rowcycle + 2][colcycle] == board[rowcycle + 3][colcycle]
				&& board[rowcycle + 3][colcycle] == board[rowcycle + 4][colcycle]) {
				if (board[rowcycle][colcycle] == O)	//if board equals with 0
					winner = 2;	//winner is initialized 2
				else
					winner = 1;	//winner is initialized 1
				break;
			}
			else if (board[rowcycle][colcycle] != EMPTY	//horizontal
				&& board[rowcycle][colcycle] == board[rowcycle][colcycle + 1]   
				&& board[rowcycle][colcycle + 1] == board[rowcycle][colcycle + 2]
				&& board[rowcycle][colcycle + 2] == board[rowcycle][colcycle + 3]
				&& board[rowcycle][colcycle + 3] == board[rowcycle][colcycle + 4]) {
				if (board[rowcycle][colcycle] == O)
					winner = 2;
				else
					winner = 1;
				break;
			}
			else if (board[rowcycle][colcycle] != EMPTY //diagonal
				&& board[rowcycle][colcycle] == board[rowcycle + 1][colcycle + 1]  
				&& board[rowcycle + 1][colcycle + 1] == board[rowcycle + 2][colcycle + 2]
				&& board[rowcycle + 2][colcycle + 2] == board[rowcycle + 3][colcycle + 3]
				&& board[rowcycle + 3][colcycle + 3] == board[rowcycle + 4][colcycle + 4]) {
			
				if (board[rowcycle][colcycle] == O)
					winner = 2;	
				else 
					winner = 1;
				break;
			}
			else if (board[rowcycle][colcycle] != EMPTY //diagonal
				&& board[rowcycle][colcycle] == board[rowcycle + 1][colcycle - 1]  
				&& board[rowcycle + 1][colcycle - 1] == board[rowcycle + 2][colcycle - 2]
				&& board[rowcycle + 2][colcycle - 2] == board[rowcycle + 3][colcycle - 3]
				&& board[rowcycle + 3][colcycle - 3] == board[rowcycle + 4][colcycle - 4]) {
				if (board[rowcycle][colcycle] == O)
					winner = 2;
				else
					winner = 1;
				break;

			}
			else
				colcycle++;//if not, colcycle will be added 1
			if (colcycle == 10) { //if colcycle equals 10
				rowcycle++;	//rowcycle will be added 1	
				colcycle = 0;//at the end of the loop, colcycle equals 0
		}
	}
	if (winner!=0) {	//until winner is 0,
		if (winner ==1)	//if winner equals 1 
			MessageBox(hWnd, _T("Player 1 Wins!"), _T("Omok"), MB_OK); //Messagebox will be out with "Player 1 Wins!" and "Omok"
		else if (winner == 2)	//if winner equals 2
			MessageBox(hWnd, _T("Player 2 Wins!"), _T("Omok"), MB_OK);	//Messagebox will be out with "Player 2 Wins!" and "Omok"
		gameOver = true;	//gameOver is initialized true, it means game is over
	}
}


