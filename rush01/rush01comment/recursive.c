#include "rush01.h"

void	ft_free(int **tab)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	check_line_column(int **tab, int nbr_a_mettre, int lign, int column)
{
	int k;

	k = 0;
	while (k < 4)
	{
		if (k != column) //retourne 0 si on a une valeur egale a nbr_a_mettre dans la colonne
		{
			if (nbr_a_mettre == tab[lign][k])
			return (0);
		}
		k++;
	}
	k = 0;
	while (k < 4)
	{
		if (k != lign)//retourne 0 si on a une valeur egale a nbr_a_mettre dans la ligne
		{
			if (nbr_a_mettre == tab[k][column])
			return (0);
		}
		k++;
	}
	return (1);
}

int	**check_n(int lign, int column, int **tab, char **av)
{
	int nbr_a_mettre;

	nbr_a_mettre = 1;
	while (nbr_a_mettre < 5)
	{
		if (check_line_column(tab, nbr_a_mettre, lign, column) == 1)//check la ligne et la colonne pour voir si on a deja un nbr = a nbr_a_mettre dedans
		{
			tab[lign][column] = nbr_a_mettre; // met le nbr dans le tableau
			if (column < 3)
			{
				if (recursive(av, tab, lign, column + 1) == 0) //teste chaque colonne de la ligne en mettant des nbr dedans
					return (0);
			}
			else
			{
				if (recursive(av, tab, lign + 1, 0) == 0) // change de ligne et repart a la premiere colonne
					return (0);
			}
		}
		nbr_a_mettre++;
	}
	return (tab);
}

int	recursive(char **av, int **tab, int lign, int column)
{
	//on commence ligne 0 colonne 0 
	if (lign < 4) //pour chaque ligne
	{
		if (check_n(lign, column, tab, av) == 0)
			return (0);
	}
	else
	{
		if (ft_check_param(tab, av) == 1) //si les parametres de av sont coherents entre eux et avec le tableau
		{
			ft_print(tab, 0, 0); //affiche le tab
			return (0); // met les fonctions recursives a 0 et les conditions dans checkn vont donc return 0
		}
	}
	tab[lign][column] = 0;//si un truc marche pas, met un 0 et repasse a l'etape d'avant
	return (1); //si on a pas trouve de possibilites avec av
}
