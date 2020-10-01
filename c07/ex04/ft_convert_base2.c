/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:03:47 by vazra             #+#    #+#             */
/*   Updated: 2020/09/28 11:48:15 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	i = 0;
	j = 0;
	size_base = 0;
	if (ft_strlen(base) < 2)
		return (0);
	size_base = ft_strlen(base);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
				|| (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
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
	int result;
	int sign;
	int id;

	result = 0;
	sign = 1;
	size_base = ft_exist_base(base);
	if (ft_exist_base(base) == 0)
		return (0);
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((id = contains(base, *str)) > -1)
	{
		result = result * size_base + id;
		str++;
	}
	return (result * sign);
}
