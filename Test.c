#include <stdio.h>
#include "dtabs.h"

int main()
{
    int rows, cols, operation;
    scanf("%d %d", &rows, &cols);
    int **table = dynamic_table_input(rows, cols);
    dynamic_table_output(table, rows, cols);
    int **table2 = dynamic_table_input(rows, cols);
    dynamic_table_output(table2, rows, cols);
    int **table3 = create_empty(rows,cols);
    
    scanf("%d", &operation);
    
    if(operation==1)
    {
    	add_dtabs(table, table2, table3, rows, cols);
    	free_dtab(table,rows);
    	free_dtab(table2,rows);
	}    	
    else
    {
        if(operation==2)
        {
            mul_dtabs(table, table2, table3, rows, cols);
        }            
        else
        {
            sub_dtabs(table, table2, table3, rows, cols);
        }    	    
    	free_dtab(table,rows);
    	free_dtab(table2,rows);
	}
    	
    dynamic_table_output(table3, rows, cols);
    return 0;
}
