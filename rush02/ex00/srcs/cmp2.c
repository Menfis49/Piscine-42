/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvernhes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:47:43 by vvernhes          #+#    #+#             */
/*   Updated: 2020/09/27 19:46:42 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int		nb_units(int nb, char *av, t_dico *tab, t_result **begin_list)
{
	int		i;
	int		j;
	char	temp[4];

	i = 0;
	temp[0] = av[i];
	temp[1] = '\0';
	if (look_doubles(temp, tab, begin_list) == -1)
		return (-1);
	if (nb > 3)
		if (look_for_sep(nb, tab, begin_list) == -1)
			return (-1);
	j = 1;
	while ((nb % 3 == 1) && av[j] != '\0' && av[j] == '0')
		j++;
	if (av[j] == '\0')
		return (0);
	nb = nb - 1;
	return (nb);
}

int		nb_diz(int nb, char *av, t_dico *tab, t_result **begin_list)
{
	int		j;
	char	temp[3];

	if (av[0] == '1')
	{
		ft_get_temp(temp, av, nb);
		nb = nb - 1;
	}
	else
		ft_get_temp(temp, av, nb);
	if (look_doubles(temp, tab, begin_list) == -1)
		return (-1);
	if (nb > 3 && (nb % 3) == 1)
		if (look_for_sep(nb, tab, begin_list) == -1)
			return (-1);
	j = 1;
	while ((nb % 3 == 1) && av[j] != '\0' && av[j] == '0')
		j++;
	if (av[j] == '\0')
		return (0);
	nb = nb - 1;
	return (nb);
}

void	ft_get_temp(char temp[3], char *av, int nb)
{
	int		i;

	i = 0;
	if (av[i] == '1')
	{
		temp[0] = av[i];
		temp[1] = av[i + 1];
		temp[2] = '\0';
		i++;
		nb = nb - 1;
	}
	else
	{
		temp[0] = av[i];
		temp[1] = '0';
		temp[2] = '\0';
	}
}

int		nb_cent(int nb, char *av, t_dico *tab, t_result **begin_list)
{
	int		i;
	int		j;
	char	temp[4];

	i = 0;
	temp[0] = av[i];
	temp[1] = '\0';
	if (look_doubles(temp, tab, begin_list) == -1)
		return (-1);
	temp[0] = '1';
	temp[1] = '0';
	temp[2] = '0';
	temp[3] = '\0';
	if (look_doubles(temp, tab, begin_list) == -1)
		return (-1);
	j = 1;
	while ((nb % 3 == 1) && av[j] != '\0' && av[j] == '0')
		j++;
	if (av[j] == '\0')
		return (0);
	nb = nb - 1;
	return (nb);
}

int		nb_void(int nb, char *av, t_dico *tab, t_result **begin_list)
{
	int		i;
	int		j;

	i = 0;
	if (nb > 3 && (nb % 3) == 1 && (av[i - 1] != '0' || av[i - 2] != '0'))
		if (look_for_sep(nb, tab, begin_list) == -1)
			return (-1);
	return (nb - 1);
	j = 1;
	while ((nb % 3 == 1) && av[j] != '\0' && av[j] == '0')
		j++;
	if (av[j] == '\0')
		return (0);
	nb = nb - 1;
	return (nb);
}
