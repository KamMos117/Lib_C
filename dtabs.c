#include <stdio.h>
#include <stdlib.h>
#include "dtabs.h"

int **dynamic_table_input(int rows, int cols)
{
    int i, j;
    int **tab = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++)
    {
        tab[i] = (int *)malloc(cols * sizeof(int));
    }

    for (i = 0; i < rows; i++)
    {
    	for (j = 0; j < cols; j++)
    	{
    		scanf("%d", &tab[i][j]);
		}            
	}
        

    return tab;
}

void dynamic_table_output(int **tab, int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%d ", tab[i][j]);
        printf("\n");
    }

    for (i = 0; i < rows; i++)
        free(tab[i]);
    free(tab);
}

void add_dtabs(int **tab, int ** tab2,int **out_tab, int rows, int cols)
{
	int i, j;

    for (i = 0; i < rows; i++)
    {
    	for (j = 0; j < cols; j++)
    	{
    		out_tab[i][j] = tab[i][j] + tab2[i][j];
		}            
	}
}

void sub_dtabs(int **tab, int ** tab2,int **out_tab, int rows, int cols)
{
	int i, j;
	
	for(i = 0; i < rows;i++)
	{
		for(j = 0; j < cols; j++)
		{
			out_tab[i][j] = tab[i][j] - tab2[i][j];
		}
	}
}

void mul_dtabs(int **tab, int ** tab2,int **out_tab, int rows, int cols)
{
	int i, j, k, m;
	
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			for(k = 0; k < rows; k++)
	        {
                out_tab[i][j] += (tab[i][k]*tab2[k][j]);
		 	}
		}
	}
}

int **create_empty(int rows, int cols)
{
	int i, j;
	
	int **tab = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++)
    {
        tab[i] = (int *)malloc(cols * sizeof(int));
    }
    
    return tab;
}

void free_dtab(int **tab,int rows)
{
	int i;
	
	for (i = 0; i < rows; i++)
        free(tab[i]);
    free(tab);
}
