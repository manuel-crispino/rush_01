
#include <stdio.h>
#include <unistd.h>

int fill_matrix(char *str, char matrix[4][4])
{ 	
	int i = 0; 
	int col = 0 ;
	int row = 0; 
	int count = 0;
	while(str[i] != '\0')
	{
		if  (str[i] <= '4' &&  str[i] >= '1' )
		{
			matrix[row][col] = str[i];
			col++;
			
			if (col == 4)
			{
				col = 0;
				row++;
			}
			count++;
		}
		else if (str[i] != ' ' )
		{
			write(1,"Error\n",6);
			printf("error str[%d] != ' ' = %c \n",i,str[i]);
			return 0;
		}
		i++;
	}
		if (count != 16)
		{
			write(1,"Error\n",6);
			printf("error count 16\n");
			return 0;
		}
	return 1;
}

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

void print (char puzzle[6][6])
{
	int row = 0 ;
	int col = 1 ; 
	while(row < 6)
	{
		col = 0;
		
		while(col < 6)
		{
			write(1, &puzzle[row][col],1);
			write(1," ",1);
			col++;
		}
		write(1,"\n",1);
		row++;	
	}
}


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

//char	*apply_obvious_rules(){};

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


int main (int argc,char **argv)
{
	char puzzle[6][6] = 
	{
    	{' ','0','0','0','0',' '},
    	{'0','0','0','0','0','0'},
    	{'0','0','0','0','0','0'},
    	{'0','0','0','0','0','0'},
    	{'0','0','0','0','0','0'},
    	{' ','0','0','0','0',' '}
	};
	char matrix[4][4];
	char top[4];
	char bottom[4];
	char right[4];
	char left[4];
	
	if (argc != 2)
	{
		write(1, "Error\n",6);
		printf("error argc\n");
		return (1);
	}
	if(!fill_matrix(argv[1],matrix))
	{ 
		printf("error matrix return\n");
		return 1;
	}
	addrules(puzzle,matrix,top,bottom,left,right);
        print(puzzle);
	if (!recursive(puzzle, 1, 1))
		write(1, "No solution\n", 12);
	else
		print(puzzle);
return (0);
}
