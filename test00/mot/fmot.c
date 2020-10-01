#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	fword(char *str)
{
	int i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
	{
		i++;
	}
	while (str[i] && ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] <= '9' && str[i] >= '0') || (str[i] >= 'a' && str[i] <= 'z' )))
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2 || argv[1] == '\0')
	{
		write(1, "\n", 1);
		return (0);
	}
	
	fword(argv[1]);

	return (0);
}
