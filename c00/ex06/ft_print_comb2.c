/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:01:13 by vazra             #+#    #+#             */
/*   Updated: 2020/09/10 13:17:27 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_commaspace(int a, int b)
{
	if (!(a == 98 && b == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_affichage_a(int a)
{
	if (a < 10)
	{
		ft_putchar('0');
		ft_putchar(a + '0');
	}
	else
	{
		ft_putchar(a / 10 % 10 + '0');
		ft_putchar(a % 10 + '0');
	}
}

void	ft_affichage_b(int b)
{
	if (b < 10)
	{
		ft_putchar('0');
		ft_putchar(b + '0');
	}
	else
	{
		ft_putchar(b / 10 % 10 + '0');
		ft_putchar(b % 10 + '0');
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < 100)
	{
		while (b < 99)
		{
			b++;
			ft_affichage_a(a);
			ft_putchar(' ');
			ft_affichage_b(b);
			ft_commaspace(a, b);
		}
		b = a + 1;
		a++;
	}
}
