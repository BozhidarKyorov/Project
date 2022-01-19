#include<iostream>
#include<fstream>
#include<vector>

using namespace std;
//Prototypes
void loadSudoku(ifstream&, char[10][9], char);
//loadSudoku(ifstream&, char[10][9], char)
//void printSudoku(vector<string>&);
//bool isSudokuSolven(vector<string>&);

int main()
{
	ifstream input;
	char difficulty[2];

	cout << "Hello, please select sudoku difficulty:\n";
	cout << "| 1 - Easy | 2 - Medium | 3 - Hard | 4 - Very hard |\n";

	//Selection for diffiulty. Checking for choosing invalid difficulty
	bool f = true;
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

	char sudokuNumber[2];

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
	cout << "Your sudoku:\n";
	//printSudoku(sudoku);

	


	

	return 0;
}

void loadSudoku(ifstream& input, char sudoku[10][9], char sudokuNumber)
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

//void printSudoku(vector<string>& sudoku)
//{
//	cout << char(201);
//	for (int i = 0; i < 17; i++)
//	{
//		if (i % 6 == 5) { cout << char(203); }
//		else { cout << char(205); }
//	}
//	cout << char(187) << endl;
//
//	for (int i = 0; i < 9; i++)
//	{
//		if (i % 3 == 0 && i != 0)
//		{
//			cout << char(204);
//			for (int i = 0; i < 17; i++)
//			{
//				if (i % 6 == 5) { cout << char(206); }
//				else { cout << char(205); }
//			}
//			cout << char(185);
//			cout << endl;
//		}
//		cout << char(186);
//
//		for (int j = 0; j < 9; j++)
//		{
//			if (j % 3 == 2) { cout << sudoku[i][j] << char(186); }
//			else { cout << sudoku[i][j] << " "; }
//		}
//		cout << endl;
//	}
//	cout << char(200);
//	for (int i = 0; i < 17; i++)
//	{
//		if (i % 6 == 5) { cout << char(202); }
//		else { cout << char(205); }
//	}
//	cout << char(188) << endl;
//}
//
//bool isSudokuSolven(vector<string>& sudoku)
//{
//	int sumRow = 0;
//	int sumCol = 0;
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			sumRow = sumRow + int(sudoku[i][j]) - 48;
//			sumCol = sumCol + int(sudoku[j][i]) - 48;
//		}
//		if (sumRow != 45) { return false; }
//		if (sumCol != 45) { return false; }
//		sumRow = 0;
//		sumCol = 0;
//	}
//	return true;
//}