/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:59:01 by vazra             #+#    #+#             */
/*   Updated: 2020/09/29 12:57:34 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_swap(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_ascii_tab(char **tab, int size)
{
	int		i;
	int		j;
	char	*tamp;

	if (size < 2)
		return ;
	tamp = tab[--size];
	i = 0;
	j = -1;
	while (++j < size)
		if (ft_strcmp(tab[j], tamp) < 0)
			ft_swap(&tab[i++], &tab[j]);
	if (ft_strcmp(tab[i], tab[size]) > 0)
		ft_swap(&tab[i], &tab[size]);
	ft_sort_ascii_tab(tab, i);
	ft_sort_ascii_tab(tab + i + 1, size - i);
}

void	ft_sort_string_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	ft_sort_ascii_tab(tab, i);
}
