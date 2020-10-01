/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coco.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:02:12 by vazra             #+#    #+#             */
/*   Updated: 2020/09/16 16:04:21 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(int x, char m, char n, char o)
{
	int j;

	j = 1;
	while (j <= x)
	{
		if (j == 1)
			ft_putchar(m);
		else if (j > 1 && j < x)
			ft_putchar(n);
		else if (j == x)
			ft_putchar(o);
		j++;
	}
}

void	rush(int x, int y)
{
	int i;

	i = 1;
	if (x <= 0 || y <= 0)
		return ;
	while (i <= y)
	{
		if (i == 1)
			ft_print_line(x, '/', '*', '\\');
		else if (i > 1 && i < y)
			ft_print_line(x, '*', ' ', '*');
		else if (i == y)
			ft_print_line(x, '\\', '*', '/');
		ft_putchar('\n');
		i++;
	}
}
