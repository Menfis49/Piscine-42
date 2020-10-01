#include <unistd.h>

void	ft_putchar(char c)
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

void	lword(char *str)
{
	int i;
	int j;
	char *last;

	i = 0;
	j = 0;
	last = &str[i];
	while (str[i] != '\0')
	{
		if (str[i] >= 33 && str[i] <= 126)
		{
			if (str[i + 1] >= 33 && str[i + 1] <= 126)
			{
				last[j] = str[i+1];
				j++;
			}
		}
		i++;
	}
	if (last)
		ft_putstr(last);
}


int main(int argc, char **argv)
{
	if (argc == 2)
	{
		lword(argv[1]);
	}
	write(1, "\n", 1);
	return 0;
}
