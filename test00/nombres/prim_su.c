#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == ' ')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	is_prim(int n)
{
	int i;

	i = 2;
	if (n < 2)
		return (0);
	while (i <= (n / i))
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int nb)
{
	long n;
	n = nb;
	if (n <= 9 && n >= 0)
	{
		ft_putchar(n + '0');
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	prim_sum(int nb)
{
	int i;
	int result;

	i = 2;
	result = 0;
	if (nb < 2)
		return (0);
	while (i <= nb)
	{
		if (is_prim(i) == 1)
			result += i;
		i++;
	}
	return (result);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_putnbr(prim_sum(ft_atoi(av[1])));
	}
	else
	{
		write(1, "0", 1);
	}
	return (0);
}
