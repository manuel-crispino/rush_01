#include <stdio.h>
#include <unistd.h>
#include "rush01.h"

int recursive(char puzzle[6][6], int row, int col)
{	
	char num;
	int next_row;
	int next_col;

	if (row == 5)
		return 1;

	next_row = row;
	next_col = col + 1;
	if (next_col == 5)
	{
		next_col = 1;
		next_row++;
	}

	if (puzzle[row][col] != '0') // già pieno? passa al prossimo
		return recursive(puzzle, next_row, next_col);

	num = '1';
	while(num <= '4')
	{
		if (is_valid(puzzle, row, col, num))
		{
			puzzle[row][col] = num;
			if (recursive(puzzle, next_row, next_col))
				return 1;
			puzzle[row][col] = '0'; // backtrack
		}
		num++;
	}
	return 0;
}
