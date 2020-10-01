/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:39:48 by vazra             #+#    #+#             */
/*   Updated: 2020/09/28 20:33:15 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	make_operation(int a, int b, int (*operation)(int, int))
{
	long result;

	result = operation(a, b);
	ft_putnbr(result);
	ft_putchar('\n');
}

void	ft_do_op(char **av)
{
	if (av[2][0] == '+')
		make_operation(ft_atoi(av[1]), ft_atoi(av[3]), ft_addition);
	else if (av[2][0] == '-')
		make_operation(ft_atoi(av[1]), ft_atoi(av[3]), ft_soustraction);
	else if (av[2][0] == '*')
		make_operation(ft_atoi(av[1]), ft_atoi(av[3]), ft_multiplication);
	else if (av[2][0] == '/')
	{
		if (ft_atoi(av[3]) == 0)
		{
			ft_putstr("Stop : division by zero\n");
			return ;
		}
		make_operation(ft_atoi(av[1]), ft_atoi(av[3]), ft_division);
	}
	else if (av[2][0] == '%')
	{
		if (ft_atoi(av[3]) == 0)
		{
			ft_putstr("Stop : modulo by zero\n");
			return ;
		}
		make_operation(ft_atoi(av[1]), ft_atoi(av[3]), ft_modulo);
	}
}
