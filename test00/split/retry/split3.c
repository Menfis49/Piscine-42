#include <stdio.h>
#include <stdlib.h>

int	nb_words(char *str)
{
	int i;
	int nb_w;

	i = 0;
	nb_w = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0')
			nb_w++;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] == '\0')
		{
			return nb_w;
		}
	}
	return (nb_w);
}

int	len_words(char *str, int *start)
{
	int i;
	int st;

	i = 0;
	st = *start;
	while (str[st] != ' ' && str[st] != '\t' && str[st] != '\n' && str[st] != '\0')
	{
		st++;
		i++;
	}
	return i;
}

char	*ft_copy(char *str, int *start, int *len_w)
{
	char *result;
	int i;

	i = 0;
	result = malloc(sizeof(*result) * (*len_w + 1));
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
	int nb_w;
	int len_w;
	int start;
	int i;

	nb_w = 0;
	len_w = 0;
	start = 0;
	i = 0;
	nb_w = nb_words(str);
	printf("nb_w = %d\n", nb_w);
	result = malloc(sizeof(*result) * (nb_w + 1));
	while (i < nb_w)
	{
		while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
			start++;
		len_w = len_words(str, &start);
	//	printf("start = %d et len_w[%d] = %d\n",start, i, len_w);
		result[i] = ft_copy(str, &start, &len_w);
	//	printf("result[%d] = %s\n", i, result[i]);
		i++;
	}
	result[i] = malloc(sizeof(**result) * 1);
	result[i] = 0;
	return (result);
}

int	main(int ac, char **av)
{
	int i = 0;
	char **result;
	
	if (ac == 2)
	{
		result = ft_split(av[1]);
		while (i < 4)
		{
			printf("result[%d] = %s\n", i, result[i]);
			i++;
		}
	}
	return (0);
}
