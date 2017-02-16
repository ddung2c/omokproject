#pragma once

const char EMPTY = '\0';
const char X = 'x';
const char O = 'o';

extern char board[10][10]; //board's row=10, column=10
extern bool xMove; //turn of players
extern bool gameOver; //if game is over, gameOver value is true

void GameReset();	//GameReset function: make new board
void GameDrawBoard(HWND hwnd, HDC hdc);	//DrawBoard function
void GameDrawX(HDC hdc, int i, int j,bool xMove);	//Draw white stone
void GameDrawO(HDC hdc, int i, int j,bool xMove);	//Draw black stone
void GameSetMove(int i, int j);	//GameSetMove function: if you click board, this function recognizes where you click
void GameCheckWinner(HWND hWnd);//GameCheckWinner function: this funtion checks which player is winner

