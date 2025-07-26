#ifndef RUSH01_H
# define RUSH01_H

int  fill_matrix(char *str, char matrix[4][4]);
void addrules(char puzzle[6][6], char matrix[4][4],
              char top[4], char bottom[4], char left[4], char right[4]);
void print(char puzzle[6][6]);
int  is_valid(char puzzle[6][6], int row, int col, char num);
int  recursive(char puzzle[6][6], int row, int col);

#endif

