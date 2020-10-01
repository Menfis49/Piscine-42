/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:01:42 by vazra             #+#    #+#             */
/*   Updated: 2020/09/23 16:46:06 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_separator(char *str, char *charset)
{
	while (*charset)
		if (*str == *charset++)
			return (1);
	return (0);
}

int		ft_len_word(char *str, char *charset)
{
	int i;

	i = 0;
	while (str[i] && (ft_is_separator(&str[i], charset) == 0))
		i++;
	return (i);
}

int		ft_count_words(char *str, char *charset)
{
	int i;
	int nbr_words;

	nbr_words = 0;
	while (*str)
	{
		while (*str && (ft_is_separator(str, charset) == 1))
			str++;
		i = ft_len_word(str, charset);
		str += i;
		if (i)
			nbr_words++;
	}
	return (nbr_words);
}

char	*ft_copy_word(char *str, int len_word)
{
	char *result;

	if (!(result = malloc(sizeof(*result) * (len_word + 1))))
		return (0);
	result[len_word] = '\0';
	while (len_word--)
		result[len_word] = str[len_word];
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		nbr_words;
	int		len_word;
	int		i;

	nbr_words = ft_count_words(str, charset);
	if (!(result = malloc(sizeof(*result) * (nbr_words + 1))))
		return (0);
	i = -1;
	while (++i < nbr_words)
	{
		while (*str && (ft_is_separator(str, charset) == 1))
			str++;
		len_word = ft_len_word(str, charset);
		if (!(result[i] = ft_copy_word(str, len_word)))
			return (0);
		str += len_word;
	}
	result[nbr_words] = 0;
	return (result);
}
