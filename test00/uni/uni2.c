#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_check(char *str, char c, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (str[j] == c)
			return (0);
		j++;
	}
	return (1);
}

void	ft_union(char *str1, char *str2)
{
	int i;
	int k;

	i = 0;
	k = ft_strlen(str1);
	while (str1[i])
	{
		if (ft_check(str1, str1[i], i) == 1)
		{
			write(1, &str1[i], 1);
		}
		i++;
	}
	i = 0;
	while (str2[i])
	{	
		if (ft_check(str2, str2[i], i) == 1)
		{
			if (ft_check(str1, str2[i], k) == 1)
			{
				write(1, &str2[i], 1);
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_union(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}
