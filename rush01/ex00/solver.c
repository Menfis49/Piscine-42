/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:18:45 by vazra             #+#    #+#             */
/*   Updated: 2020/09/20 18:33:41 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		check_line_column(int **tab, int nbr_a_mettre, int lign, int column)
{
	int k;

	k = 0;
	while (k < 4)
	{
		if (k != column)
		{
			if (nbr_a_mettre == tab[lign][k])
				return (0);
		}
		k++;
	}
	k = 0;
	while (k < 4)
	{
		if (k != lign)
		{
			if (nbr_a_mettre == tab[k][column])
				return (0);
		}
		k++;
	}
	return (1);
}

int		**check_number(int lign, int column, int **tab, char **av)
{
	int nbr_a_mettre;

	nbr_a_mettre = 1;
	while (nbr_a_mettre < 5)
	{
		if (check_line_column(tab, nbr_a_mettre, lign, column) == 1)
		{
			tab[lign][column] = nbr_a_mettre;
			if (column < 3)
			{
				if (ft_solver(av, tab, lign, column + 1) == 0)
					return (0);
			}
			else
			{
				if (ft_solver(av, tab, lign + 1, 0) == 0)
					return (0);
			}
		}
		nbr_a_mettre++;
	}
	return (tab);
}

int		ft_solver(char **av, int **tab, int lign, int column)
{
	if (lign < 4)
	{
		if (check_number(lign, column, tab, av) == 0)
			return (0);
	}
	else
	{
		if (ft_check_param(tab, av) == 1)
		{
			ft_print_tab(tab, 0, 0);
			return (0);
		}
	}
	tab[lign][column] = 0;
	return (1);
}
