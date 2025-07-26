#include <stdio.h>
#include <unistd.h>
#include "rush01.h"

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
