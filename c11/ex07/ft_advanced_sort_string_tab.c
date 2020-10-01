/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:30:15 by vazra             #+#    #+#             */
/*   Updated: 2020/09/29 14:03:31 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int i;
	int size;

	size = 0;
	while (tab[size])
		size++;
	while (--size >= 0)
	{
		i = 0;
		while (++i <= size)
			if (cmp(tab[i - 1], tab[i]) > 0)
				ft_swap(&tab[i - 1], &tab[i]);
	}
}
