#include <unistd.h>
#include <stdio.h>
#include "rush01.h"

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

