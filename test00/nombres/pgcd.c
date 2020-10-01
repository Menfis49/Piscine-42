#include <stdio.h>
#include <stdlib.h>

int	ft_pgcd(int a, int b)
{
	int i;

	if (a == b)
		return (a);
	if (a > b)
	{
		i = b;
		while (i >= 1)
		{
			if (a % i == 0 && b % i == 0)
				return i;
			i--;
		}
	}
	if (a < b)
	{
		i = a;
		while (i >= 1)
		{
			if (b % i == 0 && a % i == 0)
				return i;
			i--;
		}
	}
	return (1);
}


int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%d", ft_pgcd(atoi(av[1]), atoi(av[2])));
	}
}
