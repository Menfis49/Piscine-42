#include <unistd.h>

int		ft_atoi(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long a;

	a = nb;
	if (a > 9)
	{
		ft_putnbr(a / 10);
		ft_putnbr(a % 10);
	}
	else
	{
		ft_putchar(a + '0');
	}
}

void	ft_mult(int nb)
{
	int i;
	int res;

	i = 1;
	while (i <= 9)
	{
		res = 0;
		ft_putchar(i + '0');
		write(1, " x ", 3);
		ft_putnbr(nb);
		write(1, " = ", 3);
		res = nb * i;
		ft_putnbr(res);
		ft_putchar('\n');
		i++;
	}	
}

int	main(int ac, char **av)
{
	int nb;

	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		ft_mult(nb);
	}
	write (1, "\n", 1);
	return (0);
}
