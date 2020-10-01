#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_expand(char *str)
{
	int i;
	int space;

	i = 0;
	while (str[i])
	{
		space = 0;
		if (str[i] != ' ' || str[i] != '\t')
		{	
			ft_putchar(str[i]);
			i++;
		}
		while (str[i] == ' ' || str[i] == '\t')
		{
			space = 1;
			i++;
		}
		if (space == 1 && str[i] != '\0')
		{
			write(1,"   ", 3);
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_expand(av[1]);
	}
	write(1, "\n", 1);
}
