#include <stdio.h>
#include <unistd.h>
#include "rush01.h"

int is_valid(char puzzle[6][6], int row, int col, char num)
{
	int i;

	// Check riga
	i = 1;
	while (i < 5)
	{
		if (puzzle[row][i] == num)
			return 0;
		i++;
	}

	// Check colonna
	i = 1;
	while (i < 5)
	{
		if (puzzle[i][col] == num)
			return 0;
		i++;
	}
	return 1;
}

