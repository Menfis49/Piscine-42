#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}

int	ft_atoi(char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (i < ft_strlen(str))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign *result);
}

void	print_convert(int nb)
{
	char base[16] = "0123456789abcdef";
	int i;

	if (nb < 0)
		return ;
	if (nb > 15)
	{
		print_convert(nb / 16);
		print_convert(nb % 16);
	}
	else
	{
		ft_putchar(base[nb]);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		print_convert(ft_atoi(av[1]));
	}

	write(1, "\n", 1);
}
