
#include <stdio.h>
#include <unistd.h>
#include "rush01.h"

//char	*apply_obvious_rules(){};

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
