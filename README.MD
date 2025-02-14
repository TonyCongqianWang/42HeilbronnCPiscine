# C PISCINE AT 42 HEILBRONN

This Repository contains some of the more interesting tasks I solved during the C Pisine at 42 Heibronn. It is my first time creating C projects on my own. Every project has to satisfy [The Norm](https://github.com/42School/norminette) which includes various formatting rules like aligning varliable and function declarations with tabs. Additonally Every function has at most 25 lines and every file has at most 5 function declarations. Every program can be compiled with a standard C compiler. At 42 Heilbronn clang gcc was used and referred to as cc.

## SkyscraperSolver

Program that uses constraint programming to solve a 1x1 up to 9x9 [Skyscraper puzzle](https://www.brainbashers.com/skyscrapers.asp). Only puzzles with complete constraint values and no grid values can be input as this was the task at the piscine. Support for different puzzles might be added.

## biggest_square

Program that uses dynamic programming to solve the [Maximal Square](https://leetcode.com/problems/maximal-square/description/) problam. The program takes file names as arguments or stdin if no file name is given. The files are expected to have a special format, specifying a rectangular map with obstacles. It prints the map with the biggest possible square filled in.

## file_utils

Three small programs that display contents of files using only basic C functions.
