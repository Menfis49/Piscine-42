#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return i;
}

int	checkstr(char *str, char c, int end)
{
	int i;

	i = 0;
	while (i < end)
	{
		if(str[i] == c)
			return (0);
		i++;
	}
	return 1;
}

void	inter(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (checkstr(s1, s1[i], i) && s1[i] == s2[j])
			{
				ft_putchar(s1[i]);
				break ;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		inter(av[1], av[2]);
	}
	write(1, "\n", 1);
}
