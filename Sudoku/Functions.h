#pragma once

const int NUMBER_FROM_LETTER = 48;

void loadSudoku(std::ifstream&, char[10][9], char);
void printSudoku(char[10][9]);
bool isSudokuSolven(char[10][9]);
bool check3x3Box(char[10][9], int, int);
void instructions();
