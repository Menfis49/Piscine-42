#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

void ft_putchar(char c);
void ft_print(int **tab, int i, int f);
void ft_error(void);
int ft_principal(char **av);
int ft_compare(int s1, int s2);
int ft_check_col(int **tab, char **av, int f, int n);
int ft_check_row(int **tab, char **av, int f, int n);
int ft_check_param(int **tab, char **av);
int check_line_column(int **tab, int n, int i, int f);
int recursive(char **av, int **tab, int i, int f);
int **ft_initialize(int **tab);
void ft_free(int **tab);

#endif
