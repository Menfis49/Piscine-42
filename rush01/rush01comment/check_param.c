#include "rush01.h"

int	ft_check_rcol(int i, int column, int **tab)//check une colonne en remontant
{
	int j;
	int count;

	count = 0;
	j = 0;
	while (i >= 0)
	{
		if (tab[column][i] == 0)//si il reste un 0 c'est qu'on a pas trouve de soluce
			return (0);
		if (j < tab[i][column])//compare tous les chiffres de la colonne en remontant et en incremantant count qui sera egal normalement au chiffre de av sous la colonne
		{
			j = tab[i][column];
			count++;
		}
		i--;
	}
	return (count);
}

int	ft_check_col(int **tab, char **av, int column, int num_av)//check une colonne en descendant
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < 4)
	{
		if (tab[column][i] == 0)//si il reste un 0 c'est qu'on a pas trouve de soluce
			return (0);
		if (j < tab[i][column])//compare tous les chiffres de la colonne en descendant et en incremantant count qui sera egale normalement au chiffre de av au dessus de la colonne
		{
			j = tab[i][column];
			count++;
		}
		i++;
	}
	if ((av[1][num_av] - '0') != count)//si la valeur de count est pas egale au nbr au dessus de la colonne
		return (0);
	i = i - 1;
	count = ft_check_rcol(i, column, tab);
	if ((av[1][num_av + 8] - '0') != count)//si la valeur de count est pas egale a la valeur de av qui correspond au dessous de la colonne
		return (0);
	return (1);
}

int	ft_check_rrow(int i, int lign, int **tab)//check une ligne de droite a gauche
{
	int j;
	int count;

	count = 0;
	j = 0;
	while (i >= 0)
	{
		if (tab[lign][i] == 0)//si il reste un 0 c'est au'on a pas trouve de soluce
			return (0);
		if (j < tab[lign][i])
		{
			j = tab[lign][i];
			count++;
		}
		i--;
	}
	return (count);
}

int	ft_check_row(int **tab, char **av, int lign, int num_av)//check une ligne de gauche a droite
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < 4)
	{
		if (tab[lign][i] == 0)//si il reste un 0 c'est au'on a pas trouve de soluce
			return (0);
		if (j < tab[lign][i])
		{
			j = tab[lign][i];
			count++;
		}
		i++;
	}
	if ((av[1][num_av] - '0') != count)
		return (0);
	i--;
	count = ft_check_rrow(i, lign, tab);
	if ((av[1][num_av + 8] - '0') != count)
		return (0);
	return (1);
}

int	ft_check_param(int **tab, char **av)
{
	int f;
	int num_av;

	f = 0;
	num_av = 0;
	while (f < 4)//check les colonnes
	{
		if (ft_check_col(tab, av, f, num_av) != 1)//si on a return 0 dans ft_check_col
			return (0);
		num_av = num_av + 2;//saute l'espace
		f++;
	}
	f = 0;
	num_av = 16;
	while (f < 4)//check les lignes
	{
		if (ft_check_row(tab, av, f, num_av) != 1)//si on a return 0 dans ft_check_row
			return (0);
		num_av = num_av + 2;
		f++;
	}
	return (1);
}

