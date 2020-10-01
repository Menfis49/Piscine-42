/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 13:29:55 by vazra             #+#    #+#             */
/*   Updated: 2020/09/14 12:54:50 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_exist_base(char *base)
{
	int i;
	int j;
	int size_base;

	j = 0;
	i = 0;
	size_base = 0;
	if (ft_strlen(base) < 2)
		return (0);
	size_base = ft_strlen(base);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (size_base);
}

int	contains(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int size_base;
	int r;
	int sign;
	int id;

	r = 0;
	sign = 1;
	if (ft_exist_base(base) == 0)
		return (0);
	size_base = ft_exist_base(base);
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while ((id = contains(base, *str)) > -1)
	{
		r = r * size_base + id;
		str++;
	}
	return (r * sign);
}
