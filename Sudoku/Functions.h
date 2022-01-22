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
* Header file for all functions
*
*/
#pragma once

const int NUMBER_FROM_LETTER = 48;

void loadSudoku(std::ifstream&, char[10][9], char);
void printSudoku(char[10][9]);
bool isSudokuSolved(char[10][9]);
bool check3x3Box(char[10][9], int, int);
void instructions();
