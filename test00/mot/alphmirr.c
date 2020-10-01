#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	alph_mirr(char *str)
{
	int i;
	int temp;

	i = 0;
	while (str[i])
	{	if (!(str[i] >= 97 && str[i] <= 126) && !(str[i] >= 65 && str[i] <= 90))
		{
			ft_putchar(str[i]);
		}
		if (str[i] >= 97 && str[i] <= 110)
		{
			temp = str[i] - 122 + 26;
			ft_putchar(123 - temp);
		}
		if (str[i] >= 111 && str[i] <= 122)
		{
			temp = str[i] - 122 + 26;
			ft_putchar(123 - temp);
		}
		if (str[i] >= 65 && str[i] <= 78)
		{
			temp = str[i] - 90 + 26;
			ft_putchar(91 - temp);
		}
		if (str[i] >= 79 && str[i] <= 90)
		{
			temp = str[i] - 90 + 26;
			ft_putchar(91 - temp);
		}
		i++;
	}
}

/*
void	alpha_mirror(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			ft_putchar('z' - (str[i] - 'a'));
		if (str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar('Z' - (str[i] - 'A'));
		if (str[i])
	}
}
*/

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		alph_mirr(av[1]);
	}
	write(1, "\n", 1);
}
