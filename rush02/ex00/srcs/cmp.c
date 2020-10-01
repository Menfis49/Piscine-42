/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvernhes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:31:37 by vvernhes          #+#    #+#             */
/*   Updated: 2020/09/29 16:10:54 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"
#include <stdio.h>

int		compare_doubles(t_dico *tab, int j)
{
	int i;

	i = 0;
	while (tab[i].chiffre != 0)
	{
		if (ft_strcmp(tab[i].chiffre, tab[j].chiffre) == 0)
		{
			if (ft_strcmp(tab[i].lettre, tab[j].lettre) != 0)
			{
				printf("ici3\n");
				error(2);
				return (-1);
			}
		}
		i++;
	}
	return (1);
}

int		look_doubles(char *temp, t_dico *tab, t_result **begin_list)
{
	int		j;
	int		bol;

	j = 0;
	bol = 0;
	while (tab[j].chiffre != 0)
	{
		if (bol == 0 && (ft_strcmp(temp, tab[j].chiffre) == 0))
		{
			ft_list_push_back(begin_list, tab[j].lettre);
			bol = 1;
		}
		else if (bol == 1 && (ft_strcmp(temp, tab[j].chiffre) == 0))
		{
			if (compare_doubles(tab, j) == -1)
				return (-1);
		}
		j++;
	}
	if (bol == 0)
	{
		
		printf("ici2\n");
		error(2);
		return (-1);
	}
	return (1);
}

int		look_for_sep(int nb, t_dico *tab, t_result **begin_list)
{
	char	*temp;
	int		i;

	if (!(temp = malloc(sizeof(char) * (nb + 1))))
		return (-1);
	temp[0] = '1';
	i = 1;
	while (i < nb)
	{
		temp[i] = '0';
		i++;
	}
	temp[i] = '\0';
	if (look_doubles(temp, tab, begin_list) == -1)
		return (-1);
	free(temp);
	return (0);
}

int		num_temp_zero(t_dico *tab, t_result **begin_list)
{
	int		i;
	int		j;
	char	temp[4];

	i = 0;
	j = 0;
	temp[0] = '0';
	temp[1] = '\0';
	if (look_doubles(temp, tab, begin_list) == -1)
		return (-1);
	return (0);
}

int		cmp(t_dico *tab, char *av, t_result **begin_list, int nb)
{
	int		i;
	int		tamp;

	i = 0;
	while (nb > 0)
	{
		if (av[0] == '0' && av[1] == '\0')
			tamp = num_temp_zero(tab, begin_list);
		else if (av[i] == '0')
			tamp = nb_void(nb, av + i, tab, begin_list);
		else if (nb % 3 == 1)
			tamp = nb_units(nb, av + i, tab, begin_list);
		else if (nb % 3 == 2)
			tamp = nb_diz(nb, av + i, tab, begin_list);
		else if (nb % 3 == 0)
			tamp = nb_cent(nb, av + i, tab, begin_list);
		if (tamp == -1)
			return (-1);
		if (nb - tamp == 2)
			i++;
		nb = tamp;
		i++;
	}
	return (1);
}
