#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int nb_words(char *str)
{
	int i;
	int nb_word;

	i = 0;
	nb_word = 0;
	while (str[i])
	{
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		nb_word++;
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	}
	return nb_word;
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return i;
}

int	len_words(char *str, int *start)
{
	int i;
	int st = *start;
	
	i = 0;
	while (str[st] && str[st] != ' ' && str[st] != '\t' && str[st] != '\n')
	{
		i++;
		st++;
	}
	return i;
}

char *ftcopy(char *str, int *len_w, int *start)
{
	int i;
	int st;
	char *result;

	i = 0;
	st = *start;
	result = malloc(sizeof(*result) * (*len_w + 1));
	while (str[st] && str[st] != ' ' && str[st] != '\t' && str[st] != '\n')
	{
		result[i] = str[st];
		i++;
		st++;
	}
	return result;
}

char	**ftsplit(char *str)
{
	char **result;
	int i;
	int nb_w;
	int len_str;
	int start;
	int len_w;

	i = 0;
	start = 0;
	len_w = 0;
	nb_w = nb_words(str);
	len_str = ft_strlen(str);
	printf("nb word = %d et len_str = %d\n", nb_w, len_str);
	result = malloc(sizeof(*result) * len_str);
	while (i < nb_w)
	{
		while(str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
			start++;
		len_w = len_words(str, &start);
		printf("i = %d, %d\n", i, len_w);
		result[i] = ftcopy(str, &len_w, &start);
		printf("result[%d] = %s\n", i, result[i]);
		start = start + len_w;
		i++;
	}
	return result;
}

void	rev_wstr(char **split, char *str)
{
	int nb_word = 0;

	nb_word = nb_words(str) - 1;
	while (nb_word >= 0)
	{
		ft_putstr(split[nb_word]);
		write(1, " ", 1);
		nb_word--;
	}
}


int	main(int ac, char **av)
{
	if (ac == 2)
	{
		rev_wstr(ftsplit(av[1]), av[1]);
	}
	write(1, "\n", 1);
}
