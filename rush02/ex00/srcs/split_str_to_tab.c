/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 11:40:49 by jacher            #+#    #+#             */
/*   Updated: 2020/09/29 15:55:01 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int		print(int index, int i, char *str, char *tab_k)
{
	int j;

	j = 0;
	while (j < i - index)
	{
		tab_k[j] = str[index + j];
		j++;
	}
	tab_k[j] = '\0';
	return (1);
}

int		split_str_to_tab(char *str, char car, char **tab)
{
	int		i;
	int		k;
	int		index;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		index = i;
		while (str[i] != car && str[i] != '\0')
			i++;
		if (i > 0)
		{
			if (!(tab[k] = malloc(sizeof(char) * (i - index + 1))))
				return (-1);
			k = print(index, i, str, tab[k]) + k;
		}
		i++;
	}
	tab[k] = NULL;
	return (1);
}
