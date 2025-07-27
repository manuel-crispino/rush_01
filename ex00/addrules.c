#include <unistd.h>
#include "rush01.h"

void addrules_top(char puzzle[6][6], char matrix[4][4])
{
    int i = 0;
    while (i < 4)
    {
        puzzle[0][i + 1] = matrix[0][i];
        i++;
    }
}

void addrules_bottom(char puzzle[6][6], char matrix[4][4])
{
    int i = 0;
    while (i < 4)
    {
        puzzle[5][i + 1] = matrix[1][i];
        i++;
    }
}

void addrules_left(char puzzle[6][6], char matrix[4][4])
{
    int i = 0;
    while (i < 4)
    {
        puzzle[i + 1][0] = matrix[2][i];
        i++;
    }
}

void addrules_right(char puzzle[6][6], char matrix[4][4])
{
    int i = 0;
    while (i < 4)
    {
        puzzle[i + 1][5] = matrix[3][i];
        i++;
    }
}

void addrules(char puzzle[6][6], char matrix[4][4])
{
    addrules_top(puzzle, matrix);
    addrules_bottom(puzzle, matrix);
    addrules_left(puzzle, matrix);
    addrules_right(puzzle, matrix);
}

