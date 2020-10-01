/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_dico.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:50:45 by jacher            #+#    #+#             */
/*   Updated: 2020/09/29 16:22:43 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

#include <stdio.h>
int		ft_fill_struct_chiffre(t_dico tab, char *dico_tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (dico_tab[i] == '\n' && dico_tab[i+1] == '\0')
		return (0);
	while ((dico_tab[i] >= '0' && dico_tab[i] <= '9') || (dico_tab[i] == '\n' && dico_tab[i+1] == '\0'))
	{
		tab.chiffre[j] = dico_tab[i];
		i++;
		j++;
	}
	printf("value return chiffre : %d\n", i);
	if (i == 0)
		return (-1);
	while (dico_tab[i] == ' ' || dico_tab[i] == ':')
		i++;
	if (i > 1 && dico_tab[i] == '\0')
		return (-1);
	return (i);
}

int		ft_fill_struct_lettre(t_dico tab, char *dico_tab, int i, int j)
{
	int		space;
	int		bol;

	bol = 0;
	while (dico_tab[i] >= 32 && dico_tab[i] <= 126)
	{
		space = 0;
		while (dico_tab[i] == ' ')
		{
			space = 1;
			i++;
		}
		if (dico_tab[i] == '\0' && bol == 0)
			return (-1);
		if (space == 1 && dico_tab[i] != '\0')
		{
			tab.lettre[j] = ' ';
			j++;
		}
		bol = 1;
		tab.lettre[j] = dico_tab[i];
		i++;
		j++;
	}
	printf("value return lettre  : %d\n", 1);
	return (1);
}

int		s_c(char *dico_tab)
{
	int		i;

	i = 0;
	while (dico_tab[i] >= '0' && dico_tab[i] <= '9')
		i++;
	return (i);
}

int		s_l(char *dico_tab)
{
	int		i;
	int		size_lettre;

	i = 0;
	size_lettre = 0;
	while (dico_tab[i] == ' ')
		i++;
	while (dico_tab[i] >= 32 && dico_tab[i] <= 126)
	{
		while (dico_tab[i] == ' ')
			i++;
		size_lettre++;
		i++;
	}
	return (size_lettre);
}
t_dico	*split_dico(char **dico_tab, int lines)
{
	t_dico	*tab;
	int		i;
	int		j;
	int		k;

	i = -1;
	if (!(tab = malloc(sizeof(t_dico) * (lines + 1))))
		return (0);
	while (dico_tab[++i] != 0)
	{
		if (!(tab[i].lettre = malloc(sizeof(char) * s_l(dico_tab[i]) + 1))
			|| !(tab[i].chiffre = malloc(sizeof(char) * s_c(dico_tab[i]) + 1)))
			return (0);
		k = ft_fill_struct_chiffre(tab[i], dico_tab[i]);
		if (k != -1)
			j = ft_fill_struct_lettre(tab[i], dico_tab[i], k, 0);
		if (k == -1 || j == -1)
		{
			printf("celuici\n");
			error(2);
			return (0);
		}
	}
	tab[i].chiffre = 0;
	tab[i].lettre = 0;
	return (tab);
}
