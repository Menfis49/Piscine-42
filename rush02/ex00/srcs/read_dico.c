/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_dico.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 11:36:20 by jacher            #+#    #+#             */
/*   Updated: 2020/09/30 18:59:40 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int		work_dico_av(char *av, int *lines)
{
	int		fd;
	int		i;
	char	buf[500];
	int		count;
	int		bytes;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	count = 0;
	bytes = 0;
	while ((bytes = read(fd, buf, 500)))
	{
		count = count + bytes;
		i = 0;
		while (i < bytes)
		{
			if (buf[i] == '\n')
				*lines = *lines + 1;
			i++;
		}
	}
	if (close(fd) == -1)
		return (-1);
	return (count);
}

int		dico_to_str_av(char *dico, char *av)
{
	int		fd;
	int		i;
	int		j;
	char	buf[500];
	int		bytes;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	bytes = 0;
	i = 0;
	while ((bytes = read(fd, buf, 500)))
	{
		j = 0;
		while (j < bytes)
		{
			dico[i] = buf[j];
			i++;
			j++;
		}
	}
	dico[i] = '\0';
	if (close(fd) == -1)
		return (-1);
	return (1);
}
