#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check(char *str, char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_union(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (ft_check(s1, s1[i], i) == 1)
			ft_putchar(s1[i]);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if ((ft_check(s2, s2[i], i) == 1) && (ft_check(s1,s2[i],i) == 1))
			ft_putchar(s2[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)	
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
}
