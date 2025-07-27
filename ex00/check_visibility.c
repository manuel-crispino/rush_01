#include <unistd.h>
#include "rush01.h"

// Conta quante torri si vedono da sinistra in una riga (indici da 1 a 4)
int visibility_from_left(char row[6])
{
    int max_height = 0;
    int visible_count = 0;
    for (int i = 1; i <= 4; i++)
    {
        if (row[i] > max_height)
        {
            max_height = row[i];
            visible_count++;
        }
    }
    return visible_count;
}

// Conta quante torri si vedono da destra in una riga (indici da 1 a 4)
int visibility_from_right(char row[6])
{
    int max_height = 0;
    int visible_count = 0;
    for (int i = 4; i >= 1; i--)
    {
        if (row[i] > max_height)
        {
            max_height = row[i];
            visible_count++;
        }
    }
    return visible_count;
}

// Conta quante torri si vedono dall’alto in una colonna (righe da 1 a 4)
int visibility_from_top(char puzzle[6][6], int col)
{
    int max_height = 0;
    int visible_count = 0;
    for (int row = 1; row <= 4; row++)
    {
        if (puzzle[row][col] > max_height)
        {
            max_height = puzzle[row][col];
            visible_count++;
        }
    }
    return visible_count;
}

// Conta quante torri si vedono dal basso in una colonna (righe da 1 a 4)
int visibility_from_bottom(char puzzle[6][6], int col)
{
    int max_height = 0;
    int visible_count = 0;
    for (int row = 4; row >= 1; row--)
    {
        if (puzzle[row][col] > max_height)
        {
            max_height = puzzle[row][col];
            visible_count++;
        }
    }
    return visible_count;
}
// Controlla che tutte le righe e colonne rispettino le regole di visibilità impostate sui bordi
int check_visibility(char puzzle[6][6])
{
    int i;
    int left, right, top, bottom;

    // Controlla righe (visibilità da sinistra e destra)
    for (i = 1; i <= 4; i++)
    {
        // Se la riga i è completa (non ci sono '0')
        int complete = 1;
        for (int col = 1; col <= 4; col++)
        {
            if (puzzle[i][col] == '0')
            {
                complete = 0;
                break;
            }
        }
        if (complete)
        {
            left = visibility_from_left(puzzle[i]);
            right = visibility_from_right(puzzle[i]);
            if (left != puzzle[i][0] - '0' || right != puzzle[i][5] - '0')
                return 0; // violazione regola visibilità riga
        }
    }

    // Controlla colonne (visibilità dall’alto e dal basso)
    for (i = 1; i <= 4; i++)
    {
        // verifica se colonna completa
        int complete = 1;
        for (int row = 1; row <= 4; row++)
        {
            if (puzzle[row][i] == '0')
            {
                complete = 0;
                break;
            }
        }
        if (complete)
        {
            top = visibility_from_top(puzzle, i);
            bottom = visibility_from_bottom(puzzle, i);
            if (top != puzzle[0][i] - '0' || bottom != puzzle[5][i] - '0')
                return 0; // violazione regola visibilità colonna
        }
    }
    return 1; // tutto ok
}

