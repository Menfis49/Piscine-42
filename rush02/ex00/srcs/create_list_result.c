/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_result.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 10:47:53 by jacher            #+#    #+#             */
/*   Updated: 2020/09/27 18:35:39 by vvernhes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

t_result	*ft_create_elem(char *data)
{
	t_result		*elem;

	if (!(elem = malloc(sizeof(t_result))))
		return (NULL);
	elem->aff = ft_strdup(data);
	elem->next = NULL;
	return (elem);
}

char		*ft_strdup(char *data)
{
	char			*dest;
	unsigned int	i;
	unsigned int	dest_len;

	i = 0;
	dest_len = ft_strlen(data);
	if (!(dest = malloc(sizeof(char) * (dest_len + 1))))
		return (NULL);
	while (data[i] != '\0')
	{
		dest[i] = data[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void		ft_list_push_back(t_result **begin_list, char *data)
{
	t_result		*temp;

	if (!(begin_list) || !(*begin_list))
		*begin_list = ft_create_elem(data);
	else
	{
		temp = *begin_list;
		while (temp->next)
			temp = temp->next;
		temp->next = ft_create_elem(data);
	}
}

void		print_result(t_result **begin_list)
{
	t_result		*temp;

	temp = *begin_list;
	while (temp)
	{
		write(1, temp->aff, ft_strlen(temp->aff));
		if (temp->next != 0)
			write(1, " ", 1);
		else
			write(1, "\n", 1);
		temp = temp->next;
	}
}
