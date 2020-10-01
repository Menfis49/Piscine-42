/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:35:26 by vazra             #+#    #+#             */
/*   Updated: 2020/09/21 12:20:20 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_create_str(int size, char **strs, char *sep)
{
	char			*str;
	unsigned int	len;
	unsigned int	i;
	unsigned int	size_strs;

	i = 0;
	len = 0;
	size_strs = size;
	while (i < size_strs)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += (ft_strlen(sep) * (i - 1));
	if (size_strs <= 0)
		len = 1;
	if (!(str = malloc(sizeof(*str) * len + 1)))
		return (0);
	return (str);
}

char			*ft_fill_str(char *str, int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			str[k] = strs[i][j];
			j++;
			k++;
		}
		j = 0;
		while (sep[j] && i != size - 1)
		{
			str[k] = sep[j];
			j++;
			k++;
		}
	}
	str[k] = '\0';
	return (str);
}

char			*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;

	str = ft_create_str(size, strs, sep);
	str = ft_fill_str(str, size, strs, sep);
	return (str);
}
