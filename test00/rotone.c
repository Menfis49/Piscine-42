#include <unistd.h>

void	ft_putchar(char  c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'y')
				argv[1][i] += 1;
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Y')
				argv[1][i] += 1;
			if (argv[1][i] == 'Z' || argv[1][i] == 'z')
				argv[1][i] -= 25;
			i++;
		}
		ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
