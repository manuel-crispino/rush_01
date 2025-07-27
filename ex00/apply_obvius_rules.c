#include <unistd.h>
#include "rush01.h"

// Apply rules based on top border clues
void apply_rules_top(char puzzle[6][6])
{
	int i = 1;
	while (i <= 4)
	{
		if (puzzle[0][i] == '4')
		{
			puzzle[1][i] = '1';
			puzzle[2][i] = '2';
			puzzle[3][i] = '3';
			puzzle[4][i] = '4';
		}
		else if (puzzle[0][i] == '1')
		{
			puzzle[1][i] = '4';
		}
		else if (puzzle[0][i] == '3' && puzzle[5][i] == '1')
		{
			puzzle[3][i] = '4';
		}
		i++;
	}
}

// Apply rules based on bottom border clues
void apply_rules_bottom(char puzzle[6][6])
{
	int i = 1;
	while (i <= 4)
	{
		if (puzzle[5][i] == '4')
		{
			puzzle[1][i] = '4';
			puzzle[2][i] = '3';
			puzzle[3][i] = '2';
			puzzle[4][i] = '1';
		}
		else if (puzzle[5][i] == '1')
		{
			puzzle[4][i] = '4';
		}
		else if (puzzle[5][i] == '3' && puzzle[0][i] == '1')
		{
			puzzle[2][i] = '4';
		}
		i++;
	}
}

// Apply rules based on left border clues
void apply_rules_left(char puzzle[6][6])
{
	int i = 1;
	while (i <= 4)
	{
		if (puzzle[i][0] == '4')
		{
			puzzle[i][1] = '1';
			puzzle[i][2] = '2';
			puzzle[i][3] = '3';
			puzzle[i][4] = '4';
		}
		else if (puzzle[i][0] == '1')
		{
			puzzle[i][1] = '4';
		}
		else if (puzzle[i][0] == '3' && puzzle[i][5] == '1')
		{
			puzzle[i][3] = '4';
		}
		i++;
	}
}

// Apply rules based on right border clues
void apply_rules_right(char puzzle[6][6])
{
	int i = 1;
	while (i <= 4)
	{
		if (puzzle[i][5] == '4')
		{
			puzzle[i][1] = '4';
			puzzle[i][2] = '3';
			puzzle[i][3] = '2';
			puzzle[i][4] = '1';
		}
		else if (puzzle[i][5] == '1')
		{
			puzzle[i][4] = '4';
		}
		else if (puzzle[i][5] == '3' && puzzle[i][0] == '1')
		{
			puzzle[i][2] = '4';
		}
		i++;
	}
}

// Apply all direct rules from borders
void apply_obvious_rules(char puzzle[6][6])
{
	apply_rules_top(puzzle);
	apply_rules_bottom(puzzle);
	apply_rules_left(puzzle);
	apply_rules_right(puzzle);
}
