/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 21:56:31 by vazra             #+#    #+#             */
/*   Updated: 2020/09/16 18:39:17 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		exist_base(char *base)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!base || ft_strlen(base) < 2)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
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
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		size_base;

	nb = nbr;
	if (!(exist_base(base) == 1))
		return ;
	size_base = ft_strlen(base);
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb > size_base - 1)
	{
		ft_putnbr_base(nb / size_base, base);
		ft_putnbr_base(nb % size_base, base);
	}
	else
		ft_putchar(base[nb]);
}

int	main()
{
	ft_putnbr_base(300, "0123456789abcdef");
}
