#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_epur(char *str)
{
	int i;
	int space;

	i = 0;
	space = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		space = 0;
		if (str[i] != '\t'  && str[i] != ' ')
			ft_putchar(str[i]);
		while (str[i] == ' ' || str[i] == '\t')
		{
			space = 1;
			i++;
		}
		if (str[i] == '\0')
		{

		}
		else if (space == 1 && str[i])
		{
			ft_putchar(' ');
		}
		else
		{
			i++;
		}
	}

	while (str[i] == ' ' || str[i] == '\t')
		i++;
}

int	main(int ac, char **av)
{
	if (ac == 2 && av[1][0] != '\0')
	{
		ft_epur(av[1]);
	}
	write(1, "\n", 1);
}
