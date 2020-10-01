/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coco.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:02:12 by vazra             #+#    #+#             */
/*   Updated: 2020/09/13 14:47:48 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line_rush00(int x, char m, char n, char o)
{
	int i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
			ft_putchar(m);
		else if (i > 1 && i < x)
			ft_putchar(n);
		else if (i == x)
			ft_putchar(o);
		i++;
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
			ft_print_line_rush00(x, 'o', '-', 'o');
		else if (i > 1 && i < y)
			ft_print_line_rush00(x, '|', ' ', '|');
		else if (i == y)
			ft_print_line_rush00(x, 'o', '-', 'o');
		ft_putchar('\n');
		i++;
	}
}
