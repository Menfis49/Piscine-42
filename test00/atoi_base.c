int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int	ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!base || ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	while (base[i])
	{
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

int	contains(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return i;
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int id;
	int result;

	i = 0;
	result = 0;
	sign = 1;
	if (ft_check_base(base) == 0)
		return (0);
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((id = contains(base, str[i])) > -1)
	{
		result = result*ft_strlen(base) + id;
		i++;
	}
	return (sign * result);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	printf("%d", ft_atoi_base(av[1], av[2]));
}
