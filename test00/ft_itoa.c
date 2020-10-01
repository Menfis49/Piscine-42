#include <stdlib.h>

int	ft_size_number(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return i;
}

char	*ft_itoa(int nbr)
{
	char *result;
	int size_number;

	size_number = ft_size_number(nbr);
	if (!(result = malloc(sizeof(*result) * size_number + 1)))
		return (0);
	//result[size_number] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = nbr * (-1);
	}
	size_number = size_number - 1;
	while (nbr > 0)
	{
		result[size_number] = 48 + (nbr % 10);
		nbr = nbr / 10;
		size_number--;
	}
	return result;
}

#include <stdio.h>

int	main()
{
	printf("%d\n", ft_size_number(-405));
	printf("%s\n", ft_itoa(-405));
}
