#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rev_print(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i = i - 1;
	while (i >= 0)
	{
		ft_putchar(str[i]);
		i--;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		rev_print(av[1]);
	}
	write(1, "\n", 1);
}
