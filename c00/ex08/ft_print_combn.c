/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 11:15:15 by vazra             #+#    #+#             */
/*   Updated: 2020/09/30 14:45:44 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	int		i;
	char	tab[11];

	i = 1;
	tab[0] = '0';
	if (n < 1 || n > 9)
		return ;
	while (i < n)
	{
		tab[i] = tab[i - 1] + 1;
		i++;
	}
	tab[n] = ',';
	tab[n + 1] = ' ';
	while (*tab <= 58 - n)
	{
		write(1, tab, n + ((*tab != 58 - n) ? 2 : 0));
		i = n;
		while (i--)
			if (++tab[i] <= 58 - n + i)
				break ;
		while (++i > 0 && i < n)
			tab[i] = tab[i - 1] + 1;
	}
}

int main(void)
{
	ft_print_combn(5);
	return (0);



}
