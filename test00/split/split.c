#include <stdio.h>
#include <stdlib.h>

int	nb_words(char *str)
{
	int i;
	int nb_word;

	i = 0;
	nb_word = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0')
			nb_word++;
		if (str[i] == '\0')
			return (nb_word);
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	}
	return (nb_word);
}

int	len_words(char *str)
{
	int len;

	len = 0;
	while (str[len] != ' ' && str[len] != '\t' && str[len] != '\n' && str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char *ft_copy(char *str, int *start, int *len_word)
{
	char *result;
	int i;
	
	i = 0;
	result = malloc(sizeof(*result) * (*len_word) + 1);
	while (str[*start] != ' ' && str[*start] != '\t' && str[*start] != '\n' && str[*start] != '\0')
	{
		result[i] = str[*start];
		i++;
		(*start)++;
	}
	return (result);
}

char **ft_split(char *str)
{
	char **result;
	int nb_word;
	int len_word;
	int i;
	int start;

	len_word = 0;
	i = 0;
	start = 0;
	nb_word = nb_words(str);
	result = malloc(sizeof(*result) * (nb_word + 1));
	while (i < nb_word)
	{
		while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
			start++;
		len_word = 0;
		len_word = len_words(&str[start]);
		result[i] = ft_copy(str, &start, &len_word);
		i++;
	}
	result[i] = malloc(sizeof(**result) * 1);
	result[i] = 0;
	return (result);
}

int main(int ac, char **av)
{

	if (ac == 2)
	{
		char **tab;
		tab = ft_split(av[1]);
		int i = 0;
		while (i < 4)
		{
			printf("%s\n", tab[i]);
			i++;
		}
	}
	return (0);
}
