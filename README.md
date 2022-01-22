
# Project

Project №6 - Sudoku by Bozhidar Kyorov

The program will be finished at 22nd of January 2022. 
Rules of normal Sudoku:
Use only the numbers from 1 to 9 while solving a sudoku
Use each number once in every row column and 3x3 box
You cannot replace the starting numbers
Instruction for playing:
Before each move you will see 'Row:' , 'Column:' and 'Number:'
Use 1 to 9 to select row and column to put new number in the box
Numbers can be 1 to 9
Typing 'x' instead of number on 'Number:' will delete the selected number
Typing 'q' instead of number on 'Number:' will quit the sudoku after confirmation
The basic rules and instructions are integrated in the code itself

The only problem i had was validation, because I did not found good way except using string
I have working algorithm for validation, although its not perfect and its breakable

About functions and headers, I decided to not include a lot of function and the most of the 
game is is the body of the function. Because of that, i have only few functions contained in
one header named "Functions.h"