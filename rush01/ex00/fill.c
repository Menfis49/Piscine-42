/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:18:37 by vazra             #+#    #+#             */
/*   Updated: 2020/09/20 18:33:20 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab(int **tab, int i, int f)
{
	while (i < 4)
	{
		f = 0;
		while (f < 4)
		{
			ft_putchar(tab[i][f] + '0');
			if (f < 3)
				ft_putchar(' ');
			f++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		**ft_initialize(int **tab)
{
	int i;
	int f;

	i = 0;
	while (i < 5)
	{
		f = 0;
		while (f < 4)
		{
			tab[i][f] = 0;
			f++;
		}
		i++;
	}
	return (tab);
}

int		**ft_malloc(void)
{
	int i;
	int **tab;

	i = 0;
	tab = malloc(sizeof(int*) * 5);
	if (!tab)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (i < 5)
	{
		tab[i] = malloc(sizeof(int) * 4);
		if (!tab[i])
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (tab);
}

int		ft_fill(char **av)
{
	int **tab;

	if (ft_malloc() == NULL)
		return (0);
	else
		tab = ft_malloc();
	tab = ft_initialize(tab);
	if (ft_solver(av, tab, 0, 0) == 1)
	{
		ft_free(tab);
		write(1, "Error\n", 6);
		return (0);
	}
	ft_free(tab);
	return (1);
}
