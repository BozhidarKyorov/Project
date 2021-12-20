#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;
//Prototypes
void loadSudoku(ifstream&, vector<string>&, string);
void printSudoku(vector<string>&);
bool isSudokuSolven(vector<string>&);

int main()
{
	ifstream input;
	string consoleDifficulty;
	string consoleSudokuNumber;
	char difficulty;
	char sudokuNumber[2];


	cout << "Hello, please select sudoku difficulty:\n";
	cout << "| 1 - Easy | 2 - Medium | 3 - Hard | 4 - Very hard |\n";


	//Selection for diffiulty. Checking for choosing invalid difficulty
	bool f = true;
	while (f)
	{
		cin >> consoleDifficulty;
		difficulty = consoleDifficulty[0];
		if (consoleDifficulty.size() != 1)
		{
			cout << "Infalid difficuly!\n";
			cout << "Please choose new difficulty:\n";
			continue;
		}

		switch (difficulty)
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

	cout << "-------------------------------------------------------\n";

	cout << "Please, choose which sudoku you want to solve:\n";
	cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |\n";

	//Selection for sudoku. Chekcing for choosing invalid number
	f = true;
	while (f)
	{
		cin >> consoleSudokuNumber;
		sudokuNumber[0] = consoleSudokuNumber[0];
		sudokuNumber[1] = consoleSudokuNumber[1];
		if (consoleSudokuNumber.size() > 2)
		{
			cout << "Invalid number!\n";
			cout << "Please choose new sudoku:\n";
			continue;
		}
		if (int(sudokuNumber[0]) >= int('1') && int(sudokuNumber[0]) <= int('9') && sudokuNumber[1] == '\0')
		{
			cout << "Chosen sudoku: " << sudokuNumber << endl;
			f = false;
		}
		else if (int(sudokuNumber[0]) == int('1') && int(sudokuNumber[1]) == int('0'))
		{
			cout << "Chosen sudoku: " << sudokuNumber[0] << sudokuNumber[1] << endl;
			f = false;
		}
		else
		{
			cout << "Invalid number!\n";
			cout << "Please choose new sudoku:\n";
		}

	}

	cout << "-------------------------------------------------------\n";

	//Input sudoku from the appropiate .dat file
	vector<string> sudoku;
	if (difficulty == '1')
	{
		input.open("Sudoku1_easy.dat");
		loadSudoku(input, sudoku, consoleSudokuNumber);
		input.close();
	}
	else if (difficulty == '2')
	{
		input.open("Sudoku2_medium.dat");
		loadSudoku(input, sudoku, consoleSudokuNumber);
		input.close();
	}
	else if (difficulty == '3')
	{
		input.open("Sudoku3_hard.dat");
		loadSudoku(input, sudoku, consoleSudokuNumber);
		input.close();
	}
	else if (difficulty == '4')
	{
		input.open("Sudoku4_very_hard.dat");
		loadSudoku(input, sudoku, consoleSudokuNumber);
		input.close();
	}
	cout << "Your sudoku:\n";
	printSudoku(sudoku);

	vector<string> sudoku1;
	for (int i = 0; i < 9; i++)
	{
		sudoku1.push_back("123456789");
	}

	cout << isSudokuSolven(sudoku1) << endl;;




	return 0;
}

void loadSudoku(ifstream& input, vector<string>& sudoku, string sudokuNumber)
{
	string temp;
	input >> temp;
	while (temp != sudokuNumber)
	{
		input >> temp;
	}
	for (int i = 0; i < 9; i++)
	{
		input >> temp;
		sudoku.push_back(temp);
	}
}

void printSudoku(vector<string>& sudoku)
{
	cout << char(201);
	for (int i = 0; i < 17; i++)
	{
		if (i % 6 == 5) { cout << char(203); }
		else { cout << char(205); }
	}
	cout << char(187) << endl;

	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0 && i != 0)
		{
			cout << char(204);
			for (int i = 0; i < 17; i++)
			{
				if (i % 6 == 5) { cout << char(206); }
				else { cout << char(205); }
			}
			cout << char(185);
			cout << endl;
		}
		cout << char(186);

		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 2) { cout << sudoku[i][j] << char(186); }
			else { cout << sudoku[i][j] << " "; }
		}
		cout << endl;
	}
	cout << char(200);
	for (int i = 0; i < 17; i++)
	{
		if (i % 6 == 5) { cout << char(202); }
		else { cout << char(205); }
	}
	cout << char(188) << endl;
}

bool isSudokuSolven(vector<string>& sudoku)
{
	string row = "123456789";
	bool isNumberMet[9] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				if (sudoku[i][j] == row[k])
				{
					if (isNumberMet[int(row[k] - 48)]) { return false; }
					else { isNumberMet[int(row[k] - 48)] = true; }
				}
			}
			
		}
	}
	return true;
}