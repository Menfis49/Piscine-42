#include <stdio.h>
#include <stdlib.h>

int	nb_words(char *str)
{
	int i;
	int nb_word;

	i = 0;
	nb_word = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
			i++;
		while ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n') && str[i])
			i++;
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0')
			nb_word++;
		if (str[i] == '\0')
			return (nb_word);
//		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
//			i++;	
	}
	return (nb_word);
}

int	len_words(char *str)
{
	int i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
		i++;
	return i;
}

char	*ftcopy(char *str, int len_word, int *start)
{
	char *result;
	int i;

	i = 0;
	result = malloc(sizeof(*result) * (len_word + 1));
	while (str[*start] != ' ' && str[*start] != '\t' && str[*start] != '\n' && str[*start] != '\0')
	{
		result[i] = str[*start];
		(*start)++;
		i++;
	}
	return (result);
}

char	**split(char *str)
{
	char **result;
	int i;
	int len_word;
	int nb_word;
	int start;

	i = 0;
	start = 0;
	nb_word = nb_words(str);
	result = malloc(sizeof(*result) * (nb_word + 1));
	while (i < nb_word)
	{
		while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
			start++;
		len_word = 0;
		len_word = len_words(str);
		result[i] = ftcopy(str, len_word, &start);
		i++;
	}
	result[i] = malloc(sizeof(**result) * 1);
	result[i] = 0;
	return (result);
}


int	main(int ac, char **av)
{
	char **result;
	int i = 0;
	if (ac == 2)
	{
		result = split(av[1]);
		while (i < 4)
		{
			printf("result[%d] = %s\n", i, result[i]);
			i++;
		}
	}
	return (0);
}
