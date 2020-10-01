/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 16:08:10 by jacher            #+#    #+#             */
/*   Updated: 2020/09/27 18:36:55 by vvernhes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	free_dico_tab(char **dico_tab)
{
	int i;

	i = 0;
	while (dico_tab[i] != 0)
	{
		free(dico_tab[i]);
		i++;
	}
	free(dico_tab);
}

void	free_dico_struct(t_dico *dico_struct)
{
	int i;

	i = 0;
	while (dico_struct[i].chiffre != 0 && dico_struct[i].lettre != 0)
	{
		free(dico_struct[i].lettre);
		free(dico_struct[i].chiffre);
		i++;
	}
	free(dico_struct[i].lettre);
	free(dico_struct[i].chiffre);
	free(dico_struct);
}

void	free_list_result(t_result **begin_list)
{
	t_result *free_node;

	if (!(*begin_list) || !(begin_list))
		return ;
	while (*begin_list)
	{
		free_node = *begin_list;
		*begin_list = (*begin_list)->next;
		free(free_node->aff);
		free(free_node);
	}
	*begin_list = NULL;
}
