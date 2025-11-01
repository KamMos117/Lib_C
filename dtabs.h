#ifndef DTABS_H
#define DTABS_H

#ifdef _WIN32
__declspec(dllexport)
#endif
int **dynamic_table_input(int rows, int cols);

#ifdef _WIN32
__declspec(dllexport)
#endif
void dynamic_table_output(int **table, int rows, int cols);

#ifdef _WIN32
__declspec(dllexport)
#endif
void add_dtabs(int **tab, int ** tab2,int **out_tab, int rows, int cols);

#ifdef _WIN32
__declspec(dllexport)
#endif
void sub_dtabs(int **tab, int ** tab2,int **out_tab, int rows, int cols);

#ifdef _WIN32
__declspec(dllexport)
#endif
void mul_dtabs(int **tab, int ** tab2,int **out_tab, int rows, int cols);

#ifdef _WIN32
__declspec(dllexport)
#endif
int **create_empty(int rows,int cols);

#ifdef _WIN32
__declspec(dllexport)
#endif
void free_dtab(int **tab, int rows);

#endif // DTABS_H
