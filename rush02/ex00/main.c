/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 13:03:59 by jacher            #+#    #+#             */
/*   Updated: 2020/09/29 16:07:56 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		lines;
	char	*source;
	int		count;

	lines = 0;
	if (check_argv(ac, av) == 0)
	{
		error(1);
		return (0);
	}
	source = put_dico_main(ac, av);
	count = work_dico_av(source, &lines);
	if (count == -1)
	{
		error(1);
		return (0);
	}
	else
		main2(lines, count, source, av);
	return (0);
}

int		main2(int lines, int count, char *source, char **av)
{
	char	*dico_str;
	char	**dico_tab;

	if (!(dico_str = malloc(sizeof(char) * (count + 1))))
		return (0);
	if ((dico_to_str_av(dico_str, source) == -1))
	{
		free(dico_str);
		error(1);
		return (0);
	}
	else
	{
		if (!(dico_tab = malloc(sizeof(char*) * (lines + 1))))
			return (0);
		if ((split_str_to_tab(dico_str, '\n', dico_tab) == -1))
			return (0);
		else
		{
			free(dico_str);
			main3(lines, av, dico_tab);
		}
	}
	return (0);
}

int		main3(int lines, char **av, char **dico_tab)
{
	t_dico		*dico_struct;
	t_result	*begin_list;

	begin_list = NULL;
	if (check_dico(dico_tab) == 1)
	{
		dico_struct = split_dico(dico_tab, lines);
		free_dico_tab(dico_tab);
		if (dico_struct == 0)
			return (0);
		else
		{
			if (check_base_dico(dico_struct) == -1)
			{
				printf("la\n");
				error(2);
				return (0);
			}
			cmp_main(dico_struct, av, begin_list);
			free_dico_struct(dico_struct);
			free_list_result(&begin_list);
		}
	}
	else
	{
		printf("ici\n");
		error(2);
	}
	return (1);
}

char	*put_dico_main(int ac, char **av)
{
	char *source;

	if (ac == 3)
		source = av[1];
	else
		source = "numbers.dict.txt";
	return (source);
}

void	cmp_main(t_dico *dico_struct, char **av, t_result *begin_list)
{
	int resultat;
	int	i;
	int nb;

	i = 0;
	while (av[i] != 0)
		i++;
	if (i == 3)
	{
		nb = ft_strlen(av[2]);
		resultat = cmp(dico_struct, av[2], &begin_list, nb);
	}
	else
	{
		nb = ft_strlen(av[1]);
		resultat = cmp(dico_struct, av[1], &begin_list, nb);
	}
	if (resultat > 0)
		print_result(&begin_list);
}
