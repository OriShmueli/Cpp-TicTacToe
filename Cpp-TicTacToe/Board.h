#pragma once

#include <string>
#include <iostream>
#include <vector>


class Board
{
public:
	void initializeBoard();
	 std::string board[3][3];
	 int iboard[3][3];
	 void drawBoard(); 
	 bool checkInput(std::string& input);
	 std::string getSign();
	 void setPlayerSign(std::string sign);
	 bool isd(std::string& str);
private:
	
	std::string m_drawPosition(int x, int y);
	std::vector<int> m_closedPositions;
	bool m_checkClosedPositions(int pos);
	std::string sign;
	int arr[9] = { 1,2,3,4,5,6,7,8,9 };
	int arr2d[3][3] = { 1,2,3,4,5,6,7,8,9 };
	
};

