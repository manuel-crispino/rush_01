#include <stdio.h>
#include <unistd.h>
#include "rush01.h"

void addrules(char puzzle[6][6], char matrix[4][4],char top[4],char bottom[4],char left[4],char right[4])
{
    int i;

    // TOP → matrix[0][0..3] → puzzle[0][1..4]
    i = 0;
    while (i < 4)
    {
        puzzle[0][i + 1] = matrix[0][i];
	top[i] = matrix[0][i];
        i++;
    }

    // BOTTOM → matrix[1][0..3] → puzzle[5][1..4]
    i = 0;
    while (i < 4)
    {
        puzzle[5][i + 1] = matrix[1][i];
	bottom[i] = matrix[1][i];
        i++;
    }

    // LEFT → matrix[2][0..3] → puzzle[1..4][0]
    i = 0;
    while (i < 4)
    {
        puzzle[i + 1][0] = matrix[2][i];
	left[i] = matrix[2][i];
        i++;
    }

    // RIGHT → matrix[3][0..3] → puzzle[1..4][5]
    i = 0;
    while (i < 4)
    {
        puzzle[i + 1][5] = matrix[3][i];
	right[i] = matrix[3][i];
        i++;
    }
}

