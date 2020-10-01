#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	disp_space(char *str)
{
	int i;
	int space;

	i = 0;
	space = 0;
	while(str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while (str[i] >= 33 && str[i] <= 126)
		{
			ft_putchar(str[i]);
			i++;
		}
		while(str[i] == ' ' || str[i] == '\t')
		{
			space = 1;
			i++;
		}
		if (space == 1 && str[i] != '\0')
		{
			ft_putchar(' ');
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		disp_space(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
