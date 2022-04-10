#include "Board.h"

void Board::drawBoard()
{
	//std::cout << "Chose a number: " << std::endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (m_checkClosedPositions(i * 3 + j + 1)) {
				//board[i][j] = std::to_string(i * 3 + j + 1);
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
			//board[i][j] = m_drawPosition(i, j);
			std::cout << "[" << board[i][j] << "]";
			//std::cout << board[i][j];
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
				//std::cout << "is 1,2,3,4,5,6,7,8,9" << std::endl;
				if (m_checkClosedPositions(arr[i])) {
					board[(arr[i]-1) / 3][(arr[i]-1) % 3] = sign;
					//std::cout << "sign: " << board[arr[i] / 3][arr[i] % 3] << std::endl;
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
			//std::cout << "not a number" << std::endl;
		}
	}
	//std::cout << "a number" << std::endl;
	return true;
}

std::string Board::m_drawPosition(int x, int y)
{
	if (m_checkClosedPositions(x * 3 + y + 1)) {
		//return "[" + m_player->getSign() + "]";
		//std::cout << "sign check position: " << board[(x * 3 + y + 1) / 3][(x * 3 + y + 1) % 3] << std::endl;
		
		//return board[x][y];
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