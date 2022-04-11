#include "Board.h"

void Board::drawBoard()
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (m_checkClosedPositions(i * 3 + j + 1)) {
				
				std::cout << "[" << arr2d[i][j] << "]";
			}
			else {
				std::cout << "[ ]";
			}
			
		}
		std::cout << "\n";
	}

	std::cout << "\n";

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			
			std::cout << "[" << board[i][j] << "]";

		}
		std::cout << "\n";
	}
}

void Board::initializeBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = "_";
			
		}
	}
}

bool Board::checkInput(std::string& input)
{
	
	if (isd(input)) {
		for (int i = 0; i < 9; i++)
		{
			if (arr[i] == std::stoi(input)) {
				
				if (m_checkClosedPositions(arr[i])) {
					board[(arr[i]-1) / 3][(arr[i]-1) % 3] = sign;
					
					m_closedPositions.push_back(arr[i]);
					return true;
				}
				
			}
		}
	}
	return false;
	
}

bool Board::isd(std::string& str)
{
	for (char const& c : str) {
		if (std::isdigit(c) == 0) {
			return false;
			
		}
	}
	
	return true;
}

std::string Board::m_drawPosition(int x, int y)
{
	if (m_checkClosedPositions(x * 3 + y + 1)) {
		
		return "_";
	}
	return board[(x * 3 + y+1) / 3][(x * 3 + y +1) % 3];
}

bool Board::m_checkClosedPositions(int pos) {

	for (auto i = m_closedPositions.begin(); i != m_closedPositions.end(); ++i)
	{
		if (*i == pos) {
			
			return false;
		}
	}
	return true;
}


void Board::setPlayerSign(std::string sign) {
	this->sign = sign;

}

std::string Board::getSign() {
	return sign;
}