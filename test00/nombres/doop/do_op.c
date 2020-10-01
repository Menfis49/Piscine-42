#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "doop.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long n;

	n = nb;
	if (n < 0)
	{
		n *= (-1);
		ft_putchar('-');
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
	}
}

int	main(int ac, char **av)
{
	int k;

	if (ac == 4)
	{
		if (av[2][0] == '+')
		{
			k = ft_atoi(av[1]) + ft_atoi(av[3]);
			ft_putnbr(k);
		}
		if (av[2][0] == '-')
		{
			k = ft_atoi(av[1]) - ft_atoi(av[3]);
			ft_putnbr(k);
		}
		if (av[2][0] == '*')
		{
			k = ft_atoi(av[1]) * ft_atoi(av[3]);
			ft_putnbr(k);
		}
		if (av[2][0] == '/')
		{
			k = ft_atoi(av[1]) / ft_atoi(av[3]);
			ft_putnbr(k);
		}
		if (av[2][0] == '%')
		{
			k = ft_atoi(av[1]) % ft_atoi(av[3]);
			ft_putnbr(k);
		}
	}
	write(1, "\n", 1);
}
