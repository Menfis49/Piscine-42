#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rep_alph(char *str)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while(str[i])
	{
		j = 0;
		if (str[i] < 65 || str[i] > 122 || (str[i] > 90 && str[i] < 97))
			ft_putchar(str[i]);
		if (str[i] >= 65 && str[i] <= 90)
		{
			k = str[i] - 64;
		}
		if (str[i] >= 97 && str[i] <= 122)
			k = str[i] - 96;
		if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90))
		{
			while (j < k)
			{
				ft_putchar(str[i]);
				j++;
			}
		}
		i++;
	}
}


int	main(int ac, char **av)
{
	if (ac == 2)
	{
		rep_alph(av[1]);
	}
	write(1, "\n", 1);
}
