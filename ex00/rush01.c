
#include <unistd.h>
#include "rush01.h"

void init_puzzle(char puzzle[6][6])
{
    char init[6][6] = {
        {' ','0','0','0','0',' '},
        {'0','0','0','0','0','0'},
        {'0','0','0','0','0','0'},
        {'0','0','0','0','0','0'},
        {'0','0','0','0','0','0'},
        {' ','0','0','0','0',' '}
    };
    int row = 0;
    int col = 0;
    while (row < 6)
    {
        col = 0;
        while (col < 6)
        {
            puzzle[row][col] = init[row][col];
            col++;
        }
        row++;
    }
}

int check_args_and_fill(int argc, char **argv, char matrix[4][4])
{
    if (argc != 2)
    {
        write(1, "Error\n", 6);
        return 0;
    }
    if (!fill_matrix(argv[1], matrix))
    {
        write(1, "Error\n", 6);
        return 0;
    }
    return 1;
}



int main(int argc, char **argv)
{
	char puzzle[6][6];
	char matrix[4][4];

	init_puzzle(puzzle);

	if (!check_args_and_fill(argc, argv, matrix))
		return 1;
	addrules(puzzle, matrix);
	apply_obvious_rules(puzzle);
	if (!recursive(puzzle, 1, 1))
		write(1, "No solution\n", 12);
	else
	print(puzzle);
	return (0);
}

