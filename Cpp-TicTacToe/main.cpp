#include <iostream>
#include <string>
#include "Game.h";

using namespace std;


/*
int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
int arr2[3][3];
void put_zero(int num) {
	
	arr[num / 3][num % 3] = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}
}

int xy(int x, int y) {
	//x += 1;
	//y += 1;
	return x * 3 + y+1;
}

void main2() {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = xy(i, j);
			cout << arr[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr2[i][j] = xy(i, j);
			cout << arr2[i][j];
		}
		cout << "\n";
	}

	cout << "\n\n";
	put_zero(4);
}*/

int main() {
	
	Game *game = new Game();
	string commend;
	while (true)
	{
		game->enterGameMode();
		game->startGame();
		game->freePlayerMemory();
		cin >> commend;
		if (commend == "exit") { break; }
	}
	
	delete game;

	cin.get();
	return 0;
}
