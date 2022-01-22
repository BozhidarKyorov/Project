#include<iostream>
#include<fstream>
#include"Functions.h"


void instructions()
{
	std::cout << "Rules:\n";
	std::cout << "Choose in which position to put new number.\n";
	std::cout << "You should use each number once in every row, column and 3x3 box.\n";
	std::cout << "You can delete number by entering 'x' on the number place.\n";
	std::cout << "You can give up by entering 'q' on the number place.\n";
	std::cout << "You cannot change the starting numbers.\n";
	std::cout << "You can enter number like this:\n";
	std::cout << "Row:(number between 1 and 9)\n";
	std::cout << "Column:(number between 1 and 9) \n";
	std::cout << "Number:(number between 1 and 9 or x or q) \n";
	std::cout << "Good luck!\n";
}

void loadSudoku(std::ifstream& input, char sudoku[10][9], char sudokuNumber)
{
	char temp[10];
	input >> temp;
	while (temp[0] != sudokuNumber || temp[1] != 0)
	{
		input >> temp;
	}
	for (int i = 0; i < 9; i++)
	{
		input >> temp;
		for (int j = 0; j < 9; j++)
		{
			sudoku[i][j] = temp[j];
		}
	}
}

void printSudoku(char sudoku[10][9])
{
	std::cout << char(201);
	for (int i = 0; i < 17; i++)
	{
		if (i % 6 == 5) { std::cout << char(203); }
		else { std::cout << char(205); }
	}
	std::cout << char(187) << std::endl;

	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0 && i != 0)
		{
			std::cout << char(204);
			for (int i = 0; i < 17; i++)
			{
				if (i % 6 == 5) { std::cout << char(206); }
				else { std::cout << char(205); }
			}
			std::cout << char(185);
			std::cout << std::endl;
		}
		std::cout << char(186);

		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 2)
			{
				if (sudoku[i][j] != '0') { std::cout << sudoku[i][j] << char(186); }
				else { std::cout << " " << char(186); }
			}
			else
			{
				if (sudoku[i][j] != '0') { std::cout << sudoku[i][j] << " "; }
				else { std::cout << " " << " "; }
			}
		}
		std::cout << std::endl;
	}
	std::cout << char(200);
	for (int i = 0; i < 17; i++)
	{
		if (i % 6 == 5) { std::cout << char(202); }
		else { std::cout << char(205); }
	}
	std::cout << char(188) << std::endl;
}

bool isSudokuSolved(char sudoku[10][9])
{
	int sumRow = 0;
	int sumCol = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			sumRow = sumRow + int(sudoku[i][j]) - NUMBER_FROM_LETTER;
			sumCol = sumCol + int(sudoku[j][i]) - NUMBER_FROM_LETTER;
		}
		if (sumRow != 45) { return false; }
		if (sumCol != 45) { return false; }
		sumRow = 0;
		sumCol = 0;
	}
	return true;
}

bool check3x3Box(char sudoku[10][9], int number, int boxNumber)
{
	int startRow, endRow;
	int startCol, endCol;
	switch (boxNumber)
	{
	case 1:
	{
		startRow = 0; endRow = 2;
		startCol = 0; endCol = 2;
	}break;
	case 2:
	{
		startRow = 0; endRow = 2;
		startCol = 3; endCol = 5;
	}break;
	case 3:
	{
		startRow = 0; endRow = 2;
		startCol = 6; endCol = 8;
	}break;
	case 4:
	{
		startRow = 3; endRow = 5;
		startCol = 0; endCol = 2;
	}break;
	case 5:
	{
		startRow = 3; endRow = 5;
		startCol = 3; endCol = 5;
	}break;
	case 6:
	{
		startRow = 3; endRow = 5;
		startCol = 6; endCol = 8;
	}break;
	case 7:
	{
		startRow = 6; endRow = 8;
		startCol = 0; endCol = 2;
	}break;
	case 8:
	{
		startRow = 6; endRow = 8;
		startCol = 3; endCol = 5;
	}break;
	case 9:
	{
		startRow = 6; endRow = 8;
		startCol = 6; endCol = 8;
	}break;
	default: return false;
	}

	for (int i = startRow; i <= endRow; i++)
	{
		for (int j = startCol; j <= endCol; j++)
		{
			if (sudoku[i][j] == boxNumber) return false;
		}
	}
	return true;
}
