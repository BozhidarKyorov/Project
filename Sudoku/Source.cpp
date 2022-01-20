/**
*
* Solution to course project # 6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Bozhidar Kyorov
* @idnumber 3MI0600075
* @compiler vc
*
* <>
*
*/
#include<iostream>
#include<fstream>
#include"Functions.h"

using namespace std;

//Constants
const int KB_SIZE = 1024;


int main()
{
	ifstream input;
	bool f; //f states for 'flag'
	
	char difficulty[KB_SIZE];
	cout << "Hello, please select sudoku difficulty:\n";
	cout << "| 1 - Easy | 2 - Medium | 3 - Hard | 4 - Very hard |\n";

	//Selection for diffiulty. Checking for choosing invalid difficulty
	f = true;
	while (f)
	{
		cin >> difficulty;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //I stole it from internet and have no idea how it works, i know it clear the whole bufffer

		if (difficulty[1] == '\0') //Test for entering more than one digit, first of which could be valid difficulty
		{
			switch (difficulty[0])
			{
			case '1':
			{
				cout << "Chosen difficulty: Easy\n";
				f = false;
			}break;
			case '2':
			{
				cout << "Chosen difficulty: Medium\n";
				f = false;
			}break;
			case '3':
			{
				cout << "Chosen difficulty: Hard\n";
				f = false;
			}break;
			case '4':
			{
				cout << "Chosen difficulty: Very hard\n";
				f = false;
			}break;
			default:
			{
				cout << "Infalid difficuly!\n";
				cout << "Please choose new difficulty:\n";
			}
			}
		}
		else
		{
			cout << "Infalid difficuly!\n";
			cout << "Please choose new difficulty:\n";
		}
	}

	cout << "-------------------------------------------------------\n";

	char sudokuNumber[KB_SIZE];
	cout << "Please, choose which sudoku you want to solve:\n";
	cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |\n";

	//Selection for sudoku. Chekcing for choosing invalid number
	f = true;
	while (f)
	{
		cin >> sudokuNumber;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (sudokuNumber[1] == '\0')
		{
			if (sudokuNumber[0] >= '1' && sudokuNumber[0] <= '9')
			{
				cout << "Chosen sudoku: " << sudokuNumber[0] << endl;
				f = false;
			}
		}
		else
		{
			cout << "Invalid number!\n";
			cout << "Please choose new sudoku:\n";
		}

	}

	cout << "-------------------------------------------------------\n";
	//Input sudoku from the appropiate .dat file
	char sudoku[10][9];
	if (difficulty[0] == '1')
	{
		input.open("Sudoku1_easy.dat");
		loadSudoku(input, sudoku, sudokuNumber[0]);
		input.close();
	}
	else if (difficulty[0] == '2')
	{
		input.open("Sudoku2_medium.dat");
		loadSudoku(input, sudoku, sudokuNumber[0]);
		input.close();
	}
	else if (difficulty[0] == '3')
	{
		input.open("Sudoku3_hard.dat");
		loadSudoku(input, sudoku, sudokuNumber[0]);
		input.close();
	}
	else if (difficulty[0] == '4')
	{
		input.open("Sudoku4_very_hard.dat");
		loadSudoku(input, sudoku, sudokuNumber[0]);
		input.close();
	}

	//Remembers the position of starting numbers
	bool startingNumbersPositions[9][9] = { false };
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sudoku[i][j] != '0') { startingNumbersPositions[i][j] = true; }
		}
	}

	//Instructions and rules
	instructions();

	cout << "-------------------------------------------------------\n";
	cout << "Your sudoku:\n";
	printSudoku(sudoku);

	char consoleRow, consoleCol, consoleNum;
	int indexRow, indexCol;
	while (!isSudokuSolven(sudoku))
	{
		cout << "Row:";
		cin >> consoleRow;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Column:";
		cin >> consoleCol;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Number:";
		cin >> consoleNum;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		indexRow = int(consoleRow - NUMBER_FROM_LETTER - 1);
		indexCol = int(consoleCol - NUMBER_FROM_LETTER - 1);

		if (indexRow < 0 || indexRow > 8 || indexCol < 0 || indexCol > 8 )
		{
			cout << "Invalid move! Please choose valid coordinates!\n";
			continue;
		}
		if (!((consoleNum >= '1' && consoleNum <= '9') || consoleNum == 'x'))
		{
			cout << "Invalid move! Please choose valid number!\n";
			continue;
		}
		if (startingNumbersPositions[indexRow][indexCol])
		{
			cout << "You cannot replace the starting numbers!\n";
			continue;
		}
		f = true;
		for (int i = 0; i < 9; i++)
		{
			if (consoleNum == sudoku[indexRow][i])
			{
				cout << "You have " << consoleNum << " on row " << consoleRow << endl;
				f = false;
				break;
			}
			else if (consoleNum == sudoku[i][indexCol])
			{
				cout << "You have " << consoleNum << " on column " << consoleRow << endl;
				f = false;
				break;
			}
		}
		int boxNumber;
		if (indexRow <= 2)
		{
			if (indexCol <= 2) { boxNumber = 1; }
			else if (indexCol <= 5) { boxNumber = 2; }
			else { boxNumber = 3; }
		}
		else if (indexRow <= 5)
		{
			if (indexCol <= 2) { boxNumber = 4; }
			else if (indexCol <= 5) { boxNumber = 5; }
			else { boxNumber = 6; }
		}
		else
		{
			if (indexCol <= 2) { boxNumber = 7; }
			else if (indexCol <= 5) { boxNumber = 8; }
			else { boxNumber = 9; }
		}
		if(!check3x3Box(sudoku, consoleNum, boxNumber))
		{
			cout << "You have " << consoleNum << " in box " << boxNumber << endl;
			f = false;
		}

		if (f)
		{
			if (consoleNum == 'x') { sudoku[indexRow][indexCol] = '0'; }
			else { sudoku[indexRow][indexCol] = consoleNum; }
		
		}
		
		
		printSudoku(sudoku);

	}
	cout << "SOLVEN!" << endl;
	

	return 0;
}

