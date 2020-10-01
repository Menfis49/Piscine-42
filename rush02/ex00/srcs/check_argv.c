/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 10:15:25 by jacher            #+#    #+#             */
/*   Updated: 2020/09/27 23:00:59 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int		check_num(char *av)
{
	int i;

	if (ft_strlen(av) == 0)
		return (0);
	if (av[0] == '0' && av[1] == '\0')
		return (1);
	i = 0;
	while (av[i])
	{
		if (av[0] < '1' || av[0] > '9')
			return (0);
		else if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		check_argv(int ac, char **av)
{
	if (ac == 1 || ac > 3)
	{
		return (0);
	}
	else if (ac == 2)
	{
		if (check_num(av[1]) == 0)
			return (0);
		return (1);
	}
	else
	{
		if (check_num(av[2]) == 0)
			return (0);
		return (1);
	}
}
