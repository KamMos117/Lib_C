
#include <stdio.h>
#include "dtabs.h"

int main()
{
    int rows, cols, rows2, cols2, operation;
    int **table3,**table,**table2;
    
    scanf("%d", &operation);
    
    switch(operation)
    {
        case 0:
            scanf("%d %d", &rows, &cols);
            table = dynamic_table_input(rows, cols);
            scanf("%d %d", &rows2, &cols2);
            table2 = dynamic_table_input(rows2, cols2);
            table3 = create_empty(rows,cols);
            sub_dtabs(table, table2, table3, rows, cols, rows2, cols2);
            free_dtab(table,rows);
    	    free_dtab(table2,rows);
            break;
        case 1:
            scanf("%d %d", &rows, &cols);
            table = dynamic_table_input(rows, cols);
            scanf("%d %d", &rows2, &cols2);
            table2 = dynamic_table_input(rows2, cols2);
            table3 = create_empty(rows,cols);
            add_dtabs(table, table2, table3, rows, cols, rows2, cols2);
    	    free_dtab(table,rows);
    	    free_dtab(table2,rows);
            break;
        case 2:
            scanf("%d %d", &rows, &cols);
            table = dynamic_table_input(rows, cols);
            scanf("%d %d", &rows2, &cols2);
            table2 = dynamic_table_input(rows2, cols2);
            table3 = create_empty(rows,cols2);
            mul_dtabs(table, table2, table3, rows, cols, rows2, cols2);
            free_dtab(table,rows);
    	    free_dtab(table2,rows);
            break;
        case 3:
            scanf("%d %d", &rows, &cols);
            table = dynamic_table_input(rows, cols);
            table3 = create_empty(cols,rows);
            trans_dtab(table,table3,rows,cols);
            free_dtab(table,rows);
            break;
        default:
            printf("No inputed operation");
            break;
    }
    	
    dynamic_table_output(table3, rows, cols2);
    return 0;
}
