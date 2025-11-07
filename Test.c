
#include <stdio.h>
#include "dtabs.h"

int main()
{
    int rows, cols, rows2, cols2, operation;
    scanf("%d %d", &rows, &cols);
    int **table = dynamic_table_input(rows, cols);
    scanf("%d %d", &rows2, &cols2);
    int **table2 = dynamic_table_input(rows2, cols2);
    int **table3 = create_empty(rows,cols2);
    
    scanf("%d", &operation);
    
    switch(operation)
    {
        case 0:
            sub_dtabs(table, table2, table3, rows, cols, rows2, cols2);
            free_dtab(table,rows);
    	    free_dtab(table2,rows);
            break;
        case 1:
            add_dtabs(table, table2, table3, rows, cols, rows2, cols2);
    	    free_dtab(table,rows);
    	    free_dtab(table2,rows);
            break;
        case 2:
            mul_dtabs(table, table2, table3, rows, cols, rows2, cols2);
            free_dtab(table,rows);
    	    free_dtab(table2,rows);
            break;
        default:
            printf("No inputed operation");
            break;
    }
    	
    dynamic_table_output(table3, rows, cols2);
    return 0;
}
