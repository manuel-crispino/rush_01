#include <unistd.h>
#include "rush01.h"

int is_valid(char puzzle[6][6], int row, int col, char num)
{
    int i;

    // Controllo riga (no duplicati)
    for (i = 1; i <= 4; i++)
    {
        if (puzzle[row][i] == num)
            return 0;
    }

    // Controllo colonna (no duplicati)
    for (i = 1; i <= 4; i++)
    {
        if (puzzle[i][col] == num)
            return 0;
    }

    // Inserisci temporaneamente il numero
    puzzle[row][col] = num;

    // Controlla se riga è completa
    int row_complete = 1;
    for (i = 1; i <= 4; i++)
    {
        if (puzzle[row][i] == '0')
        {
            row_complete = 0;
            break;
        }
    }

    // Controlla se colonna è completa
    int col_complete = 1;
    for (i = 1; i <= 4; i++)
    {
        if (puzzle[i][col] == '0')
        {
            col_complete = 0;
            break;
        }
    }

    // Se riga o colonna completa, verifica visibilità
    if (row_complete || col_complete)
    {
        if (!check_visibility(puzzle))
        {
            puzzle[row][col] = '0'; // backtrack
            return 0;
        }
    }

    // Ripristina cella a '0' (backtrack)
    puzzle[row][col] = '0';
    return 1;
}

