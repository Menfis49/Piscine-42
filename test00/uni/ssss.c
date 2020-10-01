#include <unistd.h>

int	ft_check(char *str, char c, int end)
{
	int i;

	i = 0;
	while(i < end)
	{
		if (str[i] == c)
			return 0;
		i++;
	}
	return 1;
}

void	ftunion(char *s1, char *s2)
{
	int i;
	int lens1;

	i = 0;
	lens1 = 0;
	while (s1[lens1])
		lens1++;
	while (s1[i])
	{
		if (ft_check(s1, s1[i], i) == 1)
			write(1, &s1[i], 1);
		i++;
	}
	i = 0;	
	while (s2[i])
	{
		if (ft_check(s2, s2[i], i) && ft_check(s1, s2[i], lens1))
			write(1, &s2[i], 1);
		i++;
	}
}


int	main(int ac, char **av)
{
	if (ac == 3)
	{
		ftunion(av[1], av[2]);
	}
	write(1, "\n", 1);
}
